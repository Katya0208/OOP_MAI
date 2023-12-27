cmake_minimum_required(VERSION 3.10)
project(oop6)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES src/observer.cpp src/princess.cpp src/dragon.cpp src/knight.cpp src/npc.cpp)

add_executable(app main.cpp ${SOURCES})

enable_testing()
# add_subdirectory(googletest)

add_executable(tests tests.cpp 
${SOURCES})

target_link_libraries(tests ${GTEST_LIBRARIES})

add_test(NAME counter_test COMMAND test_lab6)
