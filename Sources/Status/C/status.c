/* @owner ... */
/**
 * @file status.c
 * @brief This module implements 
 *
 * @copyright Copyright of this program is the property of AMADEUS, without
 * whose written permission reproduction in whole or in part is prohibited.
 */

#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#include "status.h"

#include "logger.h"


int Status_Init(void)
{
   return Logger_Init("fakelib.log");
}


int Status_Quit(void)
{
   return Logger_Quit();
}


void FillStatusOK(Status_t *Status)
{
   Status->State = OK;
}


void FillStatusWN(Status_t *Status, const char *Message)
{
   Status->State = WN;
   Logger_Print(Message);
}


void FillStatusKO(Status_t *Status, const char *Message)
{
   Status->State = KO;
   Logger_Print(Message);
}


