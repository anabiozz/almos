#ifndef SCREEN_H
#define SCREEN_H

/**
    For interaction with a display 
*/

#include "types.h"

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param from [description]
 * @param to [description]
 */
extern void clear_line(uint8_t from, uint8_t to);

/**
 * @brief [brief description]
 * @details [long description]
 */
extern void update_cursor();

/**
 * @brief [brief description]
 * @details [long description]
 */
extern void clear_screen();

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param line_number [description]
 */
extern void scroll_up(uint8_t line_number);

/**
 * @brief [brief description]
 * @details [long description]
 */
extern void new_line_check();

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param c [description]
 */
extern void print_char(char c);

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param ch [description]
 */
extern void print(string ch);

#endif
