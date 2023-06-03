//
// Created by luism on 23/05/2023.
//

#ifndef DA_QUIMBOIO_READFILE_H
#define DA_QUIMBOIO_READFILE_H

#include "data_structs/Graph.h"
#include <string>
#include <fstream>
#include <sstream>

class readFile {
public:
    readFile();
    /**
     * Reads nodes from a file using the distances given in it. If any edge isn't given, nothing will be done
     * @param std::string the directory of the file to be read
     * @param bool whether the first line of the file is trash or not
     * @return the Graph that was read
     */
    static Graph readNormal(std::string file, bool trash);
    /**
     * Reads nodes from two files in a folder, one named edges.csv with edges, and another named nodes.csv with the nodes. If any edge isn't given by edges.csv, it will be calculated using haversine with the coordinates of the nodes given
     * @param file
     * @param trashNode
     * @param trashEdge
     * @return
     */
    static Graph readHaversine(std::string file, bool trashNode, bool trashEdge);
    /**
     * Removes commas from a string for ease of reading
     * @param std::string the string with commas
     * @return the string without commas
     */
    static std::string removeCommas(std::string in);
};


#endif //DA_QUIMBOIO_READFILE_H
