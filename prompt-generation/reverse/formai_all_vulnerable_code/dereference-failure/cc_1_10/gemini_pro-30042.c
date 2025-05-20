//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to generate a sine wave
double sine_wave(double frequency, double amplitude, double phase, double time) {
    return amplitude * sin(2 * PI * frequency * time + phase);
}

// Function to apply a moving average filter to a signal
double moving_average(double *signal, int window_size, int index) {
    double sum = 0;
    for (int i = index - window_size + 1; i <= index; i++) {
        sum += signal[i];
    }
    return sum / window_size;
}

int main() {
    // Generate a sine wave
    int sample_rate = 1000;
    int num_samples = 1000;
    double frequency = 100;
    double amplitude = 1;
    double phase = 0;
    double time_step = 1.0 / sample_rate;
    double *signal = malloc(num_samples * sizeof(double));
    for (int i = 0; i < num_samples; i++) {
        signal[i] = sine_wave(frequency, amplitude, phase, i * time_step);
    }

    // Apply a moving average filter to the signal
    int window_size = 10;
    double *filtered_signal = malloc(num_samples * sizeof(double));
    for (int i = 0; i < num_samples; i++) {
        filtered_signal[i] = moving_average(signal, window_size, i);
    }

    // Plot the original and filtered signals
    for (int i = 0; i < num_samples; i++) {
        printf("%f, %f\n", signal[i], filtered_signal[i]);
    }

    // Free the allocated memory
    free(signal);
    free(filtered_signal);

    return 0;
}