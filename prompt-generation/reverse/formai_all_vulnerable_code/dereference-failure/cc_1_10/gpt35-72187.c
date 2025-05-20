//FormAI DATASET v1.0 Category: Digital signal processing ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

// Function to calculate sine values for a given frequency
void calculateSineValues(double frequency, int32_t* sineValues, int32_t numSamples, int32_t sampleRate) {
    double sineFrequency = 2 * M_PI * frequency / sampleRate;
    for (int32_t i = 0; i < numSamples; i++) {
        sineValues[i] = (int32_t) (INT32_MAX * sin(i * sineFrequency));
    }
}

// Function to apply digital filter on input signal
void applyFilter(int32_t* inputSignal, int32_t* filteredSignal, int32_t numSamples) {

    // Filter parameters
    double a[3] = {1, -1.9695, 0.9702};
    double b[3] = {0.0008001, 0.0016, 0.0008001};

    // Initialize filter state variables
    double x[3] = {0};
    double y[3] = {0};

    for (int32_t i = 0; i < numSamples; i++) {

        // Shift state variables
        x[2] = x[1];
        x[1] = x[0];
        y[2] = y[1];
        y[1] = y[0];

        // Update input
        x[0] = inputSignal[i];

        // Calculate output
        y[0] = b[0] * x[0] + b[1] * x[1] + b[2] * x[2]
                - a[1] * y[1] - a[2] * y[2];

        filteredSignal[i] = (int32_t) round(y[0]);

    }
}

int main() {

    // Sampling parameters
    int32_t sampleRate = 44100;
    int32_t durationInSeconds = 5;
    int32_t numSamples = sampleRate * durationInSeconds;

    // Allocate memory for input and output signals
    int32_t* inputSignal = (int32_t*) calloc(numSamples, sizeof(int32_t));
    int32_t* filteredSignal = (int32_t*) calloc(numSamples, sizeof(int32_t));

    // Generate input signal with frequency of 440Hz
    double frequency = 440;
    calculateSineValues(frequency, inputSignal, numSamples, sampleRate);

    // Apply the filter
    applyFilter(inputSignal, filteredSignal, numSamples);

    // Print filtered signal
    for (int32_t i = 0; i < numSamples; i++) {
        printf("%d\n", filteredSignal[i]);
    }

    // Free memory
    free(inputSignal);
    free(filteredSignal);

    return 0;
}