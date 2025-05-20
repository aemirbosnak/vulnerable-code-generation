//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define DURATION 2.0
#define FREQUENCY 440.0
#define PI 3.14159265358979323846
#define FILTER_COEFF 0.1

void generate_sine_wave(double *buffer, int num_samples) {
    for (int i = 0; i < num_samples; i++) {
        buffer[i] = sin(2 * PI * FREQUENCY * ((double)i / SAMPLE_RATE));
    }
}

void apply_low_pass_filter(double *input, double *output, int num_samples) {
    output[0] = input[0]; // Initialize the first sample

    for (int i = 1; i < num_samples; i++) {
        output[i] = (1 - FILTER_COEFF) * output[i - 1] + FILTER_COEFF * input[i];
    }
}

void write_to_file(const char *filename, double *buffer, int num_samples) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for writing\n");
        exit(1);
    }

    for (int i = 0; i < num_samples; i++) {
        fprintf(file, "%f\n", buffer[i]);
    }
    fclose(file);
}

int main() {
    int num_samples = (int)(DURATION * SAMPLE_RATE);
    double *sine_wave = (double *)malloc(num_samples * sizeof(double));
    double *filtered_wave = (double *)malloc(num_samples * sizeof(double));

    if (sine_wave == NULL || filtered_wave == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    generate_sine_wave(sine_wave, num_samples);
    apply_low_pass_filter(sine_wave, filtered_wave, num_samples);

    write_to_file("sine_wave.txt", sine_wave, num_samples);
    write_to_file("filtered_wave.txt", filtered_wave, num_samples);

    free(sine_wave);
    free(filtered_wave);

    printf("Sine wave and filtered wave have been written to files.\n");
    return 0;
}