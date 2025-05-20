//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: brave
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SAMPLE_RATE 8000
#define DURATION 1.0
#define FREQUENCY 440.0 // A4 note
#define PI 3.14159265358979

#define FILTER_ORDER 5

// Function to generate a sine wave signal
void generate_sine_wave(double *signal, int length, double frequency, double sample_rate) {
    for (int i = 0; i < length; i++) {
        signal[i] = sin(2 * PI * frequency * (i / sample_rate));
    }
}

// Function to apply a simple low-pass filter using a moving average
void low_pass_filter(double *input, double *output, int length, int order) {
    for (int i = 0; i < length; i++) {
        output[i] = 0;
        int count = 0;
        for (int j = -order / 2; j <= order / 2; j++) {
            if (i + j >= 0 && i + j < length) {
                output[i] += input[i + j];
                count++;
            }
        }
        output[i] /= count; // Average the sum
    }
}

// Function to print a simple text-based graph
void print_signal(double *signal, int length) {
    for (int i = 0; i < length; i++) {
        int amplitude = (int)(signal[i] * 10);
        for (int j = 0; j < amplitude + 10; j++) {
            putchar(' ');
        }
        putchar('*');
        putchar('\n');
    }
}

int main() {
    int length = (int)(SAMPLE_RATE * DURATION);
    double *sine_wave = (double *)malloc(length * sizeof(double));
    double *filtered_signal = (double *)malloc(length * sizeof(double));

    // Generate sine wave
    generate_sine_wave(sine_wave, length, FREQUENCY, SAMPLE_RATE);

    // Apply low-pass filter
    low_pass_filter(sine_wave, filtered_signal, length, FILTER_ORDER);

    // Print original sine wave
    printf("Original Sine Wave:\n");
    print_signal(sine_wave, length);

    // Print filtered sine wave
    printf("\nFiltered Sine Wave (Low Pass Filter):\n");
    print_signal(filtered_signal, length);

    // Cleanup
    free(sine_wave);
    free(filtered_signal);

    return 0;
}