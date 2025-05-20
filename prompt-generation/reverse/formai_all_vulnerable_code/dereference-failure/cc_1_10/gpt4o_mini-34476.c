//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fftw3.h>

// Constants for the signal
#define SAMPLE_RATE 1024     // Hz
#define FREQUENCY 50         // Hz
#define DURATION 1.0         // seconds
#define N (int)(SAMPLE_RATE * DURATION)

// Function to generate a sine wave signal
void generateSineWave(double *signal, double frequency, double sample_rate, int length) {
    for (int i = 0; i < length; i++) {
        signal[i] = sin(2 * M_PI * frequency * i / sample_rate);
    }
}

// Function to perform FFT and store the result
void performFFT(double *in_signal, fftw_complex *out_freq_domain, int length) {
    fftw_plan plan = fftw_plan_dft_r2c_1d(length, in_signal, out_freq_domain, FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);
}

// Function to calculate the magnitude of each frequency bin
void calculateMagnitude(fftw_complex *out_freq_domain, double *magnitudes, int length) {
    for (int i = 0; i < length / 2 + 1; i++) {
        magnitudes[i] = sqrt(out_freq_domain[i][0] * out_freq_domain[i][0] +
                             out_freq_domain[i][1] * out_freq_domain[i][1]);
    }
}

// Function to print the magnitude spectrum
void printMagnitude(double *magnitudes, int length) {
    printf("Frequency Bins Magnitude:\n");
    for (int i = 0; i < length / 2 + 1; i++) {
        printf("Bin %d: %.3f\n", i, magnitudes[i]);
    }
}

// Main function
int main() {
    // Allocate memory for the signal
    double *signal = (double *)malloc(N * sizeof(double));
    fftw_complex *out_freq_domain = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * (N / 2 + 1));
    double *magnitudes = (double *)malloc((N / 2 + 1) * sizeof(double));
    
    // Check for memory allocation failure
    if (signal == NULL || out_freq_domain == NULL || magnitudes == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    // Step 1: Generate the sine wave signal
    printf("Generating a sine wave of frequency %.2f Hz...\n", FREQUENCY);
    generateSineWave(signal, FREQUENCY, SAMPLE_RATE, N);

    // Step 2: Perform FFT on the generated signal
    printf("Performing FFT...\n");
    performFFT(signal, out_freq_domain, N);

    // Step 3: Calculate magnitude of frequency components
    printf("Calculating magnitude of frequency components...\n");
    calculateMagnitude(out_freq_domain, magnitudes, N);

    // Step 4: Print the magnitude spectrum
    printMagnitude(magnitudes, N);

    // Clean up
    free(signal);
    fftw_free(out_freq_domain);
    free(magnitudes);

    return EXIT_SUCCESS;
}