use std::fs;
use std::process::{Command, Stdio};

fn main() {
    let mut left = 0u32;
    let mut right = 1000000u32;

    while left + 1 < right {
        let mid = (left + right) / 2;
        println!("{} {} -> {}", left, right, mid);

        let text = format!("int x={}5{}; int main(){}",
            "(".repeat(mid as usize),
            ")".repeat(mid as usize),
            "{}"
        );

        fs::write("test.c", text).unwrap();

        let child = Command::new("clang")
            .arg("test.c")
            .stdout(Stdio::null())
            .stderr(Stdio::null())
            .spawn()
            .unwrap()
            .wait()
            .unwrap();

        if child.success() {
            left = mid;
        } else {
            right = mid;
        }

        println!("{:?}", child);
    }
}
