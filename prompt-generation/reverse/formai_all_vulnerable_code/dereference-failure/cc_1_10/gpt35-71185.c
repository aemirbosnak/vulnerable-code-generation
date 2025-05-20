//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100.0 // Sample rate in Hz
#define FREQUENCY 440.0 // Frequency of the sine wave in Hz
#define AMPLITUDE 0.5 // Amplitude of the sine wave

float* generateSineWave(float frequency, float amplitude, float duration);
float* applyLowPassFilter(float* signal, float cutoffFrequency, float duration);

int main() {
    // Generate sine wave signal
    float* signal = generateSineWave(FREQUENCY, AMPLITUDE, 1.0);

    // Apply low pass filter with cutoff frequency of 200 Hz
    signal = applyLowPassFilter(signal, 200.0, 1.0);

    // Output signal to file
    FILE* file = fopen("output.pcm", "wb");
    fwrite(signal, sizeof(float), (int)(1.0 * SAMPLE_RATE), file);
    fclose(file);

    // Free memory
    free(signal);

    return 0;
}

float* generateSineWave(float frequency, float amplitude, float duration) {
    int numSamples = (int)(duration * SAMPLE_RATE);
    float* signal = (float*)calloc(numSamples, sizeof(float));
    float phaseIncrement = 2.0 * M_PI * frequency / SAMPLE_RATE;
    float phase = 0.0;

    for (int i = 0; i < numSamples; i++) {
        signal[i] = amplitude * sin(phase);
        phase += phaseIncrement;
    }

    return signal;
}

float* applyLowPassFilter(float* signal, float cutoffFrequency, float duration) {
    int numSamples = (int)(duration * SAMPLE_RATE);
    float* filteredSignal = (float*)calloc(numSamples, sizeof(float));
    float RC = 1.0 / (2.0 * M_PI * cutoffFrequency);
    float dt = 1.0 / SAMPLE_RATE;
    float alpha = RC / (RC + dt);

    filteredSignal[0] = signal[0];
    for (int i = 1; i < numSamples; i++) {
        filteredSignal[i] = alpha * signal[i] + (1.0 - alpha) * filteredSignal[i - 1];
    }

    // Free memory of original signal
    free(signal);

    return filteredSignal;
}