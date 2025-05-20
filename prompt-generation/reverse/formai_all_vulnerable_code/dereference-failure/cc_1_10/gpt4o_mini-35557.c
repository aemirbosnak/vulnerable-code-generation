//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SAMPLE_RATE 44100
#define DURATION_SECONDS 5
#define PI 3.14159

// Structure to represent the sound signal
typedef struct {
    double *samples;
    int sample_count;
} SoundSignal;

// Function to generate a sine wave
SoundSignal generateSineWave(double frequency) {
    SoundSignal signal;
    signal.sample_count = SAMPLE_RATE * DURATION_SECONDS;
    signal.samples = (double *)malloc(signal.sample_count * sizeof(double));
    
    for (int i = 0; i < signal.sample_count; i++) {
        signal.samples[i] = sin((2 * PI * frequency * i) / SAMPLE_RATE);
    }

    return signal;
}

// Function to perform Fast Fourier Transform (FFT) to analyze frequencies
void fft(double *x, int N) {
    if (N <= 1) return;

    // Divide
    double *even = (double *)malloc(N / 2 * sizeof(double));
    double *odd = (double *)malloc(N / 2 * sizeof(double));
    
    for (int i = 0; i < N / 2; i++) {
        even[i] = x[i * 2];
        odd[i] = x[i * 2 + 1];
    }

    // Recursion
    fft(even, N / 2);
    fft(odd, N / 2);

    // Combine
    for (int k = 0; k < N / 2; k++) {
        double t = odd[k] * cos(2 * PI * k / N) - odd[k] * sin(2 * PI * k / N);
        x[k] = even[k] + t;
        x[k + N / 2] = even[k] - t;
    }

    free(even);
    free(odd);
}

// Function to analyze the frequency components of the signal
void analyzeFrequencies(SoundSignal *signal) {
    printf("Analyzing frequencies of the mysterious sounds...\n");
    
    // Performing FFT
    fft(signal->samples, signal->sample_count);

    // Displaying results
    for (int i = 0; i < signal->sample_count; i++) {
        printf("Frequency Component [%d]: %f\n", i, signal->samples[i]);
    }
}

int main() {
    printf("Elementary, my dear Watson! Let's investigate the mystery of sound...\n");

    // Generate a sample sound signal (sine wave at 440 Hz)
    SoundSignal sound = generateSineWave(440.0);

    // Analyze the sound frequency components
    analyzeFrequencies(&sound);

    // Clean up
    free(sound.samples);
    printf("Investigation complete. The truth about these sounds has been uncovered.\n");

    return 0;
}