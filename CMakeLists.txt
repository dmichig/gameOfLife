cmake_minimum_required(VERSION 3.16)
project(gameOfLife)

set(CMAKE_CXX_STANDARD 14)

add_executable(gameOfLife main.cpp cell.cpp cell.h space.cpp space.h)