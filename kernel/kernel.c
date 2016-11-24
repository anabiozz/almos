#include "screen.h"
#include "keyboard.h"
#include "types.h"
#include "string.h"

kmain(void* multiboot_structure, uint32_t magic_number)
{
    clear_screen();
    print("Welcome to ALMOS operation system");
    while(1)
    {
        print("\nALMOS >");
        PrintfKeyboardEventHandler kbhandler;
        keyboard(&interrupts, &kbhandler);
       /* string ch = read_str();
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
        }*/
    }
}