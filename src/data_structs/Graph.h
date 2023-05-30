#ifndef DA_TP_CLASSES_GRAPH
#define DA_TP_CLASSES_GRAPH

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

#include "VertexEdge.h"
#include "MutablePriorityQueue.h"

class Graph {
public:
    ~Graph();

    /// Auxiliary function to find a vertex with a given ID.
    /// @param id
    /// @return NSEI                                                                      -----------------------------
    ///
    Vertex *findVertex(const int &id) const;

    /// Adds a vertex with a given content or info (in) to a graph (this).
    /// Returns true if successful, and false if a vertex with that content already exists.
    /// @param id
    /// @return NSEI                                                                      -----------------------------
    ///
    bool addVertex(const int &id);

    ///                                                                                     --------------------------
    bool addVertex(const int &id, double lat, double lon);

    /// Adds an edge to a graph (this), given the contents of the source and
    /// destination vertices and the edge weight (w).
    /// @param sourc
    /// @param dest
    /// @param w
    /// @return true if successful, and false if the source or destination vertex does not exist.
    ///
    bool addEdge(const int &sourc, const int &dest, double w);

    /// Adds an bidirectional edge to a graph (this), given the contents of the source and
    /// destination vertices and the edge weight (w).
    /// @param sourc
    /// @param dest
    /// @param w
    /// @return true if successful, and false if the source or destination vertex does not exist.
    ///
    bool addBidirectionalEdge(const int &sourc, const int &dest, double w);

    ///                                                                                     --------------------------
    /// @return                                                                             --------------------------
    ///
    int getNumVertex() const;

    ///                                                                                     --------------------------
    /// @return                                                                             --------------------------
    ///
    std::vector<Vertex *> getVertexSet() const;

    ///                                                                                     --------------------------
    /// @param sourc
    /// @param dest
    /// @return                                                                             --------------------------
    ///
    int djikstra(int sourc, int dest);

    ///                                                                                     --------------------------
    /// @param sourc
    /// @param dest
    /// @return                                                                             --------------------------
    ///
    std::vector<Vertex*> shortestPath(int sourc, int dest);

    ///                                                                                     --------------------------
    /// @return                                                                             --------------------------
    ///
    void generateHaversineEdges();

    ///                                                                                     --------------------------
    /// @param src
    /// @return                                                                             --------------------------
    ///
    double prim(int src);

    ///                                                                                     --------------------------
    /// @param src
    /// @return                                                                             --------------------------
    ///
    std::vector<int> getDfsPath(int src);

    ///                                                                                     --------------------------
    /// @param v
    /// @return                                                                             --------------------------
    ///
    double pathDist(std::vector<int> v);

protected:
    /// Vertex set
    std::vector<Vertex *> vertexSet;

    /// Dist matrix for Floyd-Warshall
    double ** distMatrix = nullptr;

    /// Path matrix for Floyd-Warshall
    int **pathMatrix = nullptr;

    /// Finds the index of the vertex with a given content.
    /// @param id
    /// @return                                                                             --------------------------
    ///
    int findVertexIdx(const int &id) const;
};

///                                                                                     --------------------------
/// @param m
/// @param n
/// @return                                                                             --------------------------
///
void deleteMatrix(int **m, int n);

///                                                                                     --------------------------
/// @param m
/// @param n
/// @return                                                                             --------------------------
///
void deleteMatrix(double **m, int n);

#endif /* DA_TP_CLASSES_GRAPH */