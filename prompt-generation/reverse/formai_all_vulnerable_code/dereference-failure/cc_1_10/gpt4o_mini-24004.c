//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the number of samples
#define NUM_SAMPLES 1024

// Function to generate a test signal
void generate_signal(double* signal, int num_samples) {
    for (int i = 0; i < num_samples; i++) {
        // Creating a combination of sine and square wave signals
        signal[i] = 0.5 * sin(2 * M_PI * 0.1 * i) + 0.5 * (i % 20 < 10 ? 1.0 : -1.0);
    }
}

// Function to apply a simple low-pass filter
void low_pass_filter(double* input, double* output, int num_samples, double alpha) {
    output[0] = input[0]; // Initialize the first sample
    for (int i = 1; i < num_samples; i++) {
        output[i] = alpha * input[i] + (1.0 - alpha) * output[i - 1];
    }
}

// Function to display the signals
void display_signals(double* original, double* filtered, int num_samples) {
    printf("Sample\tOriginal\tFiltered\n");
    for (int i = 0; i < num_samples; i++) {
        printf("%d\t%f\t%f\n", i, original[i], filtered[i]);
    }
}

int main() {
    double* signal = (double*)malloc(NUM_SAMPLES * sizeof(double));
    double* filtered_signal = (double*)malloc(NUM_SAMPLES * sizeof(double));
    
    if (signal == NULL || filtered_signal == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    // Generate the test signal
    generate_signal(signal, NUM_SAMPLES);

    // Define the smoothing factor for the low-pass filter
    double alpha = 0.1;

    // Apply the low-pass filter
    low_pass_filter(signal, filtered_signal, NUM_SAMPLES, alpha);

    // Display the original and filtered signals
    display_signals(signal, filtered_signal, NUM_SAMPLES);

    // Free allocated memory
    free(signal);
    free(filtered_signal);

    return EXIT_SUCCESS;
}