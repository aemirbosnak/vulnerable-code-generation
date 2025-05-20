//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100 // Samples per second
#define DURATION 1        // Duration of the signal in seconds
#define FREQUENCY 440     // Frequency of the sine wave (A4 note)
#define PI 3.14159265358979323846
#define NUM_SAMPLES (SAMPLE_RATE * DURATION)

// Function to generate a sine wave signal
void generateSineWave(double *signal, int numSamples, double frequency) {
    for (int i = 0; i < numSamples; i++) {
        signal[i] = sin(2 * PI * frequency * (i / (double)SAMPLE_RATE));
    }
}

// Function to apply a simple low-pass filter
void lowPassFilter(double *input, double *output, int numSamples, double alpha) {
    output[0] = input[0]; // First sample is the same
    for (int i = 1; i < numSamples; i++) {
        output[i] = alpha * input[i] + (1 - alpha) * output[i - 1];
    }
}

// Function to print the signal samples
void printSamples(double *samples, int numSamples) {
    for (int i = 0; i < numSamples; i++) {
        printf("%d: %f\n", i, samples[i]);
    }
}

int main() {
    double *sineWave = (double *)malloc(NUM_SAMPLES * sizeof(double));
    double *filteredSignal = (double *)malloc(NUM_SAMPLES * sizeof(double));
    
    if (sineWave == NULL || filteredSignal == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Generate sine wave
    generateSineWave(sineWave, NUM_SAMPLES, FREQUENCY);
    printf("Original Sine Wave Signal:\n");
    printSamples(sineWave, 100); // Print the first 100 samples for brevity

    // Apply low-pass filter with alpha = 0.1
    lowPassFilter(sineWave, filteredSignal, NUM_SAMPLES, 0.1);
    printf("\nFiltered Signal (Low-Pass):\n");
    printSamples(filteredSignal, 100); // Print the first 100 samples for brevity

    // Clean up allocated memory
    free(sineWave);
    free(filteredSignal);

    return 0;
}