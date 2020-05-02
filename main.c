// -----------------------------------------------------------------------------
// C-Skeleton to be used with HAM Library from www.ngine.de
// -----------------------------------------------------------------------------
// #include "numbers.h"
#include "gba.h"
#include "mygbalib.h"
#include "position.h"
// #include "virus.h"

// Global variable for counter
int IDENTITY = 0;
int XPOS = 10;
int YPOS = SCREEN_HEIGHT / 2;
int num = 1;

#define STATE_JUST_LAUNCHED 0
#define STATE_START 1
#define STATE_PLAYING 2
#define STATE_END 3

int COUNTER_0 = 0;
int COUNTER_1 = 0;
int LOOP_COUNT = 0;

Viruses viruses;
Virus virus;

// Viruses viruses[] = {
//     {.id = 2, .xPos = 40, .yPos = 120, .xVel = 0, .yVel = 0},
//     {.id = 3, .xPos = 70, .yPos = 30, .xVel = 0, .yVel = 0}};

void interruptsHandler(void)
{

    REG_IME = 0x00; // Stop all other interrupt handling, while we handle this current one

    if ((REG_IF & INT_TIMER0) == INT_TIMER0)
    {
        if (COUNTER_0 % 2 == 0)
        {
            // drawSprite(3, 2, COUNTER_0 + 5, COUNTER_0 + 5);
            addVirus(&viruses);
        }
        COUNTER_0++;
    }

    if ((REG_IF & INT_BUTTON) == INT_BUTTON)
    {
        checkMovementButtonInGame();
    }

    // Update interrupt table, to confirm we have handled this interrupt
    REG_IF = REG_IF;
    REG_IME = 0x01; // Re-enable interrupt handling
}

// -----------------------------------------------------------------------------
// Project Entry Point
// -----------------------------------------------------------------------------
int main(void)
{
    int i;
    // Set Mode 2
    REG_DISPCNT = OBJ_MAP_1D | MODE2 | OBJ_ENABLE;
    // REG_DISPCNT = MODE2 | OBJ_ENABLE;

    // Fill SpritePal
    // *(unsigned short *)0x5000200 = 0;
    // *(unsigned short *)0x5000202 = RGB(31, 31, 31);

    fillPalette();
    fillSprites();

    // Set Handler Function for interrupts
    REG_INT = (int)&interruptsHandler;

    // choose which interrupt to enable.
    REG_IE |= INT_TIMER0 | INT_BUTTON | INT_TIMER1;
    REG_IME = 0x1; // Enable interrupt handling

    REG_TM0D = 0x8000;
    REG_TM0CNT |= TIMER_FREQUENCY_256 | TIMER_INTERRUPTS | TIMER_ENABLE;

    REG_TM1D = 0x0;
    REG_TM1CNT |= TIMER_FREQUENCY_1024 | TIMER_INTERRUPTS | TIMER_ENABLE;

    REG_P1CNT |= 0x7FFF;

    if (LOOP_COUNT >= 100)
    {
        LOOP_COUNT = 0;
    }

    drawSprite(IDENTITY, num, XPOS, YPOS);

    InitViruses(&viruses);

    addVirus(&viruses);
    // addVirus(&viruses);
    // addVirus(&viruses);
    // addVirus(&viruses);
    // addVirus(&viruses);
    // addVirus(&viruses);
    // addVirus(&viruses);
    // addVirus(&viruses);
    // addVirus(&viruses);

    while (1)
    {
        // renderGame();
        drawViruses(&viruses);
    }
    return 0;
}
