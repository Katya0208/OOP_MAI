cmake_minimum_required(VERSION 3.10)
project(oop7)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(app main.cpp src/npc.cpp src/princess.cpp src/knight.cpp src/dragon.cpp)

enable_testing()


add_executable(tests tests.cpp src/npc.cpp src/princess.cpp src/knight.cpp src/dragon.cpp)

target_link_libraries(tests ${GTEST_LIBRARIES})

add_test(NAME counter_test COMMAND test_lab7)