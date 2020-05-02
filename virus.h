#include "gba.h"
#include "position.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int VIRUS_LENGTH = 12;
#define VIRUS_NUM_MAX 9999

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
    Virus freeVirus[VIRUS_NUM_MAX];
    int length;
} Viruses;

void InitViruses(Viruses *viruses)
{
    viruses->length = 1;
    // memset(&viruses->freeVirus[0], 0, sizeof(Virus) * 22 * 14);
}

void addVirus(Viruses *v)
{
    Virus *newVirus = &v->freeVirus[v->length - 1];
    newVirus->id = v->length + 2;
    newVirus->xPos = (rand() % 6) * 44; //minimum x pos is 0, max is 220
    if (newVirus->xPos < 220)           //virus is coming from top wall
    {
        newVirus->yPos = 0;
    }
    else if (newVirus->xPos == 220) //virus is coming from right wall
    {
        newVirus->yPos = (rand() % 6) * 28; //minimum y pos is 0. max is 140
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

        if (currentVirus->xPos <= 16)
        {
            currentVirus->yPos = SCREEN_HEIGHT + 16;
        }
    }
}

void virusCollisionWithPlayer(Viruses *v)
{
    int i;
    for (i = 0; i < v->length; i++)
    {
        Virus *currentVirus = &v->freeVirus[i];

        // check for horizontal collision
        if (PLAYER_XPOS >= currentVirus->xPos && PLAYER_XPOS <= currentVirus->xPos + VIRUS_LENGTH)
        {
            // check for vertical collision
            if (PLAYER_YPOS >= currentVirus->yPos && PLAYER_YPOS <= currentVirus->yPos + VIRUS_LENGTH)
            {
                PLAYER_LIFE_COUNTS -= 1;
            }
        }
    }
}