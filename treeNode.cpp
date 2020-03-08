#include "treeNode.h"

treeNode::treeNode(board *b)
{
    parent = NULL;
    nodeBoardPtr = b;
    nodeBoardPtr->generateAllMove();
    nodeBoardPtr->simulateBoard();
}
treeNode::treeNode(treeNode *t, board *b)
{ //treeNode t= parent
    nodeBoardPtr = b;
    parent = t;
    //t->children.push_back();
    nodeBoardPtr->generateAllMove();
    nodeBoardPtr->simulateBoard();
}
// treeNode::treeNode(){
//     parent = NULL;
//     //nodeBoardPtr->initBoard();
//     nodeBoardPtr->generateAllMove();
//     nodeBoardPtr->simulateBoard();

// }
