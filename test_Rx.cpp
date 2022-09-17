#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "DataReceiver.hpp"
#include "DataSender.h"

TEST_CASE("Tests to check whether sensor data is read from console and also to check whether correct Max, Min and Avg values of sensor parameters are printed on console") 
{
  float Temperature[total_count] = {0};
  float RateOfCharge[total_count] = {0};
  displayData(&Temperature[0], &RateOfCharge[0]);
  float Temp[2][2] = {{10,0.1}, {20,0.20}};
  printf("-----------------------------------------------");
  printf("/n %f /n %f",Temperature[0],RateOfCharge[0]);
  for(int index = 0; index < 2; index++)
  {
    REQUIRE(Temperature[index] == Temp[index][0]);
    REQUIRE(RateOfCharge[index] == Temp[index][1]);
  }
  
  float observedMaxValue, observedMinValue, observedAvgValue, expectedMaxValue, expectedMinValue, expectedAvgValue;
  expectedMaxValue = 45;
  expectedMinValue = 0;
  expectedAvgValue = 18;
  observedMaxValue = calculateMaxValue(&Temperature[0]);
  observedMinValue = calculateMinValue(&Temperature[0]);
  observedAvgValue = calculateMovingAverage(&Temperature[0]);
  REQUIRE(observedMaxValue == expectedMaxValue);
  REQUIRE(observedMinValue == expectedMinValue);
  REQUIRE(observedAvgValue == expectedAvgValue);

  REQUIRE(printSensorData(&Temperature[0],45,0,18) == 1);  

  expectedMaxValue = 0.79;
  expectedMinValue = 0.00;
  expectedAvgValue = 0.162;
  observedMaxValue = calculateMaxValue(&RateOfCharge[0]);
  observedMinValue = calculateMinValue(&RateOfCharge[0]);
  observedAvgValue = calculateMovingAverage(&RateOfCharge[0]);
  REQUIRE(observedMaxValue == expectedMaxValue);
  REQUIRE(observedMinValue == expectedMinValue);
  REQUIRE(observedAvgValue == expectedAvgValue);

  REQUIRE(printSensorData(&ChargeRate[0],0.79,0.00,0.81) == 1);
}

