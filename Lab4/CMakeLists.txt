cmake_minimum_required(VERSION 3.10)
project(lab_4)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

add_executable(lab4
    main.cpp
    include/figure.hpp
    include/point.hpp
    include/rhomb.hpp
    include/hexagon.hpp
    include/pentagon.hpp
    include/vector.hpp)

enable_testing()
add_executable(test_lab4
    test.cpp
    include/figure.hpp
    include/point.hpp
    include/rhomb.hpp
    include/pentagon.hpp
    include/hexagon.hpp
)
target_link_libraries(test_lab4 ${GTEST_LIBRARIES})
add_test(NAME counter_test COMMAND test_lab4)
