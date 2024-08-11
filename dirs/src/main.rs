use anyhow::Result;
use futures::future::{BoxFuture, FutureExt};
use tokio::{
    fs::{read_dir, DirEntry},
    task::JoinSet,
};

fn recursive(name: String) -> BoxFuture<'static, Result<Vec<String>>> {
    do_folder(name).boxed()
}

struct Context {
    files: Vec<String>,
    folders: JoinSet<BoxFuture<'static, Result<Vec<String>>>>,
}

async fn do_one_file(entry: DirEntry, ctx: &mut Context) {
    let name = entry.file_name();
    let Some(name) = name.to_str() else {
        println!(
            "ignoring path because it's not unicode: {:?}",
            entry.file_name()
        );
        return;
    };
    let name = name.to_string();

    let ty = entry.file_type().await?;
    if ty.is_dir() {
        let new = recursive(name);
        ctx.folders.spawn(new);
    } else if ty.is_file() {
        ctx.files.push(name);
    } else {
        println!("unknown file type: {ty:?} => {name}");
    }
}

async fn do_folder(path: String) -> Result<Vec<String>> {
    let mut folders = JoinSet::new();
    let mut files = Vec::with_capacity(16);

    let mut reader = read_dir(path).await?;
    while let Some(entry) = reader.next_entry().await? {}

    while let Some(res) = folders.join_next().await {
        let res = res.unwrap().unwrap();
        files.extend(res.into_iter());
    }

    Ok(files)
}

async fn do_folders(paths: Vec<String>) -> Vec<String> {
    let mut set = JoinSet::new();

    for i in paths {
        set.spawn(do_folder(i));
    }

    let mut files = Vec::with_capacity(16);
    while let Some(res) = set.join_next().await {
        let res = res.unwrap().unwrap();
        files.extend(res.into_iter());
    }

    files
}

#[tokio::main]
async fn main() {
    let paths = [r#"D:\mctest\test\world"#.to_string()].to_vec();

    for i in do_folders(paths).await {
        println!("{i}");
    }
}
