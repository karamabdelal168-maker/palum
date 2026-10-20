#!/bin/bash
cmake ./CMakeLists.txt
cmake -S . -B bin
cmake --build bin
abspath=$(realpath "./bin/")
export PATH="$PATH:$abspath"
echo "use the command palum to use the program"
