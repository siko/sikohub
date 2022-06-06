#!/bin/bash

#WABT_BIN=$HOME/Code/wabt/bin
#BINARYEN_BIN=$HOME/Code/binaryen/bin
TARGET=wasm32-unknown-unknown
NAME=do_nothing
BINARY=target/$TARGET/release/$NAME.wasm

cargo build --target $TARGET --release
wasm-strip $BINARY
mkdir -p www
wasm-opt -o www/$NAME.wasm -Oz $BINARY