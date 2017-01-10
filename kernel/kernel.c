#include "screen.h"
#include "drivers/keyboard.h"
#include "common/types.h"
#include "strings/string.h"
#include "hardware/isr.h"
#include "hardware/gdt.h"

int kmain()
{
    create_gdt();
    isr_install();
    clear_screen();
    print("Hi and Welcome to NIDOS operating system\nPlease enter a command\n");
    launch_shell(0);
   
    return 0;
}