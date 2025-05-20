//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: portable
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SAMPLE_RATE 1000  // Sample rate in Hz
#define FREQUENCY 5       // Frequency of the sine wave
#define NUM_SAMPLES 100   // Number of samples
#define FILTER_ORDER 4    // Order of the FIR filter

// FIR filter coefficients (simple low-pass filter)
const float fir_coefficients[FILTER_ORDER + 1] = {0.2, 0.2, 0.2, 0.2, 0.2};

// Function to generate a sine wave
void generate_sine_wave(float *signal, int num_samples, float frequency, float sample_rate) {
    for (int i = 0; i < num_samples; i++) {
        signal[i] = sinf(2 * M_PI * frequency * i / sample_rate);
    }
}

// Function to apply FIR filter
void apply_fir_filter(float *input, float *output, int num_samples, const float *coefficients, int filter_order) {
    for (int n = 0; n < num_samples; n++) {
        output[n] = 0.0;
        for (int k = 0; k <= filter_order; k++) {
            if (n - k >= 0) {
                output[n] += coefficients[k] * input[n - k];
            }
        }
    }
}

// Function to print the signal
void print_signal(const float *signal, int num_samples) {
    for (int i = 0; i < num_samples; i++) {
        printf("%d: %f\n", i, signal[i]);
    }
}

int main() {
    // Allocate memory for input and output signals
    float *input_signal = (float *)malloc(NUM_SAMPLES * sizeof(float));
    float *output_signal = (float *)malloc(NUM_SAMPLES * sizeof(float));

    if (input_signal == NULL || output_signal == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    // Generate the sine wave signal
    generate_sine_wave(input_signal, NUM_SAMPLES, FREQUENCY, SAMPLE_RATE);

    // Apply the FIR filter
    apply_fir_filter(input_signal, output_signal, NUM_SAMPLES, fir_coefficients, FILTER_ORDER);

    // Print the original and filtered signals
    printf("Original Signal:\n");
    print_signal(input_signal, NUM_SAMPLES);

    printf("\nFiltered Signal:\n");
    print_signal(output_signal, NUM_SAMPLES);

    // Free the allocated memory
    free(input_signal);
    free(output_signal);

    return 0;
}