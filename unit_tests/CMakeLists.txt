set(This linked_lists_unittests)
add_executable(${This} linked_lists_unittests.cpp)

target_link_libraries(${This} PRIVATE GTest::gtest_main Singly)

include(GoogleTest)
gtest_discover_tests(${This})