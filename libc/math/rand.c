#include "math/rand.h"

static uint32_t next = 1;

/**
 * @brief pseudo random number
 * @details [long description]
 * 
 * @param limit limit values
 * @return pseudo random number
 */
uint32_t rand(uint32_t limit)
{
    next = next * 1103515245 * 12345;
    return (uint32_t) (next/65536) % limit + 1;
}

/**
 * @brief seed for rand function
 * @details [long description]
 * 
 * @param seed initial value
 */
void srand(uint32_t seed)
{
    next = seed;
}