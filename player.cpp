#include "player.h"
#include <errno.h>

player::player() {}

void player::sendFirstMove()
{
    FILE *move;
    move = fopen("move.txt", "w+");
    fprintf(move, "1\nb4\n0\n");
    fclose(move);
}
bool player::getFirstColor()
{ //紅先0黑先1
    fstream board;
    board.open("board.txt", ios::in);
    int boardLine = 0;
    //int count = 0;
    string line;

    char firstReveal;
    while (boardLine != 14)
    { //過濾到第12行
        getline(board, line);
        boardLine++;
    }
    firstReveal = line.at(8);
    if (firstReveal >= 65 & firstReveal <= 90) //小寫-紅棋 return 0
    {
        return 0;
    }
    else if (firstReveal >= 97 & firstReveal <= 122) //大寫-黑棋 return 1
    {
        return 1;
    }
    board.close();
}
bool player::getFirst()
{ //me first=1, not me first=0 ????????????????????????????????????????????
    int boardLine = 0;
    fstream board;
    string line;
    string tmp;

    board.open("board.txt", ios::in);
    //printf("GetFirst():");
    while (boardLine != 14)
    { //過濾到第14行????????????????????????????????????????????
        getline(board, line);
        boardLine++;
    }
    //printf("\n");
    while ((line.at(2) <= 57) & (line.at(2) >= 49))
    {
        tmp = line;
        getline(board, line);
    }
    if (tmp.length() < 14)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    board.close();
}
void player::setMyColor()
{ //紅0 黑1
    bool firstColor = getFirstColor();
    bool mefirst = getFirst();
    //printf("first color:%d\n",firstColor);
    //printf("first:%d\n",mefirst);
    //printf("??????\n");
    // if (mefirst == 1)
    // {
    //     //printf("one");
    //     playerColor = firstColor;
    // }
    // else if (mefirst == 0)
    // {
    //     //printf("two");
    //     playerColor = (!firstColor);
    // }
    playerColor = !(mefirst ^ firstColor);
    //cout << !(mefirst ^ firstColor) << endl;
    // const player &player::operator=(player p){
    //     p.playerColor = playerColor;
    //     //p.first = first;
    //     return *this;
    // }
}
//int first = getFirst();
