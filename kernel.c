#include "include/screen.h"

kmain()
{
    clearScreen();
    uint8 temp = 0;
    for(temp; temp < 100; temp++)
    {
        print("Hello this is my first kernel\n");
    }
    //clearLine(0,0);
}