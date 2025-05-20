//FormAI DATASET v1.0 Category: Temperature monitor ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>

//function to get average temperature of all sensors
float averageTemperature(float*, int);

int main()
{
    int numSensors = 5;
    float *sensorTemps = (float*) malloc(numSensors * sizeof(float));
    float *sensorThresholds = (float*) malloc(numSensors * sizeof(float));

    //initialize temperature and threshold readings
    for(int i=0; i<numSensors; i++)
    {
        sensorTemps[i] = 20.0 + ((float) rand() / RAND_MAX) * (40.0 - 20.0);
        sensorThresholds[i] = 30.0 + ((float) rand() / RAND_MAX) * (45.0 - 30.0);

        //print initial readings
        printf("Sensor %d: Temperature reading=%.2f Celsius, Threshold=%.2f Celsius\n", i+1, sensorTemps[i], sensorThresholds[i]);
    }

    //get average temperature of all sensors
    float avgTemp = averageTemperature(sensorTemps, numSensors);

    //check if any sensor temperature reading exceeds threshold
    for(int i=0; i<numSensors; i++)
    {
        if(sensorTemps[i] > sensorThresholds[i])
        {
            printf("Sensor %d: WARNING! Temperature reading=%.2f Celsius exceeds threshold=%.2f Celsius\n", i+1, sensorTemps[i], sensorThresholds[i]);
        }
        else
        {
            printf("Sensor %d: Temperature reading=%.2f Celsius is within threshold=%.2f Celsius\n", i+1, sensorTemps[i], sensorThresholds[i]);
        }
    }

    //print average temperature
    printf("Average temperature across all sensors: %.2f Celsius\n", avgTemp);

    //free memory allocated for sensorTemps and sensorThresholds
    free(sensorTemps);
    free(sensorThresholds);

    return 0;
}

//function definition to get average temperature of all sensors
float averageTemperature(float *sensorTemps, int numSensors)
{
    float sum = 0;

    for(int i=0; i<numSensors; i++)
    {
        sum += sensorTemps[i];
    }
    
    return sum/numSensors;
}