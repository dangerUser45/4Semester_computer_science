cmake_minimum_required(VERSION 3.16)

project(Task1 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(task1
    src/main.c
    src/cat.c
    src/dog.c
)

target_include_directories(task1 PRIVATE
    include
)
