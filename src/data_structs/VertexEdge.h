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
    ///                                                                                     --------------------------
    /// @param int id
    ///
    Vertex(int id);

    ///                                                                                     --------------------------
    /// @param int id
    /// @param double lat
    /// @param double lon
    ///
    Vertex(int id, double lat, double lon);

    ///                                                                                     --------------------------
    /// @param Vertex vertex
    /// @return NSEI                                                                      -----------------------------
    ///
    bool operator<(Vertex & vertex) const; // // required by MutablePriorityQueue        ------------------------------

    ///                                                                                     --------------------------
    /// @return NSEI                                                                      -----------------------------
    ///
    int getId() const;

    ///                                                                                     --------------------------
    std::vector<Edge *> getAdj() const;

    ///                                                                                     --------------------------
    /// @return NSEI                                                                      -----------------------------
    ///
    bool isVisited() const;

    ///                                                                                     --------------------------
    /// @return NSEI                                                                      -----------------------------
    ///
    bool isProcessing() const;

    ///                                                                                     --------------------------
    /// @return NSEI                                                                      -----------------------------
    ///
    unsigned int getIndegree() const;

    ///                                                                                     --------------------------
    /// @return NSEI                                                                      -----------------------------
    ///
    double getDist() const;

    ///                                                                                     --------------------------
    /// @return NSEI                                                                      -----------------------------
    ///
    Edge *getPath() const;

    ///                                                                                     --------------------------
    /// @return NSEI                                                                      -----------------------------
    ///
    std::vector<Edge *> getIncoming() const;

    ///                                                                                     --------------------------
    /// @param int info
    /// @return NSEI                                                                      -----------------------------
    ///
    void setId(int info);

    ///                                                                                     --------------------------
    /// @param bool visited
    /// @return NSEI                                                                      -----------------------------
    ///
    void setVisited(bool visited);

    ///                                                                                     --------------------------
    /// @param bool processing
    /// @return NSEI                                                                      -----------------------------
    ///
    void setProcesssing(bool processing);

    ///                                                                                     --------------------------
    /// @param unsigned int indegree
    /// @return NSEI                                                                      -----------------------------
    ///
    void setIndegree(unsigned int indegree);

    ///                                                                                     --------------------------
    /// @param double dist
    /// @return NSEI                                                                      -----------------------------
    ///
    void setDist(double dist);

    ///                                                                                     --------------------------
    /// @param Edge *path
    /// @return NSEI                                                                      -----------------------------
    ///
    void setPath(Edge *path);

    ///                                                                                     --------------------------
    /// @param Vertex *dest
    /// @param double w
    /// @return NSEI                                                                      -----------------------------
    ///
    Edge * addEdge(Vertex *dest, double w);

    ///                                                                                     --------------------------
    /// @param int destID
    /// @return NSEI                                                                      -----------------------------
    ///
    bool removeEdge(int destID);

    ///                                                                                     --------------------------
    ///
    void removeOutgoingEdges();

    ///                                                                                     --------------------------
    /// @param int dest
    /// @return NSEI                                                                      -----------------------------
    ///
    Edge* getEdgeTo(int dest);

    ///                                                                                     --------------------------
    /// @param Vertex* v
    /// @return NSEI                                                                      -----------------------------
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

    ///                                                                                     --------------------------
    /// @param Edge *edge
    /// @return NSEI                                                                      -----------------------------
    ///
    void deleteEdge(Edge *edge);

    ///                                                                                     -------------------------
    float lat, lon;
};

/********************** Edge  ****************************/

class Edge {
public:
    ///                                                                                     --------------------------
    /// @param Vertex *orig
    /// @param Vertex *dest
    /// @param double w
    ///
    Edge(Vertex *orig, Vertex *dest, double w);

    ///                                                                                     --------------------------
    ///
    Vertex * getDest() const;

    ///                                                                                     --------------------------
    /// @return NSEI                                                                      -----------------------------
    ///
    double getWeight() const;

    ///                                                                                     --------------------------
    /// @return NSEI                                                                      -----------------------------
    ///
    bool isSelected() const;

    ///                                                                                     --------------------------
    ///
    Vertex * getOrig() const;

    ///                                                                                     --------------------------
    ///
    Edge *getReverse() const;

    ///                                                                                     --------------------------
    /// @return NSEI                                                                      -----------------------------
    ///
    double getFlow() const;

    ///                                                                                     --------------------------
    /// @param bool selected
    ///
    void setSelected(bool selected);

    ///                                                                                     --------------------------
    /// @param Edge *reverse
    ///
    void setReverse(Edge *reverse);

    ///                                                                                     --------------------------
    /// @param double flow
    ///
    void setFlow(double flow);
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