//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fftw3.h>

#define SAMPLING_RATE 8000 // 8 KHz
#define DURATION 1.0       // 1 second
#define NUM_SAMPLES (int)(SAMPLING_RATE * DURATION)
#define PI 3.14159265358979323846

// Function to generate a sine wave
void generate_sine_wave(double* signal, double frequency, int num_samples) {
    for (int i = 0; i < num_samples; i++) {
        signal[i] = sin(2 * PI * frequency * (i / (double)SAMPLING_RATE));
    }
}

// Function to print the signal
void print_signal(const char* label, double* signal, int num_samples) {
    printf("%s:", label);
    for (int i = 0; i < num_samples; i++) {
        printf(" %f", signal[i]);
    }
    printf("\n");
}

// Function to perform FFT
void perform_fft(double* signal, fftw_complex* output, int num_samples) {
    fftw_plan p;
    p = fftw_plan_dft_r2c_1d(num_samples, signal, output, FFTW_ESTIMATE);
    fftw_execute(p); // Execute the FFT
    fftw_destroy_plan(p);
}

// Function to print FFT results
void print_fft_results(fftw_complex* output, int num_samples) {
    printf("FFT Results:\n");
    for (int i = 0; i < num_samples / 2; i++) { // Only half of the FFT result is needed
        double frequency = (double)i * SAMPLING_RATE / num_samples;
        double magnitude = sqrt(output[i][0] * output[i][0] + output[i][1] * output[i][1]);
        printf("Frequency: %.2f Hz, Magnitude: %f\n", frequency, magnitude);
    }
}

int main() {
    // Allocate memory for the signal and FFT output
    double* signal = (double*)malloc(sizeof(double) * NUM_SAMPLES);
    fftw_complex* output = (fftw_complex*)malloc(sizeof(fftw_complex) * (NUM_SAMPLES / 2 + 1));

    // Example signal with frequency 440 Hz (A4 note)
    double frequency = 440.0;
    printf("Generating a sine wave signal with frequency: %.2f Hz\n", frequency);
    generate_sine_wave(signal, frequency, NUM_SAMPLES);
    
    // Print the original signal (optional, could be very long)
    // print_signal("Generated Sine Wave", signal, NUM_SAMPLES);

    // Perform FFT
    printf("Performing FFT...\n");
    perform_fft(signal, output, NUM_SAMPLES);

    // Print FFT results
    print_fft_results(output, NUM_SAMPLES);

    // Free allocated memory
    free(signal);
    free(output);

    return 0;
}