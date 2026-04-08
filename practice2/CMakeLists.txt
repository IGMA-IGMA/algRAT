cmake_minimum_required(VERSION 3.10)
project(IntegrationTest)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")

add_executable(test_solution test_solution.cpp solution.cpp)

target_include_directories(test_solution PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Для отладочной сборки
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG")