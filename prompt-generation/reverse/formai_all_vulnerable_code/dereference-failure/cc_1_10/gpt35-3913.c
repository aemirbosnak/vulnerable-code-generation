//FormAI DATASET v1.0 Category: Audio processing ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define SAMPLE_RATE 44100.0
#define PI 3.14159265358979323846

// Function to generate a sine wave of a given frequency and duration
float* generateSinewave(float frequency, float duration)
{
    int numSamples = (int) (SAMPLE_RATE * duration);
    float* samples = (float*) malloc(numSamples * sizeof(float));
    int i;
    for (i = 0; i < numSamples; i++) {
        samples[i] = sin(2 * PI * i * frequency / SAMPLE_RATE);
    }
    return samples;
}


// Function to apply a low-pass filter to audio samples
void applyLowPassFilter(float* samples, int numSamples, float cutoffFrequency)
{
    float RC = 1.0 / (2 * PI * cutoffFrequency);
    float dt = 1.0 / SAMPLE_RATE;
    float alpha = dt / (RC + dt);
    float y = 0.0;
    int i;
    for (i = 0; i < numSamples; i++) {
        y = y + alpha * (samples[i] - y);
        samples[i] = y;
    }
}


// Function to normalize audio samples to have a maximum amplitude of 1
void normalizeSamples(float* samples, int numSamples)
{
    float maxAmp = 0.0;
    int i;
    for (i = 0; i < numSamples; i++) {
        if (fabs(samples[i]) > maxAmp) {
            maxAmp = fabs(samples[i]);
        }
    }
    for (i = 0; i < numSamples; i++) {
        samples[i] /= maxAmp;
    }
}


// Main function
int main()
{
    // Generate a sine wave of frequency 440 Hz and duration 1 second
    float* samples = generateSinewave(440.0, 1.0);

    // Apply a low-pass filter with cutoff frequency of 1000 Hz
    applyLowPassFilter(samples, SAMPLE_RATE, 1000.0);

    // Normalize the samples
    normalizeSamples(samples, SAMPLE_RATE);

    // Write the samples to a file
    FILE* fp = fopen("output.raw", "wb");
    fwrite(samples, sizeof(float), SAMPLE_RATE, fp);
    fclose(fp);

    // Free memory
    free(samples);

    return 0;
}