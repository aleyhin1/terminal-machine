#ifndef CIRCUITS_H
#define CIRCUITS_H

#include "bits.h"

bool multiplexer_bits8(Bit8 in, Bit3 sel);

Bit8 decoder_bit8(Bit3 in);

bool comparator_bit4(Bit4 a, Bit4 b);

Bit8 bit1_shifter_bit8(Bit8 in, bool sel);

#endif
