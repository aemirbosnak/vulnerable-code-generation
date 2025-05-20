//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: invasive
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SAMPLE_RATE 44100  // Sampling rate in Hz
#define FREQUENCY 440      // Frequency of the sine wave in Hz
#define DURATION 5         // Duration in seconds
#define FILTER_ORDER 5     // Order of the low-pass filter
#define PI 3.14159265358979323846

// Function prototypes
void generate_sine_wave(double* signal, int sample_count);
void apply_low_pass_filter(double* input, double* output, int sample_count);
void print_signals(double* signal1, double* signal2, int sample_count);

int main() {
    // Total number of samples
    int sample_count = SAMPLE_RATE * DURATION;
    double* sine_wave = (double*)malloc(sample_count * sizeof(double));
    double* filtered_signal = (double*)malloc(sample_count * sizeof(double));

    // Generate sine wave
    generate_sine_wave(sine_wave, sample_count);

    // Apply low-pass filter
    apply_low_pass_filter(sine_wave, filtered_signal, sample_count);

    // Print the original and filtered signals
    print_signals(sine_wave, filtered_signal, sample_count);

    // Free allocated memory
    free(sine_wave);
    free(filtered_signal);

    return 0;
}

// Generate a sine wave
void generate_sine_wave(double* signal, int sample_count) {
    for (int i = 0; i < sample_count; i++) {
        signal[i] = sin(2 * PI * FREQUENCY * ((double)i / SAMPLE_RATE));
    }
}

// Simple low-pass filter
void apply_low_pass_filter(double* input, double* output, int sample_count) {
    double alpha = 0.1;  // Smoothing factor
    output[0] = input[0]; // Initialize first sample

    for (int i = 1; i < sample_count; i++) {
        output[i] = (1 - alpha) * output[i - 1] + alpha * input[i];
    }
}

// Print original and filtered signals
void print_signals(double* signal1, double* signal2, int sample_count) {
    FILE *fp = fopen("signals.txt", "w");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(fp, "Sample\tOriginal\tFiltered\n");
    for (int i = 0; i < sample_count; i++) {
        fprintf(fp, "%d\t%.4f\t%.4f\n", i, signal1[i], signal2[i]);
    }

    fclose(fp);
    printf("Signals have been written to signals.txt\n");
}