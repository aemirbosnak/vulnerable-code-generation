//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SAMPLE_RATE 1000   // Samples per second
#define FREQUENCY 5        // Frequency of the sine wave
#define DURATION 1         // Duration in seconds
#define N_SAMPLES (DURATION * SAMPLE_RATE) // Total samples
#define FILTER_SIZE 5      // Size of the moving average filter

void generate_sine_wave(double *signal, int n_samples) {
    for (int i = 0; i < n_samples; i++) {
        signal[i] = sin(2 * M_PI * FREQUENCY * (i / (double)SAMPLE_RATE));
    }
}

void moving_average_filter(double *input, double *output, int n_samples, int filter_size) {
    for (int i = 0; i < n_samples; i++) {
        double sum = 0.0;
        int count = 0;

        for (int j = -filter_size/2; j <= filter_size/2; j++) {
            if (i + j >= 0 && i + j < n_samples) {
                sum += input[i + j];
                count++;
            }
        }
        output[i] = sum / count; // Calculate the average
    }
}

void print_signal(const double *signal, int n_samples) {
    for (int i = 0; i < n_samples; i++) {
        printf("%d: %f\n", i, signal[i]);
    }
}

int main() {
    double *sine_wave = malloc(N_SAMPLES * sizeof(double));
    double *filtered_signal = malloc(N_SAMPLES * sizeof(double));

    if (sine_wave == NULL || filtered_signal == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    // Generate sine wave
    generate_sine_wave(sine_wave, N_SAMPLES);
    
    // Apply moving average filter
    moving_average_filter(sine_wave, filtered_signal, N_SAMPLES, FILTER_SIZE);

    // Print original and filtered signals
    printf("Original Signal (Sine Wave):\n");
    print_signal(sine_wave, N_SAMPLES);
    
    printf("\nFiltered Signal (Moving Average):\n");
    print_signal(filtered_signal, N_SAMPLES);

    // Free memory
    free(sine_wave);
    free(filtered_signal);

    return 0;
}