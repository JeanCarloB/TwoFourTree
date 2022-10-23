//
// Created by jeanc on 17/10/2022.
//

#include "NodeData.h"

NodeData::NodeData(int dd) {
    this->dData=dd;
}

NodeData::~NodeData() {

}

string NodeData::displayItem() {
    stringstream s;
    s<<dData<<",";
    return s.str();
}
