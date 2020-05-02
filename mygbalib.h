#include "sprites.h"
#include "position.h"
#include "virus.h";
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
    // moveSprite(XPOS, YPOS);
};

void drawViruses(Viruses *v)
{
    int i;
    for (i = 0; i < v->length; i++)
    {
        Virus *currentVirus = &v->freeVirus[i];
        drawSprite(3, currentVirus->id, currentVirus->xPos, currentVirus->yPos);
    }
}


void fillPalette(void)
{
    int i;

    // Fill the palette in GBA memory
    for (i = 0; i < NCOLS; i++)
        spritePal[i] = palette[i];
}

void fillSprites(void)
{
    int i;

    // Load all sprites in GBA memory
    for (i = 0; i < 128 * 16 * 16; i++)
        spriteData[i] = (sprites[i * 2 + 1] << 8) + sprites[i * 2];

    // // draw all sprites on screen, but all of them outside of the screen (starting at position (240,160) the bottom right corner of the GBA screen)
    // for (i = 0; i < 128; i++)
    //     drawSprite(0, i, 240, 160);
}

void drawSprite(int numb, int N, int x, int y)
{
    // Same as CA2, make specific sprite (based on its name/numb) appear on screen, as slide number N (each sprite needs a different, arbitrary, N >= 0)
    *(unsigned short *)(0x7000000 + 8 * N) = y | 0x2000;
    *(unsigned short *)(0x7000002 + 8 * N) = x | 0x4000;
    *(unsigned short *)(0x7000004 + 8 * N) = numb * 8;
}

// void drawLaser(void)
// {
// Gift function showing you how to draw an example sprite defined in sprite.h on screen, using drawSprite()
// Note that this code uses largeer sprites with a palette, so the main code needs to be initialized in graphical mode 2, using:
// *(unsigned short *) 0x4000000 = 0x40 | 0x2 | 0x1000;
// 	// at the beginning of main() in main.c

//     switch(lPlat) {
//         case 16:
//         {
//             drawSprite(LASER, NPLATS*3 + 5 + NROCK + NMET, LaserX, LaserY);
//             break;
//         }
//         case 9:
//         {
//             drawSprite(LASER, NPLATS*2 + 5 + NROCK + NMET, LaserX, LaserY);
//             break;
//         }
//         default:
//             break;
//     }
// }
