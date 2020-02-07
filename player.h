#ifndef playerh
#define playerh
#include <iostream>
#include <cstdio>

using namespace std;

class player{
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