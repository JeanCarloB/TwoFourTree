//
// Created by jeanc on 17/10/2022.
//

#ifndef PROYECTO_2_NODEDATA_H
#define PROYECTO_2_NODEDATA_H

#include <iostream>
#include <sstream>
#include <time.h>
#include <windows.h>
#include "RuntimeException.h"

class NodeData {

public:
    int dData;

    NodeData(int);

    string displayItem();

    virtual ~NodeData();
};


#endif //PROYECTO_2_NODEDATA_H
