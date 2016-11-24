bits 32
section .multiboot
    align 4
    dd    0x1BADB002
    dd    0x00
    dd    -(0x1BADB002+0x00)

section .text

global start
extern kmain ; this function is gonna be located in our c code(kernel.c)
start:
    push eax
    push ebx
    call kmain ;send precessor to continue execution from kmain function to c code 

_stop:
    cli
    hlt
    jmp _stop