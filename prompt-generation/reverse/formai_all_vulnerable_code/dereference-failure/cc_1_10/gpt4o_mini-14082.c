//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define SAMPLE_RATE 44100
#define FILTER_ORDER 4

// function prototypes
void apply_fir_filter(double *input, double *output, double *coefficients, int num_samples);
void generate_signal(double *signal, int num_samples);
void print_signal(double *signal, int num_samples);

int main() {
    const int num_samples = SAMPLE_RATE; // 1 second of audio
    double *input_signal = (double *)malloc(num_samples * sizeof(double));
    double *output_signal = (double *)malloc(num_samples * sizeof(double));
    double filter_coefficients[FILTER_ORDER + 1] = {0.2, 0.2, 0.2, 0.2, 0.2}; // a simple averaging filter
    
    if (input_signal == NULL || output_signal == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    // Step 1: Generate an Input Signal (A shocking square wave for surprise!)
    generate_signal(input_signal, num_samples);

    // Step 2: Apply the FIR Filter
    apply_fir_filter(input_signal, output_signal, filter_coefficients, num_samples);

    // Step 3: Print the Original and Filtered Signals
    printf("Original Signal:\n");
    print_signal(input_signal, num_samples);
    
    printf("\nFiltered Signal:\n");
    print_signal(output_signal, num_samples);

    free(input_signal);
    free(output_signal);

    return 0;
}

// Function to apply FIR filter
void apply_fir_filter(double *input, double *output, double *coefficients, int num_samples) {
    for (int n = 0; n < num_samples; n++) {
        output[n] = 0.0;
        // Convolution process
        for (int k = 0; k <= FILTER_ORDER; k++) {
            if (n - k >= 0) {
                output[n] += coefficients[k] * input[n - k];
            } else {
                output[n] += 0; // padding
            }
        }
    }
}

// Function to generate an input signal
void generate_signal(double *signal, int num_samples) {
    for (int i = 0; i < num_samples; i++) {
        // A shockingly clear square wave alternating between 1 and -1
        signal[i] = (i % (num_samples / 10) < (num_samples / 20)) ? 1.0 : -1.0;
    }
}

// Function to print the signals with shocking output formatting
void print_signal(double *signal, int num_samples) {
    for (int i = 0; i < num_samples; i++) {
        printf("%.2f ", signal[i]);
        // Shockingly print only first 100 samples to avoid clutter!
        if (i == 99) {
            printf("\n... (output truncated) ...\n");
            break;
        }
    }
    printf("\n");
}