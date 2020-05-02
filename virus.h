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
    newVirus->id = v->length + 2;
    newVirus->xPos = (rand() % 6)*44; //minimum x pos is 0, max is 220
    if (newVirus->xPos < 220) //virus is coming from top wall
    {
        newVirus->yPos = 0;
    }
    else if (newVirus->xPos == 220)//virus is coming from right wall
    {
        newVirus->yPos = (rand() % 6)*28; //minimum y pos is 0. max is 140
    }
    newVirus->xVel = 8;
    newVirus->yVel = 8;
    v->length++;
}

void updateVirusPosition(Viruses *v)
{
    int i;

    for (i = 0; i < v->length; i++)
    {
        Virus *currentVirus = &v->freeVirus[i];
        currentVirus->xPos -= currentVirus->xVel;
        currentVirus->yPos += currentVirus->yVel;
    }
}
