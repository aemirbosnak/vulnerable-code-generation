//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the input signal
double input_signal[] = {0.0, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5, 5.0};

// Define the filter coefficients (FIR filter)
double filter_coeffs[] = {0.1, 0.2, 0.3, 0.4, 0.5};

// Function to perform convolution
double *convolve(double *input, int input_len, double *filter, int filter_len) {
    // Allocate memory for the output signal
    double *output = (double *)malloc(sizeof(double) * (input_len + filter_len - 1));

    // Initialize the output signal to zero
    for (int i = 0; i < input_len + filter_len - 1; i++) {
        output[i] = 0.0;
    }

    // Perform the convolution
    for (int i = 0; i < input_len; i++) {
        for (int j = 0; j < filter_len; j++) {
            output[i + j] += input[i] * filter[j];
        }
    }

    // Return the output signal
    return output;
}

// Main function
int main() {
    // Get the lengths of the input signal and the filter
    int input_len = sizeof(input_signal) / sizeof(double);
    int filter_len = sizeof(filter_coeffs) / sizeof(double);

    // Perform convolution
    double *output = convolve(input_signal, input_len, filter_coeffs, filter_len);

    // Print the output signal
    printf("Output signal:\n");
    for (int i = 0; i < input_len + filter_len - 1; i++) {
        printf("%f ", output[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(output);

    return 0;
}