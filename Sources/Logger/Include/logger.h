/* @owner ... */
/**
 * @file logger.h
 * @brief This module declares 
 *
 * @copyright Copyright of this program is the property of AMADEUS, without
 * whose written permission reproduction in whole or in part is prohibited.
 */

#ifndef __LOGGER_H__
#define __LOGGER_H__

int Logger_Init(char* fname);
int Logger_Quit(void);
int Logger_Print(const char* format, ...);

#endif /* !__LOGGER_H__ */

