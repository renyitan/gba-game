#include "gba.h"

#define MASK_NUM_MAX 20

typedef struct Mask
{
    int id;
    int xPos;
    int yPos;
} Mask;

typedef struct Masks
{
    Mask freeMasks[MASK_NUM_MAX];
    int length;
} Masks;

void InitMasks(Masks *masks, int numMasks)
{
    masks->length = 1;
}

void addMask(Masks *m)
{
    Mask *newMask = &m->freeMasks[m->length - 1];
    newMask->id = m->length + 10;
}