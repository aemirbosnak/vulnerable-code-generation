//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define SAMPLE_RATE 44100
#define DURATION 2 // in seconds
#define SIGNAL_FREQUENCY 440 // A4 frequency in Hz
#define PI 3.14159265358979323846
#define MAX_SAMPLES (SAMPLE_RATE * DURATION)

// Function prototypes
void generate_sine_wave(double *signal, int num_samples);
void apply_low_pass_filter(double *signal, double *filtered_signal, int num_samples, double cutoff_frequency);
void print_signal(double *signal, int num_samples);
void cleanup(double *signal, double *filtered_signal);

int main() {
    double *signal = (double *)malloc(MAX_SAMPLES * sizeof(double));
    double *filtered_signal = (double *)malloc(MAX_SAMPLES * sizeof(double));
    
    if (signal == NULL || filtered_signal == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Generate sine wave
    generate_sine_wave(signal, MAX_SAMPLES);
    
    // Apply low-pass filter
    double cutoff_frequency = 200; // Cut-off frequency in Hz
    apply_low_pass_filter(signal, filtered_signal, MAX_SAMPLES, cutoff_frequency);

    // Print original signal and filtered signal
    printf("Original Signal:\n");
    print_signal(signal, MAX_SAMPLES);

    printf("\nFiltered Signal (Low-pass at %.1f Hz):\n", cutoff_frequency);
    print_signal(filtered_signal, MAX_SAMPLES);

    // Cleanup
    cleanup(signal, filtered_signal);
    
    return 0;
}

void generate_sine_wave(double *signal, int num_samples) {
    for (int i = 0; i < num_samples; i++) {
        signal[i] = sin(2 * PI * SIGNAL_FREQUENCY * i / SAMPLE_RATE);
    }
}

void apply_low_pass_filter(double *signal, double *filtered_signal, int num_samples, double cutoff_frequency) {
    double RC = 1.0 / (2 * PI * cutoff_frequency);
    double dt = 1.0 / SAMPLE_RATE;
    double alpha = dt / (RC + dt);

    filtered_signal[0] = signal[0]; // Set the first sample

    for (int i = 1; i < num_samples; i++) {
        filtered_signal[i] = filtered_signal[i - 1] + alpha * (signal[i] - filtered_signal[i - 1]);
    }
}

void print_signal(double *signal, int num_samples) {
    for (int i = 0; i < num_samples; i++) {
        // Scale the output for better visibility
        printf("%.4f\n", signal[i] * 100); // Scale the output for terminal visual
    }
}

void cleanup(double *signal, double *filtered_signal) {
    free(signal);
    free(filtered_signal);
}