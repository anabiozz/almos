#include "string.h"

uint16 str_len(string ch)
{
    uint16 i = 1;
    while(ch[i++]);
    return --i;
}

uint8 str_cmp(string ch1, string ch2)
{
    uint8 result = 1;
    uint8 size = str_len(ch1);
    if(size != str_len(ch2)) result = 0;
    else 
    {
        uint8 i = 0;
        for(i;i<=size;i++)
        {
            if(ch1[i] != ch2[i]) result = 0;
        }
    }
    return result;
}