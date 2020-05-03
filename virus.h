#include "gba.h"
#include "player.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sprites_id.h"

#define VIRUS_PADDING 12
#define MAX_FREE_VIRUS 50

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
    Virus freeVirus[MAX_FREE_VIRUS];
    int length;
} Viruses;

void InitViruses(Viruses *viruses)
{
    viruses->length = 0;
}

void addVirus(Viruses *v, int count)
{
    if (v->length < count)
    {
        Virus *newVirus = &v->freeVirus[v->length];
        newVirus->id = VIRUS_INITIAL_ID + v->length;
        newVirus->xPos = ((rand() % 224) + 1); //minimum x pos is 0, max is 224
        newVirus->yPos = ((rand() % 144) + 1); //minimum y pos is 0. max is 145
                                               // newVirus->xVel = ((rand() % 50) - 25);
                                               // newVirus->yVel = ((rand() % 50) - 25);
        newVirus->xVel = ((rand() % 30) - 15);
        newVirus->yVel = ((rand() % 30) - 15);
        v->length++;
    }
    else
    {
        return;
    }
}

void updateVirusPosition(Viruses *v)
{
    int i;

    for (i = 0; i < v->length; i++)
    {
        Virus *currentVirus = &v->freeVirus[i];

        //if virus hits left or right wall
        if ((abs(currentVirus->xPos - 1) < (abs(currentVirus->xVel) - 1)) || (abs(currentVirus->xPos - 224) < abs(currentVirus->xVel)))
        {
            currentVirus->xVel = currentVirus->xVel * (-1);
        }
        //if virus hits top or bottom wall
        else if ((abs(currentVirus->yPos) < (abs(currentVirus->yVel))) || (abs(currentVirus->yPos - 144) < abs(currentVirus->yVel)))
        {
            currentVirus->yVel = currentVirus->yVel * (-1);
        }

        currentVirus->xPos += currentVirus->xVel;
        currentVirus->yPos += currentVirus->yVel;

        if (currentVirus->xPos <= 2)
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
        if ((PLAYER_XPOS >= currentVirus->xPos && PLAYER_XPOS <= currentVirus->xPos + VIRUS_PADDING) ||
            (PLAYER_XPOS + PLAYER_PADDING >= currentVirus->xPos && PLAYER_XPOS + PLAYER_PADDING <= currentVirus->xPos + VIRUS_PADDING))
        {
            // check for vertical collision
            if (PLAYER_YPOS >= currentVirus->yPos && PLAYER_YPOS <= currentVirus->yPos + VIRUS_PADDING ||
                (PLAYER_YPOS + PLAYER_PADDING >= currentVirus->yPos && PLAYER_YPOS + PLAYER_PADDING <= currentVirus->yPos + VIRUS_PADDING))
            {
                PLAYER_LIFE_COUNTS -= 1;
            }
        }
    }
}