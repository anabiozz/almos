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

/*static inline void *__memcpy(void *to, const void *from, size_t n)
{
    int d0, d1, d2;
    asm volatile("rep ; movsl\n\t"
             "movl %4,%%ecx\n\t"
             "andl $3,%%ecx\n\t"
             "jz 1f\n\t"
             "rep ; movsb\n\t"
             "1:"
             : "=&c" (d0), "=&D" (d1), "=&S" (d2)
             : "0" (n / 4), "g" (n), "1" ((long)to), "2" ((long)from)
             : "memory");
    return to;
}*/