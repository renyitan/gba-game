#include "position.h"


void spawnVirus(void)
{
    drawSprite(2, 5, 100, 80);
}

void renderGame(void)
{
    drawSprite(IDENTITY, num, XPOS, YPOS);
    spawnVirus();
}
