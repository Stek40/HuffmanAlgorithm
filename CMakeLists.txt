cmake_minimum_required(VERSION 3.21)
project(HuffmanAlgorithm)

set(CMAKE_CXX_STANDARD 14)

include_directories(HuffmanAlgorithm)

add_executable(HuffmanAlgorithm
        HuffmanAlgorithm/Demo.cpp
        HuffmanAlgorithm/Node.cpp
        HuffmanAlgorithm/Node.h
        HuffmanAlgorithm/Pair.cpp
        HuffmanAlgorithm/Pair.h
        HuffmanAlgorithm/Tree.cpp
        HuffmanAlgorithm/Tree.h
        HuffmanAlgorithm/Utils.cpp
        HuffmanAlgorithm/Utils.h)
