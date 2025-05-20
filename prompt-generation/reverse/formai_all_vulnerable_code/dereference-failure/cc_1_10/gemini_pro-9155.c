//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// FIR filter design function
void fir_design(double *h, int N, double fc, double fs) {
    int n;
    double w;
    for (n = 0; n < N; n++) {
        w = 2 * M_PI * fc * n / fs;
        if (n == N / 2) {
            h[n] = fc;
        } else {
            h[n] = sin(w) / (w);
        }
    }
}

// FIR filter function
void fir_filter(double *x, int Nx, double *h, int Nh, double *y, int Ny) {
    int n, k;
    for (n = 0; n < Ny; n++) {
        y[n] = 0;
        for (k = 0; k < Nh; k++) {
            if (n - k >= 0 && n - k < Nx) {
                y[n] += h[k] * x[n - k];
            }
        }
    }
}

// Main function
int main() {
    // Filter order
    int N = 100;
    // Cutoff frequency
    double fc = 500;
    // Sampling rate
    double fs = 10000;
    // Input signal length
    int Nx = 1000;
    // Output signal length
    int Ny = Nx;

    // Input signal
    double *x = (double *)malloc(Nx * sizeof(double));
    for (int n = 0; n < Nx; n++) {
        x[n] = sin(2 * M_PI * 100 * n / fs);
    }

    // FIR filter coefficients
    double *h = (double *)malloc(N * sizeof(double));
    fir_design(h, N, fc, fs);

    // Output signal
    double *y = (double *)malloc(Ny * sizeof(double));
    fir_filter(x, Nx, h, N, y, Ny);

    // Print the output signal
    for (int n = 0; n < Ny; n++) {
        printf("%f\n", y[n]);
    }

    // Free the allocated memory
    free(x);
    free(h);
    free(y);

    return 0;
}