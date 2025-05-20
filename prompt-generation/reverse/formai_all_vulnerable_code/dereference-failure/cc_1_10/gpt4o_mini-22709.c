//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100 // Samples per second
#define DURATION 1.0 // Duration of the signal in seconds
#define FREQUENCY 440.0 // Frequency of the sine wave (Hz)
#define FILTER_COF 0.1 // Coefficient for the low-pass filter

void generate_sine_wave(double *signal, int num_samples, double frequency, double sample_rate) {
    for (int i = 0; i < num_samples; i++) {
        signal[i] = sin(2 * M_PI * frequency * (i / sample_rate));
    }
}

void low_pass_filter(double *input, double *output, int num_samples, double filter_coefficient) {
    output[0] = input[0]; // First sample is the same

    for (int i = 1; i < num_samples; i++) {
        output[i] = filter_coefficient * input[i] + (1 - filter_coefficient) * output[i - 1];
    }
}

void save_to_csv(const char *filename, double *signal, int num_samples) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < num_samples; i++) {
        fprintf(file, "%d,%f\n", i, signal[i]);
    }

    fclose(file);
}

int main() {
    int num_samples = (int)(SAMPLE_RATE * DURATION);
    double *sine_wave = (double *)malloc(num_samples * sizeof(double));
    double *filtered_signal = (double *)malloc(num_samples * sizeof(double));

    if (sine_wave == NULL || filtered_signal == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    // Generate sine wave
    generate_sine_wave(sine_wave, num_samples, FREQUENCY, SAMPLE_RATE);

    // Apply low-pass filter
    low_pass_filter(sine_wave, filtered_signal, num_samples, FILTER_COF);

    // Save filtered signal to a CSV file
    save_to_csv("filtered_signal.csv", filtered_signal, num_samples);

    // Free allocated memory
    free(sine_wave);
    free(filtered_signal);

    printf("Sine wave generated, filtered, and saved to 'filtered_signal.csv'.\n");
    return EXIT_SUCCESS;
}