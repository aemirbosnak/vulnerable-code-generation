//FormAI DATASET v1.0 Category: Audio processing ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants
#define PI 3.14159265358979323846

// Function to generate a sine wave
void generateSineWave(double amplitude, double frequency, double duration, double fs, double *out) {
    double ts = 1/fs; // Sampling period
    int numSamples = (int)(duration * fs); // Number of samples
    for(int i = 0; i < numSamples; i++) {
        out[i] = amplitude * sin(2 * PI * frequency * i * ts);
    }
}

// Function to add noise to a signal
void addNoise(double *signal, double noiseLevel, int length) {
    double mean = 0;
    double stddev = noiseLevel * mean;
    for(int i = 0; i < length; i++) {
        signal[i] += stddev * sqrt(-2 * log((double)rand() / RAND_MAX)) * cos(2 * PI * ((double)rand() / RAND_MAX));
    }
}

// Function to filter a signal using a lowpass filter
void lowpassFilter(double *signal, double fc, double fs, int length) {
    double wc = 2 * PI * fc / fs; // Cutoff frequency
    double alpha = sin(wc) / (2 * cos(wc) + sin(wc)); // Denormalization coefficient
    double beta = (1 - cos(wc)) / 2; // Normalization coefficient
    double yPrev = 0;
    double xPrev = 0;
    for(int i = 0; i < length; i++) {
        double y = alpha * (signal[i] + signal[i-1]) + beta * yPrev + beta * xPrev;
        yPrev = y;
        xPrev = signal[i];
        signal[i] = y;
    }
}

int main() {
    double amplitude = 1; // Amplitude of sine wave
    double frequency = 1000; // Frequency of sine wave
    double duration = 1; // Duration of sine wave
    double fs = 44100; // Sampling frequency
    int length = duration * fs; // Length of signal
    double noiseLevel = 0.1; // Level of noise to add
    double fc = 500; // Cutoff frequency of lowpass filter

    double *signal = (double *)malloc(length * sizeof(double)); // Allocate memory for signal
    generateSineWave(amplitude, frequency, duration, fs, signal); // Generate sine wave
    addNoise(signal, noiseLevel, length); // Add noise to signal
    lowpassFilter(signal, fc, fs, length); // Filter signal using lowpass filter

    for(int i = 0; i < length; i++) {
        printf("%f\n", signal[i]); // Print filtered signal
    }

    free(signal); // Free memory for signal

    return 0;
}