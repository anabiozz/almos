#include "strings/string.h"

uint16_t strlen(string ch)
{
    uint16_t i = 1;
    while(ch[i++]);
    return --i;
}

uint8_t strcmp(string ch1, string ch2)
{
    uint8_t result = 1;
    uint8_t size = strlen(ch1);
    if(size != strlen(ch2)) result = 0;
    else 
    {
        uint8_t i = 0;
        for(i;i<=size;i++)
        {
            if(ch1[i] != ch2[i]) result = 0;
        }
    }
    return result;
}