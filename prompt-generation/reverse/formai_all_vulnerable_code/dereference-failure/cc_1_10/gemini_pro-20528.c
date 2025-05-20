//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: calm
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Function to generate a sine wave
float *generate_sine_wave(int num_samples, float frequency, float sampling_rate) {
    float *sine_wave = malloc(sizeof(float) * num_samples);
    for (int i = 0; i < num_samples; i++) {
        sine_wave[i] = sin(2 * M_PI * frequency * i / sampling_rate);
    }
    return sine_wave;
}

// Function to apply a moving average filter to a signal
float *moving_average_filter(float *signal, int num_samples, int window_size) {
    float *filtered_signal = malloc(sizeof(float) * num_samples);
    for (int i = 0; i < num_samples; i++) {
        float sum = 0;
        for (int j = 0; j < window_size; j++) {
            if (i - j >= 0) {
                sum += signal[i - j];
            }
        }
        filtered_signal[i] = sum / window_size;
    }
    return filtered_signal;
}

// Function to plot a signal
void plot_signal(float *signal, int num_samples) {
    for (int i = 0; i < num_samples; i++) {
        printf("%f\n", signal[i]);
    }
}

int main() {
    // Generate a sine wave
    int num_samples = 1000;
    float frequency = 10;
    float sampling_rate = 100;
    float *sine_wave = generate_sine_wave(num_samples, frequency, sampling_rate);

    // Apply a moving average filter to the sine wave
    int window_size = 10;
    float *filtered_sine_wave = moving_average_filter(sine_wave, num_samples, window_size);

    // Plot the original and filtered sine waves
    printf("Original sine wave:\n");
    plot_signal(sine_wave, num_samples);

    printf("\nFiltered sine wave:\n");
    plot_signal(filtered_sine_wave, num_samples);

    // Free the allocated memory
    free(sine_wave);
    free(filtered_sine_wave);

    return 0;
}