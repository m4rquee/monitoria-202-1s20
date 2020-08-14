cmake_minimum_required(VERSION 3.10.2)
project(lab10 C)

set(CMAKE_C_STANDARD 90)

add_executable(
        lab10 lab10.c
        hash.h hash.c
        lib/saida64.o
)

target_link_libraries(lab10 m)
