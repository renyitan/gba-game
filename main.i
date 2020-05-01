# 1 "main.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "main.c"




# 1 "gba.h" 1







typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

typedef unsigned char byte;
typedef unsigned short hword;
typedef unsigned int word;
# 211 "gba.h"
enum
{
    VBLANK_HANDLER,
    HBLANK_HANDLER,
    VCOUNT_HANDLER,
    TIMER0_HANDLER,
    TIMER1_HANDLER,
    TIMER2_HANDLER,
    TIMER3_HANDLER,
    SERIAL_COM_HANDLER,
    DMA0_HANDLER,
    DMA1_HANDLER,
    DMA2_HANDLER,
    DMA3_HANDLER,
    KEYS_HANDLER,
    CART_HANDLER,
    MAX_INTERRUPT_HANDLERS,
};
# 267 "gba.h"
typedef void (*fp)(void);
# 6 "main.c" 2
# 16 "main.c"
inline u16 MakeCol(u8 red, u8 green, u8 blue)
{
    return red | green << 5 | blue << 10;
}

inline void vsync()
{
    while (*(volatile u16*)0x4000006 >= 160)
        ;
    while (*(volatile u16*)0x4000006 < 160)
        ;
}

void drawRect(int left, int top, int width, int height, u16 clr)
{
    int y, x;
    for (y = 0; y < height; ++y)
    {
        for (x = 0; x < width; ++x)
        {
            ((volatile u16 *)0x06000000)[(top + y) * 240 + left + x] = clr;
        }
    }
}

int main(void)
{

    *(u32*)0x4000000 = 0x3 | 0x400;

    int i;
    for (i = 0; i < 240 * 160; ++i)
    {
        ((volatile u16 *)0x06000000)[i] = MakeCol(0, 0, 0);
    }

    int x = 0;
    while (1)
    {
        vsync();

        if (x > 240 * (240 / 10))
            x = 0;
        if (x)
        {
            int last = x - 10;
            drawRect(last % 240, (last / 240) * 10, 10, 10, MakeCol(0, 0, 0));
        }

        drawRect(x % 240, (x / 240) * 10, 10, 10, MakeCol(31, 31, 31));
        x += 10;
    }

    return 0;
}
