//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define NUM_SAMPLES 1024

// Function to generate a synthetic audio signal (sine wave)
void generate_sine_wave(double *signal, double frequency, double duration) {
    for (int i = 0; i < SAMPLE_RATE * duration; i++) {
        signal[i] = sin(2.0 * M_PI * frequency * ((double)i / SAMPLE_RATE));
    }
}

// Simple Low Pass Filter implementation
void low_pass_filter(double *input, double *output, double alpha, int num_samples) {
    output[0] = input[0]; // Initialize the first sample
    for (int i = 1; i < num_samples; i++) {
        output[i] = alpha * input[i] + (1.0 - alpha) * output[i - 1];
    }
}

// Function to print samples
void print_samples(double *samples, int num_samples) {
    for (int i = 0; i < num_samples; i++) {
        printf("%lf\n", samples[i]);
    }
}

int main() {
    double *input_signal = (double *)malloc(NUM_SAMPLES * sizeof(double));
    double *filtered_signal = (double *)malloc(NUM_SAMPLES * sizeof(double));

    if (input_signal == NULL || filtered_signal == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    // Generate a 440Hz sine wave signal for 1 second
    double frequency = 440.0; // A4 note frequency
    double duration = 1.0;    // 1 second
    generate_sine_wave(input_signal, frequency, duration);

    // Apply the Low Pass Filter
    double alpha = 0.1; // Filter coefficient (adjustable)
    low_pass_filter(input_signal, filtered_signal, alpha, SAMPLE_RATE * duration);

    // Print the original and filtered samples
    printf("Original Signal (Sine Wave):\n");
    print_samples(input_signal, SAMPLE_RATE * duration);

    printf("\nFiltered Signal (Low Pass):\n");
    print_samples(filtered_signal, SAMPLE_RATE * duration);

    // Free allocated memory
    free(input_signal);
    free(filtered_signal);

    return EXIT_SUCCESS;
}