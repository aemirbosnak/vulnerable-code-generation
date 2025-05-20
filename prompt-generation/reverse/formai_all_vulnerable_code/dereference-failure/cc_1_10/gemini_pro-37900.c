//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the input signal
double input_signal[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};

// Define the filter coefficients
double filter_coefficients[] = {0.1, 0.2, 0.3, 0.4, 0.5};

// Function to perform convolution
double *convolve(double *input_signal, int input_signal_length, double *filter_coefficients, int filter_coefficients_length) {
    // Allocate memory for the output signal
    double *output_signal = (double *)malloc(input_signal_length + filter_coefficients_length - 1);

    // Perform the convolution
    for (int i = 0; i < input_signal_length + filter_coefficients_length - 1; i++) {
        double sum = 0.0;
        for (int j = 0; j < filter_coefficients_length; j++) {
            if (i - j >= 0 && i - j < input_signal_length) {
                sum += input_signal[i - j] * filter_coefficients[j];
            }
        }
        output_signal[i] = sum;
    }

    // Return the output signal
    return output_signal;
}

// Main function
int main() {
    // Get the length of the input signal
    int input_signal_length = sizeof(input_signal) / sizeof(double);

    // Get the length of the filter coefficients
    int filter_coefficients_length = sizeof(filter_coefficients) / sizeof(double);

    // Perform the convolution
    double *output_signal = convolve(input_signal, input_signal_length, filter_coefficients, filter_coefficients_length);

    // Print the output signal
    for (int i = 0; i < input_signal_length + filter_coefficients_length - 1; i++) {
        printf("%f ", output_signal[i]);
    }

    printf("\n");

    // Free the memory allocated for the output signal
    free(output_signal);

    return 0;
}