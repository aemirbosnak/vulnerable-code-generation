//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the input signal
double input_signal[] = {1.0, 2.0, 3.0, 4.0, 5.0};
int input_signal_length = 5;

// Define the filter coefficients
double filter_coefficients[] = {0.25, 0.5, 0.25};
int filter_coefficients_length = 3;

// Perform convolution
double *convolve(double *input_signal, int input_signal_length, double *filter_coefficients, int filter_coefficients_length) {
    // Allocate memory for the output signal
    double *output_signal = (double *)malloc(input_signal_length + filter_coefficients_length - 1);

    // Perform convolution
    for (int i = 0; i < input_signal_length + filter_coefficients_length - 1; i++) {
        output_signal[i] = 0.0;
        for (int j = 0; j < filter_coefficients_length; j++) {
            if (i - j >= 0 && i - j < input_signal_length) {
                output_signal[i] += input_signal[i - j] * filter_coefficients[j];
            }
        }
    }

    // Return the output signal
    return output_signal;
}

// Print the signal
void print_signal(double *signal, int signal_length) {
    for (int i = 0; i < signal_length; i++) {
        printf("%f ", signal[i]);
    }
    printf("\n");
}

// Main function
int main() {
    // Convolve the input signal with the filter coefficients
    double *output_signal = convolve(input_signal, input_signal_length, filter_coefficients, filter_coefficients_length);

    // Print the input signal
    printf("Input signal: ");
    print_signal(input_signal, input_signal_length);

    // Print the filter coefficients
    printf("Filter coefficients: ");
    print_signal(filter_coefficients, filter_coefficients_length);

    // Print the output signal
    printf("Output signal: ");
    print_signal(output_signal, input_signal_length + filter_coefficients_length - 1);

    // Free the memory allocated for the output signal
    free(output_signal);

    return 0;
}