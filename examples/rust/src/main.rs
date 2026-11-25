#![no_std]
#![no_main]

use xbox360_env::println;

#[unsafe(no_mangle)]
extern "C" fn main() -> i32 {
    println!("Hello from Rust!");
    0
}
