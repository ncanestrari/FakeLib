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
#include <stdarg.h>

#include "vector.h"

#include "logger.h"
#include "status.h"

struct Vector_s{
   int      Size;
   double  *Values;
};

typedef int (*Printer)(const char *, ...);

static Status_t Vector_PrintAux(Vector_t *vec, Printer printer);


Vector_t *Vector_Create(int Size, ...)
{
   Vector_t *vec = (Vector_t *) malloc(sizeof(Vector_t));
   int i;
   va_list Values;
   va_start(Values, Size);
   vec->Size = Size;
   vec->Values = (double *) malloc(Size*sizeof(double));
   for(i = 0; i < Size; ++i)
      vec->Values[i] = va_arg(Values, double);
   va_end(Values);
   return vec;
}


Vector_t *Vector_CreateZero(int Size)
{
   int i;
   Vector_t *vec = (Vector_t *) malloc(sizeof(Vector_t));
   vec->Size = Size;
   for(i = 0; i < Size; ++i){
      vec->Values[i] = 0.0;
   }
   return vec;
}


Status_t Vector_Destroy(Vector_t *vec)
{
   Status_t Status;   
   if(!vec) {
      FillStatusWN(Status, "Vector is NULL\n");
   } else {
      free(vec->Values);
      free(vec);
      FillStatusOK(Status);
   }
   return Status;
}


Status_t Vector_Print(Vector_t *vec)
{
   Status_t Status;
   Status = Vector_PrintAux(vec, &printf);
   return Status;
}


Status_t Vector_Log(Vector_t *vec)
{
   Status_t Status;
   Status = Vector_PrintAux(vec, &Logger_Print);
   return Status;
}


Status_t Vector_Scalar(Vector_t *vec1, Vector_t *vec2, double *res)
{
   Status_t Status;
   if(!vec1 || !vec2){
      FillStatusKO(Status, "Argument NULL\n");
   } else if(vec1->Size != vec2->Size){
      FillStatusKO(Status, "Incompatible vectors\n");
   } else {
      int i;
      *res = 0.0;
      for(i = 0; i < vec1->Size; ++i)
         *res += vec1->Values[i]*vec2->Values[i];
      FillStatusOK(Status);
   }
   return Status;
}


Status_t Vector_Add(Vector_t *vec1, Vector_t * vec2, Vector_t *res)
{
   Status_t Status;
   if(!vec1 || !vec2){
      FillStatusKO(Status, "Argument NULL\n");
   } else if(vec1->Size != vec2->Size){
      FillStatusKO(Status, "Incompatible vectors\n");
   } else {
      int i;
      if(!res) res = Vector_CreateZero(vec1->Size);
      for(i = 0; i < vec1->Size; ++i)
         res->Values[i] += vec1->Values[i] + vec2->Values[i];
      FillStatusOK(Status);
   }
   return Status;
}


Status_t Vector_Opposite(Vector_t *vec, Vector_t *res)
{
   Status_t Status;
   if(!vec || !vec->Values ){
      FillStatusKO(Status, "Argument NULL\n");
   } else if(res){
      FillStatusWN(Status, "result will be overwritten\n");
      free(res);
   } else {
      int i;
      res = Vector_CreateZero(vec->Size);
      for(i = 0; i < vec->Size; ++i)
         res->Values[i] = -vec->Values[i];
      FillStatusOK(Status);
   }
   return Status;
}


static Status_t Vector_PrintAux(Vector_t *vec, Printer printer)
{
   Status_t Status;
   if(!vec || !vec->Values ){
      FillStatusKO(Status, "Argument NULL\n");
   } else {
      int i;
      printer("Vector instance %p\nSize: %u\n", vec, vec->Size);
      for(i = 0; i < vec->Size; ++i)
         printer("%f\n", vec->Values[i]);
      printer("\n");
      FillStatusOK(Status);
   }
   return Status;
}


