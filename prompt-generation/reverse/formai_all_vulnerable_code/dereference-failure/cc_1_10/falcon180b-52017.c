//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SAMPLE_RATE 44100 // Sample rate in Hz
#define WINDOW_SIZE 1024 // Window size for FFT

// Function to generate a window function
void generate_window(double *window, int size) {
    for (int i = 0; i < size; i++) {
        window[i] = 0.5 * (1 - cos(2 * M_PI * i / (size - 1)));
    }
}

// Function to perform FFT
void fft(double *data, int size) {
    int log2n = log2(size);
    int n = 1 << log2n;
    double *twiddle = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        twiddle[i] = cos(2 * M_PI * i / n);
    }
    for (int j = 0; j < log2n; j++) {
        int m = 1 << j;
        for (int k = 0; k < size; k += m) {
            double w = twiddle[k % n];
            for (int l = 0; l < m / 2; l++) {
                double t = data[k + l];
                data[k + l] = data[k + l + m / 2] * w;
                data[k + l + m / 2] = t * w;
            }
        }
    }
    free(twiddle);
}

// Function to apply window function and perform FFT
void process_data(double *data, int size) {
    double *window = malloc(size * sizeof(double));
    generate_window(window, size);
    for (int i = 0; i < size; i++) {
        data[i] *= window[i];
    }
    fft(data, size);
}

int main() {
    srand(time(NULL)); // Seed random number generator

    // Generate random data
    double *data = malloc(WINDOW_SIZE * sizeof(double));
    for (int i = 0; i < WINDOW_SIZE; i++) {
        data[i] = rand() / RAND_MAX;
    }

    // Process data
    process_data(data, WINDOW_SIZE);

    // Print FFT result
    printf("FFT result:\n");
    for (int i = 0; i < WINDOW_SIZE / 2; i++) {
        printf("%f %f\n", data[2 * i], data[2 * i + 1]);
    }

    free(data);
    return 0;
}