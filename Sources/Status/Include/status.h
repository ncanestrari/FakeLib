/* @owner ... */
/**
 * @file status.h
 * @brief This module declares 
 *
 * @copyright Copyright of this program is the property of AMADEUS, without
 * whose written permission reproduction in whole or in part is prohibited.
 */

#ifndef __STATUS_H__
#define __STATUS_H__

enum State_e{
   OK,
   WN,
   KO
};
typedef enum State_e State_t;

struct Status_s
{
   State_t State;
};
typedef struct Status_s Status_t;

int Status_Init(void);
int Status_Quit(void);

void FillStatusOK(Status_t *Status);
void FillStatusWN(Status_t *Status, const char *Message);
void FillStatusKO(Status_t *Status, const char *Message);

#endif /* !__STATUS_H__ */

