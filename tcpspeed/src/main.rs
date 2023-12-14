use std::{
    io::{Read, Write},
    net::{TcpListener, TcpStream},
    sync::{
        atomic::{AtomicU64, Ordering},
        Arc,
    },
    time::Duration,
};

use clap::Parser;
use humansize::{format_size, BINARY};

#[derive(Parser)]
#[command(version, about = "tcpspeed")]
struct Args {
    #[arg(short, long)]
    client: Option<String>,
}

const NO_OF_SOCKETS: u8 = 4;

fn main() {
    let args = Args::parse();

    match args.client {
        Some(ip) => client(ip),
        None => server(),
    }

    std::thread::sleep(Duration::from_secs(u64::MAX));
}

fn server() {
    let listener = TcpListener::bind("0.0.0.0:8080").unwrap();

    let bytes_sent = Arc::new(AtomicU64::new(0));
    let bytes_sent_clone = bytes_sent.clone();
    std::thread::spawn(|| print_progress(bytes_sent_clone));

    for _ in 0..NO_OF_SOCKETS {
        let stream = listener.accept().unwrap().0;

        let bytes_sent_clone = bytes_sent.clone();
        std::thread::spawn(|| server_thread(stream, bytes_sent_clone));
    }
}

fn print_progress(bytes: Arc<AtomicU64>) {
    let mut last = 0;
    loop {
        let current = bytes.load(Ordering::Relaxed);

        let diff = current - last;

        println!("{}", format_size(diff, BINARY));

        last = current;

        std::thread::sleep(Duration::from_secs(1));
    }
}

fn server_thread(mut socket: TcpStream, bytes_sent: Arc<AtomicU64>) {
    socket.set_nodelay(true).unwrap();

    let buffer: Vec<u8> = (0..1024 * 1024).map(|x| x as u8).collect();
    let mut current = buffer.as_slice();

    loop {
        let sent = socket.write(current).unwrap();
        if sent == 0 {
            println!("done");
            return;
        }

        bytes_sent.fetch_add(sent as u64, Ordering::Relaxed);

        current = &current[sent..];
        if current.is_empty() {
            current = buffer.as_slice()
        }
    }
}

fn client_impl(ip: String, bytes_sent: Arc<AtomicU64>) {
    let mut socket = TcpStream::connect(ip).unwrap();
    socket.set_nodelay(true).unwrap();

    let mut buffer = [0; 64 * 1024];

    loop {
        let read = socket.read(&mut buffer).unwrap();
        if read == 0 {
            println!("done");
            return;
        }

        bytes_sent.fetch_add(read as u64, Ordering::Relaxed);
    }
}

fn client(ip: String) {
    let bytes_sent = Arc::new(AtomicU64::new(0));

    let bytes_sent_clone = bytes_sent.clone();
    std::thread::spawn(|| print_progress(bytes_sent_clone));

    for _ in 0..NO_OF_SOCKETS {
        let ip = ip.clone();
        let bytes_sent_clone = bytes_sent.clone();

        std::thread::spawn(|| client_impl(ip, bytes_sent_clone));
    }
}
