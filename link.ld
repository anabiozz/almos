OUTPUT_FORMAT(elf32-i386)
ENTRY(start)
SECTIONS
{
    . = 0x100000;
    .text :
    {
        *(.multiboot)
        *(.text) 
        *(.rodata)
    }
    .data :
    {
        start_ctors = .;
        KEEP(*( .init_array ));
        KEEP(*(SORT_BY_INIT_PRIORITY( .init_array.* )));
        end_ctors = .;
        *(.data)
    }
    .bss :
    { 
        *(.bss)
    }
    /DISCARD/ : { *(.fini_array*) *(.comment) }
}