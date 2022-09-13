#include "DataSender.h"

void readSensorData(float* temperature, float* rateOfCharge)
{ 
    FILE *fp; 
    float temperature_data,rateOfCharge_data;
    fp =fopen("Data.text","r");
    if (fp)
    {
        for(int index=0; fscanf(fp, "%f %f\n",&temperature_data,&rateOfCharge_data)!=EOF; index++)
        {
          *(temperature+index) = temperature_data;
          *(rateOfCharge+index) = rateOfCharge_data;
        }
    }
    fclose(fp); 
 }
 
 int printSensorData(float* temperature, float* rateOfCharge)
 {
     int count=0;
     for(int index=0; index<total_count; index++)
     {
         printf("\n Temperature : %f \t Charge rate : %f \n",*(temperature+index),*(rateOfCharge+index));
         count++;
     }
     if(count == total_count)
         return 1;
     else
         return 0;
 }
 

int communicateSensorData()
{
    float temperature[total_count], rateOfCharge[total_count] = {0};
    readSensorData(temperature,rateOfCharge);
    return printSensorData(temperature,rateOfCharge);
}
