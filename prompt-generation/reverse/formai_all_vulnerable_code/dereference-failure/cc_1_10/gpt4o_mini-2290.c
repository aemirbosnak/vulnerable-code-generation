//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fftw3.h>

#define SAMPLE_RATE 44100    // Sample rate in Hz
#define DURATION 1.0         // Duration of the signal in seconds
#define FREQUENCY 440.0      // Frequency of the sine wave in Hz
#define N (int)(SAMPLE_RATE * DURATION) // Number of samples

void generate_sine_wave(double *buffer, int n, double frequency, double sample_rate) {
    for (int i = 0; i < n; ++i) {
        buffer[i] = sin(2.0 * M_PI * frequency * i / sample_rate);
    }
}

void apply_hanning_window(double *buffer, int n) {
    for (int i = 0; i < n; ++i) {
        buffer[i] *= 0.5 * (1 - cos(2.0 * M_PI * i / (n - 1)));
    }
}

void compute_fft(double *input, fftw_complex *output, int n) {
    fftw_plan plan = fftw_plan_dft_r2c_1d(n, input, output, FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);
}

void print_fft_magnitude(fftw_complex *output, int n) {
    printf("Frequency\tMagnitude\n");
    for (int i = 0; i <= n / 2; ++i) {
        double magnitude = sqrt(output[i][0] * output[i][0] + output[i][1] * output[i][1]);
        printf("%d\t\t%f\n", i, magnitude);
    }
}

int main() {
    // Allocate memory for the sine wave and the FFT output
    double *sine_wave = (double *)malloc(N * sizeof(double));
    fftw_complex *fft_output = (fftw_complex *)fftw_malloc((N / 2 + 1) * sizeof(fftw_complex));

    // Generate the sine wave
    generate_sine_wave(sine_wave, N, FREQUENCY, SAMPLE_RATE);

    // Apply Hanning window
    apply_hanning_window(sine_wave, N);

    // Compute FFT
    compute_fft(sine_wave, fft_output, N);

    // Print the FFT magnitudes
    print_fft_magnitude(fft_output, N);

    // Free allocated memory
    free(sine_wave);
    fftw_free(fft_output);

    return 0;
}