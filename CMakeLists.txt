cmake_minimum_required(VERSION 3.21)
project(Multithreading_Course)

set(CMAKE_CXX_STANDARD 20)

add_executable(Multithreading_Course main.cpp headers/IgnoringProcess.hpp headers/IProcess.hpp sources/IgnoringProcess.cc sources/ZombieProcess.cc headers/ZombieProcess.hpp sources/UnnamedPipesProcess.cc headers/UnnamedPipesProcess.hpp)
