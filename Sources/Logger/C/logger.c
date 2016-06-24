/* @owner ... */
/**
 * @file logger.c
 * @brief This module implements 
 *
 * @copyright Copyright of this program is the property of AMADEUS, without
 * whose written permission reproduction in whole or in part is prohibited.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "logger.h"

static FILE* log;

int Logger_Init(const char* fname)
{
   if( !fname ) log = stdout;
   else log = fopen(fname, "w");
   if( !log ) return EXIT_FAILURE;
   return EXIT_SUCCESS;
}


int Logger_Quit(void)
{
   if( log != stdout || log == NULL) fclose(log);
   return EXIT_SUCCESS;
}


int Logger_Print(const char* format, ...)
{
   va_list args;
   va_start(args, format);
   vfprintf(log, format, args);
   va_end(args);
   return EXIT_SUCCESS;
}

