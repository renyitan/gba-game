// -----------------------------------------------------------------------------
// C-Skeleton to be used with HAM Library from www.ngine.de
// -----------------------------------------------------------------------------
// #include "numbers.h"
// #include "gba.h"
// #include "mygbalib.h"

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

#define SCREENBUFFER ((volatile uint16 *)0x06000000)
#define REG_DISPLAYCONTROL *((volatile uint32 *)(0x04000000))
#define VIDEOMODE_3 0x0003
#define BGMODE_2 0x0400

#define SCREENBUFFER ((volatile uint16 *)0x06000000)
#define SCREEN_W 240
#define SCREEN_H 160

// -----------------------------------------------------------------------------
// Project Entry Point
// -----------------------------------------------------------------------------
int main(void)
{
    // Set Mode 3
    REG_DISPLAYCONTROL = VIDEOMODE_3 | BGMODE_2;

    // Fill SpritePal
    // *(unsigned short *)0x5000200 = 0;
    // *(unsigned short *)0x5000202 = RGB(31, 31, 31);

    // Fill SpriteData
    // for (i = 0; i < 10 * 8 * 8 / 2; i++)
    //     spriteData[i] = (numbers[i * 2 + 1] << 8) + numbers[i * 2];

    int i;
    for (i = 0; i < SCREEN_W * SCREEN_H; ++i)
    {
        SCREENBUFFER[i] = 0xFFFF;
    }

    while (1)
        ;

    return 0;
}
