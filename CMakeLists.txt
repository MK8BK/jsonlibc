cmake_minimum_required(VERSION 3.25)
project(clibjson C)

set(CMAKE_C_STANDARD 23)

add_library(clibjson library.c tests/test.c)
