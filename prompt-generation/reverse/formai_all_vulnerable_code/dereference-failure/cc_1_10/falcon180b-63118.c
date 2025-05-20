//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <fftw3.h>

typedef struct {
    int n;
    fftw_complex *in, *out;
    fftw_plan plan;
} fft_t;

void fft_init(fft_t *fft, int n) {
    fft->n = n;
    fft->in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * n);
    fft->out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * n);
    fft->plan = fftw_plan_dft_1d(n, fft->in, fft->out, FFTW_FORWARD, FFTW_MEASURE);
}

void fft_free(fft_t *fft) {
    fftw_destroy_plan(fft->plan);
    fftw_free(fft->in);
    fftw_free(fft->out);
}

void fft_execute(fft_t *fft, float *data) {
    memcpy(fft->in, data, sizeof(float) * fft->n);
    fftw_execute(fft->plan);
    memcpy(data, fft->out, sizeof(float) * fft->n);
}

int main() {
    int n = 1024;
    float *data = (float*) malloc(sizeof(float) * n);
    fft_t fft;
    fft_init(&fft, n);

    // Generate some data
    for (int i = 0; i < n; i++) {
        data[i] = sin(2 * M_PI * i / n);
    }

    // Perform FFT
    fft_execute(&fft, data);

    // Print results
    printf("Original Data:\n");
    for (int i = 0; i < n; i++) {
        printf("%f ", data[i]);
    }
    printf("\n");

    printf("FFT Result:\n");
    for (int i = 0; i < n; i++) {
        printf("%f ", data[i]);
    }
    printf("\n");

    fft_free(&fft);
    free(data);
    return 0;
}