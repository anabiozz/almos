#ifndef UTIL_H
#define UTIL_H

#include "types.h"

void memcpy(char* source, char* dest, int nbytes);
void memset(uint8_t* dest, uint8_t val, uint32_t len);
void int_to_ascii(int n, char str[]);
//static inline void *__memcpy(void *to, const void *from, size_t n);

#endif