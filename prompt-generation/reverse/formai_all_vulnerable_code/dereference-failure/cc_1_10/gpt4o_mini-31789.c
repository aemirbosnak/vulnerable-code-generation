//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: introspective
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SAMPLE_RATE 44100  // Standard sample rate in Hz
#define DURATION 1         // Duration of the signal in seconds
#define FREQUENCY 440      // Frequency of the sine wave (A4 note)
#define FILTER_COEFF 0.1   // Coefficient for the low-pass filter

void generate_sine_wave(double *signal, int sample_count, double frequency) {
    for (int i = 0; i < sample_count; i++) {
        signal[i] = sin(2 * M_PI * frequency * ((double)i / SAMPLE_RATE));
    }
}

void apply_low_pass_filter(double *input_signal, double *output_signal, int sample_count, double alpha) {
    output_signal[0] = input_signal[0]; // Initialize the first output sample
    for (int i = 1; i < sample_count; i++) {
        output_signal[i] = (alpha * input_signal[i]) + ((1.0 - alpha) * output_signal[i - 1]);
    }
}

void print_signal(double *signal, int sample_count) {
    for (int i = 0; i < sample_count; i++) {
        printf("%f\n", signal[i]);
    }
}

int main() {
    int sample_count = SAMPLE_RATE * DURATION;
    double *sine_wave = (double *)malloc(sample_count * sizeof(double));
    double *filtered_signal = (double *)malloc(sample_count * sizeof(double));

    // Step 1: Generate a sine wave
    generate_sine_wave(sine_wave, sample_count, FREQUENCY);
    
    // Step 2: Apply a low-pass filter to the sine wave
    apply_low_pass_filter(sine_wave, filtered_signal, sample_count, FILTER_COEFF);

    // Step 3: Print original and filtered signals for comparison
    printf("Original Sine Wave:\n");
    print_signal(sine_wave, sample_count);
    
    printf("\nFiltered Signal:\n");
    print_signal(filtered_signal, sample_count);
    
    // Free allocated memory to avoid memory leaks
    free(sine_wave);
    free(filtered_signal);

    return 0;
}