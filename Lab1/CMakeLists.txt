cmake_minimum_required(VERSION 3.15)
project(Lab1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab1 main.cpp ArrayList/ArrayList.cpp ArrayList/ArrayList.h ItemType/ItemType.cpp ItemType/ItemType.h Application/Application.cpp Application/Application.h)