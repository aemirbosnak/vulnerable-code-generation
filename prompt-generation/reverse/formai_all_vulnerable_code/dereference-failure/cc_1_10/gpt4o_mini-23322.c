//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 1024    // Number of samples per second
#define N 256               // Number of points in FFT
#define PI 3.14159265358979323846

void fft(double *real, double *imag, int n);
void calculate_sine_wave(double *signal, double frequency, int duration);
void print_spectrum(double *real, double *imag, int n);

int main() {
    double *signal = (double *)malloc(N * sizeof(double));
    double *real = (double *)malloc(N * sizeof(double));
    double *imag = (double *)malloc(N * sizeof(double));
    
    if (signal == NULL || real == NULL || imag == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    // Frequency of the sine wave
    double frequency = 10.0; // 10 Hz
    int duration = 1;         // Duration in seconds
    
    // Generate the sine wave
    calculate_sine_wave(signal, frequency, duration);
    
    // Initialize real and imaginary parts for FFT
    for (int i = 0; i < N; i++) {
        real[i] = signal[i];
        imag[i] = 0.0; // No imaginary part for real input
    }
    
    // Perform FFT
    fft(real, imag, N);
    
    // Print the frequency spectrum
    print_spectrum(real, imag, N);
    
    // Free allocated memory
    free(signal);
    free(real);
    free(imag);
    
    return 0;
}

void calculate_sine_wave(double *signal, double frequency, int duration) {
    for (int i = 0; i < N; i++) {
        signal[i] = sin(2 * PI * frequency * i / SAMPLE_RATE);
    }
}

void fft(double *real, double *imag, int n) {
    // Cooley-Tukey FFT algorithm
    if (n <= 1) return;
    
    // Divide
    double even_real[N/2], even_imag[N/2];
    double odd_real[N/2], odd_imag[N/2];
    
    for (int i = 0; i < n / 2; i++) {
        even_real[i] = real[i * 2];
        even_imag[i] = imag[i * 2];
        odd_real[i] = real[i * 2 + 1];
        odd_imag[i] = imag[i * 2 + 1];
    }
    
    // Recursive calls
    fft(even_real, even_imag, n / 2);
    fft(odd_real, odd_imag, n / 2);
    
    // Combine
    for (int k = 0; k < n / 2; k++) {
        double t_real = cos(-2 * PI * k / n) * odd_real[k] - sin(-2 * PI * k / n) * odd_imag[k];
        double t_imag = sin(-2 * PI * k / n) * odd_real[k] + cos(-2 * PI * k / n) * odd_imag[k];

        real[k] = even_real[k] + t_real;
        imag[k] = even_imag[k] + t_imag;
        real[k + n / 2] = even_real[k] - t_real;
        imag[k + n / 2] = even_imag[k] - t_imag;
    }
}

void print_spectrum(double *real, double *imag, int n) {
    printf("Frequency Spectrum:\n");
    for (int i = 0; i < n; i++) {
        double magnitude = sqrt(real[i] * real[i] + imag[i] * imag[i]);
        printf("Frequency bin %d: Magnitude = %f\n", i, magnitude);
    }
}