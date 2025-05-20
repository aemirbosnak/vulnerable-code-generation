//FormAI DATASET v1.0 Category: Audio processing ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to generate a sine wave signal
void generateSineWave(float A, float f, float phi, float dur, float sr, float *signal)
{
    int nSamples = dur * sr; // Total number of samples required
    float deltaT = 1 / sr; // Time difference between samples

    for (int i = 0; i < nSamples; i++)
    {
        float t = i * deltaT; // Time value for current sample
        signal[i] = A * sin(2 * PI * f * t + phi); // Sine wave equation
    }
}

// Function to apply a low pass filter to a signal
void lowPassFilter(float *signal, int nSamples, float cutoffFreq, float sr)
{
    float RC = 1 / (2 * PI * cutoffFreq); // Time constant for low pass filter
    float dt = 1 / sr; // Time difference between samples
    float alpha = dt / (RC + dt); // Alpha value for low pass filter

    // Apply low pass filter using recursive formula
    for (int i = 1; i < nSamples; i++)
    {
        signal[i] = alpha * signal[i] + (1 - alpha) * signal[i - 1];
    }
}

int main()
{
    float A = 1; // Amplitude of sine wave
    float f = 440; // Frequency of sine wave
    float phi = 0; // Phase shift of sine wave
    float dur = 1; // Duration of sine wave in seconds
    float sr = 44100; // Sample rate in Hz
    float cutoffFreq = 10000; // Cutoff frequency for low pass filter

    int nSamples = dur * sr; // Total number of samples required
    float *signal = malloc(nSamples * sizeof(float)); // Allocate memory for signal

    // Generate sine wave signal
    generateSineWave(A, f, phi, dur, sr, signal);

    // Apply low pass filter to signal
    lowPassFilter(signal, nSamples, cutoffFreq, sr);

    // Print first 10 samples of filtered signal
    printf("Filtered signal:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%f\n", signal[i]);
    }

    free(signal); // Free allocated memory

    return 0;
}