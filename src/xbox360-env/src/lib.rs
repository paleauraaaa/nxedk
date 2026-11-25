#![no_std]

#[global_allocator]
static ALLOC: mimalloc::MiMalloc = mimalloc::MiMalloc;

extern crate alloc;

use alloc::format;

#[macro_export]
macro_rules! print {
    ($($arg:tt)*) => {{
        $crate::_print(core::format_args!($($arg)*));
    }};
}

#[macro_export]
macro_rules! println {
    () => {
        $crate::print!("\n")
    };
    ($($arg:tt)*) => {{
        $crate::_print(core::format_args!($($arg)*));
        $crate::println!();
    }};
}

#[doc(hidden)]
pub fn _print(args: core::fmt::Arguments) {
    let s = format!("{}", args);
    unsafe {
        if libc::fwrite(s.as_ptr().cast(), 1, s.len(), libc::stdout) != s.len() {
            xboxkrnl_sys::DbgPrint(c"Failed to write to stdout\n".as_ptr().cast());
        }
    }
}

#[panic_handler]
fn panic(info: &core::panic::PanicInfo) -> ! {
    println!("************************************ PANIC! ************************************");
    println!("{}", info);
    println!("********************************************************************************");
    unsafe { xboxkrnl_sys::DbgBreakPoint(); }
    unsafe { libc::exit(-1) };
}