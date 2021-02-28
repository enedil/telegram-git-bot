#!/bin/sh

sourcetree=$1

cd $sourcetree/external/seastar
./configure.py --mode=release --without-apps --without-tests --without-demos
ninja-build -C build/release/

echo $sourcetree/external/seastar/
cd ../../build
cmake ..  -DSEASTAR_DIR=$sourcetree/external/seastar/ -GNinja
ninja
