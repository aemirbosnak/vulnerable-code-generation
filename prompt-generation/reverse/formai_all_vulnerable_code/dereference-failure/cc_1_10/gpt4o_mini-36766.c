//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fftw3.h>
#include <stdint.h>
#include <stdbool.h>

#define SAMPLE_RATE 1024
#define DURATION 1.0
#define FREQUENCY 5.0

void create_signal(double *signal, int sample_count) {
    for (int i = 0; i < sample_count; i++) {
        signal[i] = sin(2 * M_PI * FREQUENCY * ((double)i / SAMPLE_RATE));
    }
}

void compute_fft(fftw_complex *in, fftw_complex *out, int N) {
    fftw_plan plan;
    plan = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);
}

void print_frequency_spectrum(fftw_complex *out, int N) {
    printf("Frequency spectrum:\n");
    for (int i = 0; i < N; i++) {
        double magnitude = sqrt(out[i][0] * out[i][0] + out[i][1] * out[i][1]);
        printf("Frequency bin %d: Magnitude = %f\n", i, magnitude);
    }
}

int main() {
    int sample_count = (int)(SAMPLE_RATE * DURATION);
    double *signal = (double *)malloc(sample_count * sizeof(double));
    fftw_complex *in = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * sample_count);
    fftw_complex *out = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * sample_count);

    create_signal(signal, sample_count);
   
    // Prepare input for FFT
    for (int i = 0; i < sample_count; i++) {
        in[i][0] = signal[i]; // Real part
        in[i][1] = 0.0;       // Imaginary part
    }

    // Compute FFT
    compute_fft(in, out, sample_count);

    // Print results
    print_frequency_spectrum(out, sample_count);

    // Cleanup
    free(signal);
    fftw_free(in);
    fftw_free(out);

    return 0;
}