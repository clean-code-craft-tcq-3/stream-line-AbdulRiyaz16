#include<stdio.h>

#define total_count 20

void readSensorData(float* temperature, float* chargerate);
int printSensorData(float* temperature, float* chargerate);
int verifyConsoleData(int count);
int communicateSensorData();
