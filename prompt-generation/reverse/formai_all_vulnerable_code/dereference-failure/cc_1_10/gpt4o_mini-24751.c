//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FILTER_ORDER 5
#define SAMPLE_RATE 44100
#define PI 3.14159265358979323846

void generate_signal(double *signal, int length);
void apply_fir_filter(double *input, double *output, double *coefficients, int length, int order);
void print_signal(double *signal, int length);

int main() {
    int signal_length = SAMPLE_RATE; // 1 second of audio at 44100 Hz
    double *input_signal = (double *)malloc(signal_length * sizeof(double));
    double *output_signal = (double *)malloc(signal_length * sizeof(double));
    double coefficients[FILTER_ORDER + 1] = {0.1, 0.2, 0.3, 0.2, 0.1, 0.1}; // Example FIR coefficients

    // Generate a test signal
    generate_signal(input_signal, signal_length);
    
    // Apply the FIR filter
    apply_fir_filter(input_signal, output_signal, coefficients, signal_length, FILTER_ORDER);
    
    // Print the filtered signal
    printf("Input Signal:\n");
    print_signal(input_signal, 10); // Print first 10 samples
    printf("\nFiltered Signal:\n");
    print_signal(output_signal, 10); // Print first 10 samples

    free(input_signal);
    free(output_signal);
    return 0;
}

void generate_signal(double *signal, int length) {
    // Generate a simple sine wave as the input signal for testing
    for (int i = 0; i < length; i++) {
        signal[i] = sin(2 * PI * 440 * ((double)i / SAMPLE_RATE)); // 440 Hz tone
    }
}

void apply_fir_filter(double *input, double *output, double *coefficients, int length, int order) {
    // Apply the FIR filter using the convolution sum
    for (int n = 0; n < length; n++) {
        output[n] = 0.0; // Initialize output sample
        for (int k = 0; k <= order; k++) {
            if (n - k >= 0) { // Check for valid index
                output[n] += coefficients[k] * input[n - k];
            }
        }
    }
}

void print_signal(double *signal, int length) {
    for (int i = 0; i < length; i++) {
        printf("%f ", signal[i]);
    }
    printf("\n");
}