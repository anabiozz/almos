#include "common/util.h"

void memcpy(char* source, char* dest, int nbytes)
{
    for(int i = 0; i < nbytes; i++) 
        *(dest + i) = *(source + i);
}

void memset(uint8_t* dest, uint8_t val, uint32_t len)
{
    uint8_t *temp = (uint8_t*)dest;
    for(; len != 0; len--) *temp++ = val;
}

void int_to_ascii(int n, char str[])
{
    int i, sign;
    if((sign = n) < 0) n = -n;
    i = 0;
    do {
        str[i++] = n % 10 + '0';
    } while((n /= 10) > 0);

    if(sign < 0) str[i++] = '-';
    str[i] = '\0';
}