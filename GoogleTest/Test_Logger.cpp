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
   EXPECT_EQ(EXIT_SUCCESS, Logger_Print("Test Printing to Log %f %d\n", 3.14, 6));
}

