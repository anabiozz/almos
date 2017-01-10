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

string int_to_string(int n)
{
    string ch = malloc(50);
    int_to_ascii(n,ch);
    int len = strlen(ch);
    int i = 0;
    int j = len - 1;
    while(i<(len/2 + len%2))
    {
        char tmp = ch[i];
        ch[i] = ch[j];
        ch[j] = tmp;
        i++;
        j--;
    }
    return ch;
}

int str_to_int(string ch)
{
    int n = 0;
    int p = 1;
    int len = strlen(ch);
    int i;
    for (i = len-1;i>=0;i--)
    {
        n += ((int)(ch[i] - '0')) * p;
        p *= 10;
    }
    return n;
}
void * malloc(int nbytes)
{
    char variable[nbytes];
    return &variable;
}