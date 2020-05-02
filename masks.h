#include "gba.h"
#include "player.h"
#include <stdlib.h>
#include <stdbool.h>
// #include <limits.h>

#define MASK_NUM_MAX 20
#define MASK_PADDING 16

typedef struct
{
    int id;
    int xPos;
    int yPos;
    bool collected;
} Mask;

typedef struct
{
    Mask freeMasks[MASK_NUM_MAX];
    int length;
} Masks;

void InitMasks(Masks *masks)
{
    masks->length = 1;
}

void addMask(Masks *m)
{
    Mask *newMask = &m->freeMasks[m->length];
    newMask->id = 9000 + m->length;
    newMask->xPos = (rand() % (150/2)) + SCREEN_WIDTH/3;
    newMask->yPos = (rand() % (SCREEN_HEIGHT-8)) ;
    newMask->collected = false;

    m->length++;
}

void maskCollisionWithPlayer(Masks *m)
{
    int i;
    for (i = 0; i < m->length; i++)
    {
        Mask *currentMask = &m->freeMasks[i];

        // check for horizontal collision
        if ((PLAYER_XPOS >= currentMask->xPos && PLAYER_XPOS <= currentMask->xPos + MASK_PADDING) ||
            (PLAYER_XPOS + PLAYER_PADDING >= currentMask->xPos && PLAYER_XPOS + PLAYER_PADDING <= currentMask->xPos + MASK_PADDING))
        {
            // check for vertical collision
            if ((PLAYER_YPOS >= currentMask->yPos && PLAYER_YPOS <= currentMask->yPos + MASK_PADDING) ||
                (PLAYER_YPOS + PLAYER_PADDING >= currentMask->yPos && PLAYER_YPOS + PLAYER_PADDING <= currentMask->yPos + MASK_PADDING))
            {
                currentMask->collected = true;
            }
        }
    }
}
