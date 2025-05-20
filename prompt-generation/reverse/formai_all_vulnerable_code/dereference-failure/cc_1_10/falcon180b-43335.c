//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the signal sampling rate and duration
#define SAMPLING_RATE 44100
#define DURATION 5

// Define the frequency and amplitude of the sine wave
#define FREQUENCY 440
#define AMPLITUDE 0.5

// Define the size of the FFT
#define FFT_SIZE 1024

// Define the window function
static double window(int n, int N) {
    return (double)sin((2 * M_PI * n) / N);
}

int main() {
    // Allocate memory for the signal and FFT
    double *signal = malloc(SAMPLING_RATE * DURATION * sizeof(double));
    double *fft = malloc(FFT_SIZE * sizeof(double));

    // Generate the signal
    for (int i = 0; i < SAMPLING_RATE * DURATION; i++) {
        double t = (double)i / SAMPLING_RATE;
        signal[i] = AMPLITUDE * sin(2 * M_PI * FREQUENCY * t);
    }

    // Apply the window function
    for (int i = 0; i < SAMPLING_RATE * DURATION; i++) {
        signal[i] *= window(i, SAMPLING_RATE * DURATION);
    }

    // Perform the FFT
    for (int i = 0; i < FFT_SIZE; i++) {
        double sum = 0;
        for (int j = 0; j < SAMPLING_RATE * DURATION; j += FFT_SIZE) {
            sum += signal[j] * cos((2 * M_PI * i * j) / FFT_SIZE);
        }
        fft[i] = sum;
    }

    // Print the FFT results
    for (int i = 0; i < FFT_SIZE / 2; i++) {
        printf("%d Hz: %.2f\n", i * SAMPLING_RATE / FFT_SIZE, sqrt(fft[i] * fft[i] + fft[FFT_SIZE - i] * fft[FFT_SIZE - i]));
    }

    // Free the memory
    free(signal);
    free(fft);

    return 0;
}