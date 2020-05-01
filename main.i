# 1 "main.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "main.c"



# 1 "numbers.h" 1
# 14 "numbers.h"
unsigned short numbers[] = {

    0,0,1,1,1,1,0,0,
    0,1,1,0,0,0,1,0,
    0,1,1,0,0,1,1,0,
    0,1,1,0,1,0,1,0,
    0,1,1,1,0,0,1,0,
    0,1,1,0,0,0,1,0,
    0,1,1,0,0,0,1,0,
    0,0,1,1,1,1,0,0,

    0,0,0,0,1,0,0,0,
    0,0,1,1,1,0,0,0,
    0,0,0,1,1,0,0,0,
    0,0,0,1,1,0,0,0,
    0,0,0,1,1,0,0,0,
    0,0,0,1,1,0,0,0,
    0,0,0,1,1,0,0,0,
    0,0,1,1,1,1,0,0,

    0,0,1,1,1,1,0,0,
    0,1,1,1,1,1,1,0,
    0,1,0,0,0,0,1,0,
    0,0,0,0,0,1,1,0,
    0,0,0,0,1,1,0,0,
    0,0,0,1,1,0,0,0,
    0,0,1,1,0,0,0,0,
    0,1,1,1,1,1,1,0,

    0,0,1,1,1,1,0,0,
    0,1,1,1,1,1,1,0,
    0,1,0,0,0,0,1,0,
    0,0,0,0,0,0,1,0,
    0,0,0,1,1,1,0,0,
    0,0,0,0,0,0,1,0,
    0,1,0,0,0,0,1,0,
    0,0,1,1,1,1,0,0,

    0,0,0,0,1,1,0,0,
    0,0,0,1,1,1,0,0,
    0,0,1,1,0,1,0,0,
    0,1,1,0,0,1,0,0,
    0,1,1,1,1,1,0,0,
    0,0,0,0,1,1,0,0,
    0,0,0,0,1,1,0,0,
    0,0,0,0,1,1,0,0,

    0,1,1,1,1,1,1,0,
    0,1,1,1,1,1,1,0,
    0,1,1,0,0,0,0,0,
    0,1,1,0,0,0,0,0,
    0,0,1,1,1,1,0,0,
    0,0,0,0,0,0,1,0,
    0,1,0,0,0,0,1,0,
    0,0,1,1,1,1,0,0,

    0,0,0,1,1,1,1,0,
    0,0,1,1,1,1,1,0,
    0,1,1,0,0,0,0,0,
    0,1,1,0,0,0,0,0,
    0,1,1,1,1,1,0,0,
    0,1,1,0,0,0,1,0,
    0,1,1,0,0,0,1,0,
    0,0,1,1,1,1,0,0,

    0,1,1,1,1,1,1,0,
    0,1,1,1,1,1,1,0,
    0,1,0,0,0,1,1,0,
    0,0,0,0,1,1,0,0,
    0,0,0,0,1,1,0,0,
    0,0,0,1,1,0,0,0,
    0,0,0,1,1,0,0,0,
    0,0,1,1,0,0,0,0,

    0,0,1,1,1,1,0,0,
    0,1,1,1,1,1,1,0,
    0,1,1,0,0,0,1,0,
    0,0,1,0,0,0,1,0,
    0,0,1,1,1,1,0,0,
    0,1,1,0,0,0,1,0,
    0,1,1,0,0,0,1,0,
    0,0,1,1,1,1,0,0,

    0,0,1,1,1,1,0,0,
    0,1,1,1,1,1,1,0,
    0,1,1,0,0,0,1,0,
    0,1,1,0,0,0,1,0,
    0,0,1,1,1,1,1,0,
    0,0,0,0,0,1,1,0,
    0,0,0,0,0,1,1,0,
    0,0,0,0,0,1,1,0,
};
# 5 "main.c" 2
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

# 1 "mygbalib.h" 1
# 1 "sprites.h" 1





int palette[] = {
((0) + (0<<5) + (0<<10)),
((31) + (31<<5) + (31<<10)),
((0) + (31<<5) + (31<<10)),
((26) + (26<<5) + (26<<10)),
((9) + (9<<5) + (9<<10)),
((31) + (31<<5) + (0<<10)),
((31) + (0<<5) + (0<<10)),
((0) + (0<<5) + (31<<10)),
((11) + (8<<5) + (3<<10)),
((27) + (27<<5) + (27<<10)),
((16) + (16<<5) + (16<<10)),
((31) + (17<<5) + (17<<10)),
((31) + (24<<5) + (24<<10)),
((27) + (0<<5) + (0<<10)),
((0) + (16<<5) + (0<<10)),
((0) + (31<<5) + (0<<10)),
((16) + (31<<5) + (16<<10)),
((23) + (31<<5) + (23<<10))
};




u16 sprites[] = {


0,0,0,0,0,0,1,1,
0,0,0,0,0,1,1,2,
0,0,0,0,0,1,2,2,
0,0,0,3,0,0,1,1,
0,0,3,3,3,1,1,1,
0,0,3,3,3,1,1,1,
0,0,3,3,3,1,1,1,
0,4,3,4,3,1,1,1,

1,0,0,0,0,0,0,0,
2,0,0,0,0,0,0,0,
2,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,1,1,3,0,0,0,0,
0,0,0,0,0,0,0,0,

0,4,3,4,3,1,1,1,
0,0,0,0,0,1,1,1,
0,0,0,0,0,1,1,0,
0,0,0,0,0,1,1,0,
0,0,0,0,0,1,1,0,
0,0,0,0,0,1,1,0,
0,0,0,0,0,1,1,0,
0,0,0,0,0,3,1,1,

0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,



0,0,0,0,0,0,1,1,
0,0,0,0,0,1,1,2,
0,0,0,0,0,1,2,2,
0,0,0,3,0,0,1,1,
0,0,3,3,3,1,1,1,
0,0,3,3,3,1,1,1,
0,0,3,3,3,1,1,1,
0,4,3,4,3,1,1,1,

1,0,0,0,0,0,0,0,
2,0,0,0,0,0,0,0,
2,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,1,1,3,0,0,0,0,
0,0,0,0,0,0,0,0,

0,4,3,4,3,1,1,1,
0,0,5,6,5,1,1,1,
0,0,5,6,5,1,1,0,
0,0,0,5,0,1,1,0,
0,0,0,5,0,1,1,0,
0,0,0,0,0,1,1,0,
0,0,0,0,0,1,1,0,
0,0,0,0,0,3,1,1,

0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,



0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,2,
0,0,0,0,0,0,0,2,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,1,
0,0,0,0,3,1,1,1,
0,0,0,0,0,0,0,0,

1,1,0,0,0,0,0,0,
2,1,1,0,0,0,0,0,
2,2,1,0,0,0,0,0,
1,1,0,0,3,0,0,0,
1,1,1,3,3,3,0,0,
1,1,1,3,3,3,0,0,
1,1,1,3,3,3,0,0,
1,1,1,3,4,3,4,0,

0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,

1,1,1,3,4,3,4,0,
1,1,1,0,0,0,0,0,
0,1,1,0,0,0,0,0,
0,1,1,0,0,0,0,0,
0,1,1,0,0,0,0,0,
0,1,1,0,0,0,0,0,
0,1,1,0,0,0,0,0,
1,1,3,0,0,0,0,0,



0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,2,
0,0,0,0,0,0,0,2,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,1,
0,0,0,0,3,1,1,1,
0,0,0,0,0,0,0,0,

1,1,0,0,0,0,0,0,
2,1,1,0,0,0,0,0,
2,2,1,0,0,0,0,0,
1,1,0,0,3,0,0,0,
1,1,1,3,3,3,0,0,
1,1,1,3,3,3,0,0,
1,1,1,3,3,3,0,0,
1,1,1,3,4,3,4,0,

0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,

1,1,1,3,4,3,4,0,
1,1,1,5,6,5,0,0,
0,1,1,5,6,5,0,0,
0,1,1,0,5,0,0,0,
0,1,1,0,5,0,0,0,
0,1,1,0,0,0,0,0,
0,1,1,0,0,0,0,0,
1,1,3,0,0,0,0,0,



1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,


1,1,1,1,1,1,1,1,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,


1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,1,1,1,1,1,1,1,


0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
1,1,1,1,1,1,1,1,




1,1,1,1,1,1,1,1,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,


1,1,1,1,1,1,1,1,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,


0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
1,1,1,1,1,1,1,1,


0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
1,1,1,1,1,1,1,1,




1,1,1,1,1,1,1,1,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,


1,1,1,1,1,1,1,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,


0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
1,1,1,1,1,1,1,1,


0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
1,1,1,1,1,1,1,1,



1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,


1,1,1,1,1,1,1,1,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,


1,1,1,1,1,1,1,1,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,


1,1,1,1,1,1,1,1,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,




1,1,1,1,1,1,1,1,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,


1,1,1,1,1,1,1,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,


1,1,1,1,1,1,1,1,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,


1,1,1,1,1,1,1,1,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,




0,0,0,0,0,0,0,0,
0,0,0,6,6,6,0,0,
0,0,6,12,12,11,6,0,
0,6,12,11,11,6,6,6,
0,6,12,11,6,6,6,6,
0,6,12,11,6,6,6,6,
0,0,6,12,11,6,6,6,
0,0,0,6,12,11,6,6,


0,0,0,0,0,0,0,0,
0,0,6,6,6,0,0,0,
0,6,12,12,11,6,0,0,
6,12,11,6,6,6,6,0,
6,11,11,6,6,6,6,0,
6,6,6,6,6,6,6,0,
6,6,6,6,6,6,0,0,
6,6,6,6,6,0,0,0,


0,0,0,6,12,11,6,6,
0,0,0,0,6,12,6,6,
0,0,0,0,6,12,11,6,
0,0,0,0,0,6,11,6,
0,0,0,0,0,0,6,6,
0,0,0,0,0,0,6,6,
0,0,0,0,0,0,0,6,
0,0,0,0,0,0,0,0,



6,6,6,6,6,0,0,0,
6,6,6,6,0,0,0,0,
6,6,6,0,0,0,0,0,
6,6,6,0,0,0,0,0,
6,6,0,0,0,0,0,0,
6,6,0,0,0,0,0,0,
6,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,




0,0,0,0,0,0,0,0,
0,0,0,3,3,3,0,0,
0,0,3,4,4,10,3,0,
0,3,4,10,10,3,3,3,
0,3,4,10,3,3,3,3,
0,3,4,10,3,3,3,3,
0,0,3,4,10,3,3,3,
0,0,0,3,4,10,3,3,


0,0,0,0,0,0,0,0,
0,0,3,3,3,0,0,0,
0,3,4,4,10,3,0,0,
3,4,10,3,3,3,3,0,
3,10,10,3,3,3,3,0,
3,3,3,3,3,3,3,0,
3,3,3,3,3,3,0,0,
3,3,3,3,3,0,0,0,


0,0,0,3,4,10,3,3,
0,0,0,0,3,4,3,3,
0,0,0,0,3,4,10,3,
0,0,0,0,0,3,10,3,
0,0,0,0,0,0,3,3,
0,0,0,0,0,0,3,3,
0,0,0,0,0,0,0,3,
0,0,0,0,0,0,0,0,



3,3,3,3,3,0,0,0,
3,3,3,3,0,0,0,0,
3,3,3,0,0,0,0,0,
3,3,3,0,0,0,0,0,
3,3,0,0,0,0,0,0,
3,3,0,0,0,0,0,0,
3,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,




0,0,0,0,0,0,0,0,
0,0,0,14,14,15,0,0,
0,0,14,15,15,17,15,0,
0,14,15,17,15,17,17,15,
0,14,15,15,17,17,17,17,
0,14,15,17,15,17,17,17,
0,14,15,17,17,17,17,17,
0,14,15,15,15,17,17,17,


0,0,0,0,0,0,0,0,
0,0,16,16,16,0,0,0,
0,16,16,17,16,16,0,0,
15,16,17,16,17,16,16,0,
17,17,17,16,17,16,16,0,
17,17,17,17,16,17,16,0,
17,17,17,17,17,16,16,0,
17,17,17,17,16,17,16,0,


0,0,14,15,17,15,17,17,
0,0,0,14,15,15,15,17,
0,0,0,0,14,15,17,15,
0,0,0,0,0,14,15,15,
0,0,0,0,0,0,14,15,
0,0,0,0,0,0,0,14,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,


17,17,17,16,17,16,0,0,
17,17,16,17,16,0,0,0,
17,16,17,16,0,0,0,0,
16,17,16,0,0,0,0,0,
17,16,0,0,0,0,0,0,
16,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,




0,0,0,0,0,6,6,6,
0,0,0,0,0,6,6,6,
0,0,0,0,13,6,6,13,
0,0,0,13,13,13,6,13,
0,0,0,13,13,13,6,13,
0,0,13,13,13,13,6,13,
0,0,13,13,13,13,6,13,
0,6,13,13,13,0,0,13,


6,6,6,0,0,0,0,0,
6,6,6,0,0,0,0,0,
13,6,6,13,0,0,0,0,
13,6,13,13,13,0,0,0,
13,6,13,13,13,0,0,0,
13,6,13,13,13,13,0,0,
13,6,13,13,13,13,0,0,
13,0,0,13,13,13,6,0,


0,6,13,13,0,0,0,13,
0,6,6,13,0,0,0,13,
0,6,6,13,0,0,0,6,
0,6,6,13,0,0,0,6,
6,6,6,6,0,0,6,6,
6,6,6,6,0,0,6,6,
6,6,6,6,0,0,6,6,
0,6,6,0,0,0,0,6,


13,0,0,13,13,13,6,0,
6,0,0,0,13,6,6,0,
6,0,0,0,13,6,6,0,
6,0,0,0,13,6,6,0,
6,6,0,0,6,6,6,6,
6,6,0,0,6,6,6,6,
6,6,0,0,6,6,6,6,
6,0,0,0,0,6,6,0,




0,0,0,1,1,1,6,6,
0,0,0,1,1,1,6,6,
0,0,0,1,1,1,6,6,
0,0,0,1,1,1,6,6,
0,0,0,1,1,1,6,6,
0,0,0,6,6,6,1,1,
0,0,0,6,6,6,1,1,
0,0,0,0,6,6,1,1,


6,1,1,1,6,0,0,0,
6,1,1,1,6,0,0,0,
6,1,1,1,6,0,0,0,
6,1,1,1,6,0,0,0,
6,1,1,1,6,0,0,0,
1,6,6,6,6,0,0,0,
1,6,6,6,6,0,0,0,
1,6,6,6,0,0,0,0,


0,0,0,0,6,6,1,1,
0,0,0,0,6,6,1,1,
0,0,0,0,1,1,6,6,
0,0,0,0,0,1,6,6,
0,0,0,0,0,1,6,6,
0,0,0,0,0,1,6,6,
0,0,0,0,0,1,6,6,
0,0,0,0,0,6,6,6,


1,6,6,6,0,0,0,0,
1,6,6,6,0,0,0,0,
6,1,1,1,0,0,0,0,
6,1,1,0,0,0,0,0,
6,1,1,0,0,0,0,0,
6,1,1,0,0,0,0,0,
6,1,1,0,0,0,0,0,
6,6,6,0,0,0,0,0,




0,0,0,0,0,0,0,6,
0,0,0,0,0,0,6,6,
0,0,0,0,0,0,6,6,
0,0,0,0,0,6,6,6,
0,0,0,0,0,6,6,6,
0,0,0,0,0,6,6,6,
0,0,0,0,0,1,6,6,
0,0,0,0,1,1,6,6,


6,0,0,0,0,0,0,0,
6,6,0,0,0,0,0,0,
6,6,0,0,0,0,0,0,
6,6,6,0,0,0,0,0,
6,6,6,0,0,0,0,0,
6,6,6,0,0,0,0,0,
6,1,1,0,0,0,0,0,
6,1,1,1,0,0,0,0,


0,0,0,0,1,1,6,6,
0,0,0,0,1,1,6,6,
0,0,0,0,1,1,6,6,
0,0,0,0,6,6,1,1,
0,0,0,6,6,6,1,1,
0,0,0,6,6,6,1,1,
0,0,0,6,6,6,1,1,
0,0,0,6,6,6,1,1,


6,1,1,1,0,0,0,0,
6,1,1,1,0,0,0,0,
6,1,1,1,0,0,0,0,
1,6,6,6,0,0,0,0,
1,6,6,6,6,0,0,0,
1,6,6,6,6,0,0,0,
1,6,6,6,6,0,0,0,
1,6,6,6,6,0,0,0,




0,0,1,1,7,7,7,1,
0,0,1,1,7,7,7,1,
0,0,6,1,7,7,7,1,
0,0,6,1,7,7,7,1,
0,0,1,1,7,7,7,1,
0,0,3,1,7,7,7,3,
0,4,1,3,7,7,7,3,
0,4,1,3,7,7,4,1,


1,1,1,7,7,7,0,0,
6,1,1,7,7,7,0,0,
6,6,1,7,7,7,0,0,
6,6,1,7,7,7,0,0,
1,1,1,7,7,7,0,0,
1,1,1,7,7,3,0,0,
3,1,1,7,4,1,3,0,
1,3,1,7,4,1,3,0,


0,4,4,1,3,7,4,1,
1,1,4,1,3,7,4,1,
1,1,1,4,3,7,4,1,
0,4,4,4,0,0,4,4,
0,0,0,8,0,0,0,8,
0,0,8,8,0,0,0,8,
0,8,8,8,8,0,8,8,
0,8,8,8,8,0,8,8,


1,3,1,4,1,4,3,0,
1,3,1,4,1,4,1,3,
1,3,1,4,4,1,1,3,
4,4,0,0,4,4,4,0,
8,0,0,0,8,0,0,0,
8,0,0,0,8,8,0,0,
8,8,0,8,8,8,8,0,
8,8,0,8,8,8,8,0,




0,0,3,3,3,3,3,3,
0,0,1,1,3,1,1,1,
0,0,1,1,3,1,1,1,
0,0,3,3,3,3,3,3,
0,0,1,1,3,1,1,1,
0,0,7,7,7,7,7,7,
0,0,7,7,7,7,7,7,
0,0,1,1,7,7,7,1,


3,3,3,3,3,3,0,0,
1,1,1,1,1,1,0,0,
1,1,1,1,1,1,0,0,
3,3,3,3,3,3,0,0,
1,1,1,1,1,1,0,0,
7,7,7,7,7,7,0,0,
7,7,7,7,7,7,0,0,
1,1,1,7,7,7,0,0,


0,0,1,1,7,7,7,1,
0,0,6,1,7,7,7,1,
0,0,6,1,7,7,7,1,
0,0,6,1,7,7,7,1,
0,0,1,1,7,7,7,1,
0,0,6,1,7,7,7,1,
0,0,6,1,7,7,7,1,
0,0,6,1,7,7,7,1,


1,1,1,7,7,7,0,0,
6,6,1,7,7,7,0,0,
6,6,1,7,7,7,0,0,
6,6,1,7,7,7,0,0,
1,1,1,7,7,7,0,0,
6,6,1,7,7,7,0,0,
6,6,1,7,7,7,0,0,
1,6,1,7,7,7,0,0,




0,0,7,7,7,7,7,7,
0,0,7,7,7,7,7,7,
0,0,1,1,7,7,7,1,
0,0,1,1,7,7,7,1,
0,0,6,1,7,7,7,1,
0,0,6,1,7,7,7,1,
0,0,6,1,7,7,7,1,
0,0,1,1,7,7,7,1,


7,7,7,7,7,7,0,0,
7,7,7,7,7,7,0,0,
1,1,1,7,7,7,0,0,
1,1,1,7,7,7,0,0,
6,6,1,7,7,7,0,0,
6,6,1,7,7,7,0,0,
6,6,1,7,7,7,0,0,
1,1,1,7,7,7,0,0,


0,0,6,1,7,7,7,1,
0,0,6,1,7,7,7,1,
0,0,1,1,3,1,1,1,
0,0,1,1,3,1,1,1,
0,0,3,3,3,3,3,3,
0,0,6,1,3,1,1,7,
0,0,1,1,3,1,1,7,
0,0,6,1,3,1,1,6,


6,6,1,7,7,7,0,0,
6,6,1,7,7,7,0,0,
1,1,1,1,1,1,0,0,
1,1,1,1,1,1,0,0,
3,3,3,3,3,3,0,0,
7,6,6,1,1,1,0,0,
7,1,1,1,1,1,0,0,
6,6,6,1,1,1,0,0,




0,0,1,1,1,1,1,1,
0,0,1,1,1,6,1,1,
0,0,1,1,1,1,1,1,
0,0,1,1,1,1,1,1,
0,0,1,1,1,6,1,1,
0,0,3,3,3,6,3,3,
0,0,1,1,1,1,1,1,
0,0,1,1,1,6,1,1,


1,1,1,1,1,1,0,0,
1,1,1,6,1,1,0,0,
1,1,1,1,1,1,0,0,
1,1,1,1,1,1,0,0,
1,1,1,6,1,1,0,0,
3,3,3,6,3,3,0,0,
1,1,1,1,1,1,0,0,
1,1,1,6,1,1,0,0,


0,0,1,1,1,1,1,1,
0,0,1,1,1,6,1,1,
0,0,1,1,1,6,1,1,
0,0,1,1,1,1,1,1,
0,0,1,1,1,6,1,1,
0,0,3,3,3,3,3,3,
0,0,1,3,1,3,1,3,
0,0,1,3,1,3,1,3,


1,1,1,1,1,1,0,0,
1,1,1,6,1,1,0,0,
1,1,1,6,1,1,0,0,
1,1,1,1,1,1,0,0,
1,1,1,6,1,1,0,0,
3,3,3,3,3,3,0,0,
1,3,1,3,1,3,0,0,
1,3,1,3,1,3,0,0,




0,0,0,0,3,3,3,3,
0,0,0,0,1,1,1,1,
0,0,0,0,1,1,3,1,
0,0,0,0,1,1,1,1,
0,0,0,0,1,1,1,1,
0,0,0,0,1,1,1,1,
0,0,0,0,1,1,1,1,
0,0,0,0,3,1,3,1,


3,3,3,3,0,0,0,0,
1,1,1,1,0,0,0,0,
1,1,3,1,0,0,0,0,
1,1,3,1,0,0,0,0,
1,1,3,1,0,0,0,0,
1,1,3,1,0,0,0,0,
1,1,1,1,0,0,0,0,
3,1,3,1,0,0,0,0,


0,0,0,0,3,3,3,7,
0,0,0,0,1,3,1,7,
0,0,0,0,1,3,1,7,
0,0,0,1,3,1,7,7,
0,0,0,1,3,1,7,7,
0,0,1,3,1,7,7,7,
0,0,1,3,1,7,7,7,
0,0,3,3,3,7,7,7,


7,7,7,7,0,0,0,0,
7,7,7,7,0,0,0,0,
7,7,7,7,0,0,0,0,
7,7,7,1,3,0,0,0,
7,7,7,1,3,0,0,0,
7,7,7,7,1,3,0,0,
7,7,0,7,1,3,0,0,
7,7,7,7,3,3,0,0,




0,0,0,0,0,0,1,1,
0,0,0,0,0,0,1,1,
0,0,0,0,0,0,1,1,
0,0,0,0,0,0,1,1,
0,0,0,0,0,0,1,1,
0,0,0,0,0,1,1,1,
0,0,0,0,0,1,1,1,
0,0,0,0,0,1,1,1,


3,1,0,0,0,0,0,0,
3,1,0,0,0,0,0,0,
3,1,0,0,0,0,0,0,
3,1,0,0,0,0,0,0,
3,1,0,0,0,0,0,0,
1,3,1,0,0,0,0,0,
1,3,1,0,0,0,0,0,
1,3,1,0,0,0,0,0,


0,0,0,0,0,1,1,1,
0,0,0,0,0,1,1,1,
0,0,0,0,0,1,1,1,
0,0,0,0,3,3,3,3,
0,0,0,0,7,7,7,7,
0,0,0,0,7,7,7,7,
0,0,0,0,3,1,3,1,
0,0,0,0,3,1,3,1,


1,3,1,0,0,0,0,0,
1,3,1,0,0,0,0,0,
1,3,1,0,0,0,0,0,
3,3,3,3,0,0,0,0,
7,7,7,7,0,0,0,0,
7,7,7,7,0,0,0,0,
3,1,3,1,0,0,0,0,
3,1,3,1,0,0,0,0,




0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,3,
0,0,0,0,0,0,0,3,
0,0,0,0,0,0,0,3,
0,0,0,0,0,0,0,3,
0,0,0,0,0,0,0,3,
0,0,0,0,0,0,0,1,


0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
3,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,


0,0,0,0,0,0,1,4,
0,0,0,0,0,0,1,1,
0,0,0,0,0,0,3,3,
0,0,0,0,0,0,3,4,
0,0,0,0,0,0,3,3,
0,0,0,0,0,0,3,3,
0,0,0,0,0,0,4,3,
0,0,0,0,0,0,1,1,


1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
4,3,0,0,0,0,0,0,
4,3,0,0,0,0,0,0,
4,3,0,0,0,0,0,0,
4,3,0,0,0,0,0,0,
4,3,0,0,0,0,0,0,
3,1,0,0,0,0,0,0,




0,0,0,0,0,0,0,0,
0,0,0,3,3,9,9,3,
0,4,0,3,3,3,3,3,
4,4,4,3,3,3,3,3,
4,10,3,3,3,3,3,10,
4,4,10,10,3,3,10,10,
4,4,10,3,3,3,4,10,
4,4,10,3,3,3,4,10,


9,9,9,0,0,0,0,0,
3,3,9,9,9,0,0,0,
9,3,3,9,9,9,0,0,
10,9,3,3,3,3,0,0,
10,10,9,3,3,9,0,0,
4,10,10,9,3,9,9,0,
3,4,10,9,9,3,9,0,
10,10,3,3,3,3,9,0,


10,10,3,10,3,3,3,4,
4,10,3,10,3,3,3,3,
4,4,10,3,10,3,3,3,
0,4,10,10,3,3,10,3,
0,4,10,10,10,10,3,10,
0,0,4,4,4,10,10,3,
0,0,0,0,4,4,4,10,
0,0,0,0,0,0,4,4,


10,10,3,3,3,3,9,9,
4,4,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,
3,3,3,10,3,3,9,0,
3,3,10,3,3,9,3,0,
10,3,3,3,3,3,0,0,
3,4,3,3,3,0,0,0,
4,4,0,0,0,0,0,0,




0,0,0,0,0,0,0,0,
0,14,14,0,0,0,0,14,
0,14,15,15,0,0,0,14,
0,0,0,16,16,0,0,0,
0,0,0,16,0,0,9,0,
0,0,0,0,0,10,3,9,
0,14,15,16,0,10,3,3,
0,14,15,16,16,1,1,1,


14,14,0,0,0,0,0,0,
15,15,14,0,0,0,0,0,
17,17,14,0,0,0,0,0,
17,17,0,0,0,16,15,15,
1,0,0,17,16,16,15,14,
1,10,3,9,17,0,14,14,
1,10,3,3,0,0,0,0,
1,0,10,10,0,0,3,0,


0,0,15,0,1,1,9,1,
0,0,17,17,17,10,1,1,
0,0,17,0,10,0,1,0,
0,17,17,0,17,0,1,3,
14,15,17,17,17,0,0,0,
15,15,16,0,0,0,0,3,
14,15,14,0,0,0,10,0,
0,14,0,0,0,0,0,0,


1,1,1,0,0,10,10,0,
3,3,1,10,0,0,0,0,
3,0,1,1,0,0,0,0,
3,3,17,17,0,0,0,0,
0,17,0,17,17,0,0,0,
0,0,0,0,16,16,14,0,
0,0,0,0,16,15,14,0,
0,0,0,0,0,14,14,0,




0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
6,6,6,6,6,6,6,6,


0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
6,6,6,6,6,6,6,6,


6,6,6,6,6,6,6,6,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,


6,6,6,6,6,6,6,6,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0
};
# 2 "mygbalib.h" 2
# 1 "position.h" 1
extern int XPOS;
extern int YPOS;
extern int IDENTITY;
extern int num;
# 3 "mygbalib.h" 2


void checkMovementButtonInGame(void)
{
    u16 buttons = (0x3FF & (~*(volatile u16*)0x4000130));
    int displacement = 1;

    if ((buttons & 0x010) == 0x010)
    {
        XPOS = XPOS + displacement;
        drawSprite(IDENTITY, num, XPOS, YPOS);
    }
    if ((buttons & 0x020) == 0x020)
    {
        XPOS = XPOS - displacement;
        drawSprite(IDENTITY, num, XPOS, YPOS);
    }
    if ((buttons & 0x080) == 0x080)
    {
        YPOS = YPOS + displacement;
        drawSprite(IDENTITY, num, XPOS, YPOS);
    }
    if ((buttons & 0x040) == 0x040)
    {
        YPOS = YPOS - displacement;
        drawSprite(IDENTITY, num, XPOS, YPOS);
    }
}
void fillPalette(void)
{
    int i;


    for (i = 0; i < 20; i++)
        ((unsigned short *) 0x5000200)[i] = palette[i];
}

void fillSprites(void)
{
    int i;


    for (i = 0; i < 128 * 16 * 16; i++)
        ((unsigned short *) 0x6010000)[i] = (sprites[i * 2 + 1] << 8) + sprites[i * 2];


    for (i = 0; i < 128; i++)
        drawSprite(0, i, 240, 160);
}

void drawSprite(int numb, int N, int x, int y)
{

    *(unsigned short *)(0x7000000 + 8 * N) = y | 0x2000;
    *(unsigned short *)(0x7000002 + 8 * N) = x | 0x4000;
    *(unsigned short *)(0x7000004 + 8 * N) = numb * 8;
}
# 8 "main.c" 2
# 1 "position.h" 1
extern int XPOS;
extern int YPOS;
extern int IDENTITY;
extern int num;
# 9 "main.c" 2
# 1 "game.h" 1
# 1 "position.h" 1
extern int XPOS;
extern int YPOS;
extern int IDENTITY;
extern int num;
# 2 "game.h" 2


void spawnVirus(void)
{
    drawSprite(2, 5, 100, 80);
}

void renderGame(void)
{
    drawSprite(IDENTITY, num, XPOS, YPOS);
    spawnVirus();
}
# 10 "main.c" 2


int IDENTITY = 0;
int XPOS = 10;
int YPOS = 160 / 2;
int num = 1;






void interruptsHandler(void)
{
    *(u16*)0x4000208 = 0x00;

    if ((*(u16*)0x4000202 & 0x1000) == 0x1000)
    {
        checkMovementButtonInGame();
    }
    *(u16*)0x4000202 = *(u16*)0x4000202;

    *(u16*)0x4000208 = 0x01;
}

u8 AppState = 0;




int main(void)
{
    int i;



    *(u32*)0x4000000 = 0x2 | 0x1000;


    *(unsigned short *)0x5000200 = 0;
    *(unsigned short *)0x5000202 = ((31) + (31<<5) + (31<<10));


    for (i = 0; i < 10 * 8 * 8 / 2; i++)
        ((unsigned short *) 0x6010000)[i] = (numbers[i * 2 + 1] << 8) + numbers[i * 2];


    (*(unsigned int*)0x3007FFC) = (int)&interruptsHandler;
    *(u16*)0x4000200 |= 0x1000;

    *(u16*)0x4000132 |= 0x7FFF;
    *(u16*)0x4000208 = 0x1;

    while (1)
    {
        renderGame();
    }

    return 0;
}
