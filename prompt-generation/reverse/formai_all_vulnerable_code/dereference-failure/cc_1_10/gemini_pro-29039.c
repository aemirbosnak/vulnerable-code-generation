//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Create a custom data type for complex numbers
typedef struct {
    double real;
    double imag;
} complex;

// Define some constants
#define PI 3.14159265358979323846
#define N 1024  // Number of samples
#define Fs 1000  // Sampling frequency

// Generate a sine wave
complex *generate_sine_wave(double frequency, double duration) {
    int i;
    double t;
    complex *sine_wave = malloc(N * sizeof(complex));
    for (i = 0; i < N; i++) {
        t = (double)i / Fs;
        sine_wave[i].real = sin(2 * PI * frequency * t);
        sine_wave[i].imag = 0;
    }
    return sine_wave;
}

// Perform FFT on a complex signal
complex *fft(complex *signal) {
    int i, j, k;
    complex *fft_result = malloc(N * sizeof(complex));
    double Wn, Wnk;
    for (i = 0; i < N; i++) {
        fft_result[i].real = 0;
        fft_result[i].imag = 0;
        for (j = 0; j < N; j++) {
            Wn = 2 * PI * i * j / N;
            fft_result[i].real += signal[j].real * cos(Wn) - signal[j].imag * sin(Wn);
            fft_result[i].imag += signal[j].real * sin(Wn) + signal[j].imag * cos(Wn);
        }
    }
    return fft_result;
}

// Plot the magnitude of the FFT result
void plot_fft_magnitude(complex *fft_result) {
    int i;
    double magnitude;
    for (i = 0; i < N / 2; i++) {
        magnitude = sqrt(pow(fft_result[i].real, 2) + pow(fft_result[i].imag, 2));
        printf("%d %f\n", i, magnitude);
    }
}

int main() {
    // Generate a sine wave at 100 Hz with a duration of 1 second
    complex *sine_wave = generate_sine_wave(100, 1);

    // Perform FFT on the sine wave
    complex *fft_result = fft(sine_wave);

    // Plot the magnitude of the FFT result
    plot_fft_magnitude(fft_result);

    // Free the allocated memory
    free(sine_wave);
    free(fft_result);

    return 0;
}