//FormAI DATASET v1.0 Category: Audio processing ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100.0
#define PI 3.14159265358979323846

/* Function to generate a waveform */
float* generateWaveform(float frequency, float duration) 
{
    int num_samples = duration * SAMPLE_RATE;
    float* waveform = (float*) malloc(num_samples * sizeof(float));
    int i;
    for (i = 0; i < num_samples; i++) {
        waveform[i] = sin(2 * PI * i * frequency / SAMPLE_RATE);
    }
    return waveform;
}

/* Function to apply a low-pass filter to a waveform */
void applyLowPassFilter(float* waveform, int num_samples, float cutoff_frequency) 
{
    int n;
    float omega_c = 2 * PI * cutoff_frequency / SAMPLE_RATE;
    float alpha = sin(omega_c) / (2 * sqrt(2) * cos(omega_c) + sin(omega_c));
    float b0 = (1 - cos(omega_c)) / 2;
    float b1 = 1 - cos(omega_c);
    float b2 = (1 - cos(omega_c)) / 2;
    float a0 = 1 + alpha;
    float a1 = -2 * cos(omega_c);
    float a2 = 1 - alpha;

    float x_prev[2] = {0, 0};
    float y_prev[2] = {0, 0};
    for (n = 0; n < num_samples; n++) {
        float x = waveform[n];
        float y = (b0 / a0) * x + (b1 / a0) * x_prev[1] + (b2 / a0) * x_prev[0]
                  - (a1 / a0) * y_prev[1] - (a2 / a0) * y_prev[0];
        x_prev[0] = x_prev[1];
        x_prev[1] = x;
        y_prev[0] = y_prev[1];
        y_prev[1] = y;
        waveform[n] = y;
    }
}

/* Main function */
int main() 
{
    /* Generate a 440 Hz sine wave */
    float* waveform = generateWaveform(440, 1);
    
    /* Apply a low-pass filter with cutoff frequency of 1000 Hz */
    applyLowPassFilter(waveform, SAMPLE_RATE, 1000);
    
    /* Output the processed waveform */
    int i;
    for (i = 0; i < SAMPLE_RATE; i++) {
        printf("%f\n", waveform[i]);
    }
    
    /* Free the allocated memory */
    free(waveform);
    
    return 0;
}