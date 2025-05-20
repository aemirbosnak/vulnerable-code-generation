//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1024  // Number of samples

// Generate a sine wave
double *generate_sine_wave(double frequency, double sampling_rate, double duration) {
    double *sine_wave = malloc(N * sizeof(double));
    for (int i = 0; i < N; i++) {
        sine_wave[i] = sin(2 * M_PI * frequency * i / sampling_rate);
    }
    return sine_wave;
}

// Apply a moving average filter to a signal
double *moving_average_filter(double *signal, int window_size) {
    double *filtered_signal = malloc(N * sizeof(double));
    for (int i = 0; i < N; i++) {
        double sum = 0;
        for (int j = i - window_size / 2; j <= i + window_size / 2; j++) {
            if (j >= 0 && j < N) {
                sum += signal[j];
            }
        }
        filtered_signal[i] = sum / window_size;
    }
    return filtered_signal;
}

// Plot a signal
void plot_signal(double *signal, int size) {
    for (int i = 0; i < size; i++) {
        printf("%f\n", signal[i]);
    }
}

int main() {
    // Generate a sine wave
    double *sine_wave = generate_sine_wave(100, 1000, 1);

    // Apply a moving average filter to the sine wave
    double *filtered_sine_wave = moving_average_filter(sine_wave, 10);

    // Plot the original and filtered sine waves
    plot_signal(sine_wave, N);
    plot_signal(filtered_sine_wave, N);

    // Free the allocated memory
    free(sine_wave);
    free(filtered_sine_wave);

    return 0;
}