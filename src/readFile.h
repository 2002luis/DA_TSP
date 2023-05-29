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
    static Graph readNormal(std::string file, bool trash);
    static Graph readHaversine(std::string file, bool trash);
    static std::string removeCommas(std::string in);
};


#endif //DA_QUIMBOIO_READFILE_H
