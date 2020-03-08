#ifndef treeNodeh
#define treeNodeh

#include "board.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class treeNode
{
public:
    treeNode(board *);
    treeNode(treeNode *, board *);
    //treeNode();
    virtual ~treeNode() {}
    //board nodeBoard;
    board *nodeBoardPtr;
    treeNode *parent;
    vector<treeNode *> children;
    int selectedBranch = 0;
};

#endif