//FormAI DATASET v1.0 Category: Digital signal processing ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_FREQ 16000
#define TONE_FREQ 500
#define TONE_AMPLITUDE 10000
#define SIGNAL_TIME 2

int main() {
    // Generate a sinusoidal tone signal
    int num_samples = SAMPLE_FREQ * SIGNAL_TIME;
    double *signal = calloc(num_samples, sizeof(double));
    for (int i = 0; i < num_samples; i++) {
        signal[i] = TONE_AMPLITUDE * sin(2 * M_PI * TONE_FREQ * i / SAMPLE_FREQ);
    }

    // Add white noise to the signal
    double *noise = calloc(num_samples, sizeof(double));
    srand(42); // Set the random seed for reproducibility
    for (int i = 0; i < num_samples; i++) {
        noise[i] = (double)rand() / (double)RAND_MAX - 0.5; // Generate random values between -0.5 and 0.5
    }
    double *noisy_signal = calloc(num_samples, sizeof(double));
    for (int i = 0; i < num_samples; i++) {
        noisy_signal[i] = signal[i] + noise[i];
    }

    // Apply a low-pass filter to the noisy signal
    int filter_order = 6;
    double cutoff_freq = 1000;
    double *filter_coeffs = calloc(filter_order + 1, sizeof(double));
    double omega_c = 2 * M_PI * cutoff_freq / SAMPLE_FREQ;
    filter_coeffs[0] = omega_c / M_PI;
    for (int i = 1; i <= filter_order; i++) {
        filter_coeffs[i] = sin(i * omega_c) / (i * M_PI);
    }
    double *filtered_signal = calloc(num_samples, sizeof(double));
    for (int i = filter_order; i < num_samples; i++) {
        double sum = 0;
        for (int j = 0; j <= filter_order; j++) {
            sum += filter_coeffs[j] * noisy_signal[i - j];
        }
        filtered_signal[i] = sum;
    }

    // Check if the filtered signal is close enough to the original signal
    int num_mismatches = 0;
    for (int i = 0; i < num_samples; i++) {
        if (fabs(filtered_signal[i] - signal[i]) > TONE_AMPLITUDE / 2) {
            num_mismatches++;
        }
    }
    if (num_mismatches > 0) {
        printf("Warning: The filtered signal does not match the original signal.\n");
    } else {
        printf("Success: The filtered signal matches the original signal.\n");
    }

    // Free memory
    free(signal);
    free(noise);
    free(noisy_signal);
    free(filter_coeffs);
    free(filtered_signal);

    return 0;
}