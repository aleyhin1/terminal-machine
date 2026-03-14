#include "bits.h"

bool bit2_multiplexer(Bit2 in, bool sel)
{
    bool out0 = in.bit0 && !sel;
    bool out1 = in.bit1 && sel;

    return out0 || out1;
}

bool bit4_multiplexer(Bit4 in, Bit2 sel)
{
    Bit2 in0;
    in0.bit0 = in.bit0;
    in0.bit1 = in.bit1;

    Bit2 in1;
    in1.bit0 = in.bit2;
    in.bit1 = in.bit3;

    Bit2 out;
    out.bit0 = bit2_multiplexer(in0, sel.bit0);
    out.bit1 = bit2_multiplexer(in1, sel.bit0);

    return bit2_multiplexer(out, sel.bit1);
}

bool bit8_multiplexer(Bit8 in, Bit3 sel)
{
    Bit2 sel0;
    sel0.bit0 = sel.bit0;
    sel0.bit1 = sel.bit1;

    Bit4 in0;
    in0.bit0 = in.bit0;
    in0.bit1 = in.bit1;
    in0.bit2 = in.bit2;
    in0.bit3 = in.bit3;

    Bit4 in1;
    in1.bit0 = in.bit4;
    in1.bit1 = in.bit5;
    in1.bit2 = in.bit6;
    in1.bit3 = in.bit7;

    Bit2 out;
    out.bit0 = bit4_multiplexer(in0, sel0);
    out.bit1 = bit4_multiplexer(in1, sel0);

    return bit2_multiplexer(out, sel.bit2);
}

Bit2 bit1_decoder(bool sel)
{
    Bit2 out;
    out.bit0 = !sel;
    out.bit1 = sel;
    return out;
}

Bit4 bit2_decoder(Bit2 sel)
{
    Bit2 out0 = bit1_decoder(sel.bit0);
    Bit2 out1 = bit1_decoder(sel.bit1);

    Bit4 out;
    out.bit0 = out0.bit0 && out1.bit0;
    out.bit1 = out0.bit1 && out1.bit0;
    out.bit2 = out0.bit0 && out1.bit1;
    out.bit3 = out0.bit1 && out1.bit1;
    return out;
}

Bit8 bit3_decoder(Bit3 sel)
{
    Bit2 in;
    in.bit0 = sel.bit0;
    in.bit1 = sel.bit1;

    Bit4 out0 = bit2_decoder(in);

    Bit8 out;
    out.bit0 = out0.bit0 && !sel.bit2;
    out.bit1 = out0.bit1 && !sel.bit2;
    out.bit2 = out0.bit2 && !sel.bit2;
    out.bit3 = out0.bit3 && !sel.bit2;
    out.bit4 = out0.bit0 && sel.bit2;
    out.bit5 = out0.bit0 && sel.bit2;
    out.bit6 = out0.bit0 && sel.bit2;
    out.bit7 = out0.bit0 && sel.bit2;
    return out;
}

Bit16 bit4_decoder(Bit4 sel)
{
    Bit3 in;
    in.bit0 = sel.bit0;
    in.bit1 = sel.bit1;
    in.bit2 = sel.bit2;

    Bit8 out0 = bit3_decoder(in);

    Bit16 out;
    out.bit0 = out0.bit0 && !sel.bit3;
    out.bit1 = out0.bit1 && !sel.bit3;
    out.bit2 = out0.bit2 && !sel.bit3;
    out.bit3 = out0.bit3 && !sel.bit3;
    out.bit4 = out0.bit4 && !sel.bit3;
    out.bit5 = out0.bit5 && !sel.bit3;
    out.bit6 = out0.bit6 && !sel.bit3;
    out.bit7 = out0.bit7 && !sel.bit3;
    out.bit8 = out0.bit0 && sel.bit3;
    out.bit9 = out0.bit1 && sel.bit3;
    out.bit10 = out0.bit2 && sel.bit3;
    out.bit11 = out0.bit3 && sel.bit3;
    out.bit12 = out0.bit4 && sel.bit3;
    out.bit13 = out0.bit5 && sel.bit3;
    out.bit14 = out0.bit6 && sel.bit3;
    out.bit15 = out0.bit7 && sel.bit3;

    return out;
}

bool bit1_comparator(bool a, bool b)
{
    bool out = a ^ b;
    return !out;
}

bool bit2_comparator(Bit2 a, Bit2 b)
{
    bool out0 = bit1_comparator(a.bit0, b.bit0);
    bool out1 = bit1_comparator(a.bit1, b.bit1);

    return out0 && out1;
}

bool bit4_comparator(Bit4 a, Bit4 b)
{
    Bit2 a0;
    a0.bit0 = a.bit0;
    a0.bit1 = a.bit1;

    Bit2 a1;
    a1.bit0 = a.bit2;
    a1.bit1 = a.bit3;

    Bit2 b0;
    b0.bit0 = b.bit0;
    b0.bit1 = b.bit1;

    Bit2 b1;
    b1.bit0 = b.bit2;
    b1.bit1 = b.bit3;

    bool out0 = bit2_comparator(a0, b0);
    bool out1 = bit2_comparator(a1, b1);

    return out0 && out1;
}

Bit2 bit2_shifter_1(Bit2 in, bool sel)
{
    Bit2 out;
    out.bit0 = in.bit1 && sel;
    out.bit1 = in.bit0 && !sel;
    return out;
}

Bit4 bit4_shifter_1(Bit4 in, bool sel)
{
    Bit2 in0;
    in0.bit0 = in.bit0;
    in0.bit1 = in.bit1;

    Bit2 in1;
    in1.bit0 = in.bit2;
    in1.bit1 = in.bit3;

    Bit2 out0 = bit2_shifter_1(in0, sel);
    Bit2 out1 = bit2_shifter_1(in1, sel);

    Bit4 out;
    out.bit0 = out0.bit1 && sel;
    out.bit1 = out1.bit0 && sel || out0.bit0 && !sel;
    out.bit2 = out1.bit1 && sel || out0.bit1 && !sel;
    out.bit3 = out1.bit0 && !sel;
    return out;
}

Bit2 bit1_half_adder(bool a, bool b)
{
    bool sum = a ^ b;
    bool carry = a && b;

    Bit2 out;
    out.bit0 = sum;
    out.bit1 = carry;

    return out;
}

Bit2 bit1_full_adder(bool a, bool b, bool carry)
{
    Bit2 out0 = bit1_half_adder(a, b);
    Bit2 sum = bit1_half_adder(out0.bit0, carry);

    Bit2 out;
    out.bit0 = sum.bit0;
    out.bit1 = out0.bit1 || sum.bit1;
    return out;
}

