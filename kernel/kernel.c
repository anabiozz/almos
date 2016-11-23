#include "screen.h"
#include "keyboard.h"

kmain()
{
    clear_screen();
    print("Welcome to ALMOS operation system");
    while(1)
    {
        print("\nALMOS >");
        string ch = read_str();
        if(str_cmp(ch,"cmd")) 
        {
            print("\nYou are allready in cmd");
        }
        else if(str_cmp(ch,"clear"))
        {
            clear_screen();
        }
        else
        {
            print("\nBad command");
        }
    }
}