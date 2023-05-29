//
// Created by up202005832 on 19/05/2023.
//

#ifndef DA_QUIMBOIO_OVERLOADS_H
#define DA_QUIMBOIO_OVERLOADS_H

#include "data_structs/Graph.h"
#include "data_structs/AdjacencyMatrix.h"

std::ostream& operator<<(std::ostream& o, Vertex v);

std::ostream& operator<<(std::ostream& o, Edge e);

std::ostream& operator<<(std::ostream& o, Graph g);

std::ostream& operator<<(std::ostream& o, AdjacencyMatrix a);

std::ostream& operator<<(std::ostream& o, std::vector<int> v);

std::ostream& operator<<(std::ostream& o, std::vector<Vertex*> v);

#endif //DA_QUIMBOIO_OVERLOADS_H
