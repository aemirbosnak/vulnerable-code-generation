//FormAI DATASET v1.0 Category: Digital signal processing ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
    // Define variables
    int fs = 1000; // Sampling frequency in Hz
    float f1 = 50; // Signal frequency in Hz
    float f2 = 150; // Signal frequency in Hz
    float A1 = 1; // Amplitude of signal 1
    float A2 = 0.5; // Amplitude of signal 2
    float t = 0; // Time
    float delta_t = 1.0 / fs; // Time interval

    // Generate time vector
    int n_samples = fs * 5; // Number of samples in 5 seconds
    float *time = malloc(sizeof(float) * n_samples);
    for (int i = 0; i < n_samples; i++)
    {
        time[i] = t;
        t += delta_t;
    }

    // Generate signal 1
    float *signal1 = malloc(sizeof(float) * n_samples);
    for (int i = 0; i < n_samples; i++)
    {
        signal1[i] = A1 * sin(2 * PI * f1 * time[i]);
    }

    // Generate signal 2
    float *signal2 = malloc(sizeof(float) * n_samples);
    for (int i = 0; i < n_samples; i++)
    {
        signal2[i] = A2 * sin(2 * PI * f2 * time[i]);
    }

    // Add signals together
    float *signal = malloc(sizeof(float) * n_samples);
    for (int i = 0; i < n_samples; i++)
    {
        signal[i] = signal1[i] + signal2[i];
    }

    // Apply a low-pass filter to the signal
    int cutoff_freq = 100; // Cutoff frequency in Hz
    float *filtered_signal = malloc(sizeof(float) * n_samples);
    float alpha = delta_t / (1.0 / (2 * PI * cutoff_freq) + delta_t);
    filtered_signal[0] = signal[0];
    for (int i = 1; i < n_samples; i++)
    {
        filtered_signal[i] = alpha * signal[i] + (1 - alpha) * filtered_signal[i-1];
    }

    // Print results
    printf("Time,Signal,Filtered Signal\n");
    for (int i = 0; i < n_samples; i++)
    {
        printf("%f,%f,%f\n", time[i], signal[i], filtered_signal[i]);
    }

    // Free memory
    free(time);
    free(signal1);
    free(signal2);
    free(signal);
    free(filtered_signal);

    return 0;
}