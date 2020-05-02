#include "gba.h"
#include "position.h"

typedef struct Player
{
    int id;
    int xPos;
    int yPos;
} Player;

void InitPlayer(Player *player)
{
    player->id = 0;
    player->xPos = 50;
    player->yPos = 50;
}

void updatePlayerPosition(Player *player)
{
    player->xPos = XPOS;
    player->yPos = YPOS;
}