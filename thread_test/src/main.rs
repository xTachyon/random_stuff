use std::thread;
use std::sync::mpsc::channel;
use std::sync::mpsc::Receiver;
use std::time::Instant;
use std::time::Duration;

fn receive(receiver: Receiver<Instant>) {
    for _ in 0..5 {
        let _ = receiver.recv().unwrap();
    }
    // when thread starts it's way slower

    let mut max = 0;
    let mut total = 0u128;
    for count in 1.. {
        let time = receiver.recv().unwrap();

        let current = time.elapsed().as_nanos();
        total += current;
        max = max.max(current);
        let average = total / count;
        println!("elapsed: {} ns, max: {} ns, average: {} ns", current, max, average);
    }
}

fn main() {
    let (writer, receiver) = channel();
    thread::spawn(move || {
        receive(receiver);
    });

    loop {
        writer.send(Instant::now()).unwrap();
        std::thread::sleep(Duration::from_millis(500));
    }
}