//FormAI DATASET v1.0 Category: Digital signal processing ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

// Function to generate a sine wave
float* generateSineWave(float amplitude, float frequency, float duration, int samplingFrequency) {
    int numberOfSamples = duration * samplingFrequency;
    float* signal = (float*) calloc(numberOfSamples, sizeof(float));
    float timeIncrement = 1.0 / samplingFrequency;
    for(int i=0; i<numberOfSamples; i++) {
        signal[i] = amplitude * sin(2*PI*frequency*i*timeIncrement);
    }
    return signal;
}

// Function to apply low pass filter on a signal
float* applyLowPassFilter(float* signal, int numSamples, int samplingFrequency, float cutoffFrequency) {
    float* outputSignal = (float*) calloc(numSamples, sizeof(float));
    float RC = 1.0 / (2*PI*cutoffFrequency);
    float dt = 1.0 / samplingFrequency;
    float alpha = RC / (RC + dt);
    outputSignal[0] = signal[0];
    for(int i=1; i<numSamples; i++) {
        outputSignal[i] = alpha * signal[i] + (1-alpha) * outputSignal[i-1];
    }
    return outputSignal;
}

// Main function
int main() {
    float amplitude = 1.0;
    float frequency = 50.0;
    float duration = 1.0;
    int samplingFrequency = 1000;
    float cutoffFrequency = 100.0;

    // Generate a sine wave
    float* inputSignal = generateSineWave(amplitude, frequency, duration, samplingFrequency);

    // Apply low pass filter
    float* outputSignal = applyLowPassFilter(inputSignal, duration * samplingFrequency, samplingFrequency, cutoffFrequency);

    // Print the signals before and after filtering
    for(int i=0; i<duration*samplingFrequency; i++) {
        printf("Input Signal: %f, Output Signal: %f\n", inputSignal[i], outputSignal[i]);
    }

    // Free the memory allocated for signals
    free(inputSignal);
    free(outputSignal);

    return 0;
}