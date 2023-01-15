cmake_minimum_required(VERSION 3.24)
project(linked_lists C)

set(CMAKE_C_STANDARD 11)

add_executable(linked_lists
        main.c functions.h optimized.c single_way.c double.c ordered_list.c)
