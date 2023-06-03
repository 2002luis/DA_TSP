// By: Gonçalo Leão

#include "Graph.h"

int Graph::getNumVertex() const {
    return vertexSet.size();
}

std::vector<Vertex *> Graph::getVertexSet() const {
    return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
Vertex * Graph::findVertex(const int &id) const {
    for (auto v : vertexSet)
        if (v->getId() == id)
            return v;
    return nullptr;
}

/*
 * Finds the index of the vertex with a given content.
 */
int Graph::findVertexIdx(const int &id) const {
    for (unsigned i = 0; i < vertexSet.size(); i++)
        if (vertexSet[i]->getId() == id)
            return i;
    return -1;
}
/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
bool Graph::addVertex(const int &id) {
    if (findVertex(id) != nullptr)
        return false;
    vertexSet.push_back(new Vertex(id));
    return true;
}

/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
bool Graph::addEdge(const int &sourc, const int &dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2, w);
    return true;
}

bool Graph::addBidirectionalEdge(const int &sourc, const int &dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    auto e1 = v1->addEdge(v2, w);
    auto e2 = v2->addEdge(v1, w);
    e1->setReverse(e2);
    e2->setReverse(e1);
    return true;
}

void deleteMatrix(int **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

void deleteMatrix(double **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

Graph::~Graph() {
    deleteMatrix(distMatrix, vertexSet.size());
    deleteMatrix(pathMatrix, vertexSet.size());
}


class cmp{
public:
    /**
     * Used to sort priority queue in dijkstra function
     */
    bool operator()(std::pair<int,double> p1, std::pair<int,double> p2){
        return p1.second>p2.second;
    }
};

double Graph::djikstra(int sourc, int dest){
    std::priority_queue<std::pair<int,double>,std::vector<std::pair<int,double>>,cmp> q;
    for(auto &i : vertexSet){
        i->setPath(nullptr);
        i->setVisited(false);
        i->setDist(INF);
    }

    q.push({sourc,0});
    double cDist = 0;
    while(!q.empty()){
        int cur = q.top().first;
        cDist = q.top().second;
        if(cur == dest) return cDist;

        findVertex(cur)->setVisited(true);
        q.pop();
        for(auto e : findVertex(cur)->getAdj()){
            double tempDist = cDist;
            if(e->getDest()->getId() != cur && !e->getDest()->isVisited()){
                if(e->getDest()->getPath() == nullptr) e->getDest()->setPath(e);
                tempDist += e->getWeight();
                if(tempDist < e->getDest()->getDist()) e->getDest()->setDist(cDist);
                q.push({e->getDest()->getId(),tempDist});
            }
        }
    }

    return -1;
}

std::vector<Vertex*> Graph::shortestPath(int sourc, int dest){
    djikstra(sourc,dest);
    std::vector<Vertex*> out;
    for(Vertex* v = findVertex(dest); v->getId()!=sourc; v = v->getPath()->getOrig()) out.push_back(v);
    out.push_back(findVertex(sourc));
    std::reverse(out.begin(),out.end());
    return out;
}

void Graph::generateHaversineEdges(){
    for(unsigned long int i = 0; i < vertexSet.size(); i++){
        for(unsigned long int j = i+1; j < vertexSet.size(); j++){
            if(vertexSet[i]->getEdgeTo(vertexSet[j]->getId()) == nullptr) addBidirectionalEdge(vertexSet[i]->getId(),vertexSet[j]->getId(),vertexSet[i]->haversine(vertexSet[j]));
        }
    }
}

double Graph::prim(int src){
    double dist = 0;
    if (vertexSet.empty()) {
        return dist;
    }

    // Reset auxiliary info
    for(auto &v : vertexSet) {
        v->setDist(INF);
        v->setPath(nullptr);
        v->setVisited(false);
        for(auto &e : v->getAdj()){
            e->setSelected(false);
        }
    }

    // start with an arbitrary vertex
    Vertex* s = vertexSet.front();
    s->setDist(0);

    // initialize priority queue
    MutablePriorityQueue<Vertex> q;
    q.insert(s);
    // process vertices in the priority queue
    while( !q.empty() ) {
        auto v = q.extractMin();
        dist += (v->getDist()*2);
        v->setVisited(true);
        for(auto &e : v->getAdj()) {
            Vertex* w = e->getDest();
            if (!w->isVisited()) {
                auto oldDist = w->getDist();
                if(e->getWeight() < oldDist) {
                    w->setDist(e->getWeight());
                    if (oldDist == INF) {
                        q.insert(w);
                    }
                    else {
                        q.decreaseKey(w);
                        w->getPath()->setSelected(false);
                    }
                    w->setPath(e);
                    e->setSelected(true);

                }
            }
        }
    }

    return dist;
}

std::vector<int> Graph::getDfsPath(int src){
    std::vector<int> out = {src};
    for(auto &e : findVertex(src)->getAdj()){
        if(e->isSelected()){
            e->setSelected(false);
            auto tmp = getDfsPath(e->getDest()->getId());
            out.insert(out.end(),tmp.begin(),tmp.end());
        }
    }
    return out;
}

double Graph::pathDist(std::vector<int> v){
    double out = 0;
    out += djikstra(v.back(),v[0]);
    for(unsigned long int i = 1; i < v.size(); i++){
        int tmp = out;
        out += djikstra(v[i-1],v[i]);
    }
    return out;
}

bool Graph::addVertex(const int &id, double lat, double lon){
    if (findVertex(id) != nullptr)
        return false;
    vertexSet.push_back(new Vertex(id,lat,lon));
    return true;
}

int Graph::countVisited(){
    int out = 0;
    for(auto i : vertexSet) if(i->isVisited()) out++;
    return out;
}
