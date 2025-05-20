//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1024 // number of samples
#define Fs 44100 // sampling frequency
#define PI 3.14159265358979323846

// function to generate a sine wave
void generate_sine_wave(double* signal, int n) {
    double freq = 440; // frequency of the sine wave
    double t = 0;
    for (int i = 0; i < n; i++) {
        signal[i] = sin(2 * PI * freq * t);
        t += (1 / Fs);
    }
}

// function to perform a Fourier transform
void fourier_transform(double* signal, int n, double* spectrum) {
    double t = 0;
    for (int i = 0; i < n; i++) {
        spectrum[i] = 0;
        for (int j = 0; j < n; j++) {
            spectrum[i] += signal[j] * cos(2 * PI * i * j / n);
        }
    }
}

// main function
int main() {
    // allocate memory for the signal and spectrum
    double* signal = (double*)malloc(N * sizeof(double));
    double* spectrum = (double*)malloc(N * sizeof(double));

    // generate the sine wave
    generate_sine_wave(signal, N);

    // perform the Fourier transform
    fourier_transform(signal, N, spectrum);

    // print the results
    for (int i = 0; i < N; i++) {
        printf("%f %f\n", signal[i], spectrum[i]);
    }

    // free the memory
    free(signal);
    free(spectrum);

    return 0;
}