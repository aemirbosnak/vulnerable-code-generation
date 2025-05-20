//FormAI DATASET v1.0 Category: Audio processing ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

// Function to generate a sine wave of given frequency and duration
float *generate_sine_wave(float freq, float duration, int sample_rate)
{
    int n_samples = duration * sample_rate;
    float *samples = malloc(n_samples * sizeof(float));
    for (int i = 0; i < n_samples; i++) {
        samples[i] = sin(2 * PI * freq * i / sample_rate);
    }
    return samples;
}

// Function to apply a simple low-pass filter using moving average
float *apply_low_pass_filter(float *samples, int n_samples, int window_size)
{
    float *filtered_samples = malloc(n_samples * sizeof(float));
    for (int i = 0; i < n_samples; i++) {
        float sum = 0;
        int count = 0;
        for (int j = i - (window_size/2); j <= i + (window_size/2); j++) {
            if (j >= 0 && j < n_samples) {
                sum += samples[j];
                count++;
            }
        }
        filtered_samples[i] = sum / count;
    }
    return filtered_samples;
}

int main()
{
    float frequency = 440; // Hz
    float duration = 2; // seconds
    int sample_rate = 44100; // Hz
    int window_size = 50;

    // Generate a sine wave
    float *samples = generate_sine_wave(frequency, duration, sample_rate);

    // Apply low-pass filter
    float *filtered_samples = apply_low_pass_filter(samples, duration*sample_rate, window_size);
    
    // Print the original and filtered samples
    for (int i = 0; i < duration*sample_rate; i++) {
        printf("%f, %f\n", samples[i], filtered_samples[i]);
    }

    // Free memory
    free(samples);
    free(filtered_samples);

    return 0;
}