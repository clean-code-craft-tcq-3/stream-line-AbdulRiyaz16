#include <assert.h>
#include "DataSender.h"

int main()
 {
     printf("\nCheck if print on console is successful");
     assert(communicateSensorData()==1);    
 
     printf("\nTo Verify read and print fucntions");
     float temperature_array[total_count] ={0};
     float chargerate_array[total_count] ={0};
     float output_data[21][2] = {{10,0.10},{20,0.20},{19,0.19},{9,0.09},{18,0.18},{8,0.08},{17,0.17},{7,0.07},{16,0.16},{6,0.06},{15,0.15},{5,0.05},{14,0.14},{4,0.04},{13,0.13},{3,0.03},{12,0.12},{2,0.02},{11,0.11},{1,0.01},{0,0.00}};
     readSensorData(temperature_array,chargerate_array);
 
     int count= 0;
     for(int index=0;index<21;index++)
     {
       assert(temperature_array[count] == output_data[index][0]);
       assert(chargerate_array[count] == output_data[index][1]);
       count++;
     }
   
     printSensorData(temperature_array,chargerate_array);
     
     return 0;
 }

