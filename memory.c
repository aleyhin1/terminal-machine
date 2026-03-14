#include "memory.h"
#include <stdlib.h>

Register1* register1_create()
{
    Register1* r;
    r = calloc(1, sizeof(Register1));
    return r;
}

void register1_destroy(Register1* r)
{
    free(r);
}

void register1_write(Register1* r, bool i, bool ck)
{
    Register1 reg = *r;
    reg.bit0 = (i && ck) || (reg.bit0 && !ck);
    *r = reg;
}

bool register1_read(Register1* r)
{
    return (*r).bit0;
}
