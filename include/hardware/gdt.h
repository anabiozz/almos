#ifndef GDT_H
#define GDT_H

#include "common/types.h"
#include "screen.h"

typedef struct {
    uint16_t limit;
    uint16_t base;
    uint16_t low_limit;
    uint8_t type;
    uint16_t low_base;
    uint8_t high_base;
    uint8_t high_limit;
} GDT;

#define GDT_ENTRIES 8192
// gdt_t gdt[GDT_ENTRIES];

// struct gdt_t gdt;
void create_descriptor(uint32_t base, uint32_t limit, uint16_t flag);
void encodeGdtEntry(uint8_t *target, GDT source);
void create_gdt();

#endif
