cmake_minimum_required(VERSION 3.0)
project(fractal_bitmap_creator)

add_compile_options(
  -std=c++11
)

include_directories(
  include
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src)

file(GLOB SOURCES
    src/*.cpp
)

add_executable(fractal_bitmap_creator src/main.cpp ${SOURCES})
