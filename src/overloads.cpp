//
// Created by feld on 19-05-2023.
//

#include "data_structs/Graph.h"
#include "overloads.h"
#include <iostream>

std::ostream& operator<<(std::ostream& o, Vertex v){
    o << v.getId();
    return o;
}

std::ostream& operator<<(std::ostream& o, Edge e){
    o << e.getOrig()->getId() << " -> " << e.getDest()->getId() << " (" << e.getWeight() << ")";
    return o;
}

std::ostream& operator<<(std::ostream& o, Graph g){
    for(auto v : g.getVertexSet()){
        o << *v << " (";
        for(auto e : v->getAdj()) o << ' ' << *e << ' ';
        o << ") " << v->getDist() << '\n';
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, AdjacencyMatrix a){
    for(auto x : a.matrix){
        for(auto y : x) o << y << '\t';
        o << '\n';
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, std::vector<int> v){
    for(auto i : v){
        o << i << ' ';
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, std::vector<Vertex*> v){
    for(auto i : v){
        o << *i << ' ';
    }
    return o;
}