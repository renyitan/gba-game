#include "gba.h"
#include "player.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sprites_id.h"

#define VIRUS_PADDING 12
#define MAX_FREE_VIRUS 50

// Generate Virus Type
typedef struct Virus
{
    int id;
    int xPos;
    int yPos;
    int xVel;
    int yVel;
} Virus;

// Generate Viruses type, which is basically an array of Virus
typedef struct
{
    Virus freeVirus[MAX_FREE_VIRUS];
    int length;
} Viruses;

void InitViruses(Viruses *viruses)
{
    viruses->length = 0;
}

int getRandomVel()
{
    int num = (rand() % 2);
    return (num == 0) ? num - 1 : num;
}

void addVirus(Viruses *v, int count)
{
    if (v->length < count)
    {
        Virus *newVirus = &v->freeVirus[v->length];
        newVirus->id = VIRUS_INITIAL_ID + v->length;
        newVirus->xPos = ((rand() % 224) + 1); //minimum x pos is 0, max is 224
        newVirus->yPos = ((rand() % 144) + 1); //minimum y pos is 0. max is 145

        // if the x,y position of the virus is where the player is, get new random positions
        if (newVirus->xPos == PLAYER_XPOS && newVirus->yPos == PLAYER_YPOS)
        {
            newVirus->xPos = ((rand() % 224) + 1);
            newVirus->yPos = ((rand() % 30) - 15);
        }

        newVirus->xVel = getRandomVel(); // generated random between -1 and 1
        newVirus->yVel = getRandomVel(); // generate randomly between -1 and 1
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

        if (currentVirus->xPos >= SCREEN_WIDTH - 8 || currentVirus->xPos <= 0)
        {
            currentVirus->xVel = currentVirus->xVel * (-1);
        }

        if (currentVirus->yPos >= SCREEN_HEIGHT - 16 || currentVirus->yPos <= 0)
        {
            currentVirus->yVel = currentVirus->yVel * (-1);
        }

        currentVirus->xPos += currentVirus->xVel;
        currentVirus->yPos += currentVirus->yVel;

    }
}

void virusCollisionWithPlayer(Viruses *v)
{
    int i;
    for (i = 0; i < v->length; i++)
    {
        Virus *currentVirus = &v->freeVirus[i];

        // check for horizontal collision with player
        if ((PLAYER_XPOS >= currentVirus->xPos && PLAYER_XPOS <= currentVirus->xPos + VIRUS_PADDING) ||
            (PLAYER_XPOS + PLAYER_PADDING >= currentVirus->xPos && PLAYER_XPOS + PLAYER_PADDING <= currentVirus->xPos + VIRUS_PADDING))
        {
            // check for vertical collision with player
            if (PLAYER_YPOS >= currentVirus->yPos && PLAYER_YPOS <= currentVirus->yPos + VIRUS_PADDING ||
                (PLAYER_YPOS + PLAYER_PADDING >= currentVirus->yPos && PLAYER_YPOS + PLAYER_PADDING <= currentVirus->yPos + VIRUS_PADDING))
            {
                // if collided, decrease player life by 1
                PLAYER_LIFE_COUNTS -= 1;
            }
        }
    }
}