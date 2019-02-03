cmake_minimum_required(VERSION 3.13)
project(ads_implementations)

set(CMAKE_CXX_STANDARD 17)

add_executable(ads_implementations main.cpp array_sorting/BucketSort.cpp header.h array_sorting/SelectionSort.cpp
        array_sorting/SelectionSort.cpp array_sorting/InsertionSort.cpp array_sorting/BubbleSort.cpp
        data_structures/BinarySearchTree.cpp data_structures/BinarySearchTree.h data_structures/array_based/Stack.h data_structures/SinglyLinkedList.h)
