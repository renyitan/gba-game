# 1 "main.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "main.c"







typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
# 24 "main.c"
int main(void)
{

    *((volatile uint32 *)(0x04000000)) = 0x0003 | 0x0400;
# 37 "main.c"
    int i;
    for (i = 0; i < 240 * 160; ++i)
    {
        ((volatile uint16 *)0x06000000)[i] = 0xFFFF;
    }

    while (1)
        ;

    return 0;
}
