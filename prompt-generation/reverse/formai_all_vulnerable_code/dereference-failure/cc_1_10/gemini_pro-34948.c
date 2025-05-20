//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <inttypes.h>
#include <string.h>

// Define the maximum length of the signal
#define MAX_SIGNAL_LENGTH 1024

// Function to generate a random signal
double *generate_signal(int length) {
    double *signal = malloc(length * sizeof(double));
    for (int i = 0; i < length; i++) {
        signal[i] = (double)rand() / RAND_MAX;
    }
    return signal;
}

// Function to apply a moving average filter to a signal
double *moving_average_filter(double *signal, int length, int window_size) {
    double *filtered_signal = malloc(length * sizeof(double));
    for (int i = 0; i < length; i++) {
        if (i < window_size / 2) {
            double sum = 0.0;
            for (int j = 0; j <= i; j++) {
                sum += signal[j];
            }
            filtered_signal[i] = sum / (i + 1);
        } else if (i >= length - window_size / 2) {
            double sum = 0.0;
            for (int j = i - window_size / 2; j <= i; j++) {
                sum += signal[j];
            }
            filtered_signal[i] = sum / window_size;
        } else {
            double sum = 0.0;
            for (int j = i - window_size / 2; j <= i + window_size / 2; j++) {
                sum += signal[j];
            }
            filtered_signal[i] = sum / window_size;
        }
    }
    return filtered_signal;
}

// Function to plot a signal
void plot_signal(double *signal, int length) {
    printf("Signal:\n");
    for (int i = 0; i < length; i++) {
        printf("%f ", signal[i]);
    }
    printf("\n");
}

int main() {
    // Generate a random signal
    double *signal = generate_signal(MAX_SIGNAL_LENGTH);

    // Plot the original signal
    plot_signal(signal, MAX_SIGNAL_LENGTH);

    // Apply a moving average filter to the signal with a window size of 10
    double *filtered_signal = moving_average_filter(signal, MAX_SIGNAL_LENGTH, 10);

    // Plot the filtered signal
    plot_signal(filtered_signal, MAX_SIGNAL_LENGTH);

    // Free the memory allocated for the signals
    free(signal);
    free(filtered_signal);

    return 0;
}