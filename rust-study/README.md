rust study
---



books
----

Rust 官方文档中文翻译 https://rustwiki.org/zh-CN/ 

Rust 程序设计语言 简体中文版  https://rustwiki.org/zh-CN/book/

通过例子学 Rust 中文版 https://rustwiki.org/zh-CN/rust-by-example/


tips
----

* 当变量离开作用域，Rust 为我们调用一个特殊的函数。这个函数叫做 drop，在这里 String 的作者可以放置释放内存的代码。Rust 在结尾的 } 处自动调用 drop。
