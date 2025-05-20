//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <fftw3.h>

// Global variables
static fftw_complex *fft_in, *fft_out;
static fftw_plan fft_plan;
static int fft_size;
static double *spectrum;

// Function to initialize the FFT
void fft_init(int size)
{
    fft_size = size;
    fft_in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * fft_size);
    fft_out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * fft_size);
    fft_plan = fftw_plan_dft_1d(fft_size, fft_in, fft_out, FFTW_FORWARD, FFTW_MEASURE);
    spectrum = (double*) malloc(sizeof(double) * fft_size);
}

// Function to execute the FFT
void fft_execute()
{
    fftw_execute(fft_plan);
}

// Function to get the frequency spectrum
void get_spectrum()
{
    for (int i = 0; i < fft_size; i++) {
        double real = fft_out[i][0];
        double imag = fft_out[i][1];
        spectrum[i] = sqrt(real * real + imag * imag);
    }
}

// Function to free the FFT resources
void fft_free()
{
    fftw_destroy_plan(fft_plan);
    fftw_free(fft_in);
    fftw_free(fft_out);
    free(spectrum);
}

int main()
{
    // Initialize the FFT
    fft_init(1024);

    // Generate some random data
    for (int i = 0; i < fft_size; i++) {
        fft_in[i][0] = (double) rand() / (double) RAND_MAX;
        fft_in[i][1] = (double) rand() / (double) RAND_MAX;
    }

    // Execute the FFT
    fft_execute();

    // Get the frequency spectrum
    get_spectrum();

    // Print the frequency spectrum
    for (int i = 0; i < fft_size; i++) {
        printf("%d: %f\n", i, spectrum[i]);
    }

    // Free the FFT resources
    fft_free();

    return 0;
}