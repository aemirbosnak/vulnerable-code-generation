//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: inquisitive
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SAMPLE_RATE 1024
#define TWO_PI (2 * 3.14159265358979323846)
#define DEFAULT_FREQ 5.0

void generate_signal(double *signal, int length, double frequency) {
    for (int i = 0; i < length; i++) {
        signal[i] = sin(TWO_PI * frequency * ((double)i / SAMPLE_RATE));
    }
}

void fft(double *real, double *imag, int n) {
    if (n <= 1) return;

    double *even_real = malloc(n / 2 * sizeof(double));
    double *even_imag = malloc(n / 2 * sizeof(double));
    double *odd_real = malloc(n / 2 * sizeof(double));
    double *odd_imag = malloc(n / 2 * sizeof(double));

    for (int i = 0; i < n / 2; i++) {
        even_real[i] = real[i * 2];
        even_imag[i] = imag[i * 2];
        odd_real[i] = real[i * 2 + 1];
        odd_imag[i] = imag[i * 2 + 1];
    }

    fft(even_real, even_imag, n / 2);
    fft(odd_real, odd_imag, n / 2);

    for (int k = 0; k < n / 2; k++) {
        double t_real = cos(TWO_PI * k / n) * odd_real[k] + sin(TWO_PI * k / n) * odd_imag[k];
        double t_imag = -sin(TWO_PI * k / n) * odd_real[k] + cos(TWO_PI * k / n) * odd_imag[k];

        real[k] = even_real[k] + t_real;
        imag[k] = even_imag[k] + t_imag;
        real[k + n / 2] = even_real[k] - t_real;
        imag[k + n / 2] = even_imag[k] - t_imag;
    }

    free(even_real);
    free(even_imag);
    free(odd_real);
    free(odd_imag);
}

void print_results(double *real, double *imag, int n) {
    printf("Frequency components:\n");
    for (int i = 0; i < n; i++) {
        if (real[i] != 0.0 || imag[i] != 0.0) {
            printf("Bin %d: Magnitude = %.5f Phase = %.5f radians\n", 
                    i, sqrt(real[i]*real[i] + imag[i]*imag[i]), 
                    atan2(imag[i], real[i]));
        }
    }
}

int main() {
    double *signal = malloc(SAMPLE_RATE * sizeof(double));
    double *real = calloc(SAMPLE_RATE, sizeof(double));
    double *imag = calloc(SAMPLE_RATE, sizeof(double));
    
    // Generate a test signal
    printf("Generating signal with frequency: %.1f Hz\n", DEFAULT_FREQ);
    generate_signal(signal, SAMPLE_RATE, DEFAULT_FREQ);

    // Prepare real and imaginary parts for FFT
    for (int i = 0; i < SAMPLE_RATE; i++) {
        real[i] = signal[i];
        imag[i] = 0.0;
    }

    // Perform FFT
    fft(real, imag, SAMPLE_RATE);

    // Print results of FFT
    print_results(real, imag, SAMPLE_RATE);

    // Cleanup
    free(signal);
    free(real);
    free(imag);

    return 0;
}