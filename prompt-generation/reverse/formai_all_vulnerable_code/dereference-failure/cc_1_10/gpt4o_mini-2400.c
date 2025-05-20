//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fftw3.h>

#define SAMPLE_RATE 1024         // Sampling rate
#define SIGNAL_DURATION 1.0      // Duration of the signal in seconds
#define PI 3.14159265358979323846

void generate_sine_wave(double *signal, double frequency, int sample_count) {
    for (int i = 0; i < sample_count; i++) {
        signal[i] = sin(2 * PI * frequency * i / SAMPLE_RATE);
    }
}

void print_frequency_spectrum(fftw_complex *output, int sample_count) {
    printf("Frequency Spectrum:\n");
    for (int i = 0; i < sample_count / 2; i++) {
        double magnitude = sqrt(output[i][0] * output[i][0] + output[i][1] * output[i][1]);
        printf("Frequency bin %d: Magnitude = %lf\n", i, magnitude);
    }
}

int main() {
    // Define parameters
    int sample_count = (int)(SAMPLE_RATE * SIGNAL_DURATION);
    double frequency = 50.0; // Frequency of the sine wave

    // Allocate memory for the signal and the FFT output
    double *signal = (double *)malloc(sample_count * sizeof(double));
    fftw_complex *output = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * (sample_count / 2 + 1));
    fftw_plan plan;

    // Generate sine wave
    generate_sine_wave(signal, frequency, sample_count);
    
    // Create FFT plan
    plan = fftw_plan_dft_r2c_1d(sample_count, signal, output, FFTW_ESTIMATE);
    
    // Perform FFT
    fftw_execute(plan);
    
    // Print the frequency spectrum
    print_frequency_spectrum(output, sample_count);
    
    // Cleanup
    fftw_destroy_plan(plan);
    fftw_free(output);
    free(signal);

    return 0;
}