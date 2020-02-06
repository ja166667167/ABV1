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
    FILE *board;
    board = fopen("board.txt", "r");
    int boardLine = 0;
    int count = 0;
    char tmp = '\0';
    while (boardLine != 14)
    { //過濾到第12行
        fscanf(board, "%c", &tmp);
        if (tmp == '*')
        {
            boardLine++;
        }
    }
    while (count != 8)
    {
        fscanf(board, "%c", &tmp);
        count++;
    }
    //printf("%c\n",tmp);
    if (tmp >= 65 & tmp <= 90)
    {
        return 0;
    }
    else if (tmp >= 97 & tmp <= 122)
    {
        return 1;
    }
}
bool player::getFirst()
{ //me first=1, not me first=0 ????????????????????????????????????????????
    int boardLine = 0, count = 0;
    char tmp = '\0';
    FILE *board;
    errno = 0;
    board = fopen("board.txt", "r");
    if (errno)
    {
        printf("Errno= %d\n", errno);
    }
    //printf("GetFirst():");
    while (boardLine != 14)
    { //過濾到第14行????????????????????????????????????????????
        fscanf(board, "%c", &tmp);
        //printf("%d",boardLine);
        if (tmp == '*')
        {
            boardLine++;
        }
    }
    //printf("\n");
    while (1)
    {
        while (tmp != 32)
        {
            fscanf(board, "%c", &tmp);
        }
        fscanf(board, "%c", &tmp);

        if (tmp <= 57 & tmp >= 49)
        {
            while (tmp != 32)
            {
                fscanf(board, "%c", &tmp);
            }
            count = 1;
            while (tmp != '\n')
            {
                fscanf(board, "%c", &tmp);
                count++;
                //printf("%d\n",count);
            }
            //printf("\n");
        }
        else
        {
            break;
        }
    }

    fclose(board);
    if (count == 7)
    {
        return 0;
    }
    if (count == 13)
    {
        return 1;
    }
}
void player::setMyColor()
{ //紅0 黑1
    bool firstColor = getFirstColor();
    bool mefirst = getFirst();
    //printf("first color:%d\n",firstColor);
    //printf("first:%d\n",mefirst);
    //printf("??????\n");
    if (mefirst == 1)
    {
        //printf("one");
        playerColor = firstColor;
    }
    else if (mefirst == 0)
    {
        //printf("two");
        playerColor = (!firstColor);
    }
}
// const player &player::operator=(player p){
//     p.playerColor = playerColor;
//     //p.first = first;
//     return *this;
// }

//int first = getFirst();
