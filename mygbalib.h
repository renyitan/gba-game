#include "sprites.h"
#include "position.h"
#include "virus.h"
#include "masks.h"

#define INPUT (KEY_MASK & (~REG_KEYS))

void movePlayer(void)
{
    u16 buttons = INPUT;
    int displacement = 1;

    if ((buttons & KEY_RIGHT) == KEY_RIGHT)
    {
        if (PLAYER_XPOS >= 240)
        {
            PLAYER_XPOS = 0;
        }

        PLAYER_SPRITE = SPRITE_NURSE_RIGHT;

        PLAYER_XPOS = PLAYER_XPOS + displacement;
        drawSprite(PLAYER_SPRITE, PLAYER_ID, PLAYER_XPOS, PLAYER_YPOS);
    }
    else if ((buttons & KEY_LEFT) == KEY_LEFT)
    {
        PLAYER_SPRITE = SPRITE_NURSE_LEFT;
        PLAYER_XPOS = PLAYER_XPOS - displacement;

        drawSprite(PLAYER_SPRITE, PLAYER_ID, PLAYER_XPOS, PLAYER_YPOS);
    }
    else if ((buttons & KEY_DOWN) == KEY_DOWN)
    {
        if (PLAYER_YPOS <= 0)
        {
            PLAYER_YPOS = 160;
        }

        PLAYER_YPOS = PLAYER_YPOS + displacement;

        drawSprite(PLAYER_SPRITE, PLAYER_ID, PLAYER_XPOS, PLAYER_YPOS);
    }
    else if ((buttons & KEY_UP) == KEY_UP)
    {
        if (PLAYER_YPOS >= 160)
        {
            PLAYER_YPOS = 0;
        }

        PLAYER_YPOS = PLAYER_YPOS - displacement;
        drawSprite(PLAYER_SPRITE, PLAYER_ID, PLAYER_XPOS, PLAYER_YPOS);
    }
};

void removePlayer(void)
{
    drawSprite(PLAYER_SPRITE, PLAYER_ID, SCREEN_WIDTH + 10, SCREEN_HEIGHT + 10);
}

// void drawMasks(Masks *m)
// {
//     int i;
//     for (i = 0; i < m->length; i++)
//     {
//         Mask *currentMask = &m->freeMasks[i];
//         drawSprite(SPRITE_MASK, currentMask->id, currentMask->xPos, currentMask->yPos);
//     }
// }

void drawViruses(Viruses *v)
{
    int i;
    for (i = 0; i < v->length; i++)
    {
        Virus *currentVirus = &v->freeVirus[i];
        drawSprite(SPRITE_VIRUS, currentVirus->id, currentVirus->xPos, currentVirus->yPos);
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
