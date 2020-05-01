// -----------------------------------------------------------------------------
// C-Skeleton to be used with HAM Library from www.ngine.de
// -----------------------------------------------------------------------------
#include "numbers.h"
#include "gba.h"
#include "mygbalib.h"

// Global variable for counter
int IDENTITY = 0;
int XPOS = 10;
int YPOS = SCREEN_HEIGHT / 2;

void Handler(void)
{
    REG_IME = 0x00; // Stop all other interrupt handling, while we handle this current one

    if ((REG_IF & INT_BUTTON) == INT_BUTTON)
    {
        checkbutton();
    }
    REG_IF = REG_IF; // Update interrupt table, to confirm we have handled this interrupt

    REG_IME = 0x01; // Re-enable interrupt handling
}

// -----------------------------------------------------------------------------
// Project Entry Point
// -----------------------------------------------------------------------------
int main(void)
{
    int i;

    // Set Mode 2
    *(unsigned short *)0x4000000 = 0x40 | 0x2 | 0x1000;

    // Fill SpritePal
    *(unsigned short *)0x5000200 = 0;
    *(unsigned short *)0x5000202 = RGB(31, 31, 31);

    // Fill SpriteData
    for (i = 0; i < 10 * 8 * 8 / 2; i++)
        spriteData[i] = (numbers[i * 2 + 1] << 8) + numbers[i * 2];

    // Set Handler Function for interrupts and enable selected interrupts
    REG_INT = (int)&Handler;
    REG_IE |= INT_BUTTON; // choose which interrupt to enable.S
    REG_P1CNT |= 0x7FFF;
    REG_IME = 0x1; // Enable interrupt handling

    drawSprite(IDENTITY, 1, XPOS, YPOS);

    while (1)
        ;

    return 0;
}
