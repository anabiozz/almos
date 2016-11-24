SOURCEDIR=kernel
BUILDDIR=obj

SOURCES=$(shell find $(SOURCEDIR) -name '*.c')
OBJECTS=$(patsubst $(SOURCEDIR)/%.c, $(BUILDDIR)/%.o, $(SOURCES))

SOURCES_ASM=$(shell find $(SOURCEDIR) -name '*.asm')
OBJECTS_ASM=$(patsubst $(SOURCEDIR)/%.asm, $(BUILDDIR)/%.o, $(SOURCES_ASM))

CC=gcc
LD=ld
NASM=nasm

CFLAGS = -c -m32 -I include/
LDFLAGS= -m elf_i386 -T link.ld

kernel.bin: $(OBJECTS) $(OBJECTS_ASM)
	$(LD) $(LDFLAGS) $(OBJECTS) $(OBJECTS_ASM) -o vidar/boot/kernel.bin

$(BUILDDIR)/%.o: $(SOURCEDIR)/%.asm
	$(NASM) -f elf32 -o $@ $<

$(BUILDDIR)/%.o: $(SOURCEDIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<

clear:
	rm -f $(BUILDDIR)/*
	rm -f vidar/boot/kernel.bin