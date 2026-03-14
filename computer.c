#include <stdio.h>
#include "circuits.h"
#include "memory.h"

int main()
{
    Register1* r = register1_create();
    register1_write(r, 0, 1);
    register1_write(r, 1, 0);
    bool out = register1_read(r);

    printf("%d\n", out);

    register1_destroy(r);

    return 0;
}