//
// Created by luism on 25/05/2023.
//

#ifndef DA_QUIMBOIO_MENU_H
#define DA_QUIMBOIO_MENU_H

#include "data_structs/Graph.h"
#include "data_structs/AdjacencyMatrix.h"

class Menu {
public:
    Menu();
    /**
     * Menu loop
     * @return true if it should loop again, false otherwise
     */
    bool MenuLoop();
    Graph g;
    AdjacencyMatrix adj;
    bool loadedGraph;
};


#endif //DA_QUIMBOIO_MENU_H
