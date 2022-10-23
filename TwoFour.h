//
// Created by jeanc on 17/10/2022.
//

#ifndef PROYECTO_2_TWOFOUR_H
#define PROYECTO_2_TWOFOUR_H

#include "Node.h"

class TwoFour {

private:
    Node *root;
    string recDisplayTree(Node *thisNode, int level, int childNumber);

public:
    TwoFour();
    virtual ~TwoFour();
    void insert(int dValue);
    void split(Node *thisNode);
    Node* getNextChild(Node *theNode, int theValue);
    string displayTree(int i);
    string inorderdisplay(Node *thisNode, int level, int childNumber);
    Node* find(int theValue);
    Node* findvalue(Node *theNode, int theValue);
    Node* deleteNode(Node *currnode, int theValue);
    Node* deleteleaf_cases(Node *thisNode, int theValue);
    Node* balancetree(Node *currnode);
    Node* getinordernode(Node *thisNode);
};
#endif //PROYECTO_2_TWOFOUR_H
