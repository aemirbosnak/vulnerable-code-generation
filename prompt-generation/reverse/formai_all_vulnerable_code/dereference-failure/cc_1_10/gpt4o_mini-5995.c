//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 1024 // Sample rate in Hz
#define FREQUENCY 5      // Frequency of the sine wave in Hz
#define N 1024           // Number of samples
#define PI 3.14159265358979323846

void generate_sine_wave(double *signal, int n, double frequency, double sample_rate) {
    for (int i = 0; i < n; i++) {
        signal[i] = sin(2 * PI * frequency * ((double)i / sample_rate));
    }
}

void fft(double *real, double *imag, int n) {
    if (n <= 1) return;

    double even_real[n / 2], even_imag[n / 2];
    double odd_real[n / 2], odd_imag[n / 2];

    for (int i = 0; i < n / 2; i++) {
        even_real[i] = real[i * 2];
        even_imag[i] = imag[i * 2];
        odd_real[i] = real[i * 2 + 1];
        odd_imag[i] = imag[i * 2 + 1];
    }

    fft(even_real, even_imag, n / 2);
    fft(odd_real, odd_imag, n / 2);

    for (int k = 0; k < n / 2; k++) {
        double t_real = cos(-2 * PI * k / n) * odd_real[k] - sin(-2 * PI * k / n) * odd_imag[k];
        double t_imag = sin(-2 * PI * k / n) * odd_real[k] + cos(-2 * PI * k / n) * odd_imag[k];

        real[k] = even_real[k] + t_real;
        imag[k] = even_imag[k] + t_imag;
        real[k + n / 2] = even_real[k] - t_real;
        imag[k + n / 2] = even_imag[k] - t_imag;
    }
}

void calculate_magnitude(double *real, double *imag, double *magnitude, int n) {
    for (int i = 0; i < n; i++) {
        magnitude[i] = sqrt(real[i] * real[i] + imag[i] * imag[i]);
    }
}

void print_frequency_spectrum(double *magnitude, int n) {
    printf("Frequency Spectrum:\n");
    for (int i = 0; i < n; i++) {
        printf("%d Hz: %f\n", i * SAMPLE_RATE / n, magnitude[i]);
    }
}

int main() {
    double *signal = (double *)malloc(N * sizeof(double));
    double *real = (double *)malloc(N * sizeof(double));
    double *imag = (double *)malloc(N * sizeof(double));
    double *magnitude = (double *)malloc(N * sizeof(double));

    // Generate the sine wave signal
    generate_sine_wave(signal, N, FREQUENCY, SAMPLE_RATE);

    // Initialize real and imaginary parts for FFT
    for (int i = 0; i < N; i++) {
        real[i] = signal[i];
        imag[i] = 0.0;
    }

    // Perform FFT
    fft(real, imag, N);

    // Calculate magnitude
    calculate_magnitude(real, imag, magnitude, N);

    // Print the frequency spectrum
    print_frequency_spectrum(magnitude, N);

    // Clean up
    free(signal);
    free(real);
    free(imag);
    free(magnitude);

    return 0;
}