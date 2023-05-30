//
// Created by luism on 25/05/2023.
//

#include "Menu.h"
#include "readFile.h"
#include <ctime>
#include <iostream>
#include <string>
#include <chrono>
#include <math.h>
#include "overloads.h"


Menu::Menu(){
    loadedGraph = false;
}

bool Menu::MenuLoop(){
    std::string input;

    std::cout << "╔════════════════════════════════════════════════════════════════════════════╗\n"
                 "║                Ocean Shipping and Urban Deliveries                  ║\n"
                 "╠════════════════════════════════════════════════════════════════════════════╣\n"
                 "║ Hi! Select one topic...                                             ║\n"
                 "║ 1. To read toy graphs                                               ║\n"
                 "║ 2. To read real data using Haversine to calculate edges             ║\n"
                 "║ 3. To read extra graphs                                             ║\n"
                 "╚════════════════════════════════════════════════════════════════════════════╝" << std::endl;

    if(loadedGraph) std::cout << "╔════════════════════════════════════════════════════════════════════════════╗\n"
                                 "║ 4. To calculate TSP using backtracking                               ║\n"
                                 "║ 5. To calculate an approximate result with a margin of error of 100% ║\n"
                                 "║ 6. To calculate TSP using dynamic programming                        ║\n"
                                 "╚════════════════════════════════════════════════════════════════════════════╝" << std::endl;

    std::cout << "╔════════════════════════════════════════════════════════════════════════════╗\n"
                 "║ 0. Exit the program                                                  ║\n"
                 "╚════════════════════════════════════════════════════════════════════════════╝" << std::endl;

    std::getline(std::cin,input);
    if(input=="0") {
        std::cout << "See you!" << std::endl;
        return false;
    }
    else if(loadedGraph){
        auto startTime = std::chrono::high_resolution_clock::now();
        if(input=="4"){
            if(g.getVertexSet().size() > 10) {
                std::cout << "This graph has more than 10 vertices, it will take really long, are you sure? Y/N" << std::endl;
                std::getline(std::cin,input);
                //if(input == "N") std::cout << "Pois bem me pareceu" << std::endl;
               //else std::cout << "Tu é que sabes chefe, boa sorte" << std::endl;
            }
            if(input == "Y" || input == "y" || input == "4"){
                auto path = adj.tspBruteforce();
                std::cout << g.pathDist(path) << std::endl;
                std::cout << "The path is " << path << std::endl;
                auto endTime = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
                std::cout << "It took " << duration.count() << " microseconds (" << duration.count()/1000 << " miliseconds)." << std::endl;
                std::cout << std::endl;
            }
        }
        else if(input=="5"){
            std::cout << "The approximation is: " << g.prim(0) << std::endl;
            auto endTime = std::chrono::high_resolution_clock::now();
            std::cout << "The path is " << g.getDfsPath(0) << std::endl;
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
            std::cout << "It took " << duration.count() << " microseconds (" << duration.count()/1000 << " miliseconds)." << std::endl;
        }
        else if(input=="6"){
            if(g.getVertexSet().size() >= 64){
                std::cout << "This algorithm uses a bitmask with 64 bits, and this graph has more than 64 vertices, so this algorithm is not usable for this problem." << std::endl;
            }
            else if(g.getVertexSet().size() > 20) {
                std::cout << "This has more than 20 vertices, it will take really long and need " << (pow(2,g.getVertexSet().size())*50*64)/8000000000 << " GB of memory, are you sure? Y/N" << std::endl;
                //std::cout << "Vai-te ocupar " << (pow(2,g.getVertexSet().size())*50*64)/8000000000 << " GB na RAM lol" << std::endl;
                std::getline(std::cin,input);
                //if(input == "N" || input == "n") std::cout << "Pois bem me pareceu" << std::endl;
                //else std::cout << "Tu é que sabes chefe, boa sorte" << std::endl;
            }
            if((input == "Y" || input == "y" || input == "6") && g.getVertexSet().size() < 64){

                std::cout << adj.tspDynamicProgramming() << std::endl;
                auto endTime = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
                std::cout << "It took " << duration.count() << " microseconds (" << duration.count()/1000 << " miliseconds)." << std::endl;
                //if(g.getVertexSet().size()>=26) std::cout << " Não valeu a pena pois não?";
                std::cout << std::endl;
            }
        }
    }
    if(input=="1"){
        std::cout << "What's the name of the file? Ex: shipping.csv" << std::endl;
        std::getline(std::cin,input);
        g = readFile::readNormal("../toyData/"+input,true);
        if(g.getVertexSet().size() == 0){
            loadedGraph = false;
            std::cout << "File does not exist!" << std::endl;
            return true;
        }
        adj = AdjacencyMatrix(g,true);
        loadedGraph = true;
    }
    else if(input=="2"){
        std::cout << "What's the name of the directory with the files? Ex: graph1" << std::endl;
        std::getline(std::cin,input);
        g = readFile::readHaversine("../realData/"+input,true,true);
        if(g.getVertexSet().size() == 0){
            loadedGraph = false;
            std::cout << "File does not exist!" << std::endl;
            return true;
        }
        adj = AdjacencyMatrix(g,false);
        loadedGraph = true;
    }
    else if(input=="3"){
        std::cout << "What's the file's name? Ex: edges_25.csv" << std::endl;
        std::getline(std::cin,input);
        g = readFile::readNormal("../extraData/"+input,false);
        if(g.getVertexSet().size() == 0){
            loadedGraph = false;
            std::cout << "File does not exist!" << std::endl;
            return true;
        }
        adj = AdjacencyMatrix(g,true);
        loadedGraph = true;
    }
    return true;

}