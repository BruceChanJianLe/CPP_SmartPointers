cmake_minimum_required(VERSION 3.17)
project(smartPointer)

# SET(CMAKE_CXX_FLAGS "-std=c++17")
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(CMAKE_CXX_COMPILE_FEATURES ON)

add_executable(test ExerciseFiles/test.cpp ExerciseFiles/my_strc.cpp)