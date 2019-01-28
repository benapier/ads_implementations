cmake_minimum_required(VERSION 3.13)
project(ads_implementations)

set(CMAKE_CXX_STANDARD 17)

add_executable(ads_implementations main.cpp sorting/BucketSort.cpp header.h sorting/SelectionSort.cpp)