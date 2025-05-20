//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fftw3.h>

#define SAMPLE_RATE 256
#define SIGNAL_FREQUENCY 5
#define DURATION 1

void generate_sine_wave(double *wave, int samples, double frequency) {
    for (int i = 0; i < samples; i++) {
        wave[i] = sin(2 * M_PI * frequency * (i / (double)SAMPLE_RATE));
    }
}

void print_wave_ascii(double *wave, int samples) {
    printf("\nGenerated Sine Wave:\n");
    for (int i = 0; i < samples; i++) {
        int num_hashes = (int)(wave[i] * 10); // Scale the wave for better ASCII representation
        for (int j = 0; j < num_hashes; j++) {
            printf("#");
        }
        printf("\n");
    }
}

void perform_fft(double *input, fftw_complex *output, int samples) {
    fftw_plan plan = fftw_plan_dft_r2c_1d(samples, input, output, FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);
}

void print_fft_ascii(fftw_complex *fft_output, int samples) {
    printf("\nFFT Magnitude Spectrum:\n");
    for (int i = 0; i < samples / 2; i++) { // We only need to print half of the FFT
        double magnitude = sqrt(fft_output[i][0] * fft_output[i][0] + fft_output[i][1] * fft_output[i][1]);
        int num_stars = (int)(magnitude / 10); // Scale for ASCII
        for (int j = 0; j < num_stars; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int samples = SAMPLE_RATE * DURATION;
    double *sine_wave = (double *)malloc(sizeof(double) * samples);
    fftw_complex *fft_output = (fftw_complex *)malloc(sizeof(fftw_complex) * (samples / 2 + 1));

    // Step 1: Generate Sine Wave
    generate_sine_wave(sine_wave, samples, SIGNAL_FREQUENCY);
    print_wave_ascii(sine_wave, samples);

    // Step 2: Perform FFT
    perform_fft(sine_wave, fft_output, samples);

    // Step 3: Print FFT Output
    print_fft_ascii(fft_output, samples);

    // Clean Up
    free(sine_wave);
    free(fft_output);
    
    return 0;
}