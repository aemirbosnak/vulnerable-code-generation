//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: active
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SAMPLE_RATE 1000  // Samples per second
#define FREQUENCY 5       // Frequency of the input signal
#define DURATION 2        // Duration in seconds
#define NOISE_LEVEL 0.5   // Amplitude of noise
#define ALPHA 0.1         // Low-pass filter constant

void generate_signal(double* signal, int length) {
    for (int i = 0; i < length; i++) {
        double time = (double)i / SAMPLE_RATE;
        // Generate a noisy sinusoidal signal
        signal[i] = sin(2 * M_PI * FREQUENCY * time) + (NOISE_LEVEL * ((double)rand() / RAND_MAX * 2 - 1));
    }
}

void apply_low_pass_filter(double* input, double* output, int length) {
    output[0] = input[0];  // Initialize the first value
    for (int i = 1; i < length; i++) {
        output[i] = ALPHA * input[i] + (1 - ALPHA) * output[i - 1];
    }
}

void print_signals(double* original, double* filtered, int length) {
    printf("Time(s)\tOriginal Signal\tFiltered Signal\n");
    for (int i = 0; i < length; i++) {
        double time = (double)i / SAMPLE_RATE;
        printf("%.3f\t%.3f\t\t%.3f\n", time, original[i], filtered[i]);
    }
}

int main() {
    int num_samples = SAMPLE_RATE * DURATION;
    double* signal = (double*)malloc(num_samples * sizeof(double));
    double* filtered_signal = (double*)malloc(num_samples * sizeof(double));

    if (signal == NULL || filtered_signal == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Generate the original noisy signal
    generate_signal(signal, num_samples);

    // Apply the low-pass filter
    apply_low_pass_filter(signal, filtered_signal, num_samples);

    // Print the results
    print_signals(signal, filtered_signal, num_samples);

    // Free allocated memory
    free(signal);
    free(filtered_signal);

    return 0;
}