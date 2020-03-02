#include "ABV1.h"
#include <cstdio>
#include <istream>
using namespace std;

FILE *movef;
int main()
{

    //cout << "OK" << endl;
    player initPlayer;
    initPlayer.setMyColor();
    board initBoard = board(&initPlayer);
    initBoard.initBoard();
    treeNode *root = new treeNode(&initBoard);
    //cout << "My color =" << root->nodeBoardPtr->MyplayerPtr->playerColor << endl;
    int result = 0;

    //root->nodeBoardPtr->printBoard();
    //exit(1);
    result = maxNode(root, -100, 100);

    printf("nodeCount=%d\n", getNodeCount());
    printf("alpha = %d\n", getAlphaCut());
    printf("beta = %d\n", getBetaCut());

    movef = fopen("move.txt", "w+");
    cout << "moveChoose: " << root->children[root->selectedBranch]->nodeBoardPtr->originMove << endl;
    string outPut =
        root->children[root->selectedBranch]->nodeBoardPtr->originMove;
    if (outPut[0] == 'R')
    {
        fprintf(movef, "1\n%c%c\n0\n", outPut[2], outPut[3]);
        fclose(movef);
    }
    else
    {
        fprintf(movef, "0\n%c%c\n%c%c\n",
                outPut[0], outPut[1], outPut[3], outPut[4]);
        fclose(movef);
    }

    return 0;
}