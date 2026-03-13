#include <stdio.h>
#include "circuits.h"

int main()
{
    Bit4 a;
    a.bit0 = 1;
    a.bit1 = 0;
    a.bit2 = 1;
    a.bit3 = 0;

    Bit4 b;
    b.bit0 = 1;
    b.bit1 = 0;
    b.bit2 = 1;
    b.bit3 = 1;

    bool out = comparator_bit4(a, b);

    printf("%d\n", out);
    
    return 0;
}