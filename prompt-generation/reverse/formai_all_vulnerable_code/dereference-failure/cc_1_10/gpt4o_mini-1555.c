//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fftw3.h>

#define SAMPLE_RATE 1024
#define PI 3.14159265358979323846
#define MAX_FREQUENCIES 512

// Function to generate a sine wave signal
void generate_signal(double *signal, int num_samples, double frequency) {
    for (int i = 0; i < num_samples; i++) {
        signal[i] = sin(2 * PI * frequency * i / SAMPLE_RATE);
    }
}

// Function to perform FFT on the signal
void perform_fft(double *signal, fftw_complex *frequency_spectrum, int num_samples) {
    fftw_plan plan = fftw_plan_dft_r2c_1d(num_samples, signal, frequency_spectrum, FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);
}

// Function to display the frequency spectrum
void display_spectrum(fftw_complex *frequency_spectrum, int num_samples) {
    printf("Frequency Spectrum:\n");
    for (int i = 0; i < num_samples / 2; i++) {
        double magnitude = sqrt(frequency_spectrum[i][0] * frequency_spectrum[i][0] + 
                                frequency_spectrum[i][1] * frequency_spectrum[i][1]);
        printf("Frequency bin %d: Magnitude = %f\n", i, magnitude);
    }
}

int main() {
    // Allocate memory for signal and frequency spectrum
    double *signal = (double *)malloc(SAMPLE_RATE * sizeof(double));
    fftw_complex *frequency_spectrum = (fftw_complex *)malloc((SAMPLE_RATE / 2 + 1) * sizeof(fftw_complex));

    // Generate a sine wave signal
    double frequency = 50.0; // Frequency of sine wave
    generate_signal(signal, SAMPLE_RATE, frequency);

    // Perform FFT on the generated signal
    perform_fft(signal, frequency_spectrum, SAMPLE_RATE);

    // Display the resulting frequency spectrum
    display_spectrum(frequency_spectrum, SAMPLE_RATE);

    // Free allocated memory
    free(signal);
    free(frequency_spectrum);

    return 0;
}