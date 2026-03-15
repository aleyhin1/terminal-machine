#include <stdio.h>
#include "circuits.h"
#include "registers.h"
#include "rams.h"

int main()
{
    Ram1x2* r = ram1x2_create();

    bool r0 = ram1x2_read_write(r, 1, 0, 1, 0, 0);
    bool r1 = ram1x2_read_write(r, 0, 1, 1, 1, 1);

    r0 = ram1x2_read_write(r, 0, 0, 1, 1, 0);

    printf("%d\n", r0);
    printf("%d\n", r1);

    ram1x2_destroy(r);

    return 0;
}