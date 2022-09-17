#include<stdio.h>
#define total_count 51

void readSensorData(float* temperature, float* Rateofcharge);
float calculateMaxValue(float* sensorData);
float calculateMinValue(float* sensorData);
float calculateAvg(float* sensorData);
int printData(float* sensorData,float maxValue, float minValue, float Avg);
void displayData(float* Temperature, float* Rateofcharge);
