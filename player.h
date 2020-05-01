#include "gba.h"

typedef struct Player 
{
    int identity;
    int xPos;
    int yPos;
};

void InitPlayer(Player* player, int startX, int startY) {
    player->identity = 1;
    player->xPos = startX;
    player->yPos = startY;
}