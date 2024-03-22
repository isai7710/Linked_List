cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

project(Linked_List LANGUAGES CXX)

# Include Linked List Library source files:
add_subdirectory(src)

# Include Google Test:
add_subdirectory(external/googletest)

# Include Unit Test directory:
add_subdirectory(unit_tests)