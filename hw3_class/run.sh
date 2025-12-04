#!/bin/bash
rm -f project
clang++ -std=c++17 -o project main.cpp elem_func.cpp menu_elements.cpp
./project
