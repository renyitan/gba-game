// -----------------------------------------------------------------------------
// C-Skeleton to be used with HAM Library from www.ngine.de
// -----------------------------------------------------------------------------
// #include "numbers.h"
#include "gba.h"
// #include "mygbalib.h"

#define SCREENBUFFER ((volatile u16 *)0x06000000)

// -----------------------------------------------------------------------------
// Project Entry Point
// -----------------------------------------------------------------------------

// write colour which isn't white
// [unused bit] BBB BBGG GGGR RRRR
inline u16 MakeCol(u8 red, u8 green, u8 blue)
{
    return red | green << 5 | blue << 10;
}

inline void vsync()
{
    while (REG_VCOUNT >= SCREEN_HEIGHT)
        ;
    while (REG_VCOUNT < SCREEN_HEIGHT)
        ;
}

void drawRect(int left, int top, int width, int height, u16 clr)
{
    int y, x;
    for (y = 0; y < height; ++y)
    {
        for (x = 0; x < width; ++x)
        {
            SCREENBUFFER[(top + y) * SCREEN_WIDTH + left + x] = clr;
        }
    }
}

int main(void)
{
    // Set Mode 3
    REG_DISPCNT = MODE3 | BG2_ENABLE;

    int i;
    for (i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; ++i)
    {
        SCREENBUFFER[i] = MakeCol(0, 0, 0);
    }

    int x = 0;
    while (1)
    {
        vsync();

        if (x > SCREEN_WIDTH * (SCREEN_WIDTH / 10))
            x = 0;
        if (x)
        {
            int last = x - 10;
            drawRect(last % SCREEN_WIDTH, (last / SCREEN_WIDTH) * 10, 10, 10, MakeCol(0, 0, 0));
        }

        drawRect(x % SCREEN_WIDTH, (x / SCREEN_WIDTH) * 10, 10, 10, MakeCol(31, 31, 31));
        x += 10;
    }

    return 0;
}
