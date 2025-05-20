//FormAI DATASET v1.0 Category: Weather simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomTemperature(int low, int high) {
    int temperature = rand() % (high - low + 1) + low;
    return temperature;
}

int randomHumidity(int low, int high) {
    int humidity = rand() % (high - low + 1) + low;
    return humidity;
}

int main() {
    srand(time(NULL));
    int minTemp = 15;
    int maxTemp = 30;
    int minHumidity = 50;
    int maxHumidity = 80;

    printf("Welcome to the Weather Simulator 1.0\n\n");
    printf("Today's weather conditions:\n");

    int currentTemperature = randomTemperature(minTemp, maxTemp);
    int currentHumidity = randomHumidity(minHumidity, maxHumidity);

    printf("Temperature: %d C\n", currentTemperature);
    printf("Humidity: %d %%\n\n", currentHumidity);

    printf("Enter the number of hours to simulate: ");
    int numHours;
    scanf("%d", &numHours);

    int simulatedTemperature[numHours];
    int simulatedHumidity[numHours];

    for (int i = 0; i < numHours; i++) {
        int deviation = rand() % 4 - 2; // Random deviation between -2 and 2
        simulatedTemperature[i] = currentTemperature + deviation;

        deviation = rand() % 6 - 3; // Random deviation between -3 and 3
        simulatedHumidity[i] = currentHumidity + deviation;

        // Adjust values to stay within the limits
        if (simulatedTemperature[i] < minTemp) simulatedTemperature[i] = minTemp;
        if (simulatedTemperature[i] > maxTemp) simulatedTemperature[i] = maxTemp;
        if (simulatedHumidity[i] < minHumidity) simulatedHumidity[i] = minHumidity;
        if (simulatedHumidity[i] > maxHumidity) simulatedHumidity[i] = maxHumidity;

        currentTemperature = simulatedTemperature[i];
        currentHumidity = simulatedHumidity[i];
    }

    printf("\nSimulation results:\n");
    printf("Hour   | Temperature | Humidity\n");

    for (int i = 0; i < numHours; i++) {
        printf("%4d   |     %2d C   |   %2d %%\n", i+1, simulatedTemperature[i], simulatedHumidity[i]);
    }

    return 0;
}