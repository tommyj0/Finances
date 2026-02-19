#!/bin/sh

cmake --build build

## check if the build was successful before running the program
if [ $? -ne 0 ]; then
    echo "Build failed. Exiting."
    exit 1
fi  

./build/Finances