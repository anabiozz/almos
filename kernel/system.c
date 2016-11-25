#include "system.h"

inline uint8_t inportb (uint16_t _port)
{
    uint8_t rv;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    return rv;
}

inline void outportb (uint16_t _port, uint8_t _data)
{
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

inline uint8_t port_8bit_read(uint16_t _port)
{
    uint8_t result;
    __asm__ volatile("inb %1, %0" : "=a" (result) : "Nd" (_port));
    return result;
}

inline void port_8bit_write(uint16_t _port, uint8_t _data)
{
    __asm__ volatile("outb %0, %1" : : "a" (_data), "Nd" (_port));
}

inline void port_8bit_slow_write(uint16_t _port, uint8_t _data)
{
    __asm__ volatile("outb %0, %1\njmp 1f\n1: jmp 1f\n1:" : : "a" (_data), "Nd" (_port));
}


inline uint16_t port_16bit_read(uint16_t _port)
{
    uint16_t result;
    __asm__ volatile("inw %1, %0" : "=a" (result) : "Nd" (_port));
    return result;
}

inline void port_16bit_write(uint16_t _port, uint16_t _data)
{
    __asm__ volatile("outw %0, %1" : : "a" (_data), "Nd" (_port));
}

inline uint32_t port_32bit_read(uint16_t _port)
{
    uint32_t result;
    __asm__ volatile("inl %1, %0" : "=a" (result) : "Nd" (_port));
    return result;
}

inline void port_32bit_write(uint16_t _port, uint32_t _data)
{
    __asm__ volatile("outl %0, %1" : : "a"(_data), "Nd" (_port));
}
