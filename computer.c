#include <stdio.h>
#include "circuits.h"

int main()
{
    Bit2 out = bit1_full_adder(1, 1, 1);

    printf("%d\n", out.bit0);
    printf("%d\n", out.bit1);
    
    return 0;
}