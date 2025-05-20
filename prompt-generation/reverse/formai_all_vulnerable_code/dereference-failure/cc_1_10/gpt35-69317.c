//FormAI DATASET v1.0 Category: Digital signal processing ; Style: systematic
/* 
 * Example program for Digital Signal Processing in C
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265 // Defining the value of Pi

/* Function to generate a sine wave signal */
void generate_sine_wave(float *signal, float frequency, float sample_rate, float signal_length) {
    int i;
    float time_per_sample = 1 / sample_rate;
    for (i = 0; i < sample_rate * signal_length; i++) {
        signal[i] = sin(2 * PI * frequency * i * time_per_sample);
    }
}

/* Function to add two signals */
void add_signals(float *signal1, float *signal2, float *result, int length) {
    int i;
    for (i = 0; i < length; i++) {
        result[i] = signal1[i] + signal2[i];
    }
}

/* Function to multiply two signals */
void multiply_signals(float *signal1, float *signal2, float *result, int length) {
    int i;
    for (i = 0; i < length; i++) {
        result[i] = signal1[i] * signal2[i];
    }
}

/* Function to apply a low-pass filter to a signal */
void apply_low_pass_filter(float *signal, float cutoff_frequency, float sample_rate, int length) {
    int i;
    float RC = 1 / (2 * PI * cutoff_frequency);
    float dt = 1 / sample_rate;
    float alpha = dt / (RC + dt);
    float previous_value = 0;
    for (i = 0; i < length; i++) {
        signal[i] = alpha * signal[i] + (1 - alpha) * previous_value;
        previous_value = signal[i];
    }
}

/* Main function */
int main() {
    float *signal1, *signal2, *result;
    float frequency1 = 500, frequency2 = 1000, sample_rate = 44100, signal_length = 1, cutoff_frequency = 500;
    int i;

    int signal_length_samples = sample_rate * signal_length;
    signal1 = (float *)malloc(sizeof(float) * signal_length_samples);
    signal2 = (float *)malloc(sizeof(float) * signal_length_samples);
    result = (float *)malloc(sizeof(float) * signal_length_samples);

    generate_sine_wave(signal1, frequency1, sample_rate, signal_length);
    generate_sine_wave(signal2, frequency2, sample_rate, signal_length);

    printf("Signal 1:\n");
    for (i = 0; i < signal_length_samples; i++) {
        printf("%f ", signal1[i]);
    }
    printf("\n");

    printf("Signal 2:\n");
    for (i = 0; i < signal_length_samples; i++) {
        printf("%f ", signal2[i]);
    }
    printf("\n");

    add_signals(signal1, signal2, result, signal_length_samples);

    printf("Result of adding signals:\n");
    for (i = 0; i < signal_length_samples; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");

    multiply_signals(signal1, signal2, result, signal_length_samples);

    printf("Result of multiplying signals:\n");
    for (i = 0; i < signal_length_samples; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");

    apply_low_pass_filter(signal1, cutoff_frequency, sample_rate, signal_length_samples);

    printf("Signal 1 after applying a low-pass filter:\n");
    for (i = 0; i < signal_length_samples; i++) {
        printf("%f ", signal1[i]);
    }
    printf("\n");

    free(signal1);
    free(signal2);
    free(result);

    return 0;
}