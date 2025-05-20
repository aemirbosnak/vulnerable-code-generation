//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SAMPLE_RATE 44100
#define SINE_WAVE_FREQUENCY 440
#define NUM_SAMPLES 44100

// Function to generate a sine wave
void generateSineWave(double *buffer, int numSamples) {
    for (int i = 0; i < numSamples; i++) {
        double angle = (double)i / SAMPLE_RATE * 2 * M_PI;
        buffer[i] = sin(angle * SINE_WAVE_FREQUENCY);
    }
}

// Function to apply a low-pass filter
void lowPassFilter(double *buffer, int numSamples) {
    double alpha = 0.7;
    double prevSample = buffer[0];
    for (int i = 1; i < numSamples; i++) {
        double nextSample = buffer[i];
        buffer[i] = alpha * nextSample + (1 - alpha) * prevSample;
        prevSample = nextSample;
    }
}

int main() {
    srand(time(NULL));

    // Generate a buffer of random noise
    double *noiseBuffer = malloc(NUM_SAMPLES * sizeof(double));
    for (int i = 0; i < NUM_SAMPLES; i++) {
        noiseBuffer[i] = rand() % 100 / 100.0;
    }

    // Apply a low-pass filter to the noise
    lowPassFilter(noiseBuffer, NUM_SAMPLES);

    // Generate a sine wave and mix it with the filtered noise
    double *outputBuffer = malloc(NUM_SAMPLES * sizeof(double));
    generateSineWave(outputBuffer, NUM_SAMPLES);
    for (int i = 0; i < NUM_SAMPLES; i++) {
        outputBuffer[i] += noiseBuffer[i];
    }

    // Save the output to a file
    FILE *outputFile = fopen("output.raw", "wb");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }
    fwrite(outputBuffer, sizeof(double), NUM_SAMPLES, outputFile);
    fclose(outputFile);

    free(noiseBuffer);
    free(outputBuffer);

    return 0;
}