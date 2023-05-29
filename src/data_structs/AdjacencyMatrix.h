//
// Created by feld on 19-05-2023.
//

#ifndef DA2_ADJACENCY_MATRIX_H
#define DA2_ADJACENCY_MATRIX_H
#include "Graph.h"
#include <vector>

class AdjacencyMatrix {
public:
    AdjacencyMatrix();
    AdjacencyMatrix(Graph g);
    std::vector<double> operator[](int n);
    std::vector<int> tspBruteforce();
    double recursiveDP(int i, long long int mask);
    double tspDynamicProgramming();
    void generateMemo();

    Graph g;
    std::vector<std::vector<double>> matrix;
    std::vector<std::vector<double>> memo;
};


#endif //DA2_ADJACENCY_MATRIX_H
