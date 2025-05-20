//FormAI DATASET v1.0 Category: Audio processing ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#define SAMPLE_RATE 44100
#define PI 3.14159265359

// Sine wave generator function
void generateSineWave(double *buffer, double frequency, int numSamples) {
    double phaseIncrement = (2.0 * PI * frequency) / SAMPLE_RATE;
    double phase = 0.0;

    for (int i = 0; i < numSamples; i++) {
        buffer[i] = sin(phase);
        phase += phaseIncrement;
    }
}

// Simple low pass filter function
void applyLowPassFilter(double *inputBuffer, double *outputBuffer, int numSamples, double cutoffFrequency) {
    double RC = 1.0 / (2.0 * PI * cutoffFrequency);
    double dt = 1.0 / SAMPLE_RATE;
    double alpha = dt / (RC + dt);

    outputBuffer[0] = inputBuffer[0];

    for (int i = 1; i < numSamples; i++) {
        outputBuffer[i] = (alpha * inputBuffer[i]) + ((1.0 - alpha) * outputBuffer[i-1]);
    }
}

int main() {
    int numSamples = 44100;
    double frequency = 440.0;
    double cutoffFrequency = 1000.0;

    double *inputBuffer = malloc(sizeof(double) * numSamples);
    double *outputBuffer = malloc(sizeof(double) * numSamples);

    // Generate a sine wave
    generateSineWave(inputBuffer, frequency, numSamples);

    // Apply a low pass filter to the sine wave
    applyLowPassFilter(inputBuffer, outputBuffer, numSamples, cutoffFrequency);

    // Print the output to the console
    for (int i = 0; i < numSamples; i++) {
        printf("%f\n", outputBuffer[i]);
    }

    free(inputBuffer);
    free(outputBuffer);

    return 0;
}