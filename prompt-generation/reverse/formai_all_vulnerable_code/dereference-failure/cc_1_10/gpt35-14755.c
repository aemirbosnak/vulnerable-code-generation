//FormAI DATASET v1.0 Category: Digital signal processing ; Style: expert-level
/***************************************************
 * Expert-level Digital Signal Processing Example  *
 *                                                 *
 * This program takes an input signal, applies a    *
 * band-pass filter, performs Fourier Transform,   *
 * and outputs the frequency and magnitude.        *
 ***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants
#define SAMPLE_RATE 44100 // Hz
#define N 1024 // Number of samples
#define FREQ_LOW 500 // Hz
#define FREQ_HIGH 1000 // Hz

int main() {
    // Allocate memory for input and output signals
    float* input = (float*) malloc(N * sizeof(float));
    float* output = (float*) malloc(N * sizeof(float));

    // Generate input signal with a frequency sweep
    for (int i = 0; i < N; i++) {
        input[i] = sin(2 * M_PI * (FREQ_LOW + (FREQ_HIGH - FREQ_LOW) * i / N) / SAMPLE_RATE * i);
    }

    // Apply band-pass filter to input signal
    float b[3] = {0.9873, -1.9747, 0.9873};
    float a[3] = {1, -1.9725, 0.9728};
    output[0] = b[0] * input[0];
    output[1] = b[0] * input[1] + b[1] * input[0] - a[1] * output[0];
    for (int i = 2; i < N; i++) {
        output[i] = b[0] * input[i] + b[1] * input[i-1] + b[2] * input[i-2] - a[1] * output[i-1] - a[2] * output[i-2];
    }

    // Perform Fourier Transform on output signal
    float freq[N];
    float mag[N];
    for (int i = 0; i < N; i++) {
        freq[i] = i * SAMPLE_RATE / N;
        float re = 0;
        float im = 0;
        for (int j = 0; j < N; j++) {
            re += output[j] * cos(2 * M_PI * i * j / N);
            im += output[j] * sin(2 * M_PI * i * j / N);
        }
        mag[i] = sqrt(re * re + im * im) / N * 2;
    }

    // Output frequency and magnitude
    for (int i = 0; i < N; i++) {
        printf("%.2f Hz: %.2f\n", freq[i], mag[i]);
    }

    // Free allocated memory
    free(input);
    free(output);

    return 0;
}