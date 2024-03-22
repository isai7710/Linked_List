cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

project(linked_lists LANGUAGES CXX)

# Include Singly Linked List Library:
add_subdirectory(lib)

# Include Google Test:
add_subdirectory(external/googletest)

# Include Unit Test directory:
add_subdirectory(linked_lists_unittests)

# Include main project source code directory:
add_subdirectory(src)



