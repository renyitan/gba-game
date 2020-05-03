#include "gba.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sprites_id.h"

#define VIRUS_PADDING 12
#define VIRUS_NUM_MAX 5000


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
    viruses->length = 0;
}

void addVirus(Viruses *v)
{
    Virus *newVirus = &v->freeVirus[v->length];
    newVirus->id = VIRUS_INITIAL_ID + v->length;
    newVirus->xPos = ((rand() % 224) + 1); //minimum x pos is 0, max is 224
    newVirus->yPos = ((rand() % 144) + 1); //minimum y pos is 0. max is 145
    newVirus->xVel = (((rand() % 50) - 25)*2);
    newVirus->yVel = (((rand() % 50) - 25)*2);
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