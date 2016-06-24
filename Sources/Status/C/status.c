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

#define MAX_MSG_LEN 128

void FillStatusOK(Status_t Status)
{
   Status.State = OK;
}


void FillStatusWN(Status_t Status, const char *Message)
{
   Status.State = WN;
   Logger_Print(Message);
}


void FillStatusKO(Status_t Status, const char *Message)
{
   Status.State = KO;
   Logger_Print(Message);
}


