#ifndef playerh
#define playerh
#include <cstdio>
#include <fstream>
#include <iostream>

using namespace std;

class player
{
public:
    player();
    bool getFirstColor();
    bool getFirst();
    void setMyColor();
    bool playerColor;
    void sendFirstMove();
    //int first;
    //const player &operator=(player);
};

#endif