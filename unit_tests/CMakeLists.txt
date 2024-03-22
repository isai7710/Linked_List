# Define source files and executable for unit tests
set(TEST_SOURCES singly_linked_list_unit_tests.cpp)

# Create executable target
add_executable(sll_unit_tests ${TEST_SOURCES})

# Link with googletest and your Linked List library
target_link_libraries(sll_unit_tests PRIVATE gtest gtest_main linked_list_library)

