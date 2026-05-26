cmake_minimum_required(VERSION 3.20)

project(containers)

enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

set(CONTAINERS_LIB "containers_lib")
add_library(${CONTAINERS_LIB} "")

add_subdirectory(src)
add_subdirectory(test)
