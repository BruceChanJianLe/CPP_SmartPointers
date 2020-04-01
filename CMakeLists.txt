cmake_minimum_required(VERSION 3.17)
project(smartPointer)

# SET(CMAKE_CXX_FLAGS "-std=c++17")
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(CMAKE_CXX_COMPILE_FEATURES ON)

add_executable(uniquePointer ExerciseFiles/unique.cpp ExerciseFiles/my_func.cpp ExerciseFiles/my_strc.cpp)
add_executable(sharedPointer ExerciseFiles/share.cpp ExerciseFiles/my_func.cpp ExerciseFiles/my_strc.cpp)
# add_executable(sharedPointer2 ExerciseFiles/shared_ptr.cpp ExerciseFiles/strc.cpp)
add_executable(weakPointer ExerciseFiles/weak.cpp ExerciseFiles/my_func.cpp ExerciseFiles/my_strc.cpp)
add_executable(customDeleter ExerciseFiles/deleter.cpp ExerciseFiles/my_func.cpp ExerciseFiles/my_strc.cpp)