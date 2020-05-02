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
    player->id = 1;
    player->xPos = SCREEN_HEIGHT / 2;
    player->yPos = 10;
}

void updatePlayerPosition(Player *player, int xPos, int yPos)
{
    player->xPos = xPos;
    player->yPos = yPos;
}