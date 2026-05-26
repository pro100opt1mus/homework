cmake_minimum_required(VERSION 3.20)


project(long_numbers)

set(LONG_NUM_LIB "long_numbers_lib")
add_library(${LONG_NUM_LIB} "")

add_subdirectory(src)
add_subdirectory(test)
