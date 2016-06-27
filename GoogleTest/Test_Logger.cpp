/* @owner SAS/SSE */
/**
 * @file Test_Logger.cpp
 * @brief This module implements 
 *
 * @copyright Copyright of this program is the property of AMADEUS, without
 * whose written permission reproduction in whole or in part is prohibited.
 */

#include <climits>
#include <cstdlib>
#include <cstdio>

#include <gtest/gtest.h>

#define MESSAGE_LEN 128

extern "C" {
#include "logger.h"
}

class Test_Logger : public ::testing::Test
{
   protected:
      void SetUp(){
         Logger_Init("fakelib.log");
      }
      void TearDown(){
         Logger_Quit();
      }
};


TEST_F(Test_Logger, Logger_Print){
   char Message[MESSAGE_LEN];
   sprintf(Message,"Test Printing to Log %f %d\n", 3.14, 6);
   EXPECT_EQ(EXIT_SUCCESS, Logger_Print(Message));
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
