#include "gba.h"
#include "player.h"
#include "sprites_id.h"
#include <stdlib.h>
#include <stdbool.h>

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
    masks->length = 0;
}

void addMask(Masks *m)
{
    Mask *newMask = &m->freeMasks[m->length];
    newMask->id = MASK_INITIAL_ID + m->length;
    newMask->xPos = ((rand() % 224) + 1); //minimum x pos is 0, max is 224
    newMask->yPos = ((rand() % 144) + 1); //minimum y pos is 0. max is 145
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
