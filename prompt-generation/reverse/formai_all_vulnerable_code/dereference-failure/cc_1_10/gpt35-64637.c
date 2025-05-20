//FormAI DATASET v1.0 Category: Audio processing ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

double *generateSineWave(int frequency, int duration, int sampleRate);
double *applyLowPassFilter(double *input, int inputSize, int sampleRate, double cutoffFrequency);

int main() {
    int frequency = 440; // A4 Note
    int duration = 2; // 2 seconds
    int sampleRate = 44100; // CD quality audio
    double cutoffFrequency = 500.0; // cutoff frequency of low pass filter
    
    // Generate sine wave
    double *sineWave = generateSineWave(frequency, duration, sampleRate);
    
    // Apply low pass filter
    double *filteredWave = applyLowPassFilter(sineWave, duration * sampleRate, sampleRate, cutoffFrequency);
    
    // Print out the filtered audio for the first 10 samples
    for (int i = 0; i < 10; i++) {
        printf("Sample %d: %.6f\n", i, filteredWave[i]);
    }
    
    // Free allocated memory
    free(sineWave);
    free(filteredWave);
    
    return 0;
}

// Function to generate a sine wave of given frequency, duration and sample rate
double *generateSineWave(int frequency, int duration, int sampleRate) {
    int numSamples = duration * sampleRate;
    double *wave = malloc(numSamples * sizeof(double));
    
    for (int i = 0; i < numSamples; i++) {
        wave[i] = sin(2.0 * PI * frequency * i / sampleRate);
    }
    
    return wave;
}

// Function to apply a low pass filter to input waveform using cutoff frequency
double *applyLowPassFilter(double *input, int inputSize, int sampleRate, double cutoffFrequency) {
    double RC = 1.0 / (2.0 * PI * cutoffFrequency);
    double dt = 1.0 / sampleRate;
    double alpha = dt / (RC + dt);
    
    double *output = malloc(inputSize * sizeof(double));
    output[0] = input[0]; // Initialize output to first input sample
    
    for (int i = 1; i < inputSize; i++) {
        output[i] = alpha * input[i] + (1.0 - alpha) * output[i - 1];
    }
    
    return output;
}