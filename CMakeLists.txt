cmake_minimum_required(VERSION 3.10)
project(c_util_demo C)

set(CMAKE_C_STANDARD 99)
add_executable(c_util_demo main.c c_util.h c_util.c)
