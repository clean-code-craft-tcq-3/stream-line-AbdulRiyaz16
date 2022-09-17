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
  printf("%f %f",Temperature[0],RateOfCharge[0]);
  for(int index = 0; index < 2; index++)
  {
    REQUIRE(Temperature[index] == Temp[index][0]);
    REQUIRE(RateOfCharge[index] == Temp[index][1]);
  }
}

TEST_CASE("Check minimum, maximum and average of temperature and RateOfCharge")
{
  float Temperature[total_count] = {0};
  float RateOfCharge[total_count] = {0};
  float observedMaxValue, observedMinValue, observedSMAValue, expectedMaxValue, expectedMinValue, expectedSAvgValue;
  expectedMaxValue = 50;
  expectedMinValue = 0;
  expectedSAvgValue = 18;
 // readSensorData(&Temperature[0], &RateOfCharge);
  observedMaxValue = calculateMaxValue(&Temperature[0]);
  observedMinValue = calculateMinValue(&Temperature[0]);
  observedSMAValue = calculateAvg(&Temperature[0]);
  REQUIRE(observedMaxValue == expectedMaxValue);
  REQUIRE(observedMinValue == expectedMinValue);
  REQUIRE(observedSMAValue == expectedSAvgValue);

  REQUIRE(printData(&Temperature[0],50,0,18) == 1);  

  expectedMaxValue = 0.50;
  expectedMinValue = 0.00;
  expectedSAvgValue = 0.162;
  observedMaxValue = calculateMaxValue(&RateOfCharge[0]);
  observedMinValue = calculateMinValue(&RateOfCharge[0]);
  observedSMAValue = calculateAvg(&RateOfCharge[0]);
  REQUIRE(observedMaxValue == expectedMaxValue);
  REQUIRE(observedMinValue == expectedMinValue);
  REQUIRE(observedSMAValue == expectedSAvgValue);

  REQUIRE(printData(&RateOfCharge[0],0.50,0.00,0.81) == 1);
}

