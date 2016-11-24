#ifndef SYSTEM_H
#define SYSTEM_H

#include "types.h"

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param _port [description]
 * @return [description]
 */
uint8_t inportb (uint16_t _port);

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param _port [description]
 * @param _data [description]
 */
void outportb (uint16_t _port, uint8_t _data);

#endif