//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define WINDOW_SIZE 1024

int main() {
    // Generate a sine wave with frequency 440 Hz
    double frequency = 440.0;
    double amplitude = 0.5;
    double phase = 0.0;
    int sample_index;
    double sample_value;
    FILE *output_file;

    // Open output file for writing
    output_file = fopen("sine_wave.raw", "wb");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    // Calculate number of samples
    int num_samples = SAMPLE_RATE * 5.0;

    // Allocate memory for samples
    double *samples = malloc(num_samples * sizeof(double));
    if (samples == NULL) {
        printf("Error: Could not allocate memory for samples.\n");
        exit(1);
    }

    // Generate samples
    for (sample_index = 0; sample_index < num_samples; sample_index++) {
        sample_value = amplitude * sin(2.0 * M_PI * frequency * (sample_index / SAMPLE_RATE) + phase);
        samples[sample_index] = sample_value;
    }

    // Apply window function
    double window[WINDOW_SIZE];
    for (int i = 0; i < WINDOW_SIZE; i++) {
        window[i] = 0.5 * (1.0 - cos(2.0 * M_PI * i / WINDOW_SIZE));
    }
    for (int i = 0; i < num_samples; i++) {
        samples[i] *= window[i % WINDOW_SIZE];
    }

    // Write samples to output file
    fwrite(samples, sizeof(double), num_samples, output_file);

    // Close output file
    fclose(output_file);

    // Free memory
    free(samples);

    return 0;
}