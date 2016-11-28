#include "screen.h"
#include "drivers/keyboard.h"
#include "common/types.h"
#include "strings/string.h"
#include "hardware/isr.h"

int kmain()
{
    clear_screen();
    isr_install();
    uint32_t a = 5/0;
    print("Welcome to ALMOS operation system");
    print_char('\n');
    while(1)
    {
        print("\nALMOS >");
       
        string ch = read_str();
        print("\n");
        print(ch);
        if(strcmp(ch,"cmd")) 
        {
            print("\nYou are allready in cmd");
        }
        else if(strcmp(ch,"clear"))
        {
            clear_screen();
        }
        else
        {
            print("\nBad command");
        }
    }

    return 0;
}