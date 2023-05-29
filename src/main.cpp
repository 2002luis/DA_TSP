//
// Created by feld on 19-05-2023.
//
#include <iostream>
#include <chrono>
#include <math.h>
#include "data_structs/Graph.h"
#include "data_structs/VertexEdge.h"
#include "data_structs/AdjacencyMatrix.h"
#include "overloads.h"
#include "menu.h"
#include "readFile.h"



int main(){
    /*
    Graph g;
    g.addVertex(0);
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);

    g.addBidirectionalEdge(0,1,5);
    g.addBidirectionalEdge(1,2,5);
    g.addBidirectionalEdge(1,3,2);
    g.addBidirectionalEdge(2,3,1);
    g.addBidirectionalEdge(2,4,5);
    g.addBidirectionalEdge(3,4,1);
    g.addBidirectionalEdge(4,5,1);

    //std::cout << g.djikstra(1,2);

    std::cout << '\n' << g;

    AdjacencyMatrix adj(g);

    std::cout << adj;

    std::cout << '\n' << adj.g.pathDist(adj.tspBruteforce());

    std::cout << '\n' << g.primApprox();
    */
    //Graph readGraph = readFile::readNormal("../extraData/edges_25.csv",false);
    //AdjacencyMatrix adj(readGraph);
    //auto a = adj.tspBruteforce();
    //std::cout << '\n' << adj.g.pathDist(a) << '\t' << a;
    //std::cout << '\n' << readGraph.primApprox();


    //std::cout << '\n' << adj.tspDynamicProgramming();


    /*
    Graph g = readFile::readNormal("../extraData/edges_25.csv",true);
    //25 demorou 80 segundos
    AdjacencyMatrix adj(g);
    std::cout << "Vai-te ocupar " << (pow(2,g.getVertexSet().size())*g.getVertexSet().size()*64)/8000000000 << " GB na RAM lol" << std::endl;
    auto startTime = std::chrono::high_resolution_clock::now();
    adj.tspDynamicProgramming();
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    std::cout << "Demorou " << duration.count() << " microsegundos.";
    */

    Menu menu;

    while(menu.MenuLoop());

    return 0;
}
