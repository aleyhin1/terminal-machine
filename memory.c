#include "memory.h"
#include <stdlib.h>

Register1* register1_create()
{
    Register1* r;
    r = calloc(1, sizeof(Register1));
    return r;
}

Register2* register2_create()
{
    Register2* r;
    r = calloc(1, sizeof(Register2));
    return r;
}

Register4* register4_create()
{
    Register4* r;
    r = calloc(1, sizeof(Register4));
    return r;
}

Register8* register8_create()
{
    Register8* r;
    r = calloc(1, sizeof(Register8));
    return r;
}

void register1_destroy(Register1* r)
{
    free(r);
}

void register2_destroy(Register2* r)
{
    free(r);
}

void register4_destroy(Register4* r)
{
    free(r);
}

void register8_destroy(Register8* r)
{
    free(r);
}

void register1_write(Register1* r, bool i, bool ck)
{
    Register1 reg = *r;
    reg.bit0 = (i && ck) || (reg.bit0 && !ck);
    *r = reg;
}

void register2_write(Register2* r, Bit2 i, bool ck)
{
    Register2 reg = *r;
    reg.data.bit0 = (i.bit0 && ck) || (reg.data.bit0 && !ck);
    reg.data.bit1 = (i.bit1 && ck) || (reg.data.bit1 && !ck);
    *r = reg;
}

void register4_write(Register4* r, Bit4 i, bool ck)
{
    Register4 reg = *r;
    reg.data.bit0 = (i.bit0 && ck) || (reg.data.bit0 && !ck);
    reg.data.bit1 = (i.bit1 && ck) || (reg.data.bit1 && !ck);
    reg.data.bit2 = (i.bit2 && ck) || (reg.data.bit2 && !ck);
    reg.data.bit3 = (i.bit3 && ck) || (reg.data.bit3 && !ck);
    *r = reg;
}

void register8_write(Register8* r, Bit8 i, bool ck)
{
    Register8 reg = *r;
    reg.data.bit0 = (i.bit0 && ck) || (reg.data.bit0 && !ck);
    reg.data.bit1 = (i.bit1 && ck) || (reg.data.bit1 && !ck);
    reg.data.bit2 = (i.bit2 && ck) || (reg.data.bit2 && !ck);
    reg.data.bit3 = (i.bit3 && ck) || (reg.data.bit3 && !ck);
    reg.data.bit4 = (i.bit4 && ck) || (reg.data.bit4 && !ck);
    reg.data.bit5 = (i.bit5 && ck) || (reg.data.bit5 && !ck);
    reg.data.bit6 = (i.bit6 && ck) || (reg.data.bit6 && !ck);
    reg.data.bit7 = (i.bit7 && ck) || (reg.data.bit7 && !ck);
    *r = reg;
}

bool register1_read(Register1* r)
{
    return (*r).bit0;
}

Bit2 register2_read(Register2* r)
{
    return (*r).data;
}

Bit4 register4_read(Register4* r)
{
    return (*r).data;
}

Bit8 register8_read(Register8* r)
{
    return (*r).data;
}
