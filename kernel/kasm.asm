bits 32
section .multiboot
    align 4
    dd    0x1BADB002
    dd    0x00
    dd    -(0x1BADB002+0x00)

gdtr dw 0 ; For limit storage
     dd 0 ; For base storage

section .text

global start
setGdt:
   mov   eax, [esp + 4]
   mov   [gdtr + 2], eax
   mov   ax, [esp + 8]
   mov   [gdtr], ax
   lgdt  [gdtr]
   ret

extern kmain ; this function is gonna be located in our c code(kernel.c)
start:
    push eax
    push ebx
    call kmain ;send precessor to continue execution from kmain function to c code 

_stop:
    cli
    hlt
    jmp _stop