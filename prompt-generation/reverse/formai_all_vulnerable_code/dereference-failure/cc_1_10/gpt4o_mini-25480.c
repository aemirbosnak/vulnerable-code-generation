//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: cheerful
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Constants
#define SAMPLE_RATE 1000
#define FREQUENCY 5
#define AMPLITUDE 1.0
#define DURATION 1.0
#define ALPHA 0.1  // Low-pass filter coefficient

// Function to generate a sinusoidal signal
void generate_sine_wave(double *signal, int num_samples) {
    for (int i = 0; i < num_samples; i++) {
        double t = (double)i / SAMPLE_RATE;
        signal[i] = AMPLITUDE * sin(2 * M_PI * FREQUENCY * t);
    }
}

// Function to apply a low-pass filter
void low_pass_filter(double *input_signal, double *output_signal, int num_samples) {
    output_signal[0] = input_signal[0]; // Initialize the first sample
    for (int i = 1; i < num_samples; i++) {
        output_signal[i] = ALPHA * input_signal[i] + (1 - ALPHA) * output_signal[i - 1];
    }
}

// Function to display the signals
void display_signals(double *original_signal, double *filtered_signal, int num_samples) {
    printf("Original Signal\t\tFiltered Signal\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < num_samples; i++) {
        printf("%0.4f\t\t%0.4f\n", original_signal[i], filtered_signal[i]);
    }
}

int main() {
    // Calculate number of samples
    int num_samples = (int)(SAMPLE_RATE * DURATION);

    // Allocate memory for signals
    double *original_signal = (double *)malloc(num_samples * sizeof(double));
    double *filtered_signal = (double *)malloc(num_samples * sizeof(double));

    if (original_signal == NULL || filtered_signal == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Generate the sinusoidal signal
    generate_sine_wave(original_signal, num_samples);
    printf("🎶 A magical sine wave has been generated! 🎶\n");

    // Apply the low-pass filter
    low_pass_filter(original_signal, filtered_signal, num_samples);
    printf("✨ The filter has worked its magic! ✨\n");

    // Display the original and filtered signals
    display_signals(original_signal, filtered_signal, num_samples);
    printf("🎉 Signal processing completed successfully! 🎉\n");

    // Free allocated memory
    free(original_signal);
    free(filtered_signal);
    
    return 0;
}