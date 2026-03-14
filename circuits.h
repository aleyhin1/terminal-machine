#ifndef CIRCUITS_H
#define CIRCUITS_H

#include "bits.h"

bool multiplexer(Bit8 in, Bit3 sel);

Bit8 decoder(Bit3 in);

bool comparator(Bit4 a, Bit4 b);

Bit8 shifter_1(Bit8 in, bool sel);

Bit2 half_adder(bool a, bool b);

#endif
