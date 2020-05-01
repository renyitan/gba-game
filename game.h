#include "position.h"
#include "gba.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getRandomNumber(int lower, int upper)
{
    return num = (rand() % (upper - lower + 1) + lower);
}

void spawnVirus(void)
{
    drawSprite(1, 2, 50,80);
}

void renderGame(void)
{
    drawSprite(IDENTITY, num, XPOS, YPOS);
    spawnVirus();
}
