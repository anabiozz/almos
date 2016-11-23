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
uint8 inportb (uint16 _port);

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param _port [description]
 * @param _data [description]
 */
void outportb (uint16 _port, uint8 _data);

#endif