#include "common/types.h"

/**
 * @brief pseudo random number
 * @details [long description]
 * 
 * @param limit limit values
 * @return pseudo random number
 */
uint32_t rand(uint32_t limit);

/**
 * @brief seed for rand function
 * @details [long description]
 * 
 * @param seed initial value
 */
void srand(uint32_t seed);