#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "DataReceiver.hpp"
#include "DataSender.h"

TEST_CASE("Tests to check whether sensor data is read from console and also to check whether correct Max, Min and Avg values of sensor parameters are printed on console") 
{
  float Temperature[total_count] = {0};
  float ChargeRate[total_count] = {0};
  displayProcessedData(&Temperature[0], &RateOfCharge[0]);
  float Temp[2][2] = {{10,0.1}, {26,0.15}};
  printf("-----------------------------------------------");
  printf("%f %f",Temperature[0],RateOfCharge[0]);
  for(int index = 0; index < 2; index++)
  {
    REQUIRE(Temperature[index] == Temp[index][0]);
    REQUIRE(RateOfCharge[index] == Temp[index][1]);
  }
}
