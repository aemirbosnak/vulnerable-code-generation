//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fftw3.h>

#define SAMPLE_RATE 1024
#define PI 3.14159265358979323846
#define FREQUENCY 5.0 // Frequency of the sine wave
#define DURATION 1.0   // Duration in seconds
#define POINTS (SAMPLE_RATE * DURATION)

// Function to generate a sine wave
void generate_sine_wave(double *signal, int num_points) {
    for (int i = 0; i < num_points; i++) {
        signal[i] = sin(2 * PI * FREQUENCY * (i / (double)SAMPLE_RATE));
    }
}

// Function to perform FFT
void compute_fft(double *signal, fftw_complex *output, int num_points) {
    fftw_plan plan = fftw_plan_dft_r2c_1d(num_points, signal, output, FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);
}

// Function to calculate magnitude spectrum
void calculate_magnitude(fftw_complex *output, double *magnitude, int num_points) {
    for (int i = 0; i < num_points / 2 + 1; i++) {
        magnitude[i] = sqrt(output[i][0] * output[i][0] + output[i][1] * output[i][1]);
    }
}

// Function to print magnitude spectrum
void print_spectrum(double *magnitude, int num_points) {
    printf("Magnitude Spectrum:\n");
    for (int i = 0; i < num_points / 2 + 1; i++) {
        double frequency = (double)i * SAMPLE_RATE / num_points;
        printf("Frequency: %.2f Hz, Magnitude: %.2f\n", frequency, magnitude[i]);
    }
}

int main() {
    // Allocate memory for the signal and FFT output
    double *signal = (double *)malloc(POINTS * sizeof(double));
    fftw_complex *output = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * (POINTS / 2 + 1));
    double *magnitude = (double *)malloc((POINTS / 2 + 1) * sizeof(double));

    // Generate sine wave signal
    generate_sine_wave(signal, POINTS);

    // Compute FFT
    compute_fft(signal, output, POINTS);

    // Calculate Magnitude
    calculate_magnitude(output, magnitude, POINTS);

    // Print magnitude spectrum
    print_spectrum(magnitude, POINTS);

    // Free allocated memory
    free(signal);
    fftw_free(output);
    free(magnitude);

    return 0;
}