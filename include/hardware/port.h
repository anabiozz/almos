#ifndef PORT_H
#define PORT_H

#include "common/types.h"

typedef struct {
    uint16_t port;
    uint8_t data;

    void (*Write8)(uint16_t port, uint8_t _data);
    uint8_t (*Read8)(uint16_t port);
} Dataport;

typedef struct {
    uint16_t port;
    uint8_t data;

    void (*Write8)(uint16_t port, uint8_t _data);
    uint8_t (*Read8)(uint16_t port);
} Commandport;

typedef struct keyboard_event_handler {
    void (*OnKeyDown)(string str);
    void (*OnKeyUp)(string str);
} KeyboardEventHandler;

typedef struct keyboard_driver {
    uint32_t (*handle_interrupt)(uint32_t esp);
    void (*activate)();
} KeyboardDriver;

static inline uint8_t port_8bit_read(uint16_t _port)
{
    uint8_t result;
    __asm__ volatile("inb %1, %0" : "=a" (result) : "Nd" (_port));
    return result;
}

static inline void port_8bit_write(uint16_t _port, uint8_t _data)
{
    __asm__ volatile("outb %0, %1" : : "a" (_data), "Nd" (_port));
}

static inline void port_8bit_slow_write(uint16_t _port, uint8_t _data)
{
    __asm__ volatile("outb %0, %1\njmp 1f\n1: jmp 1f\n1:" : : "a" (_data), "Nd" (_port));
}


static inline uint16_t port_16bit_read(uint16_t _port)
{
    uint16_t result;
    __asm__ volatile("inw %1, %0" : "=a" (result) : "Nd" (_port));
    return result;
}

static inline void port_16bit_write(uint16_t _port, uint16_t _data)
{
    __asm__ volatile("outw %0, %1" : : "a" (_data), "Nd" (_port));
}

static inline uint32_t port_32bit_read(uint16_t _port)
{
    uint32_t result;
    __asm__ volatile("inl %1, %0" : "=a" (result) : "Nd" (_port));
    return result;
}

static inline void port_32bit_write(uint16_t _port, uint32_t _data)
{
    __asm__ volatile("outl %0, %1" : : "a"(_data), "Nd" (_port));
}

#endif
