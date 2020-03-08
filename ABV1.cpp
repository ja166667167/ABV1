#include "ABV1.h"

//**//string spacing = ""; ///////////////////////////////
int const depthLimit = 4;

int depthCount = 0;
int nodeCount = 1;

int alphaCut = 0; ////////////
int betaCut = 0;  /////////////

int maxNode(treeNode *thisNode, int alpha, int beta)
{
    //**//    cout << spacing << "In MaxNode "; /////////////////////////////////////////
    //**//    cout << "depth=" << depthCount << endl; ////////////////////////
    int m;
    if (depthLimit == depthCount)
    {
        //**//        cout << spacing << "score=" << thisNode->nodeBoardPtr->scoreBoard() << endl; /////////////////////
        depthCount--;
        //**//        spacing.erase(spacing.end() - 4, spacing.end()); ///////////////////////
        return thisNode->nodeBoardPtr->scoreBoard();
    }
    else
    {
        m = alpha;
        for (int i = 0; i < thisNode->nodeBoardPtr->possibility.size(); i++)
        {

            nodeCount++;
            //**//            cout << spacing;
            //**//printf("max new Board i=%d\n", i); /////////////////////////////////////////
            treeNode *nextNode = new treeNode(thisNode, thisNode->nodeBoardPtr->possibility[i]);

            thisNode->children.push_back(nextNode);
            //**//            cout << spacing; ////////////////////
            //nextNode->nodeBoardPtr->printAll();//////////////////////

            depthCount++;
            //**//            spacing += "    "; ///////////////////////////////////
            int t = minNode(nextNode, m, beta);
            //**//            cout << spacing; ///////////////////////////////////
            //**//            cout << "back to max "; /////////////////////
            //**//            cout << "depth=" << depthCount << endl; ////////////////////////
            if (t > m)
            {
                m = t;
                thisNode->selectedBranch = i;
            }
            if (m >= beta)
            {
                //**//                cout << spacing; ///////////////////////////
                //**//                cout << "beta cut,Max m=" << m << endl; //////////////////////////////////////
                betaCut++;
                //exit(1);
                depthCount--;
                //**//                spacing.erase(spacing.end() - 4, spacing.end()); ///////////////////////////////
                return m;
            }
        }
    }
    //**//    cout << spacing; //////////////////////////////
    //**//    cout << "Max m=" << m << endl; //////////////////////////////////////
    depthCount--;
    //**//    spacing.erase(spacing.end() - 4, spacing.end()); ///////////////////////////
    return m;
}
int minNode(treeNode *thisNode, int alpha, int beta)
{
    //**//    cout << spacing << "In MinNode "; /////////////////////////////////////////////
    //**//    cout << "depth=" << depthCount << endl; /////////////////////////////
    int m;

    if (depthLimit == depthCount)
    {

        //**//        cout << spacing << "score=" << thisNode->nodeBoardPtr->scoreBoard() << endl; //////////////////////////
        depthCount--;
        //**//        spacing.erase(spacing.end() - 4, spacing.end()); /////////////////////////////
        return thisNode->nodeBoardPtr->scoreBoard();
    }
    else
    {

        m = beta;
        //thisNode->nodeBoardPtr.printBoard();
        // if(depthCount){
        //     thisNode->parent->nodeBoardPtr.printBoard();
        // }
        // cout << endl;
        // thisNode->nodeBoardPtr.printBoard();

        for (int i = 0; i < thisNode->nodeBoardPtr->possibility.size(); i++)
        {

            nodeCount++;
            //**//            printf("min new Board i=%d\n", i); /////////////////////////////////////////
            treeNode *nextNode = new treeNode(thisNode, thisNode->nodeBoardPtr->possibility[i]);
            thisNode->children.push_back(nextNode);

            //nextNode->nodeBoardPtr->printAll();//////////////////////
            //**//            cout << spacing; ////////////////////////
            depthCount++;
            //**//            spacing += "    "; /////////////////////////////////////////
            int t = maxNode(nextNode, alpha, m);
            //**//            cout << spacing;                        /////////////////////////////////
            //**//            cout << "back to min ";                 ///////////////////////////
            //**//            cout << "depth=" << depthCount << endl; ////////////////////////
            if (t < m)
            {
                m = t;
                thisNode->selectedBranch = i;
            }
            if (m <= alpha)
            {
                //**//                cout << spacing;                         /////////////////////////////
                //**//                cout << "alpha cut,Min m=" << m << endl; //////////////////////////////////////
                alphaCut++;
                //exit(1);
                depthCount--;
                //**//                spacing.erase(spacing.end() - 4, spacing.end()); ////////////////////////////////
                return m;
            }
        }
    }
    //**//    cout << "Min m=" << m << endl; //////////////////////////////////////
    depthCount--;
    //**//    spacing.erase(spacing.end() - 4, spacing.end()); ///////////////////////////
    return m;
}
int getNodeCount()
{
    return nodeCount;
}
int getAlphaCut()
{
    return alphaCut;
}
int getBetaCut()
{
    return betaCut;
}
