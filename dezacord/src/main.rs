use bumpalo::collections::vec::Vec as BVec;
use bumpalo::collections::string::String as BString;
use bumpalo::Bump;
use fs::File;
use fs_err as fs;
use indexmap::IndexMap;
use serde::Deserialize;
use serde_derive::Deserialize;
use std::borrow::Cow;
use std::io;
use std::fmt::Write;

fn read<'x>(bump: &'x Bump, path: &str) -> &'x [u8] {
    let mut file = File::open(path).unwrap();
    let size = file.metadata().unwrap().len();
    let mut result = BVec::with_capacity_in(size as usize, bump);
    io::copy(&mut file, &mut result).unwrap();
    result.into_bump_slice()
}

fn read_json<'x, T: Deserialize<'x>>(bump: &'x Bump, path: &str) -> T {
    let data = read(bump, path);
    serde_json::from_slice(data).unwrap()
}

fn read_index<'x>(bump: &Bump) -> IndexMap<u64, String> {
    read_json(bump, "messages/index.json")
}

type S<'x> = Cow<'x, str>;

#[derive(Deserialize)]
struct JsonMessage<'x> {
    #[serde(rename="Contents")]
    contents: S<'x>
}

fn main() {
    let mut bump = Bump::new();
    let index = read_index(&bump);

    for i in index.into_keys() {
        bump.reset();

        let name = &mut BString::new_in(&bump);
        write!(name, "messages/c{}/messages.json", i).unwrap();

        let data: Vec<JsonMessage> = read_json(&bump, name);
        println!("{}", data.len());
    }
}
