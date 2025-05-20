//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateSignalStrength(int *signalStrength) {
    srand(time(NULL));
    *signalStrength = rand() % 101; // generates signal strength between 0-100
}

void printSignalStatistics(int *signalStrengths, int numReadings) {
    int sum = 0, min = 100, max = 0;
    float avg;

    printf("\nSignal Strength Readings:\n");

    for (int i = 0; i < numReadings; i++) {
        printf("%d. %d\n", i+1, signalStrengths[i]);
        sum += signalStrengths[i];

        if (signalStrengths[i] < min) {
            min = signalStrengths[i];
        }

        if (signalStrengths[i] > max) {
            max = signalStrengths[i];
        }
    }

    avg = (float)sum / numReadings;

    printf("\nStatistics:\n");
    printf("Mean: %.2f\n", avg);
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
}

int main() {
    int numReadings, *signalStrengths;

    printf("Enter the number of signal strength readings: ");
    scanf("%d", &numReadings);

    signalStrengths = (int *)malloc(numReadings * sizeof(int));

    // generating signal strengths and storing them in the array
    for (int i = 0; i < numReadings; i++) {
        generateSignalStrength(&signalStrengths[i]);
    }

    printSignalStatistics(signalStrengths, numReadings);

    free(signalStrengths);

    return 0;
}