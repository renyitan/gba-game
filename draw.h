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
    int LETTER_YPOS = 50;

    drawSprite(SPRITE_V, TITLE_LETTER_ID, LETTER_XPOS, LETTER_YPOS);
    drawSprite(SPRITE_I, TITLE_LETTER_ID + 1, LETTER_XPOS + 16, LETTER_YPOS);
    drawSprite(SPRITE_R, TITLE_LETTER_ID + 2, LETTER_XPOS + 32, LETTER_YPOS);
    drawSprite(SPRITE_U, TITLE_LETTER_ID + 3, LETTER_XPOS + 48, LETTER_YPOS);
    drawSprite(SPRITE_S, TITLE_LETTER_ID + 4, LETTER_XPOS + 64, LETTER_YPOS);

    drawSprite(SPRITE_R, TITLE_LETTER_ID + 5, LETTER_XPOS + 96, LETTER_YPOS);
    drawSprite(SPRITE_U, TITLE_LETTER_ID + 6, LETTER_XPOS + 112, LETTER_YPOS);
    drawSprite(SPRITE_N, TITLE_LETTER_ID + 7, LETTER_XPOS + 128, LETTER_YPOS);
}

void drawUserPrompt(void)
{
    int LETTER_XPOS = 32;
    int LETTER_YPOS = 100;

    drawSprite(SPRITE_P_SMALL, SUBTITLE_LETTER_ID, LETTER_XPOS, LETTER_YPOS);
    drawSprite(SPRITE_R_SMALL, SUBTITLE_LETTER_ID + 1, LETTER_XPOS + 16, LETTER_YPOS);
    drawSprite(SPRITE_E_SMALL, SUBTITLE_LETTER_ID + 2, LETTER_XPOS + 32, LETTER_YPOS);
    drawSprite(SPRITE_S_SMALL, SUBTITLE_LETTER_ID + 3, LETTER_XPOS + 48, LETTER_YPOS);
    drawSprite(SPRITE_S_SMALL, SUBTITLE_LETTER_ID + 4, LETTER_XPOS + 64, LETTER_YPOS);

    drawSprite(SPRITE_S_SMALL, SUBTITLE_LETTER_ID + 5, LETTER_XPOS + 96, LETTER_YPOS);
    drawSprite(SPRITE_T_SMALL, SUBTITLE_LETTER_ID + 6, LETTER_XPOS + 112, LETTER_YPOS);
    drawSprite(SPRITE_A_SMALL, SUBTITLE_LETTER_ID + 7, LETTER_XPOS + 128, LETTER_YPOS);
    drawSprite(SPRITE_R_SMALL, SUBTITLE_LETTER_ID + 8, LETTER_XPOS + 144, LETTER_YPOS);
    drawSprite(SPRITE_T_SMALL, SUBTITLE_LETTER_ID + 9, LETTER_XPOS + 160, LETTER_YPOS);
}

void drawGameLevel(void)
{
    int LETTER_XPOS = 32;
    int LETTER_YPOS = 0;

    drawSprite(SPRITE_L, SUBTITLE_LETTER_ID, LETTER_XPOS, LETTER_YPOS);
    drawSprite(SPRITE_L, SUBTITLE_LETTER_ID + 1, LETTER_XPOS + 16, LETTER_YPOS);
    drawSprite(SPRITE_L, SUBTITLE_LETTER_ID + 2, LETTER_XPOS + 32, LETTER_YPOS);
    drawSprite(SPRITE_L, SUBTITLE_LETTER_ID + 3, LETTER_XPOS + 48, LETTER_YPOS);
    drawSprite(SPRITE_L, SUBTITLE_LETTER_ID + 4, LETTER_XPOS + 64, LETTER_YPOS);

    drawSprite(SPRITE_S_SMALL, SUBTITLE_LETTER_ID + 5, LETTER_XPOS + 96, LETTER_YPOS);
    drawSprite(SPRITE_T_SMALL, SUBTITLE_LETTER_ID + 6, LETTER_XPOS + 112, LETTER_YPOS);
    drawSprite(SPRITE_A_SMALL, SUBTITLE_LETTER_ID + 7, LETTER_XPOS + 128, LETTER_YPOS);
    drawSprite(SPRITE_R_SMALL, SUBTITLE_LETTER_ID + 8, LETTER_XPOS + 144, LETTER_YPOS);
    drawSprite(SPRITE_T_SMALL, SUBTITLE_LETTER_ID + 9, LETTER_XPOS + 160, LETTER_YPOS);
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

void drawPixel(int x, int y, COLOR color)
{
    vid_mem[y * SCREEN_WIDTH + x] = color;
}

void drawRect(int left, int top, int width, int height, COLOR color)
{
    int y;
    int x;
    for (y = 0; y < height; ++y)
    {
        for (x = 0; x < width; ++x)
        {
            drawPixel(left + x, top + y, color);
        }
    }
}

drawRect2(int left, int top, int width, int height)
{
    int y;
    int x;
    for (y = 0; y < height; ++y)
    {
        for (x = 0; x < width; ++x)
        {
            drawSprite(SPRITE_NURSE_LEFT, 0, x, y);
        }
    }
}