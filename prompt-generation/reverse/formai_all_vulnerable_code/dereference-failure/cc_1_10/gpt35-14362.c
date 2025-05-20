//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 0

void generateSignalStrengths(int signalStrengths[], int numSignals) {
    for(int i = 0; i < numSignals; i++) {
        signalStrengths[i] = rand() % (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH + 1) + MIN_SIGNAL_STRENGTH;
    }
}

void printSignalStrengths(int signalStrengths[], int numSignals) {
    for(int i = 0; i < numSignals; i++) {
        printf("Signal Strength %d: %d\n", i+1, signalStrengths[i]);
    }
}

int calculateAverageSignalStrength(int signalStrengths[], int numSignals) {
    int total = 0;
    for(int i = 0; i < numSignals; i++) {
        total += signalStrengths[i];
    }
    return total / numSignals;
}

int calculateMaxSignalStrength(int signalStrengths[], int numSignals) {
    int maxStrength = signalStrengths[0];
    for(int i = 1; i < numSignals; i++) {
        if(signalStrengths[i] > maxStrength) {
            maxStrength = signalStrengths[i];
        }
    }
    return maxStrength;
}

int calculateMinSignalStrength(int signalStrengths[], int numSignals) {
    int minStrength = signalStrengths[0];
    for(int i = 1; i < numSignals; i++) {
        if(signalStrengths[i] < minStrength) {
            minStrength = signalStrengths[i];
        }
    }
    return minStrength;
}

int main() {
    srand(time(0));  // Seed the random number generator with the current time

    printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n");

    int numSignals;
    printf("Enter the number of Wi-Fi signals to analyze: ");
    scanf("%d", &numSignals);

    int signalStrengths[numSignals];
    generateSignalStrengths(signalStrengths, numSignals);

    printf("\nHere are the generated Wi-Fi signal strengths:\n");
    printSignalStrengths(signalStrengths, numSignals);

    int averageSignalStrength = calculateAverageSignalStrength(signalStrengths, numSignals);
    printf("\nThe average Wi-Fi signal strength is: %d\n", averageSignalStrength);

    int maxSignalStrength = calculateMaxSignalStrength(signalStrengths, numSignals);
    printf("The maximum Wi-Fi signal strength is: %d\n", maxSignalStrength);

    int minSignalStrength = calculateMinSignalStrength(signalStrengths, numSignals);
    printf("The minimum Wi-Fi signal strength is: %d\n", minSignalStrength);

    int signalStrengthRange = maxSignalStrength - minSignalStrength;
    printf("The range of Wi-Fi signal strengths is: %d\n", signalStrengthRange);

    int signalStrengthVariance = 0;
    for(int i = 0; i < numSignals; i++) {
        signalStrengthVariance += pow(signalStrengths[i] - averageSignalStrength, 2);
    }
    signalStrengthVariance /= numSignals;
    printf("The variance of Wi-Fi signal strengths is: %d\n", signalStrengthVariance);

    return 0;
}