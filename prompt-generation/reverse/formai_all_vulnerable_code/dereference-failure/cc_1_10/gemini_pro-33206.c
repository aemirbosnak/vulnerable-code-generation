//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the DFT of a complex signal
void DFT(float *x_real, float *x_imag, float *X_real, float *X_imag, int N) {
    for (int k = 0; k < N; k++) {
        X_real[k] = 0;
        X_imag[k] = 0;
        for (int n = 0; n < N; n++) {
            X_real[k] += x_real[n] * cos(2 * M_PI * k * n / N) + x_imag[n] * sin(2 * M_PI * k * n / N);
            X_imag[k] += -x_real[n] * sin(2 * M_PI * k * n / N) + x_imag[n] * cos(2 * M_PI * k * n / N);
        }
    }
}

// Function to calculate the IDFT of a complex signal
void IDFT(float *X_real, float *X_imag, float *x_real, float *x_imag, int N) {
    for (int n = 0; n < N; n++) {
        x_real[n] = 0;
        x_imag[n] = 0;
        for (int k = 0; k < N; k++) {
            x_real[n] += X_real[k] * cos(2 * M_PI * k * n / N) - X_imag[k] * sin(2 * M_PI * k * n / N);
            x_imag[n] += X_real[k] * sin(2 * M_PI * k * n / N) + X_imag[k] * cos(2 * M_PI * k * n / N);
        }
        x_real[n] /= N;
        x_imag[n] /= N;
    }
}

// Function to generate a complex sinusoid
void generate_sinusoid(float *x_real, float *x_imag, float amplitude, float frequency, int N) {
    for (int n = 0; n < N; n++) {
        x_real[n] = amplitude * cos(2 * M_PI * frequency * n / N);
        x_imag[n] = amplitude * sin(2 * M_PI * frequency * n / N);
    }
}

// Main function
int main() {
    // Define the parameters of the signal
    int N = 1024;              // Number of samples
    float amplitude = 1.0;       // Amplitude of the sinusoid
    float frequency = 0.25;      // Frequency of the sinusoid

    // Allocate memory for the input and output signals
    float *x_real = (float *)malloc(N * sizeof(float));
    float *x_imag = (float *)malloc(N * sizeof(float));
    float *X_real = (float *)malloc(N * sizeof(float));
    float *X_imag = (float *)malloc(N * sizeof(float));

    // Generate a complex sinusoid
    generate_sinusoid(x_real, x_imag, amplitude, frequency, N);

    // Calculate the DFT of the signal
    DFT(x_real, x_imag, X_real, X_imag, N);

    // Calculate the IDFT of the signal
    IDFT(X_real, X_imag, x_real, x_imag, N);

    // Print the input and output signals
    for (int n = 0; n < N; n++) {
        printf("x_real[%d] = %f, x_imag[%d] = %f\n", n, x_real[n], n, x_imag[n]);
    }
    for (int k = 0; k < N; k++) {
        printf("X_real[%d] = %f, X_imag[%d] = %f\n", k, X_real[k], k, X_imag[k]);
    }

    // Free the allocated memory
    free(x_real);
    free(x_imag);
    free(X_real);
    free(X_imag);

    return 0;
}