//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to generate a sine wave signal
void generateSineWave(double *signal, int num_samples, double frequency, double sample_rate) {
    for (int i = 0; i < num_samples; i++) {
        signal[i] = sin(2 * M_PI * frequency * (i / sample_rate));
    }
}

// Function to apply an FIR filter to a signal
void applyFIRFilter(double *input_signal, double *output_signal, double *filter_coeffs, 
                    int num_samples, int filter_order) {
    for (int n = 0; n < num_samples; n++) {
        output_signal[n] = 0.0; // Initialize output sample
        for (int k = 0; k <= filter_order; k++) {
            if (n - k >= 0) {
                output_signal[n] += filter_coeffs[k] * input_signal[n - k];
            }
        }
    }
}

// Function to print a signal
void printSignal(double *signal, int num_samples) {
    for (int i = 0; i < num_samples; i++) {
        printf("%d: %.4f\n", i, signal[i]);
    }
}

int main() {
    // Parameters
    int num_samples = 100; // Length of the signal
    double frequency = 5.0; // Frequency of the sine wave
    double sample_rate = 100.0; // Sample rate
    int filter_order = 4; // Order of the FIR filter

    // Allocate memory for signals and filter coefficients
    double *input_signal = (double *)malloc(num_samples * sizeof(double));
    double *output_signal = (double *)malloc(num_samples * sizeof(double));
    double *filter_coeffs = (double *)malloc((filter_order + 1) * sizeof(double));

    // Design a simple low-pass FIR filter (Hamming Windowed)
    double alpha = 0.5; // Coefficient for Hamming window
    for (int i = 0; i <= filter_order; i++) {
        filter_coeffs[i] = alpha - (1 - alpha) * cos(2 * M_PI * (i / (double)filter_order));
        filter_coeffs[i] /= (double)(filter_order); // Normalize the coefficients
    }

    // Generate the sine wave signal
    generateSineWave(input_signal, num_samples, frequency, sample_rate);

    // Apply the FIR filter
    applyFIRFilter(input_signal, output_signal, filter_coeffs, num_samples, filter_order);

    // Print input and output signals
    printf("Input Signal (Sine Wave):\n");
    printSignal(input_signal, num_samples);
    printf("\nOutput Signal (Filtered):\n");
    printSignal(output_signal, num_samples);

    // Free allocated memory
    free(input_signal);
    free(output_signal);
    free(filter_coeffs);

    return 0;
}