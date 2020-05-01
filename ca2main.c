// -----------------------------------------------------------------------------
// C-Skeleton to be used with HAM Library from www.ngine.de
// -----------------------------------------------------------------------------
#include "numbers.h"
#include "gba.h"

// Global variable for counter
int COUNTER_NUM = 0;


void drawSprite(int numb, int N, int x, int y)
{
    // Gift function: displays sprite number numb on screen at position (x,y), as sprite object N
    *(unsigned short *)(0x7000000 + 8 * N) = y | 0x2000;
    *(unsigned short *)(0x7000002 + 8 * N) = x;
    *(unsigned short *)(0x7000004 + 8 * N) = numb * 2;
}

void Handler(void)
{
    
    REG_IME = 0x00; // Stop all other interrupt handling, while we handle this current one

    if ((REG_IF & INT_TIMER0) == INT_TIMER0) // handling INT_TIMER0 interrupt
    {
        // screen width/2 -4 is for offset of the sprites to centralise them

        drawSprite(((COUNTER_NUM / 10) % 10), 2, SCREEN_WIDTH / 2 - 4, SCREEN_HEIGHT / 2); // sprite for the ten's digit positions
        // drawSprite((COUNTER_NUM % 10), 1, SCREEN_WIDTH / 2 + 4, SCREEN_HEIGHT / 2);        // sprite for the one's digit positions
        COUNTER_NUM++;
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
    REG_IE |= INT_TIMER0; // choose which interrupt to enable.S
    REG_IME = 0x1;        // Enable interrupt handling

    // Set Timer Mode (fill that section and replace TMX with selected timer number)
    REG_TM0D = 0; // initial counter value of -16384, return to this value when counter overflows.
    REG_TM0CNT |= TIMER_FREQUENCY_256 | TIMER_INTERRUPTS | TIMER_ENABLE;

    // reset to 0 once counter reaches 99
    if (COUNTER_NUM >= 100)
    {
        COUNTER_NUM = 0;
    }

    while (1)
        ;

    return 0;
}
