#ifndef MEMORY_H
#define MEMORY_H

#include "bits.h"
#include <stdbool.h>

typedef struct 
{
    bool bit0;
} Register1;
typedef struct 
{
    Bit2 data;
} Register2;
typedef struct 
{
    Bit4 data;
} Register4;
typedef struct 
{
    Bit8 data;
} Register8;

Register1* register1_create();
Register2* register2_create();
Register4* register4_create();
Register8* register8_create();

void register1_destroy(Register1* r);
void register2_destroy(Register2* r);
void register4_destroy(Register4* r);
void register8_destroy(Register8* r);

void register1_write(Register1* r, bool i, bool ck);
void register2_write(Register2* r, Bit2 i, bool ck);
void register4_write(Register4* r, Bit4 i, bool ck);
void register8_write(Register8* r, Bit8 i, bool ck);

bool register1_read(Register1* r);
Bit2 register2_read(Register2* r);
Bit4 register4_read(Register4* r);
Bit8 register8_read(Register8* r);

#endif