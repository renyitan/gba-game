#include "sprites.h"
#include "position.h"
#include "mygbalib.h"
#define INPUT (KEY_MASK & (~REG_KEYS))

void checkMovementButtonInGame(void)
{

    u16 buttons = INPUT;
    int displacement = 1;

    if ((buttons & KEY_RIGHT) == KEY_RIGHT)
    {
        IDENTITY = 0;
        XPOS = XPOS + displacement;
        drawSprite(IDENTITY, num, XPOS, YPOS);
    }
    if ((buttons & KEY_LEFT) == KEY_LEFT)
    {
        IDENTITY = 1;
        XPOS = XPOS - displacement;
        drawSprite(IDENTITY, num, XPOS, YPOS);
    }
    if ((buttons & KEY_UP) == KEY_UP)
    {
        YPOS = YPOS + displacement;
        drawSprite(IDENTITY, num, XPOS, YPOS);
    }
    if ((buttons & KEY_DOWN) == KEY_DOWN)
    {
        YPOS = YPOS - displacement;
        drawSprite(IDENTITY, num, XPOS, YPOS);
    }
}