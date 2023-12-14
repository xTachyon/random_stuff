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

fn main() {
    let args = Args::parse();

    match args.client {
        Some(ip) => client(ip),
        None => server(),
    }
}

fn server() {
    let listener = TcpListener::bind("0.0.0.0:8080").unwrap();

    for stream in listener.incoming() {
        let stream = stream.unwrap();
        let bytes_sent = Arc::new(AtomicU64::new(0));
        let bytes_sent_clone = bytes_sent.clone();

        std::thread::spawn(|| server_thread(stream, bytes_sent));
        std::thread::spawn(|| print_progress(bytes_sent_clone));
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

fn client(ip: String) {
    let mut socket = TcpStream::connect(ip).unwrap();
    let mut buffer = [0; 64 * 1024];

    let bytes_sent = Arc::new(AtomicU64::new(0));
    let bytes_sent_clone = bytes_sent.clone();

    std::thread::spawn(|| print_progress(bytes_sent_clone));

    loop {
        let read = socket.read(&mut buffer).unwrap();
        if read == 0 {
            println!("done");
            return;
        }

        bytes_sent.fetch_add(read as u64, Ordering::Relaxed);
    }
}
