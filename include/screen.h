#ifndef SCREEN_H
#define SCREEN_H

/**
    For interaction with a display 
*/

#include "common/types.h"

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param from [description]
 * @param to [description]
 */
void clear_line(uint8_t from, uint8_t to);

/**
 * @brief [brief description]
 * @details [long description]
 */
void update_cursor();

/**
 * @brief [brief description]
 * @details [long description]
 */
void clear_screen();

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param line_number [description]
 */
void scroll_up(uint8_t line_number);

/**
 * @brief [brief description]
 * @details [long description]
 */
void new_line_check();

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param c [description]
 */
void print_char(char c);

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param ch [description]
 */
void print(string ch);

#endif
