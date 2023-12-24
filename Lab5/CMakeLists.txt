cmake_minimum_required(VERSION 3.10)
project(lab_5)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

add_executable(lab5
    main.cpp
    include/allocator.hpp)

enable_testing()
add_executable(test_lab5
    tests.cpp
    include/list.hpp
    include/allocator.hpp)

target_link_libraries(test_lab5 ${GTEST_LIBRARIES})
add_test(NAME counter_test COMMAND test_lab5)
