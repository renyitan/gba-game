#include "mygbalib.h"
#include <time.h>

// intiate global game state properties
int GAME_STATE = STATE_START;
int GAME_LEVEL = 1;
int VIRUSES_MAX = VIRUS_TOTAL_L1;
int MASKS_MAX = MASKS_TOTAL_L1;

// Initialise global player propeties;
int PLAYER_SPRITE = 0;
int PLAYER_XPOS = 50;
int PLAYER_YPOS = SCREEN_HEIGHT / 2;
int PLAYER_LIFE_COUNTS = 1;
int PLAYER_COLLECTED_MASKS = 0;

// Declare viruses instances
Virus virus;
Mask mask;

Viruses viruses1;
Masks masks1;

Viruses viruses2;
Masks masks2;

// this is the assembly function from drawLevelTitle.s
extern void drawLevelTitle(int x, int y, int label);

void interruptsHandler(void)
{
    REG_IME = 0x00; // Stop all other interrupt handling, while we handle this current one

    if ((REG_IF & INT_TIMER0) == INT_TIMER0)
    {
              if (GAME_LEVEL == 1 && GAME_STATE != STATE_WIN)
        {
            updateVirusPosition(&viruses1);
            // addVirus(&viruses1, VIRUSES_MAX);
        }
        if (GAME_LEVEL == 2 && GAME_STATE != STATE_WIN)
        {
            updateVirusPosition(&viruses2);
            // addVirus(&viruses2, VIRUSES_MAX);
        }
    }


    // Timer for 1s
    if ((REG_IF & INT_TIMER1) == INT_TIMER1)
    {
        if (GAME_LEVEL == 1 && GAME_STATE != STATE_WIN)
        {
            // updateVirusPosition(&viruses1);
            addVirus(&viruses1, VIRUSES_MAX);
        }
        if (GAME_LEVEL == 2 && GAME_STATE != STATE_WIN)
        {
            // updateVirusPosition(&viruses2);
            addVirus(&viruses2, VIRUSES_MAX);
        }

        if (PLAYER_LIFE_COUNTS <= 0 || GAME_STATE == STATE_END)
        {
            removePlayer();
            // GAME_STATE = STATE_GAMEOVER;
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

            if (PLAYER_COLLECTED_MASKS > MASKS_TOTAL_L1 + MASKS_TOTAL_L2)
            {
                GAME_STATE = STATE_WIN;
                drawGameVictory();
            }
        }
        else
        {
            // clearScreen();
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
    REG_DISPCNT = OBJ_MAP_1D | MODE2 | OBJ_ENABLE;

    // Set up sprites and palette
    fillPalette();
    fillSprites();

    // Set interrupt handler functions
    REG_INT = (int)&interruptsHandler;

    // choose which interrupt to enable.
    REG_IE |= INT_TIMER0 | INT_BUTTON | INT_TIMER1;
    REG_IME = 0x1; // Enable interrupt handling

    REG_TM0D = 0xFDDD;
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
        case STATE_PLAYING:
            renderGamePlay_L1();
            break;
        }
    }
    return 0;
}

/*
 * Render function for game splash screen / menu
*/
void renderStartPage()
{
    drawGameTitle();
    drawUserPrompt();
}

/**
 * Render function for Level 1
 */
void renderGamePlay_L1()
{
    int i;

    InitViruses(&viruses1);

    InitMasks(&masks1);
    for (i = 0; i < MASKS_MAX; i++)
    {
        addMask(&masks1);
    }

    drawSprite(PLAYER_SPRITE, PLAYER_ID, PLAYER_XPOS, PLAYER_YPOS);

    while (1)
    {
        drawLevelTitle(0, SCREEN_HEIGHT - 16, LEVEL_TITLE_ID);
        drawViruses(&viruses1);
        drawMasks(&masks1);
        virusCollisionWithPlayer(&viruses1);
        maskCollisionWithPlayer(&masks1);

        if (PLAYER_COLLECTED_MASKS >= MASKS_MAX && GAME_STATE == STATE_PLAYING)
        {
            GAME_LEVEL = 2;
        }
        if (GAME_LEVEL == 2 && GAME_STATE == STATE_PLAYING)
        {
            renderGamePlay_L2();
        }

        if (PLAYER_LIFE_COUNTS <= 0 && GAME_STATE != STATE_WIN)
        {
            GAME_STATE = STATE_END;
            drawGameOver();
            break;
        }
    }
}

/**
 * Render function for Level 2
 */
void renderGamePlay_L2()
{
    int i;
    VIRUSES_MAX = VIRUS_TOTAL_L2;
    MASKS_MAX = MASKS_TOTAL_L2;

    InitViruses(&viruses2);

    InitMasks(&masks2);
    for (i = 0; i <= MASKS_MAX; i++)
    {
        addMask(&masks2);
    }

    // Updates the game level sprite: 1->2
    drawSprite(SPRITE_TWO_SMALL, LEVEL_TITLE_ID + 5, 86, SCREEN_HEIGHT - 16);

    while (1)
    {
        drawViruses(&viruses2);
        drawMasks(&masks2);
        virusCollisionWithPlayer(&viruses2);
        maskCollisionWithPlayer(&masks2);

        if (PLAYER_LIFE_COUNTS <= 0 && GAME_STATE != STATE_WIN)
        {
            GAME_STATE = STATE_END;
            drawGameOver();
            break;
        }
    }
}

