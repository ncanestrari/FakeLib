/* @owner SAS/SSE */
/**
 * @file Main_TestAll.cpp
 * @brief This module implements 
 *
 * @copyright Copyright of this program is the property of AMADEUS, without
 * whose written permission reproduction in whole or in part is prohibited.
 */

#include <limits.h>
#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}

