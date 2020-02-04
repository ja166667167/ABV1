#include "treeNode.h"

treeNode::treeNode(board *p){
    nodeBoardPtr=p;
    nodeBoardPtr->generateAllMove();
    nodeBoardPtr->simulateBoard();
    parent = NULL;
}
treeNode::treeNode(treeNode *t,board *b){    //treeNode t= parent
    nodeBoardPtr = b;
    parent = t;
    //t->children.push_back();
    nodeBoardPtr->generateAllMove();
    nodeBoardPtr->simulateBoard();

}
treeNode::treeNode(){
    nodeBoardPtr->initBoard();
    nodeBoardPtr->generateAllMove();
    nodeBoardPtr->simulateBoard();
    parent = NULL;
}
