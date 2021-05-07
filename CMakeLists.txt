cmake_minimum_required(VERSION 3.19)
project(GameOfLife C)

set(CMAKE_C_STANDARD 11)

link_libraries(SDL2)

add_executable(GameOfLife main.c Game.c Game.h)
