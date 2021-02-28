#!/bin/sh

cd /sourcetree/external/seastar
./configure.py --mode=release --without-apps --without-tests --without-demos
ninja-build -C build/release/
ninja-build -C build/release/ install

cd ../../build
cmake .. -GNinja
ninja
