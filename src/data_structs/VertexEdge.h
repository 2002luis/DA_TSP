// By: Gonçalo Leão

#ifndef DA_TP_CLASSES_VERTEX_EDGE
#define DA_TP_CLASSES_VERTEX_EDGE

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include "MutablePriorityQueue.h"

class Edge;

#define INF std::numeric_limits<double>::max()

/************************* Vertex  **************************/

class Vertex {
public:
    /// @brief Constructor for vertex
    /// @param int the id of the vertex
    ///
    Vertex(int id);

    /// @brief Constructor for vertex
    /// @param int the id of the vertex
    /// @param double the latitude of the vertex
    /// @param double the longitude of the vertex
    ///
    Vertex(int id, double lat, double lon);

    /// @brief Compares vertex by distance
    /// @param Vertex vertex
    /// @return true if smaller, false if equal or bigger
    ///
    bool operator<(Vertex & vertex) const; // // required by MutablePriorityQueue

    /// @brief Gets vertex ID
    /// @return the id
    ///
    int getId() const;

    /**
     * @brief Get the list of adjacent vertices
     * @return the list of adjacent vertices
     */
    std::vector<Edge *> getAdj() const;

    /// @brief Gets visited variable
    /// @return the variable
    ///
    bool isVisited() const;


    /// @brief Get variable dist
    /// @return the variable
    ///
    double getDist() const;

    /// @brief Gets path variable
    /// @return the variable
    ///
    Edge *getPath() const;


    /// @brief Sets visited variable
    /// @param bool the new value of the variable
    ///
    void setVisited(bool visited);

    /// @brief Sets dist variable
    /// @param double the new value of dist
    ///
    void setDist(double dist);

    /// @brief Sets path variable
    /// @param Edge* the new value of path
    ///
    void setPath(Edge *path);

    /// @brief Creates a new edge starting in this vertex with destination in vertex dest and weight w
    /// @param Vertex* the destination vertex
    /// @param double the weight of the edge
    /// @return a pointer to the new edge
    ///
    Edge * addEdge(Vertex *dest, double w);



    /// @brief Returns the edge that ends in vertex dest
    /// @param int The ID of the vertex to search for
    /// @return the edge if it exists, nullptr if it doesn't
    ///
    Edge* getEdgeTo(int dest);

    /// @brief Calculates the geographical distance between two vertices with latitude and longitude. Undefined behaviour if either vertex doesn't have either latitude or longitude
    /// @param Vertex* The other vertex to calculate the distance
    /// @return The distance between the two nodes
    ///
    double haversine(Vertex* v);

    friend class MutablePriorityQueue<Vertex>;

protected:

    /// identifier
    int id;

    /// outgoing edges
    std::vector<Edge *> adj;

    /// auxiliary fields
    bool visited = false; /// used by DFS, BFS, Prim ...
    bool processing = false; /// used by isDAG (in addition to the visited attribute)
    unsigned int indegree; /// used by topsort
    double dist = 0;
    Edge *path = nullptr;

    /// incoming edges
    std::vector<Edge *> incoming;

    /// required by MutablePriorityQueue and UFDS
    int queueIndex = 0;

    /// @brief Deletes an edge
    /// @param Edge* the edge to delete
    ///
    void deleteEdge(Edge *edge);

    float lat, lon;
};

/********************** Edge  ****************************/

class Edge {
public:
    /// @brief Edge constructor
    /// @param Vertex* origin vertex
    /// @param Vertex* destination vertex
    /// @param double the weight of the vertex
    ///
    Edge(Vertex *orig, Vertex *dest, double w);

    /// @brief Returns a pointer to the destination vertex of the edge
    /// @return the Vertex in question
    Vertex * getDest() const;

    /// @brief Returns the weight variable
    /// @return the variable in question
    ///
    double getWeight() const;

    /// Returns the selected variable
    /// @return the variable in question
    ///
    bool isSelected() const;

    /// @brief Returns a pointer to the origin vertex of the edge
    /// @return the Vertex in question
    Vertex * getOrig() const;




    /// @brief Sets the selected variable
    /// @param bool the new value of the variable
    ///
    void setSelected(bool selected);

    /// @brief Sets the reverse variable
    /// @param Edge* the new value of the variable
    ///
    void setReverse(Edge *reverse);


protected:
    /// destination vertex
    Vertex * dest;

    /// edge weight, can also be used for capacity
    double weight;

    /// auxiliary fields
    bool selected = false;

    /// used for bidirectional edges
    Vertex *orig;
    Edge *reverse = nullptr;

    /// for flow-related problems
    double flow;
};

#endif /* DA_TP_CLASSES_VERTEX_EDGE */