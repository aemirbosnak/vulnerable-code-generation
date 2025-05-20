//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 1000
#define DURATION 1
#define NOISE_LEVEL 0.1
#define FILTER_SIZE 5

// Function to generate a sinusoidal signal
void generate_signal(double *signal, int length, double frequency) {
    for (int i = 0; i < length; i++) {
        signal[i] = sin(2 * M_PI * frequency * i / SAMPLE_RATE);
    }
}

// Function to add noise to the signal
void add_noise(double *signal, int length, double noise_level) {
    for (int i = 0; i < length; i++) {
        double noise = ((double)rand() / RAND_MAX) * 2.0 - 1.0; // Noise in range [-1, 1]
        signal[i] += noise * noise_level;
    }
}

// Function to apply a simple Moving Average Filter
void moving_average_filter(double *input_signal, double *output_signal, int length, int filter_size) {
    for (int i = 0; i < length; i++) {
        double sum = 0.0;
        int count = 0;
        
        for (int j = -filter_size / 2; j <= filter_size / 2; j++) {
            int index = i + j;
            if (index >= 0 && index < length) {
                sum += input_signal[index];
                count++;
            }
        }
        
        output_signal[i] = sum / count;
    }
}

// Function to print a signal
void print_signal(double *signal, int length) {
    for (int i = 0; i < length; i++) {
        printf("%f\n", signal[i]);
    }
}

int main() {
    int total_samples = SAMPLE_RATE * DURATION;
    double *signal = (double *)malloc(total_samples * sizeof(double));
    double *noisy_signal = (double *)malloc(total_samples * sizeof(double));
    double *filtered_signal = (double *)malloc(total_samples * sizeof(double));
    
    if (!signal || !noisy_signal || !filtered_signal) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    // Set a frequency for the signal
    double frequency = 5.0; // 5 Hz sinusoidal signal

    // Generate the signal
    generate_signal(signal, total_samples, frequency);

    // Add noise to the signal
    add_noise(signal, total_samples, NOISE_LEVEL);

    // Apply Moving Average Filter
    moving_average_filter(signal, filtered_signal, total_samples, FILTER_SIZE);

    // Print the original noisy signal
    printf("Noisy Signal:\n");
    print_signal(signal, total_samples);

    // Print the filtered signal
    printf("Filtered Signal:\n");
    print_signal(filtered_signal, total_samples);

    // Free allocated memory
    free(signal);
    free(noisy_signal);
    free(filtered_signal);

    return EXIT_SUCCESS;
}