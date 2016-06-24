/* @owner ... */
/**
 * @file vector.h
 * @brief This module declares
 *
 * @copyright Copyright of this program is the property of AMADEUS, without
 * whose written permission reproduction in whole or in part is prohibited.
 */

#ifndef __VECTOR_H__ 
#define __VECTOR_H__ 

#include "status.h"

typedef struct Vector_s Vector_t;

Vector_t *Vector_Create(int Size, ...);
Vector_t *Vector_CreateZero(int Size);
Status_t Vector_Destroy(Vector_t *vec);
Status_t Vector_Print(Vector_t *vec);
Status_t Vector_Log(Vector_t *vec);
Status_t Vector_Scalar(Vector_t *vec1, Vector_t *vec2, double *res);
Status_t Vector_Add(Vector_t *vec1, Vector_t * vec2, Vector_t *res);
Status_t Vector_Opposite(Vector_t *vec, Vector_t *res);

#endif /* __VECTOR_H__  */

