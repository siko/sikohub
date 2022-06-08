fn main() {
    another_function(-5678);

    // 表达式的结尾没有分号。如果在表达式的末尾加上分号，那么它就转换为语句，而语句不会返回值。
    let y = {
        let x = 3;
        x + 1
    };

    println!("The value of y is: {}", y);

    let x = five();

    println!("The value of x is: {}", x);

    let x = plus_one(5);

    println!("The value of x is: {}", x);
}

fn another_function(x: i32) {
    println!("The value of x is: {}", x);
}

// 函数可以向调用它的代码返回值。我们并不对返回值命名，但要在箭头（->）后声明它的类型。
// 在 Rust 中，函数的返回值等同于函数体最后一个表达式的值。
// 使用 return 关键字和指定值，可从函数中提前返回；但大部分函数隐式的返回最后的表达式。
fn five() -> i32 {
    5
}

fn plus_one(x: i32) -> i32 {
    x + 1
}

