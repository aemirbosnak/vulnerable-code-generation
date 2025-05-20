//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fftw3.h>

#define SAMPLE_RATE 1024          // Samples per second
#define DURATION 1                // Duration of the signal in seconds
#define SIGNAL_FREQ 10            // Frequency of the sine wave in Hz
#define N (SAMPLE_RATE * DURATION) // Total number of samples

void generate_signal(double *signal);
void compute_fft(double *signal, fftw_complex *out);
void print_magnitudes(fftw_complex *out);

int main() {
    // Allocate memory for the signal and FFT output
    double *signal = (double *)malloc(N * sizeof(double));
    fftw_complex *out = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * (N / 2 + 1));
    
    // Check for memory allocation failure
    if (signal == NULL || out == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    // Generate the sine wave signal
    generate_signal(signal);

    // Compute the FFT
    compute_fft(signal, out);

    // Print the magnitudes of the frequency components
    print_magnitudes(out);

    // Free allocated memory
    free(signal);
    fftw_free(out);

    return EXIT_SUCCESS;
}

void generate_signal(double *signal) {
    for (int n = 0; n < N; n++) {
        signal[n] = sin(2 * M_PI * SIGNAL_FREQ * n / SAMPLE_RATE);
    }
}

void compute_fft(double *signal, fftw_complex *out) {
    // Create a plan for FFT computation
    fftw_plan plan = fftw_plan_dft_r2c_1d(N, signal, out, FFTW_ESTIMATE);
    
    // Execute the plan
    fftw_execute(plan);
    
    // Destroy the plan after execution
    fftw_destroy_plan(plan);
}

void print_magnitudes(fftw_complex *out) {
    printf("Frequency (Hz)\tMagnitude\n");
    for (int k = 0; k <= N / 2; k++) {
        double magnitude = sqrt(out[k][0] * out[k][0] + out[k][1] * out[k][1]);
        double frequency = (double)k * SAMPLE_RATE / N;
        printf("%.1f\t\t%.2f\n", frequency, magnitude);
    }
}