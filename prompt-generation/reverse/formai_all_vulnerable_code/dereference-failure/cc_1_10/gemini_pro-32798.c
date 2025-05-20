//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the input signal
int input_signal[] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9
};
int input_signal_size = sizeof(input_signal) / sizeof(int);

// Define the filter coefficients
float filter_coefficients[] = {
    0.1, 0.2, 0.3, 0.4, 0.5
};
int filter_coefficients_size = sizeof(filter_coefficients) / sizeof(float);

// Perform the convolution operation
int *convolve(int *input_signal, int input_signal_size, float *filter_coefficients, int filter_coefficients_size) {
    int *output_signal = malloc(sizeof(int) * (input_signal_size + filter_coefficients_size - 1));

    for (int i = 0; i < input_signal_size + filter_coefficients_size - 1; i++) {
        output_signal[i] = 0;
        for (int j = 0; j < filter_coefficients_size; j++) {
            if (i - j >= 0 && i - j < input_signal_size) {
                output_signal[i] += input_signal[i - j] * filter_coefficients[j];
            }
        }
    }

    return output_signal;
}

// Print the output signal
void print_output_signal(int *output_signal, int output_signal_size) {
    printf("Output signal:\n");
    for (int i = 0; i < output_signal_size; i++) {
        printf("%d ", output_signal[i]);
    }
    printf("\n");
}

int main() {
    // Perform the convolution operation
    int *output_signal = convolve(input_signal, input_signal_size, filter_coefficients, filter_coefficients_size);

    // Print the output signal
    print_output_signal(output_signal, input_signal_size + filter_coefficients_size - 1);

    free(output_signal);

    return 0;
}