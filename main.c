// -----------------------------------------------------------------------------
// C-Skeleton to be used with HAM Library from www.ngine.de
// -----------------------------------------------------------------------------
#include "numbers.h"
#include "gba.h"

#include "mygbalib.h"
#include "position.h"
#include "game.h"

// Global variable for counter
int IDENTITY = 0;
int XPOS = 10;
int YPOS = SCREEN_HEIGHT / 2;
int num = 1;

#define STATE_JUST_LAUNCHED 0
#define STATE_START 1
#define STATE_PLAYING 2
#define STATE_END 3

void interruptsHandler(void)
{
    REG_IME = 0x00; // Stop all other interrupt handling, while we handle this current one

    if ((REG_IF & INT_BUTTON) == INT_BUTTON)
    {
        checkMovementButtonInGame();
    }
    REG_IF = REG_IF; // Update interrupt table, to confirm we have handled this interrupt

    REG_IME = 0x01; // Re-enable interrupt handling
}

u8 AppState = STATE_JUST_LAUNCHED;

// -----------------------------------------------------------------------------
// Project Entry Point
// -----------------------------------------------------------------------------
int main(void)
{
    int i;


    // Set Mode 2
    // REG_DISPCNT = OBJ_MAP_1D | MODE2 | OBJ_ENABLE;
    REG_DISPCNT = MODE2 | OBJ_ENABLE;

    // Fill SpritePal
    *(unsigned short *)0x5000200 = 0;
    *(unsigned short *)0x5000202 = RGB(31, 31, 31);

    // Fill SpriteData
    for (i = 0; i < 10 * 8 * 8 / 2; i++)
        spriteData[i] = (numbers[i * 2 + 1] << 8) + numbers[i * 2];

    // Set Handler Function for interrupts and enable selected interrupts
    REG_INT = (int)&interruptsHandler;
    REG_IE |= INT_BUTTON; // choose which interrupt to enable.S

    REG_P1CNT |= 0x7FFF;
    REG_IME = 0x1; // Enable interrupt handling

    while (1)
    {
        renderGame();
    }

    return 0;
}
