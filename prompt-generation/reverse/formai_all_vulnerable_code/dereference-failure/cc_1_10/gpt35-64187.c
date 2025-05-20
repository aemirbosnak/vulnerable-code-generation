//FormAI DATASET v1.0 Category: Digital signal processing ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793

// Function to generate a sine wave signal with a specific frequency and duration
void generateSineWave(float frequency, float duration, float sampleRate, float amplitude, float *signal) {
    int numSamples = (int)(duration * sampleRate);
    float timeIncrement = 1.0 / sampleRate;
    for (int i = 0; i < numSamples; i++) {
        float time = i * timeIncrement;
        signal[i] = amplitude * sin(2 * PI * frequency * time);
    }
}

// Function to implement a digital filter with a specific cutoff frequency
void lowPassFilter(float cutoffFrequency, float sampleRate, float *inputSignal, float *filteredSignal, int signalLength) {
    float RC = 1.0 / (cutoffFrequency * 2 * PI);
    float dt = 1.0 / sampleRate;
    float alpha = dt / (RC + dt);
    float previousOutput = 0;
    for (int i = 0; i < signalLength; i++) {
        filteredSignal[i] = alpha * inputSignal[i] + (1 - alpha) * previousOutput;
        previousOutput = filteredSignal[i];
    }
}

int main() {
    // Generate a 1kHz sine wave with a duration of 1 second, a sample rate of 48000Hz, and an amplitude of 0.5
    float sampleRate = 48000.0;
    float frequency = 1000.0;
    float duration = 1.0;
    float amplitude = 0.5;
    int numSamples = (int)(duration * sampleRate);
    float *inputSignal = (float *)malloc(numSamples * sizeof(float));
    generateSineWave(frequency, duration, sampleRate, amplitude, inputSignal);

    // Apply a low-pass filter with a cutoff frequency of 500Hz to the input signal
    float *filteredSignal = (float *)malloc(numSamples * sizeof(float));
    float cutoffFrequency = 500.0;
    lowPassFilter(cutoffFrequency, sampleRate, inputSignal, filteredSignal, numSamples);

    // Print the input and filtered signals to a file for plotting
    FILE *fp;
    fp = fopen("inputSignal.txt", "w");
    for (int i = 0; i < numSamples; i++) {
        fprintf(fp, "%f\n", inputSignal[i]);
    }
    fclose(fp);
    fp = fopen("filteredSignal.txt", "w");
    for (int i = 0; i < numSamples; i++) {
        fprintf(fp, "%f\n", filteredSignal[i]);
    }
    fclose(fp);

    free(inputSignal);
    free(filteredSignal);
    return 0;
}