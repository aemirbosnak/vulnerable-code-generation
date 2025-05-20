//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000
#define PI 3.14159265358979323846
#define FS 1000 // Sampling frequency

// Generate a sine wave with frequency f and duration t
void generate_sine_wave(double f, double t, double* wave) {
    int i;
    double phase = 0.0;

    for (i = 0; i < N; i++) {
        wave[i] = sin(2.0 * PI * f * (i / FS) + phase);
    }
}

// Compute the power spectral density of a signal using the FFT
void compute_psd(double* signal, int len, double* psd) {
    int i;
    double sum = 0.0;

    for (i = 0; i < len; i++) {
        sum += signal[i] * signal[i];
    }

    psd[0] = sum;

    for (i = 1; i < len / 2; i++) {
        psd[i] = 0.0;
    }
}

// Main function
int main() {
    double f = 100.0; // Frequency of the sine wave
    double t = 1.0; // Duration of the sine wave
    double* wave = (double*) malloc(N * sizeof(double)); // Allocate memory for the wave
    double* psd = (double*) malloc((N / 2) * sizeof(double)); // Allocate memory for the PSD

    generate_sine_wave(f, t, wave); // Generate the sine wave
    compute_psd(wave, N, psd); // Compute the PSD

    printf("Frequency: %lf Hz\n", f);
    printf("Duration: %lf seconds\n", t);
    printf("PSD:\n");

    for (int i = 0; i < N / 2; i++) {
        printf("%lf\n", psd[i]);
    }

    free(wave); // Free the memory for the wave
    free(psd); // Free the memory for the PSD

    return 0;
}