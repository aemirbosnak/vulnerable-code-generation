//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define PI 3.14159265358979323846
#define FREQ 440.0 // Frequency of the sine wave
#define DURATION 1.0 // Duration of the signal in seconds
#define ALPHA 0.1 // Low-pass filter coefficient

// Function to generate a sine wave
void generate_sine_wave(float *buffer, int samples) {
    for (int i = 0; i < samples; i++) {
        buffer[i] = (float)sin(2 * PI * FREQ * (i / (float)SAMPLE_RATE));
    }
}

// Function to apply a simple low-pass filter
void low_pass_filter(float *input_buffer, float *output_buffer, int samples) {
    output_buffer[0] = input_buffer[0]; // Initialize the first sample
    for (int i = 1; i < samples; i++) {
        output_buffer[i] = ALPHA * input_buffer[i] + (1 - ALPHA) * output_buffer[i - 1];
    }
}

int main() {
    int samples = (int)(SAMPLE_RATE * DURATION);
    float *input_buffer = (float *)malloc(samples * sizeof(float));
    float *output_buffer = (float *)malloc(samples * sizeof(float));

    if (input_buffer == NULL || output_buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Generate a sine wave
    generate_sine_wave(input_buffer, samples);
    
    // Apply low-pass filter
    low_pass_filter(input_buffer, output_buffer, samples);

    // Write the filtered signal to a file
    FILE *output_file = fopen("filtered_output.txt", "w");
    if (!output_file) {
        fprintf(stderr, "Could not open output file for writing\n");
        free(input_buffer);
        free(output_buffer);
        return 1;
    }

    for (int i = 0; i < samples; i++) {
        fprintf(output_file, "%f\n", output_buffer[i]);
    }

    fclose(output_file);
    free(input_buffer);
    free(output_buffer);

    printf("Sine wave generated and filtered output saved to filtered_output.txt\n");
    return 0;
}