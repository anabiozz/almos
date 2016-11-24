#!/bin/bash

#nasm -f elf32 kernel.asm -o kasm.o
gcc -m32 -c kernel/kernel.c -o kc.o
ld -m elf_i386 -T link.ld -o almos/boot/kernel.bin kasm.o kc.o
#dd if=/dev/zero of=kernel.img bs=1024 count=1440
#dd if=kernel.bin of=kernel.img conv=notrunc
#/home/ruabezruko/qemu/build/x86_64-softmmu/qemu-system-x86_64 -fda kernel.img -boot a
$HOME/qemu/build/x86_64-softmmu/qemu-system-x86_64 -kernel vidar/boot/kernel.bin
#grub-mkrescue -o almos.iso almos/

