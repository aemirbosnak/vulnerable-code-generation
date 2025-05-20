//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIFI_RANGE 100 // maximum wifi range in meters
#define WIFI_STRENGTH_RANGE 61 // wifi signal strength range from -60 to 0 dBm

int main()
{
    int numPoints;
    printf("Enter the number of Wi-Fi signal measurement points to take: ");
    scanf("%d", &numPoints);
    
    srand(time(0)); // seed the random number generator with current time
    
    int signalStrengths[numPoints];
    int distances[numPoints];
    
    // generate random signal strengths and distances for each point
    for(int i = 0; i < numPoints; i++)
    {
        signalStrengths[i] = (rand() % WIFI_STRENGTH_RANGE) - 60;
        distances[i] = rand() % (WIFI_RANGE + 1);
    }
    
    // print out the data for each point
    printf("\n%-10s%-10s%-10s\n", "Point", "Distance", "Signal");
    for(int i = 0; i < numPoints; i++)
    {
        printf("%-10d%-10d%-10d\n", i+1, distances[i], signalStrengths[i]);
    }
    
    // analyze the data to find the range of signal strengths and average distance
    int maxStrength = signalStrengths[0];
    int minStrength = signalStrengths[0];
    int totalDistance = 0;
    for(int i = 0; i < numPoints; i++)
    {
        if(signalStrengths[i] > maxStrength)
        {
            maxStrength = signalStrengths[i];
        }
        if(signalStrengths[i] < minStrength)
        {
            minStrength = signalStrengths[i];
        }
        totalDistance += distances[i];
    }
    float avgDistance = (float)totalDistance / numPoints;
    
    // print out the analysis results
    printf("\nAnalysis:\n");
    printf("Range of signal strengths: %d dBm to %d dBm\n", minStrength, maxStrength);
    printf("Average distance from access point: %0.2f meters\n", avgDistance);
    
    return 0;
}