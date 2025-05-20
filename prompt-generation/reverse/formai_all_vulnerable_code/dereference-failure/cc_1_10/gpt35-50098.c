//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIGNAL_STRENGTH 100

/* Function to generate random signal strengths for testing */
int getRandomSignalStrength() {
    return rand() % (MAX_SIGNAL_STRENGTH + 1);
}

int main() {
    int numNetworks; // number of Wi-Fi networks detected
    printf("How many Wi-Fi networks have been detected? ");
    scanf("%d", &numNetworks);

    // Allocate memory for an array of signal strengths
    int* signalStrengths = (int*) malloc(numNetworks * sizeof(int));

    // Populate array with random signal strengths
    for (int i = 0; i < numNetworks; i++) {
        signalStrengths[i] = getRandomSignalStrength();
    }

    // Sort the array in descending order of signal strength
    for (int i = 0; i < numNetworks-1; i++) {
        for (int j = i+1; j < numNetworks; j++) {
            if (signalStrengths[i] < signalStrengths[j]) {
                // Swap elements
                int temp = signalStrengths[i];
                signalStrengths[i] = signalStrengths[j];
                signalStrengths[j] = temp;
            }
        }
    }

    // Display the sorted signal strengths
    printf("\nSorted signal strengths (in descending order): ");
    for (int i = 0; i < numNetworks; i++) {
        printf("%d ", signalStrengths[i]);
    }
    printf("\n\n");

    // Calculate the average signal strength
    float sum = 0;
    for (int i = 0; i < numNetworks; i++) {
        sum += signalStrengths[i];
    }
    float average = sum / numNetworks;

    // Display the average signal strength
    printf("Average signal strength: %.2f\n\n", average);

    // Calculate the strongest and weakest signals
    int strongestSignal = signalStrengths[0];
    int weakestSignal = signalStrengths[numNetworks-1];

    // Display the strongest and weakest signals
    printf("Strongest signal strength: %d\n", strongestSignal);
    printf("Weakest signal strength: %d\n\n", weakestSignal);

    // Analyze the signal strengths to determine signal quality
    printf("Signal quality analysis:\n");
    for (int i = 0; i < numNetworks; i++) {
        if (signalStrengths[i] == strongestSignal) {
            printf("Network %d: Excellent signal quality\n", i+1);
        } else if (signalStrengths[i] >= (0.8 * strongestSignal)) {
            printf("Network %d: Good signal quality\n", i+1);
        } else if (signalStrengths[i] >= (0.6 * strongestSignal)) {
            printf("Network %d: Fair signal quality\n", i+1);
        } else {
            printf("Network %d: Poor signal quality\n", i+1);
        }
    }

    // Free allocated memory
    free(signalStrengths);

    return 0;
}