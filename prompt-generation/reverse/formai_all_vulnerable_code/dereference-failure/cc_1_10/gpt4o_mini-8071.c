//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILTER_ORDER 4
#define SIGNAL_LENGTH 10

// FIR Filter Coefficients (example coefficients)
double filter_coefficients[FILTER_ORDER + 1] = {0.2, 0.2, 0.2, 0.2, 0.2};

// Function to apply FIR filter
void apply_fir_filter(const double *input_signal, double *output_signal, int signal_length) {
    for (int n = 0; n < signal_length; n++) {
        output_signal[n] = 0.0; // Reset output value
        // Apply filter coefficients
        for (int k = 0; k <= FILTER_ORDER; k++) {
            if (n - k >= 0) {
                output_signal[n] += filter_coefficients[k] * input_signal[n - k];
            }
        }
    }
}

// Function to display an array of doubles
void display_signal(const char *title, const double *signal, int length) {
    printf("%s: ", title);
    for (int i = 0; i < length; i++) {
        printf("%f ", signal[i]);
    }
    printf("\n");
}

int main() {
    double *input_signal = malloc(SIGNAL_LENGTH * sizeof(double));
    double *output_signal = malloc(SIGNAL_LENGTH * sizeof(double));

    if (input_signal == NULL || output_signal == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    // Initializing an example input signal (sine wave)
    for (int i = 0; i < SIGNAL_LENGTH; i++) {
        input_signal[i] = sin(2 * 3.14159 * i / SIGNAL_LENGTH);
    }

    // Display the input signal
    display_signal("Input Signal", input_signal, SIGNAL_LENGTH);

    // Apply FIR filter
    apply_fir_filter(input_signal, output_signal, SIGNAL_LENGTH);

    // Display the output signal
    display_signal("Output Signal (Filtered)", output_signal, SIGNAL_LENGTH);

    // Free allocated memory
    free(input_signal);
    free(output_signal);

    return EXIT_SUCCESS;
}