//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the complex data type
typedef struct {
    float real;
    float imag;
} complex;

// Define the Biquad filter coefficients
typedef struct {
    float a1, a2, b1, b2;
} biquad_coefs;

// Define the filter function
void biquad_filter(complex *input, complex *output, biquad_coefs *coefs, int num_samples) {
    // Initialize the output buffer
    for (int i = 0; i < num_samples; i++) {
        output[i].real = 0.0;
        output[i].imag = 0.0;
    }

    // Apply the filter to each sample
    for (int i = 0; i < num_samples; i++) {
        // Calculate the output sample
        output[i].real = coefs->b1 * input[i].real + coefs->b2 * input[i - 1].real - coefs->a1 * output[i - 1].real - coefs->a2 * output[i - 2].real;
        output[i].imag = coefs->b1 * input[i].imag + coefs->b2 * input[i - 1].imag - coefs->a1 * output[i - 1].imag - coefs->a2 * output[i - 2].imag;
    }
}

// Define the main function
int main() {
    // Create the input signal
    int num_samples = 1000;
    complex *input = malloc(sizeof(complex) * num_samples);
    for (int i = 0; i < num_samples; i++) {
        input[i].real = sin(2 * M_PI * 1000 * i / 44100);
        input[i].imag = 0.0;
    }

    // Create the filter coefficients
    biquad_coefs coefs = {
        .a1 = -1.990000,
        .a2 = 0.980100,
        .b1 = 0.000000,
        .b2 = 0.000000
    };

    // Create the output buffer
    complex *output = malloc(sizeof(complex) * num_samples);

    // Apply the filter to the input signal
    biquad_filter(input, output, &coefs, num_samples);

    // Write the output signal to a file
    FILE *file = fopen("output.txt", "w");
    for (int i = 0; i < num_samples; i++) {
        fprintf(file, "%f\n", output[i].real);
    }
    fclose(file);

    // Free the allocated memory
    free(input);
    free(output);

    return 0;
}