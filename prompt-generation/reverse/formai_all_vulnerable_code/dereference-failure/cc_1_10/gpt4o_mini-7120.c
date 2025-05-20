//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SAMPLES 1024
#define PI 3.14159265358979323846

typedef struct {
    double *samples;
    int length;
} Signal;

// Function prototypes
Signal* create_signal(int length);
void destroy_signal(Signal* signal);
void generate_sine_wave(Signal* signal, double frequency, double sample_rate);
void apply_hamming_window(Signal* signal);
void perform_fft(Signal* signal, double *real, double *imag);
void print_signal(Signal* signal);
void print_spectrum(double *real, double *imag, int length);

int main() {
    int length = MAX_SAMPLES;
    double frequency = 440.0; // Frequency of the sine wave in Hz
    double sample_rate = 44100.0; // Sampling rate in Hz

    // Create a signal instance
    Signal* signal = create_signal(length);
    
    // Generate a sine wave
    generate_sine_wave(signal, frequency, sample_rate);
    
    // Print original signal
    printf("Original Signal:\n");
    print_signal(signal);
    
    // Apply Hamming window
    apply_hamming_window(signal);
    
    // Allocate memory for FFT results
    double *real = malloc(length * sizeof(double));
    double *imag = malloc(length * sizeof(double));
    
    // Perform FFT
    perform_fft(signal, real, imag);
    
    // Print the FFT results
    printf("FFT Spectrum:\n");
    print_spectrum(real, imag, length);

    // Clean up
    free(real);
    free(imag);
    destroy_signal(signal);
    
    return 0;
}

Signal* create_signal(int length) {
    Signal* signal = (Signal*)malloc(sizeof(Signal));
    signal->samples = (double*)malloc(length * sizeof(double));
    signal->length = length;
    return signal;
}

void destroy_signal(Signal* signal) {
    free(signal->samples);
    free(signal);
}

void generate_sine_wave(Signal* signal, double frequency, double sample_rate) {
    for (int n = 0; n < signal->length; n++) {
        signal->samples[n] = sin(2 * PI * frequency * n / sample_rate);
    }
}

void apply_hamming_window(Signal* signal) {
    for (int n = 0; n < signal->length; n++) {
        double hamming_value = 0.54 - 0.46 * cos((2 * PI * n) / (signal->length - 1));
        signal->samples[n] *= hamming_value;
    }
}

void perform_fft(Signal* signal, double *real, double *imag) {
    for (int k = 0; k < signal->length; k++) {
        real[k] = 0.0;
        imag[k] = 0.0;
        for (int n = 0; n < signal->length; n++) {
            real[k] += signal->samples[n] * cos(2 * PI * k * n / signal->length);
            imag[k] -= signal->samples[n] * sin(2 * PI * k * n / signal->length);
        }
    }
}

void print_signal(Signal* signal) {
    for (int n = 0; n < signal->length; n++) {
        printf("%d: %f\n", n, signal->samples[n]);
    }
}

void print_spectrum(double *real, double *imag, int length) {
    for (int k = 0; k < length; k++) {
        double magnitude = sqrt(real[k] * real[k] + imag[k] * imag[k]);
        printf("%d: Magnitude = %f\n", k, magnitude);
    }
}