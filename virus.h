// #include "mygbalib.h"
#include "gba.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Virus
{
    int id;
    int xPos;
    int yPos;
    int xVel;
    int yVel;
} Virus;

typedef struct
{
    Virus freeVirus[20];
    int length;
} Viruses;

// void createVirus(Virus *v)
// {
//     drawSprite(3, v->id, v->xPos, v->yPos);
// }
void InitViruses(Viruses *viruses)
{
    viruses->length = 1;
    memset(&viruses->freeVirus[0], 0, sizeof(Virus) * 22 * 14);
}

void addVirus(Viruses *v)
{
    Virus *newVirus = &v->freeVirus[v->length - 1];
    newVirus->id = v->length + 1;
    newVirus->xPos = (rand() % 160);
    newVirus->yPos = (rand() % 240);
    newVirus->xVel = 5;
    newVirus->yVel = 5;
    v->length++;
}

void updateVirusPosition(Viruses *v)
{
    int i;

    for (i = 0; i < v->length; i++)
    {
        Virus *currentVirus = &v->freeVirus[i];
        currentVirus->xPos += currentVirus->xVel;
        currentVirus->yPos += currentVirus->yVel;
    }
}
