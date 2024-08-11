use std::mem::size_of;
use std::time::Duration;
use std::time::Instant;

macro_rules! run_test {
    ($T:ident) => {
        let n = 10 * 1000 * 1000;
        let repeat = 20;

        for offset in 0..size_of::<$T>() {
            let mut big_array = vec![0 as $T; n + 2];
            println!("offset = {}", offset);

            let begin = (big_array.as_mut_ptr() as *mut u8).add(offset) as *mut $T;
            let end = begin.add(n);
            assert!((end as *const $T) < big_array.last().unwrap() as *const $T);
            let mut sumt = Duration::ZERO;

            for k in 0..repeat {
                let start = Instant::now();

                for i in 0..n {
                    begin.add(i).write_unaligned(k as $T);
                }

                let mut val: $T = 1;
                for i in 0..n {
                    let v = begin.add(i).read_unaligned();
                    let v = v.wrapping_mul(val);
                    let v = v.wrapping_add(33);
                    val = v;
                }

                sumt += start.elapsed();
                print!("{}", val);
            }

            println!(
                "\n average time for offset {offset} is {}",
                sumt.as_secs_f64() / repeat as f64
            );
        }
    };
}

fn main() {
    unsafe {
        run_test!(u32);
    }
}

// Using the same strategy as
// https://github.com/lemire/Code-used-on-Daniel-Lemire-s-blog/blob/master/2012/05/31/test.cpp
// or trying to at least
