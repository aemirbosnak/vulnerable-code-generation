//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the number of samples
#define N 1000

// Define the sampling frequency
#define fs 44100

// Define the time step
#define dt 1.0/fs

// Define the frequency of the sine wave
#define f 440

// Define the maximum amplitude of the sine wave
#define A 0.8

// Define the number of harmonics to include
#define M 10

// Define the frequency vector
double freq[M] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

// Define the amplitude vector
double amp[M] = {A, A/2, A/3, A/4, A/5, A/6, A/7, A/8, A/9, A/10};

// Define the sine wave function
double sine_wave(double t) {
    double sum = 0.0;
    for (int i = 0; i < M; i++) {
        sum += amp[i] * sin(2*M_PI*freq[i]*t);
    }
    return sum;
}

// Define the main function
int main() {
    // Allocate memory for the time vector
    double *t = (double*) malloc(N * sizeof(double));

    // Allocate memory for the sine wave vector
    double *sine = (double*) malloc(N * sizeof(double));

    // Initialize the time vector
    for (int i = 0; i < N; i++) {
        t[i] = i*dt;
    }

    // Compute the sine wave
    for (int i = 0; i < N; i++) {
        sine[i] = sine_wave(t[i]);
    }

    // Print the time and sine wave vectors
    printf("Time (s) Sine Wave\n");
    for (int i = 0; i < N; i++) {
        printf("%f %f\n", t[i], sine[i]);
    }

    // Free the memory
    free(t);
    free(sine);

    return 0;
}