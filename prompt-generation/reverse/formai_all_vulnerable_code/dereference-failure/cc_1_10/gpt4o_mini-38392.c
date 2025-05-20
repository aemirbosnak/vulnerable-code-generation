//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100 // Samples per second
#define DURATION 2        // Duration in seconds
#define N (SAMPLE_RATE * DURATION) // Total number of samples
#define FILTER_LENGTH 10 // Length of the moving average filter

// Function to generate a sine wave signal
void generate_sine_wave(double *signal, double frequency) {
    for (int i = 0; i < N; i++) {
        signal[i] = sin(2 * M_PI * frequency * ((double)i / SAMPLE_RATE));
    }
}

// Function to apply a simple moving average filter
void apply_low_pass_filter(double *input_signal, double *output_signal) {
    double filter_sum = 0.0;

    for (int i = 0; i < N; i++) {
        filter_sum = 0.0;
        for (int j = 0; j < FILTER_LENGTH; j++) {
            if (i - j >= 0) {
                filter_sum += input_signal[i - j];
            }
        }
        output_signal[i] = filter_sum / FILTER_LENGTH;
    }
}

// Function to write signals to a CSV file
void write_to_csv(const char *filename, double *original, double *filtered) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Error opening file for writing\n");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "Time,Original,Filtered\n");
    for (int i = 0; i < N; i++) {
        fprintf(file, "%lf,%lf,%lf\n", (double)i / SAMPLE_RATE, original[i], filtered[i]);
    }
    fclose(file);
}

int main() {
    double *original_signal = (double *)malloc(N * sizeof(double));
    double *filtered_signal = (double *)malloc(N * sizeof(double));
    double frequency = 5.0; // Frequency of the sine wave in Hz

    // Generate a sine wave signal
    generate_sine_wave(original_signal, frequency);

    // Apply moving average low-pass filter
    apply_low_pass_filter(original_signal, filtered_signal);

    // Write the original and filtered signals to a CSV file
    write_to_csv("signals.csv", original_signal, filtered_signal);

    // Free allocated memory
    free(original_signal);
    free(filtered_signal);

    printf("DSP processing complete. Output written to signals.csv\n");
    return 0;
}