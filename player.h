#include <iostream>
#include <cstdio>

using namespace std;

class player{
    public:
        player();
        int getFirstColor();
        int getFirst();
        int getMyColor();
        int playerColor;
        void sendFirstMove();
        //int first;
        const player &operator=(player);
};