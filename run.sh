#!/bin/bash

g++ -std=c++17 *.cpp -o nxnt

if [ $? -eq 0 ]; then
    kitty -e ./nxnt
else
    echo "Compilation failed"
fi