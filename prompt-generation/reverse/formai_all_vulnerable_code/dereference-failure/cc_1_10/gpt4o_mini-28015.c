//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define SAMPLE_RATE 8000   // Sample rate in Hz
#define FREQUENCY 440      // Frequency of the sine wave in Hz
#define DURATION 1         // Duration in seconds
#define FILTER_COEFFICIENT 0.1 // Low-pass filter coefficient
#define PI 3.14159265
#define ASCII_HEIGHT 10    // Height of ASCII output

// Function prototypes
void generate_sine_wave(float *buffer, int samples);
void apply_low_pass_filter(float *input, float *output, int samples);
void print_waveform(float *wave, int samples);

int main() {
    int total_samples = SAMPLE_RATE * DURATION;
    float *sine_wave = (float *)malloc(total_samples * sizeof(float));
    float *filtered_wave = (float *)malloc(total_samples * sizeof(float));

    // Generate the sine wave
    generate_sine_wave(sine_wave, total_samples);
    
    // Apply the low-pass filter
    apply_low_pass_filter(sine_wave, filtered_wave, total_samples);
    
    // Print original and filtered waveform
    printf("Original Sine Wave:\n");
    print_waveform(sine_wave, total_samples);
    printf("\nFiltered Sine Wave:\n");
    print_waveform(filtered_wave, total_samples);

    // Free allocated memory
    free(sine_wave);
    free(filtered_wave);
    
    return 0;
}

// Function to generate a sine wave signal
void generate_sine_wave(float *buffer, int samples) {
    for (int i = 0; i < samples; i++) {
        buffer[i] = sin(2 * PI * FREQUENCY * i / SAMPLE_RATE);
    }
}

// Function to apply a basic low-pass filter
void apply_low_pass_filter(float *input, float *output, int samples) {
    output[0] = input[0]; // Initialize the first sample
    for (int i = 1; i < samples; i++) {
        output[i] = FILTER_COEFFICIENT * input[i] + (1 - FILTER_COEFFICIENT) * output[i - 1];
    }
}

// Function to print the waveform as ASCII art
void print_waveform(float *wave, int samples) {
    for (int i = 0; i < samples; i += (SAMPLE_RATE / ASCII_HEIGHT)) {
        int height = (int)((wave[i] + 1.0) / 2.0 * ASCII_HEIGHT); // Normalize to range
        for (int j = 0; j < height; j++) {
            putchar('*');
        }
        putchar('\n');
    }
    putchar('\n');
}