#include "DataSender.h"

void readSensorData(float* temperature, float* chargerate)
{ 
    FILE *fp; 
    float temp_data,chargerate_data;
    fp =fopen("SensorData.text","r");
    if (fp)
    {
        for(int index=0; fscanf(fp, "%f %f\n",&temp_data,&chargerate_data)!=EOF; index++)
        {
          *(temperature+index) = temp_data;
          *(chargerate+index) = chargerate_data;
        }
    }
    fclose(fp); 
 }
 
 int printSensorData(float* temperature, float* chargerate)
 {
     for(int index=0; index<total_count; index++)
     {
         printf("\n Temperature : %f \t Charge rate : %f \n",*(temperature+index),*(chargerate+index));
         readings_count_check++;
     }
     return verifyPrintToConsole(readings_count_check);
 }
 
 int verifyPrintToConsole(int readings_count_check)
 {
     if(readings_count_check == total_readings_count)
         return 1;
     else
         return 0;
 }

int communicateSensorData()
{
    float temperature[total_readings_count], chargerate[total_readings_count] = {0};
    readSensorData(temperature,chargerate);
    int printsuccess = printSensorData(temperature,chargerate);
    return printsuccess;
}
