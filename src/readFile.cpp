//
// Created by luism on 23/05/2023.
//

#include "readFile.h"

readFile::readFile(){

}

std::string readFile::removeCommas(std::string in) {
    std::string out = "";
    for(auto i : in){
        if(i == ',') out.push_back(' ');
        else out.push_back(i);
    }
    return out;
}

Graph readFile::readNormal(std::string file, bool trash){
    Graph out;
    std::fstream ifs(file);
    if(!ifs.is_open()) return out;
    std::string line;
    if(trash) std::getline(ifs,line);
    while(std::getline(ifs,line)){
        line = removeCommas(line);
        std::istringstream iss(line);
        int orig, dest;
        double dist;
        iss >> orig >> dest >> dist;
        if(out.findVertex(orig) == nullptr) out.addVertex(orig);
        if(out.findVertex(dest) == nullptr) out.addVertex(dest);
        if(out.findVertex(orig)->getEdgeTo(dest) == nullptr) out.addBidirectionalEdge(orig,dest,dist);
    }
    return out;
}

Graph readFile::readHaversine(std::string file, bool trashNode, bool trashEdge) {
    std::string nodes = file+"/nodes.csv", edges = file+"/edges.csv";
    Graph out;
    std::fstream ifs(nodes), ife(edges);
    if(!ifs.is_open()) return out;
    if(!ife.is_open()) return out;
    std::string line;
    if(trashNode) std::getline(ifs,line);
    if(trashEdge) std::getline(ife,line);
    while(std::getline(ifs,line)){
        line = removeCommas(line);
        std::istringstream iss(line);
        int node;
        double lat, lon;
        iss >> node >> lat >> lon;
        if(out.findVertex(node) == nullptr) out.addVertex(node,lat,lon);
        //std::cout << node << std::endl;
    }
    while(std::getline(ife,line)){
        line = removeCommas(line);
        std::istringstream iss(line);
        int src, dest;
        double dist;
        out.addBidirectionalEdge(src,dest,dist);
    }
    out.generateHaversineEdges();
    return out;
}