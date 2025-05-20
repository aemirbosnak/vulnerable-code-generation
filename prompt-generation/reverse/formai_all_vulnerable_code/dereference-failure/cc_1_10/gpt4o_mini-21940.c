//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fftw3.h>

#define SAMPLE_RATE 1024
#define SIGNAL_LENGTH 512
#define FFT_SIZE 1024
#define FILTER_CUTOFF 0.1 // Cut off frequency in normalized units

void generate_signal(double* signal, int length) {
    for (int i = 0; i < length; i++) {
        signal[i] = 0.5 * sin(2 * M_PI * 50 * i / SAMPLE_RATE) + 
                    0.25 * sin(2 * M_PI * 120 * i / SAMPLE_RATE);
    }
}

void low_pass_filter(double* input, double* output, int length, double cutoff) {
    double RC = 1.0 / (2 * M_PI * cutoff);
    double dt = 1.0 / SAMPLE_RATE;
    double alpha = dt / (RC + dt);

    output[0] = input[0]; // Initialize output
    for (int i = 1; i < length; i++) {
        output[i] = output[i - 1] + alpha * (input[i] - output[i - 1]);
    }
}

void compute_fft(double* input, fftw_complex* output, int n) {
    fftw_plan p = fftw_plan_dft_r2c_1d(n, input, output, FFTW_ESTIMATE);
    fftw_execute(p);
    fftw_destroy_plan(p);
}

void print_magnitude(fftw_complex* fft_output, int n) {
    printf("Frequency Magnitude:\n");
    for (int i = 0; i < n / 2 + 1; i++) {
        double magnitude = sqrt(fft_output[i][0] * fft_output[i][0] + fft_output[i][1] * fft_output[i][1]);
        printf("Bin %d: %f\n", i, magnitude);
    }
}

int main() {
    double* signal = (double*)malloc(SIGNAL_LENGTH * sizeof(double));
    double* filtered_signal = (double*)malloc(SIGNAL_LENGTH * sizeof(double));
    fftw_complex* fft_output = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * FFT_SIZE);

    // Step 1: Generate a test signal
    generate_signal(signal, SIGNAL_LENGTH);

    // Step 2: Apply a low pass filter
    low_pass_filter(signal, filtered_signal, SIGNAL_LENGTH, FILTER_CUTOFF);

    // Step 3: Compute the FFT of the filtered signal
    compute_fft(filtered_signal, fft_output, SIGNAL_LENGTH);

    // Step 4: Print the magnitude of the frequency components
    print_magnitude(fft_output, SIGNAL_LENGTH);

    // Clean up
    free(signal);
    free(filtered_signal);
    fftw_free(fft_output);

    return 0;
}