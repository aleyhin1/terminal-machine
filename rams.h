#ifndef RAMS_H
#define RAMS_H

#include "bits.h"
#include "registers.h"

typedef struct 
{
    Register1 reg0;
    Register1 reg1;
} Ram1x2;

Ram1x2* ram1x2_create();
void ram1x2_destroy(Ram1x2* ram);
bool ram1x2_read_write(Ram1x2* ram, bool in, bool adr, bool cs, bool rd, bool oe);

#endif