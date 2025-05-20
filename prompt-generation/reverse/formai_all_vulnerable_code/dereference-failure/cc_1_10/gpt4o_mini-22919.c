//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fftw3.h>

#define SAMPLE_RATE 1024
#define PI 3.14159265358979323846
#define SIGNAL_FREQUENCY 50.0
#define NUM_SAMPLES 1024

void generate_sine_wave(double *signal, int num_samples, double frequency, double sample_rate) {
    for (int i = 0; i < num_samples; i++) {
        signal[i] = sin(2 * PI * frequency * ((double)i / sample_rate));
    }
}

void perform_fft(fftw_complex *in, fftw_complex *out, int num_samples) {
    fftw_plan plan = fftw_plan_dft_1d(num_samples, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);
}

void print_frequency_spectrum(fftw_complex *out, int num_samples) {
    printf("Frequency Spectrum:\n");
    for (int i = 0; i < num_samples; i++) {
        double real = out[i][0];
        double imag = out[i][1];
        double magnitude = sqrt(real * real + imag * imag);
        double frequency = (double)i * SAMPLE_RATE / num_samples;
        
        if (frequency <= (SAMPLE_RATE / 2)) {
            printf("Frequency: %.2f Hz, Magnitude: %.2f\n", frequency, magnitude);
        }
    }
}

int main() {
    double *signal = (double *)malloc(NUM_SAMPLES * sizeof(double));
    fftw_complex *in = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * NUM_SAMPLES);
    fftw_complex *out = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * NUM_SAMPLES);

    if (!signal || !in || !out) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    // Generate a sine wave
    generate_sine_wave(signal, NUM_SAMPLES, SIGNAL_FREQUENCY, SAMPLE_RATE);

    // Prepare input for FFT
    for (int i = 0; i < NUM_SAMPLES; i++) {
        in[i][0] = signal[i]; // real part
        in[i][1] = 0.0;       // imaginary part
    }

    // Perform FFT
    perform_fft(in, out, NUM_SAMPLES);

    // Print frequency spectrum
    print_frequency_spectrum(out, NUM_SAMPLES);

    // Clean up
    free(signal);
    fftw_free(in);
    fftw_free(out);

    return EXIT_SUCCESS;
}