#include "DataReceiver.hpp"
#include <iostream>
#include <string.h>
using namespace std;

void readSensorData(float* temperature, float* rateOfCharge)
{
    int numberCount = 0;
    for(int index1 = 0; index1 <= total_count*2; index1++)
    {
        char line_input[55] = {};     
        
        cin.getline(line_input,55);
        cout<<line_input<<endl;
       
        char Temperature_Trial[9] = {};
        char SOC_Trial[9] = {};
        
        if( strchr(line_input,':') != NULL)
        {   
            int index=0;
            for(int i=15 ; i<24; i++)
            {
                Temperature_Trial[index] =  line_input[i];
                index++;
            }
            temperature[numberCount] = stof(Temperature_Trial);
            cout<<temperature[numberCount]<<endl;
            
            index=0;
            for(int i=41 ; i<51; i++)
            {
                SOC_Trial[index] =  line_input[i];
                index++;
            }
            rateOfCharge[numberCount] = stof(SOC_Trial);
            cout<<rateOfCharge[numberCount]<<endl;
            
            numberCount++;
        }
    }
}


float calculateMaxValue(float* sensorData)
{
    float maxValue = sensorData[0];
    for(int index = 0; index < total_count; index++)
    {
        if(maxValue < sensorData[index])
        {
            maxValue = sensorData[index];
        }
    }

    return(maxValue);
}

float calculateMinValue(float* sensorData)
{
    float minValue = sensorData[0];
    for(int index = 0; index < total_count; index++)
    {
        if(minValue > sensorData[index])
        {
            minValue = sensorData[index];
        }
    }
    return(minValue);
}

float calculateAvg(float* sensorData)
{
    float sum = 0;
    float Avg = 0;
    
    for(int index = (total_count - 5); index < total_count; index++)
    {
        sum += sensorData[index];
    }
    Avg = sum / 5;
    return(Avg);
}

int printData(float* sensorData,float maxValue, float minValue, float Avg)
{
    printf("Data received from sender:");
    for(int index = 0; index < total_count; index++)
    {
        printf("%f\n",sensorData[index]);
    }
    printf("Maximum value = %f\n",calculateMaxValue(sensorData));
    printf("Minimum value = %f\n",calculateMinValue(sensorData));
    printf("Average value = %f\n",calculateAvg(sensorData));
    return(1);
}

void displayData(float* temperature, float* rateOfCharge)
{
    readSensorData(temperature,rateOfCharge);
    printData(temperature);
    printData(rateOfCharge);
}
