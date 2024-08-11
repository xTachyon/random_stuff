use std::fmt::Arguments;
use std::fs;

trait FmtWriteNoFail {
    fn write_fmt(&mut self, args: Arguments);
}
impl FmtWriteNoFail for String {
    fn write_fmt(&mut self, args: Arguments) {
        std::fmt::Write::write_fmt(self, args).expect("write on string failed 😢");
    }
}

fn main() {
    let mut output = String::new();
    let mut output_fn = String::new();

    writeln!(
        output,
        "
#include <cstdint>
#include <cstdio>
#include <cstdlib>

enum class Result {{
    Unknown,
    False,
    True,
}};"
    );

    let numbers_per_fn = 10;

    for fn_index in 0..50 {
        let start = fn_index * numbers_per_fn;
        let stop = start + numbers_per_fn;
        writeln!(output, "static void is_even_{start}_{stop}(uint32_t x, int& result) {{");

        for number in start..stop {
            let s = if number % 2 == 0 { "yes" } else { "no" };
            writeln!(output, r"    if (x == {number}) goto {s};");
        }

        writeln!(
            output,
            r#"
    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}}"#
        );

        writeln!(output_fn, "   c(is_even_{start}_{stop});");
    }

    writeln!(
        output,
        r#"
bool is_even(uint32_t x) {{
#define c(name)                \
    {{                          \
        int result;            \
        name(x, result); \
        if (result) {{            \
            return result;     \
        }}                      \
    }}
{output_fn}
    return false;
}}

int main(int argc, char** argv) {{
    uint32_t x = atoi(argv[1]);
    printf("%s", is_even(x) ? "even" : "odd");
}}"#
    );

    fs::write("main.cpp", output).unwrap();
}

/*
bool is_even(uint32_t x) {
    if (auto r = is_even_0_100(x); r != Result::Unknown) {
        return r == Result::True;
    }
    if (auto r = is_even_100_200(x); r != Result::Unknown) {
        return r == Result::True;
    }

    return false;
}
*/

// https://github.com/llvm/llvm-project/commit/b818da27ab6d7

/*

bool is_even(uint32_t x) {
#define c(name)                \
    {                          \
        int result;            \
        name(x, result); \
        if (result) {            \
            return result;     \
        }                      \
    }
    c(is_even_0_10);
    c(is_even_10_20);
    c(is_even_20_30);
    c(is_even_30_40);
    c(is_even_40_50);

    return false;
}*/