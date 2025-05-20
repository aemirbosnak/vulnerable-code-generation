//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: random
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SAMPLE_RATE 44100
#define FREQUENCY 440  // A4 note
#define DURATION 5     // Duration in seconds
#define PI 3.14159265359
#define FILTER_COEFF 0.1 // Coefficient for the low-pass filter

void generateSineWave(float* buffer, int samples, float frequency) {
    for (int i = 0; i < samples; i++) {
        buffer[i] = 0.5f * sinf(2.0f * PI * frequency * ((float)i / SAMPLE_RATE));
    }
}

void applyLowPassFilter(float* input, float* output, int samples) {
    output[0] = input[0]; // first sample is the same

    for (int i = 1; i < samples; i++) {
        output[i] = output[i - 1] + FILTER_COEFF * (input[i] - output[i - 1]);
    }
}

void printWaveform(float* buffer, int samples) {
    for (int i = 0; i < samples; i++) {
        int level = (int)((buffer[i] + 1.0f) * 10); // Scale waveform for visualization
        for (int j = 0; j < 20; j++) {
            if (j == level) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int samples = SAMPLE_RATE * DURATION;
    float* sineWave = (float*)malloc(samples * sizeof(float));
    float* filteredWave = (float*)malloc(samples * sizeof(float));

    if (sineWave == NULL || filteredWave == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Generate sine wave
    generateSineWave(sineWave, samples, FREQUENCY);

    // Apply low-pass filter
    applyLowPassFilter(sineWave, filteredWave, samples);

    // Print original waveform
    printf("\nOriginal Sine Wave:\n");
    printWaveform(sineWave, samples / 50);  // Print every 50th sample for brevity

    // Print filtered waveform
    printf("\nFiltered Sine Wave:\n");
    printWaveform(filteredWave, samples / 50);  // Print every 50th sample for brevity

    // Free allocated memory
    free(sineWave);
    free(filteredWave);

    return 0;
}