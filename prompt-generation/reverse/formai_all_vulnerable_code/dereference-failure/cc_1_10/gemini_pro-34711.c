//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Define the input signal
double input_signal[] = {1.0, 2.0, 3.0, 4.0, 5.0};
const int input_signal_length = 5;

// Define the filter kernel
double filter_kernel[] = {0.1, 0.2, 0.3, 0.4, 0.5};
const int filter_kernel_length = 5;

// Perform convolution between the input signal and the filter kernel
double *convolve(double *input_signal, int input_signal_length, double *filter_kernel, int filter_kernel_length) {
    // Allocate memory for the output signal
    double *output_signal = malloc(input_signal_length + filter_kernel_length - 1);

    // Initialize the output signal to zero
    for (int i = 0; i < input_signal_length + filter_kernel_length - 1; i++) {
        output_signal[i] = 0.0;
    }

    // Perform convolution
    for (int i = 0; i < input_signal_length; i++) {
        for (int j = 0; j < filter_kernel_length; j++) {
            output_signal[i + j] += input_signal[i] * filter_kernel[j];
        }
    }

    // Return the output signal
    return output_signal;
}

// Print the input signal, filter kernel, and output signal
void print_signals(double *input_signal, int input_signal_length, double *filter_kernel, int filter_kernel_length, double *output_signal) {
    // Print the input signal
    printf("Input signal:\n");
    for (int i = 0; i < input_signal_length; i++) {
        printf("%f ", input_signal[i]);
    }
    printf("\n");

    // Print the filter kernel
    printf("Filter kernel:\n");
    for (int i = 0; i < filter_kernel_length; i++) {
        printf("%f ", filter_kernel[i]);
    }
    printf("\n");

    // Print the output signal
    printf("Output signal:\n");
    for (int i = 0; i < input_signal_length + filter_kernel_length - 1; i++) {
        printf("%f ", output_signal[i]);
    }
    printf("\n");
}

int main() {
    // Perform convolution
    double *output_signal = convolve(input_signal, input_signal_length, filter_kernel, filter_kernel_length);

    // Print the input signal, filter kernel, and output signal
    print_signals(input_signal, input_signal_length, filter_kernel, filter_kernel_length, output_signal);

    // Free the memory allocated for the output signal
    free(output_signal);

    return 0;
}