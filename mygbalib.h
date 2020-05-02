#include "sprites.h"
#include "player.h"
#include "virus.h"
#include "masks.h"
#include "game_state.h"
// #include "sprites_id.h"

#define INPUT (KEY_MASK & (~REG_KEYS))

void auxButtonHandler(void)
{
    u16 buttons = INPUT;

    if ((buttons & KEY_START) == KEY_START)
    {
        GAME_STATE = STATE_PLAYING;
    }
}

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

void drawMasks(Masks *m)
{
    int i;
    for (i = 0; i < m->length; i++)
    {
        Mask *currentMask = &m->freeMasks[i];
        if (!currentMask->collected)
        {
            drawSprite(SPRITE_MASK, currentMask->id, currentMask->xPos, currentMask->yPos);
        }
        else
        {
            drawSprite(SPRITE_MASK, currentMask->id, SCREEN_WIDTH + 12, SCREEN_HEIGHT + 12);
        }
    }
}

void drawViruses(Viruses *v)
{
    int i;
    for (i = 0; i < v->length; i++)
    {
        Virus *currentVirus = &v->freeVirus[i];
        drawSprite(SPRITE_VIRUS, currentVirus->id, currentVirus->xPos, currentVirus->yPos);
    }
}

// void drawLifeCounts(void)
// {
//     int i;
//     for (i = 0; i < PLAYER_LIFE_COUNTS; i++)
//     {
//         drawSprite(LIFE_1, i + 2, (LIFE_XPOS + i) * 16, LIFE_YPOS);
//     }
// }

void drawGameTitle(void)
{
    int LETTER_XPOS = 48;
    int LETTER_YPOS = SCREEN_HEIGHT / 2;

    drawSprite(SPRITE_V, LETTER_ID, LETTER_XPOS, 50);
    drawSprite(SPRITE_I, LETTER_ID + 1, LETTER_XPOS + 16, 50);
    drawSprite(SPRITE_R, LETTER_ID + 2, LETTER_XPOS + 32, 50);
    drawSprite(SPRITE_V, LETTER_ID + 3, LETTER_XPOS + 48, 50);
    drawSprite(SPRITE_S, LETTER_ID + 4, LETTER_XPOS + 64, 50);

    drawSprite(SPRITE_R, LETTER_ID + 5, LETTER_XPOS + 96, 50);
    drawSprite(SPRITE_V, LETTER_ID + 6, LETTER_XPOS + 112, 50);
    drawSprite(SPRITE_M, LETTER_ID + 7, LETTER_XPOS + 128, 50);
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

void removeSprite(int N)
{
    *(unsigned short *)(0x7000000 + 8 * N) = 0x2000;
    *(unsigned short *)(0x7000002 + 8 * N) = 0x4000;
    *(unsigned short *)(0x7000004 + 8 * N) = 0x000;
    // free(*(unsigned short *)(0x7000004 + 8 * N));
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
