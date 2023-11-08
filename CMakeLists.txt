cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

project(linked_lists LANGUAGES CXX)

add_subdirectory(src)
add_subdirectory(lib)
add_subdirectory(external)
add_subdirectory(linked_lists_unittests)
