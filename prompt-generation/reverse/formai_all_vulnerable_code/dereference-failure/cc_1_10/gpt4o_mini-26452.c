//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fftw3.h>

#define SAMPLE_RATE 1000 // sample rate in Hz
#define DURATION 2.0     // duration of the signal in seconds
#define FREQUENCY 5.0    // frequency of the sine wave
#define FILTER_CUTOFF 10 // cutoff frequency for low-pass filter

void generate_sine_wave(double *signal, int sample_count) {
    for (int n = 0; n < sample_count; n++) {
        signal[n] = sin(2 * M_PI * FREQUENCY * n / SAMPLE_RATE);
    }
}

void apply_low_pass_filter(double *signal, double *filtered_signal, int sample_count) {
    double alpha = (double) FILTER_CUTOFF / SAMPLE_RATE; // simple normalization
    filtered_signal[0] = signal[0];
    
    for (int n = 1; n < sample_count; n++) {
        filtered_signal[n] = alpha * signal[n] + (1 - alpha) * filtered_signal[n - 1];
    }
}

void compute_fft(double *signal, fftw_complex *fft_result, int sample_count) {
    fftw_plan plan = fftw_plan_dft_r2c_1d(sample_count, signal, fft_result, FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);
}

void print_frequency_spectrum(fftw_complex *fft_result, int sample_count) {
    printf("\nFrequency Spectrum:\n");
    for (int i = 0; i < sample_count / 2; i++) {
        double magnitude = sqrt(fft_result[i][0] * fft_result[i][0] + fft_result[i][1] * fft_result[i][1]);
        printf("Frequency %d Hz: %.2f\n", i, magnitude);
    }
}

void visualize_signal(double *signal, int sample_count) {
    printf("\nVisualizing Original Signal:\n");
    for (int n = 0; n < sample_count; n++) {
        int magnitude = (int)(signal[n] * 20); // scale for visibility
        for (int i = 0; i < magnitude; i++) {
            putchar('*');
        }
        putchar('\n');
    }
}

void visualize_filtered_signal(double *filtered_signal, int sample_count) {
    printf("\nVisualizing Filtered Signal:\n");
    for (int n = 0; n < sample_count; n++) {
        int magnitude = (int)(filtered_signal[n] * 20); 
        for (int i = 0; i < magnitude; i++) {
            putchar('*');
        }
        putchar('\n');
    }
}

int main() {
    int sample_count = (int)(SAMPLE_RATE * DURATION);
    double *signal = (double *)malloc(sample_count * sizeof(double));
    double *filtered_signal = (double *)malloc(sample_count * sizeof(double));
    fftw_complex *fft_result = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * (sample_count / 2 + 1));

    if (signal == NULL || filtered_signal == NULL || fft_result == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    generate_sine_wave(signal, sample_count);
    apply_low_pass_filter(signal, filtered_signal, sample_count);
    compute_fft(filtered_signal, fft_result, sample_count);

    visualize_signal(signal, sample_count);
    visualize_filtered_signal(filtered_signal, sample_count);
    print_frequency_spectrum(fft_result, sample_count);

    free(signal);
    free(filtered_signal);
    fftw_free(fft_result);

    return 0;
}