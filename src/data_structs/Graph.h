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

    /// @brief Auxiliary function to find a vertex with a given ID.
    /// @param int id of the vertex to be added
    /// @return pointer to the created Vertex
    ///
    Vertex *findVertex(const int &id) const;

    /// @brief Adds a vertex with a given content or info (in) to a graph (this).
    /// @param int id of the vertex to be added
    /// @return true if successfully added, false if a vertex with that content already exists.
    ///
    bool addVertex(const int &id);

    /// @brief Adds a vertex with a given content or info (in) to a graph (this).
    /// @param int id of the vertex to be added
    /// @param double latitude of the vertex
    /// @param double longitude of the vertex
    /// @return true if successful, false if a vertex with that content already exists.
    ///
    bool addVertex(const int &id, double lat, double lon);

    /// @brief Adds an edge to a graph (this), given the contents of the source and destination vertices and the edge weight (w).
    /// @param int id of the source vertex
    /// @param int id of the destination vertex
    /// @param double distance of the vertex
    /// @return true if successful, and false if the source or destination vertex does not exist.
    ///
    bool addEdge(const int &sourc, const int &dest, double w);

    /// @brief Adds an bidirectional edge to a graph (this), given the contents of the source and destination vertices and the edge weight (w).
    /// @param int id of the source vertex
    /// @param int id of the destination vertex
    /// @param double distance of the vertex
    /// @return true if successful, and false if the source or destination vertex does not exist.
    ///
    bool addBidirectionalEdge(const int &sourc, const int &dest, double w);

    /// @brief Returns the number of vertices
    /// @return number of vertices
    ///
    int getNumVertex() const;

    /// @brief Returns the vector of the vertices
    /// @return vector of vertices
    ///
    std::vector<Vertex *> getVertexSet() const;

    /// @brief Finds the shortest path from one node to another
    /// Complexity O(V^2)
    /// @param int id of source vertex
    /// @param int id of destination vertex
    /// @return  the distance
    ///
    double djikstra(int sourc, int dest);

    /// @brief Finds the shortest path from a point to another
    /// Complexity O(V^2)
    /// @param int id of source vertex
    /// @param int id of destination vertex
    /// @return a vector with the shortest path from one vertex to another
    ///
    std::vector<Vertex*> shortestPath(int sourc, int dest);

    /// @brief Generates non existant edges by using latitude and longitude
    /// Complexity O(V*E)
    ///
    void generateHaversineEdges();

    /// @brief Generates a minimum spanning tree using prim's algorithm
    /// @param int id of the source node
    /// @return The cost of all edges * 2
    ///
    double prim(int src);

    /// @brief Gets the vertices of the minimum spanning tree in preorder
    /// @param int id of the vertex to start
    /// @return The vertices in preorder
    ///
    std::vector<int> getDfsPath(int src);

    /// @brief Calculates the distance in a path of vertices
    /// @param std::vector<int> a vector with the ids of vertices in order
    /// @return The distance
    ///
    double pathDist(std::vector<int> v);

    /**
     * @brief Counts the amount of nodes that are visited
     * @return Number of visited nodes
     */
    int countVisited();
protected:
    /// Vertex set
    std::vector<Vertex *> vertexSet;

    /// Dist matrix for Floyd-Warshall
    double ** distMatrix = nullptr;

    /// Path matrix for Floyd-Warshall
    int **pathMatrix = nullptr;

    /// Finds the index of the vertex with a given content.
    /// @param id
    /// @return the id
    ///
    int findVertexIdx(const int &id) const;
};

void deleteMatrix(int **m, int n);

void deleteMatrix(double **m, int n);

#endif /* DA_TP_CLASSES_GRAPH */