cmake_minimum_required(VERSION 3.29)
project(KP6 C)

set(CMAKE_C_STANDARD 99)

add_executable(KP6 main.c
        validation.h
        "customization .h"
        calculation.h
        "print_function.h"
        function.h
)
