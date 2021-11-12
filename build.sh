#!/bin/bash
OLD_DIR=$(pwd .)
BUILD_DIR=/tmp/c51-make
mkdir $BUILD_DIR 2>/dev/null
cd $BUILD_DIR || exit
echo ================= Build ===================
cmake "$OLD_DIR"
make
echo =============== Build Finish ==============
