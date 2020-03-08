#ifndef ABV1
#define ABV1
 
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <time.h>
#include"treeNode.h"
#include"board.h"
#include"player.h"


using namespace std;

int maxNode(treeNode*,int,int);
int minNode(treeNode*,int,int);
int getNodeCount();
int getAlphaCut();
int getBetaCut();

#endif