//
// Created by feld on 19-05-2023.
//

#include "AdjacencyMatrix.h"
#include <algorithm>
#include <math.h>

AdjacencyMatrix::AdjacencyMatrix() {

}

AdjacencyMatrix::AdjacencyMatrix(Graph g, bool needsEdges) {
    this->g = g;
    std::vector<double> tmp(g.getVertexSet().size(),0);
    matrix.clear();
    memo.clear(); //just in case
    for(unsigned long int i = 0; i < g.getVertexSet().size(); i++)
    {
        matrix.push_back(tmp);
    }
    if(needsEdges) for(unsigned long int x = 0; x < g.getVertexSet().size(); x++){
        matrix[x][x] = 0;
        for(unsigned long int y = x+1; y < g.getVertexSet().size(); y++){
            double cost = g.djikstra(g.getVertexSet()[x]->getId(),g.getVertexSet()[y]->getId());
            matrix[x][y] = cost;
            matrix[y][x] = cost;
        }
    }
}

void AdjacencyMatrix::generateMemo() {
    memo.clear();
    std::vector<double> tmp(pow(2,g.getVertexSet().size()),0);
    memo = std::vector<std::vector<double>>(g.getVertexSet().size(),tmp);
}

std::vector<double> AdjacencyMatrix::operator[](int n){
    return matrix[n];
}

std::vector<int> AdjacencyMatrix::tspBruteforce(){

    double cur = INF;
    double mn = cur;

    std::vector<int> curPerm;

    for(unsigned long int i = 0; i < matrix.size(); i++){
        curPerm.push_back(i);
    }

    std::vector<int> out = curPerm;

    do {
        cur = 0;
        cur+=matrix[curPerm[curPerm.size()-1]][curPerm[0]];
        for(unsigned long int i = 1; i < curPerm.size(); i++){
            cur+=matrix[curPerm[i-1]][curPerm[i]];
            if(cur>mn) i = curPerm.size(); //heuristica
        }
        if(cur<mn){
            mn = cur;
            out = curPerm;
        }
    } while(std::next_permutation(curPerm.begin(),curPerm.end()));

    return out;

}

double AdjacencyMatrix::recursiveDP(int i, long long int mask){ //so funciona para N < 64, temos pena, não é realista fazer n > 25 e não
    if(mask == ((1 << i) | 1)) return(matrix[0][i]);
    if(memo[i][mask]!=0) return memo[i][mask];
    double res = INF;
    for (int j = 0; j <= g.getVertexSet().size(); j++){
        if ((mask & (1 << j)) && j != i && j != 0) res = std::min(res, recursiveDP(j, mask & (~(1 << i))) + matrix[j][i]);
    }
    memo[i][mask] = res;
    return res;
}

double AdjacencyMatrix::tspDynamicProgramming(){
    double out = INF;
    generateMemo();
    for (int i = 0; i < g.getVertexSet().size(); i++) out = std::min(out, recursiveDP(i, (1 << (g.getVertexSet().size())) - 1) + matrix[i][0]);
    memo.clear();
    return out;
}
