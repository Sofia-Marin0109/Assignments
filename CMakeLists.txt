cmake_minimum_required(VERSION 4.1)
project(Assignments)

set(CMAKE_CXX_STANDARD 20)

add_executable(Assignments main.cpp
        FailureFunction.cpp
        FailureFunction.h
        Kmp.cpp
        Kmp.h)
