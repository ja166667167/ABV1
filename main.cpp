#include "ABV1.h"
#include <cstdio>
#include <istream>
using namespace std;

FILE *movef;
int main()
{

    cout << "OK" << endl;
    treeNode *root = new treeNode();
    cout << "My color =" << root->nodeBoardPtr->Myplayer.playerColor << endl;
    int result = 0;

    //root->nodeBoardPtr->printAll();
    //exit(1);
    result = maxNode(root, -100, 100);

    printf("nodeCount=%d\n", getNodeCount());
    printf("alpha = %d\n",getAlphaCut());
    printf("beta = %d\n",getBetaCut());
    
    movef = fopen("move.txt", "w+");
    string outPut =
        root->nodeBoardPtr->boardMove.allMove[root->selectedBranch];
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