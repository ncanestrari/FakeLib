/* @owner SAS/SSE */
/**
 * @file Test_Status.cpp
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
#include "status.h"
#include "logger.h"
}

DEFINE_FFF_GLOBALS;

FAKE_VALUE_FUNC(int, Logger_Init, const char *);
FAKE_VALUE_FUNC(int, Logger_Quit);
FAKE_VALUE_FUNC(int, Logger_Print, const char *);

class Test_Status : public ::testing::Test
{
   protected:
      void SetUp(){
         RESET_FAKE(Logger_Init);
         RESET_FAKE(Logger_Quit);
         FFF_RESET_HISTORY();
         Status_Init();         
      }
      void TearDown(){
         Status_Quit();
      }
};


TEST_F(Test_Status, Status_Init)
{
   EXPECT_EQ(1, Logger_Init_fake.call_count);
   EXPECT_EQ(0, Logger_Quit_fake.call_count);
}


TEST_F(Test_Status, Status_Fill)
{
   Status_t Status;

   FillStatusOK(&Status);
   EXPECT_EQ(OK, Status.State);

   FillStatusWN(&Status,"Warning Raised");
   EXPECT_EQ(WN, Status.State);

   FillStatusKO(&Status,"Error Raised");
   EXPECT_EQ(KO, Status.State);
}


int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}

