#include "ABV1.h"
#include <cstdio>
#include <istream>
#include <ctime>

using namespace std;

FILE *movef;
int main()
{

    srand(time(NULL));
    int x = rand();
    string outPut;
    //cout << "OK" << endl;
    player initPlayer;
    initPlayer.setMyColor();
    board initBoard = board(&initPlayer);
    initBoard.initBoard();

     initBoard.printBoard();
    // cout << initBoard.getUnrevealNum() << endl;
    // exit(1);

    if(initBoard.getUnrevealNum()>8){ //剩7顆棋子未翻開
        initBoard.generateAllMove();
        if(initBoard.boardMove.eatMove.size()!=0){
            outPut = initBoard.boardMove.eatMove.at(x % initBoard.boardMove.eatMove.size());
        }
        else{
            outPut = initBoard.boardMove.allMove.at(x % initBoard.boardMove.allMove.size());
        }
        
    }
    else{
        treeNode *root = new treeNode(&initBoard);
        //cout << "My color =" << root->nodeBoardPtr->MyplayerPtr->playerColor << endl;
        int result = 0;

        //root->nodeBoardPtr->printBoard();
        //exit(1);
        result = maxNode(root, -100, 100);

        // printf("nodeCount=%d\n", getNodeCount());
        // printf("alpha = %d\n", getAlphaCut());
        // printf("beta = %d\n", getBetaCut());

        
        cout << "moveChoose: " << root->children[root->selectedBranch]->nodeBoardPtr->originMove << endl;
        outPut = root->children[root->selectedBranch]->nodeBoardPtr->originMove;
    }
    movef = fopen("move.txt", "w+");
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