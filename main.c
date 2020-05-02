// -----------------------------------------------------------------------------
// C-Skeleton to be used with HAM Library from www.ngine.de
// -----------------------------------------------------------------------------
// #include "numbers.h"
#include "gba.h"
#include "mygbalib.h"
#include "position.h"

#define STATE_JUST_LAUNCHED 0
#define STATE_START 1
#define STATE_PLAYING 2
#define STATE_END 3

int COUNTER_0 = 0;
int COUNTER_1 = 0;
int LOOP_COUNT = 0;

int IDENTITY = 0;
int id = 1;
int XPOS = 50;
int YPOS = SCREEN_HEIGHT / 2;

Viruses viruses;
Virus virus;
Player player;

void interruptsHandler(void)
{

    REG_IME = 0x00; // Stop all other interrupt handling, while we handle this current one

    // Adds a new virus every 1s
    if ((REG_IF & INT_TIMER0) == INT_TIMER0)
    {
        // addVirus(&viruses);
    }

    if ((REG_IF & INT_TIMER1) == INT_TIMER1)
    {
        updateVirusPosition(&viruses);
        addVirus(&viruses);
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
    REG_DISPCNT = OBJ_MAP_1D | MODE2 | OBJ_ENABLE;
    // REG_DISPCNT = MODE2 | OBJ_ENABLE;

    fillPalette();
    fillSprites();

    // Set Handler Function for interrupts
    REG_INT = (int)&interruptsHandler;

    // choose which interrupt to enable.
    REG_IE |= INT_TIMER0 | INT_BUTTON | INT_TIMER1;
    REG_IME = 0x1; // Enable interrupt handling

    // Interrupt every 5s
    REG_TM0D = 0x8000;
    REG_TM0CNT |= TIMER_FREQUENCY_1024 | TIMER_INTERRUPTS | TIMER_ENABLE;

    REG_TM1D = 0x0;
    REG_TM1CNT |= TIMER_FREQUENCY_256 | TIMER_INTERRUPTS | TIMER_ENABLE;

    REG_P1CNT |= 0x7FFF;

    if (LOOP_COUNT >= 100)
    {
        LOOP_COUNT = 0;
    }

    drawSprite(IDENTITY, id, XPOS, YPOS);

    InitViruses(&viruses);
    addVirus(&viruses);

    while (1)
    {
        drawViruses(&viruses);
    }
    return 0;
}


