rust study
---



books
----

Rust [官方文档中文翻译](https://rustwiki.org/zh-CN/)

Rust 程序设计语言 [简体中文版](https://rustwiki.org/zh-CN/book/) [English]( https://doc.rust-lang.org/book/)

通过例子学Rust [中文版](https://rustwiki.org/zh-CN/rust-by-example/)

Rust [标准库文档中文版](https://rustwiki.org/zh-CN/std/)

Rust [核心库文档中文版](https://rustwiki.org/zh-CN/core/)

tips
----

* 当变量离开作用域，Rust 为我们调用一个特殊的函数。这个函数叫做 drop，在这里 String 的作者可以放置释放内存的代码。Rust 在结尾的 } 处自动调用 drop。
* 在同一时间只能有一个对某一特定数据的可变引用。
* 每个结构体都允许拥有多个 impl 块。
* `Packages: A Cargo feature that lets you build, test, and share crates
    Crates: A tree of modules that produces a library or executable
    Modules and use: Let you control the organization, scope, and privacy of paths Paths: A way of naming an item, such as a struct, function, or module`
* 
