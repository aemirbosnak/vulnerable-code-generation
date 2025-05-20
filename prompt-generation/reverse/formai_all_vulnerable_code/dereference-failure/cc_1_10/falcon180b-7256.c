//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the sampling frequency and the number of samples
#define SAMPLE_RATE 44100
#define NUM_SAMPLES 1024

// Define the signal frequency
#define SIGNAL_FREQUENCY 440

// Define the signal amplitude
#define SIGNAL_AMPLITUDE 0.5

// Define the window function
#define WINDOW_FUNCTION "hamming"

int main(void) {

    // Allocate memory for the signal
    double *signal = (double *) malloc(NUM_SAMPLES * sizeof(double));

    // Initialize the signal with zeros
    for (int i = 0; i < NUM_SAMPLES; i++) {
        signal[i] = 0.0;
    }

    // Generate the signal
    for (int i = 0; i < NUM_SAMPLES; i++) {
        double t = (double) i / SAMPLE_RATE;
        signal[i] = SIGNAL_AMPLITUDE * sin(2 * M_PI * SIGNAL_FREQUENCY * t);
    }

    // Apply the window function
    if (strcmp(WINDOW_FUNCTION, "hamming") == 0) {
        for (int i = 0; i < NUM_SAMPLES; i++) {
            signal[i] *= 0.54 - 0.46 * cos(2 * M_PI * i / (NUM_SAMPLES - 1));
        }
    }

    // Print the signal
    for (int i = 0; i < NUM_SAMPLES; i++) {
        printf("%f\n", signal[i]);
    }

    // Free the memory
    free(signal);

    return 0;
}