//
// Created by jeanc on 17/10/2022.
//

#ifndef PROYECTO_2_NODE_H
#define PROYECTO_2_NODE_H

#include "NodeData.h"

class Node {

private:
    static const int ORDER = 4;
    int numItems;
    Node *parent;
    Node** childArray;
    NodeData** itemArray;

public:
    Node();
    virtual ~Node();
    void connectChild(int childNum, Node* child);
    Node* disconnectChild(int childNum);
    Node* getChild(int childNum);
    Node* getParent();
    bool isLeaf();
    int getNumItems();
    void setNumItems(int theValue);
    NodeData* getItem(int index);
    NodeData* setItem(int index, NodeData* theValue);
    bool isFull();
    int insertItem(NodeData* newItem);
    void insertatfront(NodeData* newItem);
    NodeData* removeItem();
    string displayNode();
    string displayvalue(int j);
    void deletenodevalue(int theValue);
    void deletevalue(int theValue, string side);
    Node* getsibiling(int theValue);
};
#endif //PROYECTO_2_NODE_H
