// -----------------------------------------------------------------------------
// C-Skeleton to be used with HAM Library from www.ngine.de
// -----------------------------------------------------------------------------
#include "mygbalib.h"
#include <time.h>

// intiate global game state properties
int GAME_STATE = STATE_START;
int GAME_LEVEL = 1;
int VIRUSES_MAX = 2;
int MASKS_MAX = 2;

// Initialise global player propeties;
int PLAYER_SPRITE = 0;
int PLAYER_XPOS = 50;
int PLAYER_YPOS = SCREEN_HEIGHT / 2;
int PLAYER_LIFE_COUNTS = 1;
int PLAYER_COLLECTED_MASKS = 0;

// Declare viruses instances
Viruses viruses;
Virus virus;

Viruses viruses2;

// Declare masks instances
Masks masks;
Mask mask;

void interruptsHandler(void)
{
    REG_IME = 0x00; // Stop all other interrupt handling, while we handle this current one

    // Timer for 5s
    if ((REG_IF & INT_TIMER0) == INT_TIMER0)
    {
    }

    // Timer for 1s
    if ((REG_IF & INT_TIMER1) == INT_TIMER1)
    {
        if (GAME_LEVEL == 1)
        {
            updateVirusPosition(&viruses);
            addVirus(&viruses, VIRUSES_MAX);
        }
        if (GAME_LEVEL == 2)
        {
            updateVirusPosition(&viruses2);
            addVirus(&viruses2, VIRUSES_MAX);
        }

        if (PLAYER_LIFE_COUNTS <= 0)
        {
            removePlayer();
        }
    }

    // Button Interrupts
    if ((REG_IF & INT_BUTTON) == INT_BUTTON)
    {
        // Check for auxillary control buttons (start, select, L, R)
        auxButtonHandler();

        // Check for direction pad butons
        if (PLAYER_LIFE_COUNTS > 0)
        {
            movePlayer();
        }
        else
        {
            removePlayer();
        }
    }

    REG_IF = REG_IF;
    REG_IME = 0x01;
}

// -----------------------------------------------------------------------------
// Project Entry Point
// -----------------------------------------------------------------------------

int main(void)
{
    srand((unsigned)time(NULL));
    int i;

    // Set display mode
    // REG_DISPCNT = OBJ_MAP_1D | MODE2 | OBJ_ENABLE | 0x0100;
    REG_DISPCNT = OBJ_MAP_1D | MODE2 | OBJ_ENABLE;

    // Set up sprites and palette

    fillPalette();
    fillSprites();

    // Set interrupt handler functions
    REG_INT = (int)&interruptsHandler;

    // choose which interrupt to enable.
    REG_IE |= INT_TIMER0 | INT_BUTTON | INT_TIMER1;
    REG_IME = 0x1; // Enable interrupt handling

    REG_TM0D = 0x8000;
    REG_TM0CNT |= TIMER_FREQUENCY_1024 | TIMER_INTERRUPTS | TIMER_ENABLE;

    REG_TM1D = 0x0;
    REG_TM1CNT |= TIMER_FREQUENCY_256 | TIMER_INTERRUPTS | TIMER_ENABLE;

    REG_P1CNT |= 0x7FFF;

    /** Activate game based on state 
     * by default -- STATE_START
    */
    while (1)
    {
        switch (GAME_STATE)
        {
        case STATE_START:
            renderStartPage();
            break;
        case STATE_PLAYING_L1:
            renderGamePlay_L1();
            break;
        }
    }
    return 0;
}

void renderStartPage()
{
    drawGameTitle();
    drawUserPrompt();
}

void renderGamePlay_L1()
{
    int i;

    InitViruses(&viruses);

    InitMasks(&masks);
    for (i = 0; i < MASKS_MAX; i++)
    {
        addMask(&masks);
    }

    drawSprite(PLAYER_SPRITE, PLAYER_ID, PLAYER_XPOS, PLAYER_YPOS);

    while (1)
    {
        drawViruses(&viruses);
        drawMasks(&masks);
        virusCollisionWithPlayer(&viruses);
        maskCollisionWithPlayer(&masks);

        if (PLAYER_COLLECTED_MASKS >= MASKS_MAX)
        {
            GAME_LEVEL = 2;
        }
        if (GAME_LEVEL == 2)
        {
            renderGamePlay_L2();
        }
    }
}

void renderGamePlay_L2()
{

    VIRUSES_MAX = 20;
    MASKS_MAX = 10;
    int i;

    Masks masks2;

    InitViruses(&viruses2);

    InitMasks(&masks2);
    for (i = 0; i <= MASKS_MAX; i++)
    {
        addMask(&masks2);
    }

    drawSprite(SPRITE_R_SMALL, PLAYER_ID, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

    while (1)
    {
        drawViruses(&viruses2);
        drawMasks(&masks2);
        virusCollisionWithPlayer(&viruses2);
        maskCollisionWithPlayer(&masks2);
    }
}
