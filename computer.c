#include <stdio.h>
#include "circuits.h"

int main()
{
    Bit2 out = half_adder(0, 0);

    printf("%d\n", out.bit0);
    printf("%d\n", out.bit1);
    
    return 0;
}