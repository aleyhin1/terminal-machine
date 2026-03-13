#include "bits.h"
#include <stdio.h>

bool multiplexer_bits8(Bit8 in, Bit3 sel)
{
    bool out0 = in.bit0 && !sel.bit0 && !sel.bit1 && !sel.bit2;
    bool out1 = in.bit1 && sel.bit0 && !sel.bit1 && !sel.bit2;
    bool out2 = in.bit2 && !sel.bit0 && sel.bit1 && !sel.bit2;
    bool out3 = in.bit3 && sel.bit0 && sel.bit1 && !sel.bit2;
    bool out4 = in.bit4 && !sel.bit0 && !sel.bit1 && sel.bit2;
    bool out5 = in.bit5 && sel.bit0 && !sel.bit1 && sel.bit2;
    bool out6 = in.bit6 && !sel.bit0 && sel.bit1 && sel.bit2;
    bool out7 = in.bit7 && sel.bit0 && sel.bit1 && sel.bit2;

    return out0 || out1 || out2 || out3 || out4 || out5 || out6 || out7;
}

Bit8 decoder_bit8(Bit3 sel)
{
    Bit8 out;
    
    out.bit0 = !sel.bit0 && !sel.bit1 && !sel.bit2;
    out.bit1 = sel.bit0 && !sel.bit1 && !sel.bit2;
    out.bit2 = !sel.bit0 && sel.bit1 && !sel.bit2;
    out.bit3 = sel.bit0 && sel.bit1 && !sel.bit2;
    out.bit4 = !sel.bit0 && !sel.bit1 && sel.bit2;
    out.bit5 = sel.bit0 && !sel.bit1 && sel.bit2;
    out.bit6 = !sel.bit0 && sel.bit1 && sel.bit2;
    out.bit7 = sel.bit0 && sel.bit1 && sel.bit2;

    return out;
}

bool comparator_bit4(Bit4 a, Bit4 b)
{
    bool out0 = a.bit0 ^ b.bit0;
    bool out1 = a.bit1 ^ b.bit1;
    bool out2 = a.bit2 ^ b.bit2;
    bool out3 = a.bit3 ^ b.bit3;

    bool out4 = out0 || out1 || out2 || out3;
    return !out4;
}