cmake_minimum_required(VERSION 3.13)
project(vektorius)

set(CMAKE_CXX_STANDARD 14)

add_executable(vektorius classes/main.cpp classes/generavimas.cpp classes/function.cpp headers/time.h headers/vektorius.h headers/main_header.h classes/time.cpp)