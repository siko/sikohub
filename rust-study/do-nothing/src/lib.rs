use std::alloc::{alloc, dealloc, Layout};
use std::mem;

#[no_mangle]
pub extern "C" fn add(a: u32, b: u32) -> u32 {
    a + b
}

pub extern "C" fn greet(name: &str) -> String {
    format!("Hello, {}!", name)
}

#[export_name = "greet"]
pub extern "C" fn __greet_wrapper(arg0_ptr: *const u8, arg0_len: usize) -> *mut String {
    let arg0 = unsafe {
        let slice = std::slice::from_raw_parts(arg0_ptr, arg0_len);
        std::str::from_utf8_unchecked(slice)
    };
    let _ret = greet(arg0);
    Box::into_raw(Box::new(_ret))
}

#[no_mangle]
pub extern "C" fn __malloc(size: usize) -> *mut u8 {
    let align = mem::align_of::<usize>();
    if let Ok(layout) = Layout::from_size_align(size, align) {
        unsafe {
            if layout.size() > 0 {
                let ptr = alloc(layout);
                if !ptr.is_null() {
                    return ptr;
                }
            } else {
                return align as *mut u8;
            }
        }
    }

    panic!("malloc failed")
}

#[no_mangle]
pub unsafe extern "C" fn __free(ptr: *mut u8, size: usize) {
    if size == 0 {
        return;
    }
    let align = mem::align_of::<usize>();
    let layout = Layout::from_size_align_unchecked(size, align);
    dealloc(ptr, layout);
}

#[no_mangle]
pub unsafe extern "C" fn __boxed_str_free(ptr: *mut String) {
    let _b = Box::from_raw(ptr);
}
