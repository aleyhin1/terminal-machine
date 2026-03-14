#ifndef MEMORY_H
#define MEMORY_H

#include <stdbool.h>

typedef struct 
{
    bool bit0;
} Register1;

Register1* register1_create();

void register1_destroy(Register1* r);

void register1_write(Register1* r, bool i, bool ck);

bool register1_read(Register1* r);

#endif