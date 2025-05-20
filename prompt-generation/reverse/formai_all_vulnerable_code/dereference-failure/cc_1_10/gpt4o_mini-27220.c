//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 512  // Hz
#define DURATION 2       // seconds
#define PI 3.14159265359
#define ALPHA 0.1        // Smoothing factor for the low pass filter

// Function to generate a sine wave signal
void generate_sine_wave(float *signal, int frequency, int samples) {
    for(int i = 0; i < samples; i++) {
        signal[i] = sin(2 * PI * frequency * i / SAMPLE_RATE);
    }
}

// Function to apply a simple low-pass filter
void apply_low_pass_filter(float *input, float *output, int samples) {
    output[0] = input[0];  // Initialize the first sample
    for(int i = 1; i < samples; i++) {
        output[i] = ALPHA * input[i] + (1 - ALPHA) * output[i - 1];
    }
}

// Function to print the signal
void print_signal(const char *title, float *signal, int samples) {
    printf("%s:\n", title);
    for(int i = 0; i < samples; i++) {
        printf("%d: %.4f\n", i, signal[i]);
    }
}

int main() {
    int total_samples = SAMPLE_RATE * DURATION;
    float *sine_wave = (float *)malloc(sizeof(float) * total_samples);
    float *filtered_signal = (float *)malloc(sizeof(float) * total_samples);

    if (sine_wave == NULL || filtered_signal == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    // Generate a sine wave of 5 Hz
    generate_sine_wave(sine_wave, 5, total_samples);
    
    // Apply a low pass filter to the generated sine wave
    apply_low_pass_filter(sine_wave, filtered_signal, total_samples);
    
    // Print the original and filtered signals
    print_signal("Original Sine Wave", sine_wave, total_samples);
    print_signal("Filtered Signal", filtered_signal, total_samples);

    // Cleanup
    free(sine_wave);
    free(filtered_signal);

    return 0;
}