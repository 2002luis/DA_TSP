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

    //Dyanmic programming
    //21 nos demora 94 segundos
    //22 nos demora 208 segundos

    //24 nos demora 1059 segundos

    //é exponencial

    Menu menu;

    while(menu.MenuLoop());

    return 0;
}
