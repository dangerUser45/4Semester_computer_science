cmake_minimum_required(VERSION 3.16)

project(Task LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(task
  src/animal.c
  src/main.c
  src/cat.c
  src/dog.c
  src/class.c
  src/obj.c
)

target_include_directories(task PRIVATE
    include
)
