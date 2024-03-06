cmake_minimum_required(VERSION 3.8)
project(eigenMatrix)

find_package(Eigen3 REQUIRED)

add_executable(eigenMatrix eigenMatrix.cpp)
