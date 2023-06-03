//
// Created by feld on 19-05-2023.
//

#ifndef DA2_ADJACENCY_MATRIX_H
#define DA2_ADJACENCY_MATRIX_H
#include "Graph.h"
#include <vector>

class AdjacencyMatrix {
public:
    /**
     * Default constructor for AdjacencyMatrix (unused)
     *
     */
    AdjacencyMatrix();

    /**
     * Constructor for AdjacencyMatrix
     * @param Graph the graph to build the adjacency matrix for
     * @param bool whether the graph needs any edges or not, that is, if it is fully connected, false, if it isn't fully connected, true
     */
    AdjacencyMatrix(Graph g, bool needsEdges);
    /**
     * Overload for operator [] that allows ease of access to variable matrix
     * @param int the line of the matrix to access
     * @return the line of the matrix
     */
    std::vector<double> operator[](int n);
    /**
     * Returns the optimal path for TSP using bruteforce
     * Complexity O(N!)
     * @return
     */
    std::vector<int> tspBruteforce();
    /**
     * The recursive function call for the solution using dynamic programming
     * @param int the index of the current node
     * @param longlong a bitmask that contains information about which vertices have already been visited and which haven't
     * @return the cost of the shortest path found
     */
    double recursiveDP(int i, long long int mask);
    /**
     * The function that calculates TSP using dynamic programming
     * Complexity O(2^n * n^2)
     * Spatial Complexity O(2^n * n^2)
     * @return
     */
    double tspDynamicProgramming();
    /**
     * Generates the memo matrix with everything set to 0.
     * This should be done only when needed as to not use unnecessary space in the memory!
     */
    void generateMemo();
    /**
     * Calculates the distance of a path
     * @param std::vector<int> The path to calculate the distance of
     * @return The calculated distance
     */
    double pathDist(std::vector<int> v);

    Graph g;
    std::vector<std::vector<double>> matrix;
    std::vector<std::vector<double>> memo;
};


#endif //DA2_ADJACENCY_MATRIX_H
