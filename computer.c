#include <stdio.h>
#include "circuits.h"

int main()
{
    Bit8 a;
    a.bit0 = 1;
    a.bit1 = 1;
    a.bit2 = 0;
    a.bit3 = 0;
    a.bit4 = 0;
    a.bit5 = 1;
    a.bit6 = 0;
    a.bit7 = 1;

    Bit8 out = bit1_shifter_bit8(a, 1);

    printf("%d\n", out.bit0);
    printf("%d\n", out.bit1);
    printf("%d\n", out.bit2);
    printf("%d\n", out.bit3);
    printf("%d\n", out.bit4);
    printf("%d\n", out.bit5);
    printf("%d\n", out.bit6);
    printf("%d\n", out.bit7);
    
    return 0;
}