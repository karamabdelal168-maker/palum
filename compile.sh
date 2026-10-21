#!/bin/bash
cmake ./CMakeLists.txt
cmake -S . -B bin
cmake --build bin
sudo mv ./bin/palum /usr/bin