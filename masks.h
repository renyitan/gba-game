#include "gba.h"
#include "position.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MASK_NUM_MAX 20
#define MASK_PADDING 12

typedef struct Mask
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
    Mask *newMask = &m->freeMasks[m->length - 1];
    newMask->id = 0 + 1;
    newMask->xPos = (rand() % 240);
    newMask->yPos = (rand() % 160);
    newMask->collected = false;

    m->length++;
}

// void maskCollisionWithPlayer(Masks *m)
// {
//     int i;
//     for (i = 0; i < m->length; i++)
//     {
//         Mask *currentMask = &m->freeMasks[i];

//         // check for horizontal collision
//         if (PLAYER_XPOS >= currentMask->xPos && PLAYER_XPOS <= currentMask->xPos + MASK_PADDING)
//         {
//             // check for vertical collision
//             if (PLAYER_YPOS >= currentMask->yPos && PLAYER_YPOS <= currentMask->yPos + MASK_PADDING)
//             {
//                 currentMask->collected = true;
//             }
//         }
//     }
// }
