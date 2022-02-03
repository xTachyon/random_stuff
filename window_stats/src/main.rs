extern crate winapi;
extern crate pad;

use std::collections::HashMap;
use std::time::Duration;
use std::fmt::Write;
use std::thread;
use std::cmp::{max, min};
use std::path::Path;
use pad::PadStr;
use winapi::um::errhandlingapi::GetLastError;
use winapi::um::handleapi::CloseHandle;
use winapi::um::psapi::GetModuleFileNameExW;
use winapi::um::processthreadsapi::OpenProcess;
use winapi::shared::windef::HWND;
use winapi::um::winuser::{GetForegroundWindow, GetWindowTextW, GetWindowThreadProcessId};

#[derive(Default, Debug, Clone)]
struct WindowInformation {
    title: String,
    path: String
}

impl WindowInformation {
    fn current() -> Result<WindowInformation, u32> {
        let (window, title) = match WindowInformation::get_window() {
            Ok(x) => x,
            Err(x) => return Err(x)
        };
        let path = WindowInformation::get_window_path(window);
        return Ok(WindowInformation{title, path});
    }

    fn get_window() -> Result<(HWND, String), u32>  {
        let mut text = [0u16; 32768];
        let result;
        let window: HWND;
        unsafe {
            window = GetForegroundWindow();
            if window == std::ptr::null_mut() {
                return Err(GetLastError());
            }
            result = GetWindowTextW(window, text.as_mut_ptr(), text.len() as i32);
        }
        let _err = unsafe { GetLastError() };
        let string = String::from_utf16(&text[..result as usize]).unwrap();
        Ok((window, string))
    }

    fn get_window_path(window: HWND) -> String {
        let mut text = [0u16; 32768];
        let length;
        unsafe {
            let mut process_id = 0u32;
            let _result = GetWindowThreadProcessId(window, &mut process_id);
            let process_handle = OpenProcess(0x0410, false as i32, process_id);
            length = GetModuleFileNameExW(process_handle, std::ptr::null_mut(), text.as_mut_ptr(), text.len() as u32);
            CloseHandle(process_handle);
        }
        String::from_utf16(&text[..length as usize]).unwrap()
    }

//    fn make_string(wide_string: &[u16]) -> String {
//        let null = wide_string.iter().position(|x| *x == 0u16).unwrap();
//        let wide_string = &wide_string[..null];
//        String::from_utf16(wide_string).unwrap()
//    }
}

#[derive(Default)]
struct WindowStats {
    last_window: WindowInformation,
    times: HashMap<String, (WindowInformation, u64)>
}

impl WindowStats {
    fn do_loop(&mut self) {
        loop {
            match WindowInformation::current() {
                Ok(x) => {
                    self.last_window = x;
                    break;
                },
                Err(_) => {}
            }
        }
        loop {
            thread::sleep(Duration::from_millis(10));
            let time_current;
            {
                let (window, time) = self.times.entry(self.last_window.path.clone()).or_default();
                time_current = *time;
                *window = self.last_window.clone();
                *time += 10;
                self.last_window = match WindowInformation::current() {
                    Ok(x) => x,
                    Err(_) => {
                        *time -= 10;
                        continue;
                    }
                };
            }
            if /*self.last_window.path == env::current_exe().unwrap().to_str().unwrap() &&*/ time_current % 1000 == 0 {
                self.display_top();
            }
        }
    }

    fn display_top(&self) {
        let mut items: Vec<_> = self.times.iter().collect();
        items.sort_by(|(_, (_, x)), (_, (_, y))| y.cmp(x));


        let mut max_path = 0;
        let mut max_title = 0;
        items.iter().for_each(|(path, (window, _))| {
            max_path = max(max_path, Path::new(path).file_name().unwrap().to_str().unwrap().len());
            max_title = max(max_title, window.title.len());
        });

        let mut output = "Top applications used:\n".to_string();
        let mut count = 1;
        for (path, (window, time)) in &items[..min(20, items.len())] {
            let path = Path::new(path).file_name().unwrap().to_str().unwrap();
            let _ = write!(&mut output, "{: >2}. {} --- {} --- {}\n",
                           count, path.pad_to_width(max_path), window.title.pad_to_width(max_title), WindowStats::format_time(*time));
            count += 1;
        }

        println!("{}\n", output);
    }

    fn format_time(time: u64) -> String {
        let millis = time % 1000;
        let time = time / 1000;
        let seconds = (time % 60) as f32 + millis as f32 / 1000f32;
        let time = time / 60;
        let minutes = time % 60;
        let time = time / 60;
        let hours = time;
        let mut result = String::new();
        if hours > 0 {
            let _ = write!(&mut result, "{} hours", hours);
        }
        if minutes > 0 {
            let _ = write!(&mut result, " {} minutes", minutes);
        }
        let _ = write!(&mut result, " {} seconds", seconds);

        result.trim().to_string()
    }
}

fn main() {
    let mut w = WindowStats::default();
    w.do_loop();
}
