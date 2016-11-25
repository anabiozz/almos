#include "types.h"

//malloc

//free

uint8_t EXIT_FAILURE = 1;

uint8_t EXIT_SUCCESS = 0;

void* memcpy(void * restrict sl , const void* restrict s 2 , uint32_t n);
void* memmove(void * sl , const void * s2 , uint32_t n);
void* memset();

void ofmouth(int* const a1, int* restrict a2, int n); //old style
void ofmouth(int* a1[const], int* a2[restrict], int n); //c99