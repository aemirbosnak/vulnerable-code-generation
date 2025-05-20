//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fftw3.h>

#define SAMPLE_RATE 1024
#define FREQUENCY 5
#define NOISE_LEVEL 0.2

void generate_signal(double *signal, int length) {
    for (int i = 0; i < length; i++) {
        double time = (double)i / SAMPLE_RATE;
        signal[i] = sin(2.0 * M_PI * FREQUENCY * time);
        // Add some cheerful noise!
        signal[i] += (rand() / (double)RAND_MAX) * NOISE_LEVEL - (NOISE_LEVEL / 2);
    }
}

void compute_fft(double *signal, fftw_complex *output, int length) {
    fftw_plan plan = fftw_plan_dft_r2c_1d(length, signal, output, FFTW_ESTIMATE);
    
    fftw_execute(plan);
    fftw_destroy_plan(plan);
}

void print_frequencies(fftw_complex *output, int length) {
    printf("\nFrequencies in the Signal:\n");
    for (int i = 0; i < length / 2; i++) {
        double magnitude = sqrt(output[i][0] * output[i][0] + output[i][1] * output[i][1]);
        printf("Frequency bin %d: Magnitude = %.2f\n", i, magnitude);
    }
}

int main() {
    // Set the random seed for some cheerful randomness
    srand(time(NULL));

    // A cheerful signal to work with
    double *signal = (double *)malloc(sizeof(double) * SAMPLE_RATE);
    fftw_complex *output = (fftw_complex *)malloc(sizeof(fftw_complex) * (SAMPLE_RATE / 2 + 1));

    generate_signal(signal, SAMPLE_RATE);

    printf("✨ Generating a beautiful sine wave signal with noise! ✨\n");
    
    compute_fft(signal, output, SAMPLE_RATE);
    
    print_frequencies(output, SAMPLE_RATE);

    // Clean up and free allocated memory
    free(signal);
    free(output);

    printf("\n🎉 Hooray! The FFT is complete! 🎉\n");
    return 0;
}