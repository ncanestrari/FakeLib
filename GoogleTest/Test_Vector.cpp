/* @owner SAS/SSE */
/**
 * @file Test_Vector.cpp
 * @brief This module implements 
 *
 * @copyright Copyright of this program is the property of AMADEUS, without
 * whose written permission reproduction in whole or in part is prohibited.
 */


/* Include needed standard headers */
#include <climits>
#include <cstdlib>
#include <cstdio>

/* Include test and mock utilities headers */
#include <gtest/gtest.h>
extern "C" {
#include "fff.h"
}

/* Include functions to be tested/mocked */
extern "C" {
#include "vector.h"
#include "status.h"
#include "logger.h"
}

#define UNUSED(x) x __attribute__((unused)) 

DEFINE_FFF_GLOBALS;


FAKE_VALUE_FUNC(int, Status_Init);
FAKE_VALUE_FUNC(int, Status_Quit);
FAKE_VALUE_FUNC(int, Logger_Print, const char *);
FAKE_VOID_FUNC(FillStatusOK, Status_t *);
FAKE_VOID_FUNC(FillStatusWN, Status_t *, const char *);
FAKE_VOID_FUNC(FillStatusKO, Status_t *, const char *);


/* In this case it is trivial */
void FillStatusOK_costum_fake(Status_t *Status){ Status->State = OK; }
void FillStatusWN_costum_fake(Status_t *Status, UNUSED(const char *Message)){ Status->State = WN; }
void FillStatusKO_costum_fake(Status_t *Status, UNUSED(const char *Message)){ Status->State = KO; }


class Test_Vector : public ::testing::Test
{
   protected:
      void SetUp(){
         RESET_FAKE(Status_Init);
         RESET_FAKE(Status_Quit);
         FFF_RESET_HISTORY();
         Vector_Init();         
         FillStatusOK_fake.custom_fake = FillStatusOK_costum_fake;
         FillStatusWN_fake.custom_fake = FillStatusWN_costum_fake;
         FillStatusKO_fake.custom_fake = FillStatusKO_costum_fake;
      }
      void TearDown(){
         Vector_Quit();
      }
};


TEST_F(Test_Vector, Vector_Init)
{
   EXPECT_EQ(1, Status_Init_fake.call_count);
   EXPECT_EQ(0, Status_Quit_fake.call_count);
}


TEST_F(Test_Vector, Vector_Log)
{
   Status_t  Status;
   Vector_t *vec = Vector_CreateZero(10);

   Status = Vector_Log(vec);
   EXPECT_EQ(OK, Status.State);

   Status = Vector_Destroy(vec);
   EXPECT_EQ(OK, Status.State);
}


TEST_F(Test_Vector, Vector_Scalar)
{
   Status_t  Status;
   double    content1[] = {1., 2., 3.};
   double    content2[] = {2., 3., 4.};
   double    res = 0.;
   Vector_t *vec1 = Vector_Create(3, content1);
   Vector_t *vec2 = Vector_Create(3, content2);

   Status = Vector_Scalar(vec1, vec2, &res);
   EXPECT_EQ(OK, Status.State);
   EXPECT_EQ(20., res);

   Status = Vector_Destroy(vec1);
   EXPECT_EQ(OK, Status.State);
   Status = Vector_Destroy(vec2);
   EXPECT_EQ(OK, Status.State);
}


TEST_F(Test_Vector, Vector_Add)
{
   Status_t  Status;
   double    content1[] = {1., 2., 3.};
   double    content2[] = {2., 3., 4.};
   double    content3[] = {3., 5., 7.};
   Vector_t *vec1 = Vector_Create(3, content1);
   Vector_t *vec2 = Vector_Create(3, content2);
   Vector_t *vec3 = Vector_Create(3, content3);
   Vector_t *vec  = Vector_CreateZero(3);

   Status = Vector_Add(vec1, vec2, vec);
   EXPECT_EQ(OK, Status.State);
   EXPECT_EQ(1, Vector_Equal(vec, vec3));

   Status = Vector_Destroy(vec1);
   EXPECT_EQ(OK, Status.State);
   Status = Vector_Destroy(vec2);
   EXPECT_EQ(OK, Status.State);
   Status = Vector_Destroy(vec3);
   EXPECT_EQ(OK, Status.State);
   Status = Vector_Destroy(vec);
   EXPECT_EQ(OK, Status.State);
}


TEST_F(Test_Vector, Vector_Opposite)
{
   Status_t  Status;
   double    content1[] = { 1.,  2.,  3.};
   double    content2[] = {-1., -2., -3.};
   Vector_t *vec1 = Vector_Create(3, content1);
   Vector_t *vec2 = Vector_Create(3, content2);
   Vector_t *vec  = Vector_CreateZero(3);

   Status = Vector_Opposite(vec1, vec);
   EXPECT_EQ(OK, Status.State);
   EXPECT_EQ(1, Vector_Equal(vec, vec2));

   Status = Vector_Destroy(vec1);
   EXPECT_EQ(OK, Status.State);
   Status = Vector_Destroy(vec2);
   EXPECT_EQ(OK, Status.State);
   Status = Vector_Destroy(vec);
   EXPECT_EQ(OK, Status.State);
}


int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}

