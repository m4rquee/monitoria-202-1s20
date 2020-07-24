cmake_minimum_required(VERSION 3.10.2)
project(lab09 C)

set(CMAKE_C_STANDARD 90)

add_executable(
        lab09 lab09.c
        ordenacao.h ordenacao.c
        lib/avalia64.o
)

target_link_libraries(lab09 m)
