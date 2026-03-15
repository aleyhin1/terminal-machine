#include "rams.h"
#include "circuits.h"
#include <stdlib.h>
#include <stdio.h>

Ram1x2* ram1x2_create()
{
    return calloc(1, sizeof(Ram1x2));
}

void ram1x2_destroy(Ram1x2* ram)
{
    free(ram);
}

bool ram1x2_read_write(Ram1x2* ram, bool in, bool adr, bool cs, bool rd, bool oe)
{
    Bit2 sel = bit1_decoder(adr);
    bool ck0 = (cs && !rd) && sel.bit0;
    bool ck1 = (cs && !rd) && sel.bit1;

    Ram1x2 r = *ram;

    register1_write(&((*ram).reg0), in, ck0);
    register1_write(&((*ram).reg1), in, ck1);

    bool out0 = register1_read(&((*ram).reg0));
    bool out1 = register1_read(&((*ram).reg1));

    bool out;
    out = (out0 && sel.bit0) || (out1 && sel.bit1);
    out = out && oe && cs && rd;
    return out;
}