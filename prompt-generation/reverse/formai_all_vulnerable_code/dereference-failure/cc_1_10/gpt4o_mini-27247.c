//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fftw3.h>

#define SAMPLE_RATE 44100
#define DURATION 2.0
#define FREQUENCY 440.0 // Frequency of the sine wave (A4)

void generate_sine_wave(double *buffer, int num_samples, double frequency, double sample_rate) {
    for (int i = 0; i < num_samples; i++) {
        buffer[i] = sin(2.0 * M_PI * frequency * ((double)i / sample_rate));
    }
}

void perform_fft(double *input, fftw_complex *output, int num_samples) {
    fftw_plan p = fftw_plan_dft_r2c_1d(num_samples, input, output, FFTW_ESTIMATE);
    fftw_execute(p);
    fftw_destroy_plan(p);
}

void print_fft_results(fftw_complex *output, int num_samples) {
    printf("Frequency (Hz) | Magnitude\n");
    printf("----------------------------------\n");
    
    for (int i = 0; i < num_samples / 2; i++) {
        double magnitude = sqrt(output[i][0] * output[i][0] + output[i][1] * output[i][1]);
        double frequency = (double)i * SAMPLE_RATE / num_samples;
        printf("%15.2f | %.5f\n", frequency, magnitude);
    }
}

void apply_window_function(double *buffer, int num_samples) {
    // Hamming window function
    for (int i = 0; i < num_samples; i++) {
        buffer[i] *= 0.54 - 0.46 * cos((2.0 * M_PI * i) / (num_samples - 1));
    }
}

int main() {
    int num_samples = (int)(SAMPLE_RATE * DURATION);
    double *sine_wave = (double *)malloc(num_samples * sizeof(double));
    fftw_complex *fft_output = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * (num_samples / 2 + 1));

    // Step 1: Generate a Sine Wave
    generate_sine_wave(sine_wave, num_samples, FREQUENCY, SAMPLE_RATE);
    
    // Step 2: Apply Hamming Window
    apply_window_function(sine_wave, num_samples);
    
    // Step 3: Perform FFT
    perform_fft(sine_wave, fft_output, num_samples);
    
    // Step 4: Print FFT Results
    print_fft_results(fft_output, num_samples);
    
    // Free allocated memory
    free(sine_wave);
    fftw_free(fft_output);
    
    return 0;
}