/**
 * The draw header file holds all our draw / render functions. 
*/
#include "sprites.h"
#include "player.h"
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

void drawGameTitle(void)
{
    int LETTER_XPOS = 48;
    int LETTER_YPOS = SCREEN_HEIGHT / 2;

    drawSprite(SPRITE_V, TITLE_LETTER_ID, LETTER_XPOS, 50);
    drawSprite(SPRITE_I, TITLE_LETTER_ID + 1, LETTER_XPOS + 16, 50);
    drawSprite(SPRITE_R, TITLE_LETTER_ID + 2, LETTER_XPOS + 32, 50);
    drawSprite(SPRITE_V, TITLE_LETTER_ID + 3, LETTER_XPOS + 48, 50);
    drawSprite(SPRITE_S, TITLE_LETTER_ID + 4, LETTER_XPOS + 64, 50);

    drawSprite(SPRITE_R, TITLE_LETTER_ID + 5, LETTER_XPOS + 96, 50);
    drawSprite(SPRITE_V, TITLE_LETTER_ID + 6, LETTER_XPOS + 112, 50);
    drawSprite(SPRITE_M, TITLE_LETTER_ID + 7, LETTER_XPOS + 128, 50);
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
