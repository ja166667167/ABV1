#ifndef treeNodeh
#define treeNodeh

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include"board.h"

using namespace std;

class treeNode{
    public:
        treeNode(board*);
        treeNode(treeNode*,board*);
        treeNode();
        virtual ~treeNode(){}
        board nodeBoard;
        board *nodeBoardPtr=&nodeBoard;
        treeNode *parent;
        vector<treeNode *> children;
        int selectedBranch=0;
};

#endif