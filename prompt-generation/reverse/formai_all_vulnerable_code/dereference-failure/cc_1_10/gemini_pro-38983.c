//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the input signal
double input_signal[] = {
    0.0, 0.5, 1.0, 0.5, 0.0,
    -0.5, -1.0, -0.5, 0.0, 0.5
};

// Define the filter coefficients
double filter_coefficients[] = {
    0.2, 0.4, 0.6, 0.8, 1.0
};

// Perform convolution between the input signal and the filter coefficients
double *convolve(double *input_signal, int input_length, double *filter_coefficients, int filter_length) {
    // Allocate memory for the output signal
    double *output_signal = (double *)malloc(input_length + filter_length - 1);

    // Perform convolution
    for (int i = 0; i < input_length + filter_length - 1; i++) {
        output_signal[i] = 0.0;

        for (int j = 0; j < filter_length; j++) {
            if (i - j >= 0 && i - j < input_length) {
                output_signal[i] += input_signal[i - j] * filter_coefficients[j];
            }
        }
    }

    // Return the output signal
    return output_signal;
}

// Print the output signal
void print_output_signal(double *output_signal, int output_length) {
    for (int i = 0; i < output_length; i++) {
        printf("%f ", output_signal[i]);
    }
    printf("\n");
}

int main() {
    // Get the length of the input signal
    int input_length = sizeof(input_signal) / sizeof(double);

    // Get the length of the filter coefficients
    int filter_length = sizeof(filter_coefficients) / sizeof(double);

    // Perform convolution
    double *output_signal = convolve(input_signal, input_length, filter_coefficients, filter_length);

    // Print the output signal
    print_output_signal(output_signal, input_length + filter_length - 1);

    // Free the allocated memory
    free(output_signal);

    return 0;
}