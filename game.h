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
    int randomN;
    int randomXPOS;
    int randomYPOS;

    srand(time(0));
    randomN = getRandomNumber(num + 1, 1000);
    randomXPOS = getRandomNumber(0, SCREEN_WIDTH);
    randomYPOS = getRandomNumber(0, SCREEN_HEIGHT);

    drawSprite(1, randomN, randomXPOS, randomYPOS);
}

void renderGame(void)
{
    drawSprite(IDENTITY, num, XPOS, YPOS);
    spawnVirus();
}
