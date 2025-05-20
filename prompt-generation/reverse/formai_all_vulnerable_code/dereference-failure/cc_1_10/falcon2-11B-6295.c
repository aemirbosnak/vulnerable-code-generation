//Falcon2-11B DATASET v1.0 Category: Digital signal processing ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the power spectrum of a signal
float power_spectrum(float* signal, int size) {
    float* fft_result = (float*)malloc(sizeof(float) * size);
    float* fft_result_norm = (float*)malloc(sizeof(float) * size);
    float* fft_result_abs = (float*)malloc(sizeof(float) * size);
    float* fft_result_mag = (float*)malloc(sizeof(float) * size);

    for (int i = 0; i < size; i++) {
        fft_result[i] = 0;
        fft_result_norm[i] = 0;
        fft_result_abs[i] = 0;
        fft_result_mag[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        fft_result[i] = 0;
        fft_result_norm[i] = 0;
        fft_result_abs[i] = 0;
        fft_result_mag[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        fft_result[i] = 0;
        fft_result_norm[i] = 0;
        fft_result_abs[i] = 0;
        fft_result_mag[i] = 0;
    }

    // FFT calculation
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            fft_result[i] += signal[j] * cos(2 * M_PI * i * j / size);
            fft_result_norm[i] += signal[j] * cos(2 * M_PI * i * j / size);
            fft_result_abs[i] += abs(signal[j]) * cos(2 * M_PI * i * j / size);
            fft_result_mag[i] += abs(signal[j]) * cos(2 * M_PI * i * j / size);
        }
    }

    // Normalize the power spectrum
    for (int i = 0; i < size; i++) {
        fft_result_norm[i] /= size;
    }

    // Calculate the magnitude of the power spectrum
    for (int i = 0; i < size; i++) {
        fft_result_mag[i] = sqrt(fft_result_abs[i] * fft_result_abs[i] + fft_result_norm[i] * fft_result_norm[i]);
    }

    // Free allocated memory
    free(fft_result);
    free(fft_result_norm);
    free(fft_result_abs);
    free(fft_result_mag);

    return fft_result_mag[0];
}

int main() {
    int size = 1024;
    float* signal = (float*)malloc(sizeof(float) * size);

    for (int i = 0; i < size; i++) {
        signal[i] = (float)rand() / (float)RAND_MAX;
    }

    printf("Power Spectrum: %f\n", power_spectrum(signal, size));

    free(signal);

    return 0;
}