#include "gba.h"
#define spriteData  ((unsigned short *) 0x6010000)

#define REG_IME     (*(unsigned short*)0x4000208)
#define REG_IE      (*(unsigned short*)0x4000200)
#define REG_IF      (*(volatile unsigned short*)0x4000202)
#define REG_INT     (*(unsigned int*)0x3007FFC)
#define REG_TM0CNT  (*(unsigned short*)0x4000102)
#define REG_TM0D    (*(unsigned short*)0x4000100)

#define RGB(a,b,c) (a | (b << 5) | (c << 10))
#define NCOLS 20

// RGB palette used for sprites. The sprites defined below use the index of the color in the palette (so black = 0, white = 1, ...)
int palette[] = {
RGB(0,0,0), // pure black 0
RGB(31,31,31), // pure white 1
RGB(20,6,6), // hair brown 2
RGB(31,28,23), // skin peach 3
RGB(16,0,0), // socks brown 4
RGB(7,0,0), // boots brown 5
RGB(31,0,0), // medical red 6
RGB(15,15,15), // virus grey 7
RGB(19,25,26), // mask blue 8
RGB(0,31,31), // mask line blue 9
RGB(16,16,16), // dark grey 10
RGB(31,17,17), // light red 11
RGB(31,24,24), // lighter red 12
RGB(27,0,0), // dark red 13
RGB(0,16,0), // darkest green 14
RGB(0,31,0), // pure green 15
RGB(16,31,16), // light green 16
RGB(23,31,23) // lightest green 17
};


// Sprite array, defining each big 16x16 sprite as 4 8x8 tiles, using the palette above

u16 sprites[] = {
#define SPRITE_NURSE_RIGHT 0 // Nurse looking right
// Tile 00
0,0,0,0,0,0,2,2,
0,0,0,0,0,2,3,3,
0,0,0,0,0,2,3,3,
0,0,0,0,0,2,3,3,
0,0,0,0,2,2,0,3,
0,0,0,0,0,0,1,1,
0,0,0,0,0,1,1,3,
0,0,0,0,0,1,1,1,
// Tile 01
2,2,0,0,0,0,0,0,
3,3,0,0,0,0,0,0,
0,3,0,0,0,0,0,0,
3,3,0,0,0,0,0,0,
3,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
3,1,0,3,0,0,0,0,
// Tile 02
0,0,0,0,0,0,1,1,
0,0,0,0,0,0,1,6,
0,0,0,0,0,1,6,6,
0,0,0,0,1,1,1,6,
0,0,0,0,1,1,1,1,
0,0,0,0,0,0,3,0,
0,0,0,0,0,0,4,0,
0,0,0,0,0,0,4,5,
// Tile 03
1,3,3,0,0,0,0,0,
1,0,0,0,0,0,0,0,
6,1,0,0,0,0,0,0,
1,1,1,0,0,0,0,0,
1,1,1,0,0,0,0,0,
3,0,0,0,0,0,0,0,
4,0,0,0,0,0,0,0,
4,5,0,0,0,0,0,0,

#define SPRITE_NURSE_LEFT 1 // Nurse looking left
// Tile 00
0,0,0,0,0,0,2,2,
0,0,0,0,0,0,3,3,
0,0,0,0,0,0,3,0,
0,0,0,0,0,0,3,3,
0,0,0,0,0,0,0,3,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,1,1,
0,0,0,0,3,0,1,3,
// Tile 01
2,2,0,0,0,0,0,0,
3,3,2,0,0,0,0,0,
3,3,2,0,0,0,0,0,
3,3,2,0,0,0,0,0,
3,0,2,2,0,0,0,0,
1,1,0,0,0,0,0,0,
3,1,1,0,0,0,0,0,
1,1,1,0,0,0,0,0,
// Tile 02
0,0,0,0,0,3,3,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,1,6,
0,0,0,0,0,1,1,1,
0,0,0,0,0,1,1,1,
0,0,0,0,0,0,0,3,
0,0,0,0,0,0,0,4,
0,0,0,0,0,0,5,4,
// Tile 03
1,1,0,0,0,0,0,0,
6,1,0,0,0,0,0,0,
6,6,1,0,0,0,0,0,
6,1,1,1,0,0,0,0,
1,1,1,1,0,0,0,0,
0,3,0,0,0,0,0,0,
0,4,0,0,0,0,0,0,
5,4,0,0,0,0,0,0,

#define SPRITE_VIRUS 2 // Virus
// Tile 00
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,7,
0,0,0,0,0,7,6,7,
0,0,0,6,7,7,7,6,
0,0,0,0,7,6,7,7,
0,0,0,7,6,7,7,7,
// Tile 01
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
6,0,6,0,0,0,0,0,
7,6,7,0,0,0,0,0,
7,7,6,7,0,0,0,0,
7,6,7,6,0,0,0,0,
6,7,7,7,7,0,0,0,
// Tile 02
0,0,6,7,7,7,6,7,
0,0,0,0,6,7,7,7,
0,0,0,0,7,6,7,6,
0,0,0,0,0,7,7,7,
0,0,0,0,0,6,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
// Tile 03
7,7,7,6,7,6,0,0,
6,7,6,7,0,0,0,0,
7,7,7,6,0,0,0,0,
7,6,7,0,0,0,0,0,
7,0,6,0,0,0,0,0,
6,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,

#define SPRITE_MASK 3 // Mask
// Tile 00
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,1,0,0,0,0,0,
0,1,0,1,0,0,0,0,
0,1,0,1,0,0,0,0,
0,1,0,8,8,8,8,8,
0,1,0,8,9,9,9,9,
0,1,0,8,8,8,8,8,
// Tile 01
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,1,0,0,
0,0,0,0,1,0,1,0,
0,0,0,0,1,0,1,0,
8,8,8,8,8,0,1,0,
9,9,9,9,8,0,1,0,
8,8,8,8,8,0,1,0,
// Tile 02
0,1,0,8,8,8,8,8,
0,1,0,8,9,9,9,9,
0,1,0,8,8,8,8,8,
0,1,0,1,0,0,0,0,
0,1,0,1,0,0,0,0,
0,0,1,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
// Tile 03
8,8,8,8,8,0,1,0,
9,9,9,9,8,0,1,0,
8,8,8,8,8,0,1,0,
0,0,0,0,1,0,1,0,
0,0,0,0,1,0,1,0,
0,0,0,0,0,1,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,

#define LIFE_1 4

// Tile 00
0,0,0,0,0,0,0,0,
0,0,0,6,6,6,0,0,
0,0,6,12,12,11,6,0,
0,6,12,11,11,6,6,6,
0,6,12,11,6,6,6,6,
0,6,12,11,6,6,6,6,
0,0,6,12,11,6,6,6,
0,0,0,6,12,11,6,6,

// Tile 01
0,0,0,0,0,0,0,0,
0,0,6,6,6,0,0,0,
0,6,12,12,11,6,0,0,
6,12,11,6,6,6,6,0,
6,11,11,6,6,6,6,0,
6,6,6,6,6,6,6,0,
6,6,6,6,6,6,0,0,
6,6,6,6,6,0,0,0,

// Tile 02
0,0,0,6,12,11,6,6,
0,0,0,0,6,12,6,6,
0,0,0,0,6,12,11,6,
0,0,0,0,0,6,11,6,
0,0,0,0,0,0,6,6,
0,0,0,0,0,0,6,6,
0,0,0,0,0,0,0,6,
0,0,0,0,0,0,0,0,

// Tile 03

6,6,6,6,6,0,0,0,
6,6,6,6,0,0,0,0,
6,6,6,0,0,0,0,0,
6,6,6,0,0,0,0,0,
6,6,0,0,0,0,0,0,
6,6,0,0,0,0,0,0,
6,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,

};
