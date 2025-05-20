//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define FRAME_SIZE 1024

// Function prototypes
void init_signal(float* signal, int length);
void add_noise(float* signal, float* noise, int length);
void apply_filter(float* signal, float* filter, int length);
void print_signal(float* signal, int length);

int main() {
    int length = SAMPLE_RATE / FRAME_SIZE;
    float* signal = malloc(length * sizeof(float));
    float* noise = malloc(length * sizeof(float));
    float* filter = malloc(length * sizeof(float));

    // Initialize signal with a sine wave
    init_signal(signal, length);

    // Add noise to the signal
    add_noise(signal, noise, length);

    // Apply filter to the noisy signal
    apply_filter(signal, filter, length);

    // Print the original and filtered signals
    printf("Original Signal:\n");
    print_signal(signal, length);
    printf("\nFiltered Signal:\n");
    print_signal(signal, length);

    free(signal);
    free(noise);
    free(filter);

    return 0;
}

void init_signal(float* signal, int length) {
    for (int i = 0; i < length; i++) {
        signal[i] = sin(2 * M_PI * i / (SAMPLE_RATE / 440));
    }
}

void add_noise(float* signal, float* noise, int length) {
    for (int i = 0; i < length; i++) {
        noise[i] = rand() % 100; // Generate random noise between 0 and 99
        signal[i] += noise[i] / 100; // Add noise to signal
    }
}

void apply_filter(float* signal, float* filter, int length) {
    for (int i = 0; i < length; i++) {
        float sum = 0;
        for (int j = 0; j < length; j++) {
            sum += signal[(i - j + length) % length] * filter[j]; // Apply filter
        }
        signal[i] = sum;
    }
}

void print_signal(float* signal, int length) {
    for (int i = 0; i < length; i++) {
        printf("%f ", signal[i]);
    }
    printf("\n");
}