/* @owner ... */
/**
 * @file vector.c
 * @brief This module implements 
 *
 * @copyright Copyright of this program is the property of AMADEUS, without
 * whose written permission reproduction in whole or in part is prohibited.
 */

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vector.h"

#include "logger.h"
#include "status.h"

#define MESSAGE_LEN 128

struct Vector_s{
   int      Size;
   double  *Values;
};


int Vector_Init(void)
{
   return Status_Init();
}


int Vector_Quit(void)
{
   return Status_Quit();
}

Vector_t *Vector_Create(int Size, double *content)
{
   Vector_t *vec = (Vector_t *) malloc(sizeof(Vector_t));
   vec->Size = Size;
   vec->Values = (double *) malloc(Size*sizeof(double));
   memcpy(vec->Values, content, Size*sizeof(double));
   return vec;
}


Vector_t *Vector_CreateZero(int Size)
{
   int i;
   Vector_t *vec = (Vector_t *) malloc(sizeof(Vector_t));
   vec->Size = Size;
   vec->Values = (double *) malloc(Size*sizeof(double));
   for(i = 0; i < Size; ++i){
      vec->Values[i] = 0.0;
   }
   return vec;
}


Status_t Vector_Destroy(Vector_t *vec)
{
   Status_t Status;   
   if(!vec) {
      FillStatusWN(&Status, "Vector is NULL\n");
   } else {
      free(vec->Values);
      free(vec);
      FillStatusOK(&Status);
   }
   return Status;
}


Status_t Vector_Log(Vector_t *vec)
{
   Status_t Status;
   char Message[MESSAGE_LEN];
   if(!vec || !vec->Values ){
      FillStatusKO(&Status, "Argument NULL\n");
   } else {
      int i;
      sprintf(Message, "Vector instance %p\nSize: %u\n", vec, vec->Size);
      Logger_Print(Message);
      for(i = 0; i < vec->Size; ++i){
         sprintf(Message, "%f\n", vec->Values[i]);
         Logger_Print(Message);
      }
      Logger_Print("\n");
      FillStatusOK(&Status);
   }
   return Status;
}


Status_t Vector_Scalar(Vector_t *vec1, Vector_t *vec2, double *res)
{
   Status_t Status;
   if(!vec1 || !vec2){
      FillStatusKO(&Status, "Argument NULL\n");
   } else if(vec1->Size != vec2->Size){
      FillStatusKO(&Status, "Incompatible vectors\n");
   } else {
      int i;
      *res = 0.0;
      for(i = 0; i < vec1->Size; ++i)
         *res += vec1->Values[i]*vec2->Values[i];
      FillStatusOK(&Status);
   }
   return Status;
}


Status_t Vector_Add(Vector_t *vec1, Vector_t * vec2, Vector_t *res)
{
   Status_t Status;
   if(!vec1 || !vec2 || !res){
      FillStatusKO(&Status, "Argument NULL\n");
   } else if(vec1->Size != vec2->Size){
      FillStatusKO(&Status, "Incompatible vectors\n");
   } else {
      int i;
      for(i = 0; i < vec1->Size; ++i)
         res->Values[i] += vec1->Values[i] + vec2->Values[i];
      FillStatusOK(&Status);
   }
   return Status;
}


Status_t Vector_Opposite(Vector_t *vec, Vector_t *res)
{
   Status_t Status;
   if(!vec || !vec->Values || !res || vec->Size != res->Size){
      FillStatusKO(&Status, "Argument NULL\n");
   } else {
      int i;
      for(i = 0; i < vec->Size; ++i)
         res->Values[i] = -vec->Values[i];
      FillStatusOK(&Status);
   }
   return Status;
}

int Vector_Equal(Vector_t *vec1, Vector_t *vec2)
{
   int      res = 1;
   if(!vec1 || !vec2){
      res = 0;
   } else if(vec1->Size != vec2->Size){
      res = 0;
   } else {
      int i;
      for(i = 0; i < vec1->Size; ++i){
         res = res && (vec1->Values[i] == vec2->Values[i]);
         if(res == 0) break;
      }
   }
   return res;
}
