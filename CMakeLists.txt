cmake_minimum_required(VERSION 3.23)
project(DA_Quimboio)

set(CMAKE_CXX_STANDARD 14)

add_executable(DA2 src/data_structs/VertexEdge.cpp src/data_structs/VertexEdge.h src/data_structs/Graph.cpp src/data_structs/Graph.h src/main.cpp src/data_structs/AdjacencyMatrix.cpp src/data_structs/AdjacencyMatrix.h src/overloads.h src/overloads.cpp src/readFile.cpp src/readFile.h src/Menu.cpp src/Menu.h)
