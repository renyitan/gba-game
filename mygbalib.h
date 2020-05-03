/** 
 * This is the main library which contains all the sub-libraires to be used. 
 * It should be the only library included in main.c
*/

#include "gba.h"
#include "draw.h"
#include "player.h"

#include "game_state.h"


void fillPalette(void)
{
    int i;

    // Fill the palette in GBA memory
    for (i = 0; i < NCOLS; i++)
        spritePal[i] = palette[i];
}

void fillSprites(void)
{
    int i;

    // Load all sprites in GBA memory
    for (i = 0; i < 128 * 16 * 16; i++)
        spriteData[i] = (sprites[i * 2 + 1] << 8) + sprites[i * 2];
}