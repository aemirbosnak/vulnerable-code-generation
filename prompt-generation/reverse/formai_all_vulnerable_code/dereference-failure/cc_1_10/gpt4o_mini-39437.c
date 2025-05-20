//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fftw3.h>

#define SAMPLE_RATE 1024   // Sample Rate
#define DURATION 1         // Duration in seconds
#define NUM_SAMPLES (SAMPLE_RATE * DURATION)
#define PI 3.14159265358979

void generate_sine_wave(double *signal, double frequency) {
    for (int n = 0; n < NUM_SAMPLES; n++) {
        signal[n] = sin(2.0 * PI * frequency * n / SAMPLE_RATE);
    }
}

void compute_fft(double *signal, fftw_complex *out) {
    fftw_plan plan = fftw_plan_dft_r2c_1d(NUM_SAMPLES, signal, out, FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);
}

void print_spectrum(fftw_complex *out) {
    printf("Frequency Spectrum:\n");
    for (int i = 0; i < NUM_SAMPLES / 2; i++) {
        double magnitude = sqrt(out[i][0] * out[i][0] + out[i][1] * out[i][1]);
        printf("Frequency bin %d: Magnitude = %f\n", i, magnitude);
    }
}

int main() {
    double frequency = 50.0; // Frequency of the sine wave
    double *signal = (double *)malloc(NUM_SAMPLES * sizeof(double));
    fftw_complex *out = (fftw_complex *)malloc((NUM_SAMPLES / 2 + 1) * sizeof(fftw_complex));

    // Generate the sine wave signal
    generate_sine_wave(signal, frequency);

    // Compute FFT of the signal
    compute_fft(signal, out);

    // Print the frequency spectrum
    print_spectrum(out);

    // Free allocated memory
    free(signal);
    free(out);

    return 0;
}