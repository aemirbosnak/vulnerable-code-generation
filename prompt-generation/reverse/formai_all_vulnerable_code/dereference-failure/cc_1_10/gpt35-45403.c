//FormAI DATASET v1.0 Category: Audio processing ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to generate a sine wave
void generateSineWave(int16_t *buffer, const unsigned int bufferSize, const int sampleRate, const float frequency) {
    float timeStep = 1.0 / sampleRate;
    float angularFrequency = 2.0 * PI * frequency;

    for (unsigned int i = 0; i < bufferSize; i++) {
        buffer[i] = (int16_t)(32767.0 * sin(angularFrequency * i * timeStep));
    }
}

// Function to apply a low-pass filter to an audio buffer
void applyLowPassFilter(int16_t *buffer, const unsigned int bufferSize, const int sampleRate, const float cutoffFrequency) {
    float RC = 1.0 / (2.0 * PI * cutoffFrequency);
    float dt = 1.0 / sampleRate;
    float alpha = dt / (dt + RC);
    int16_t previousSample = buffer[0];

    for (unsigned int i = 1; i < bufferSize; i++) {
        int16_t currentSample = buffer[i];
        buffer[i] = alpha * currentSample + (1.0 - alpha) * previousSample;
        previousSample = buffer[i];
    }
}

int main() {
    // Define some parameters
    const int sampleRate = 44100;
    const float frequency = 440.0;
    const float cutoffFrequency = 1000.0;
    const unsigned int bufferSize = sampleRate;

    // Allocate memory for the audio buffer
    int16_t *audioBuffer = (int16_t*)malloc(bufferSize * sizeof(int16_t));

    // Generate a sine wave at the desired frequency
    generateSineWave(audioBuffer, bufferSize, sampleRate, frequency);

    // Apply a low-pass filter to the audio buffer
    applyLowPassFilter(audioBuffer, bufferSize, sampleRate, cutoffFrequency);

    // Write the audio buffer to a file
    FILE *fout = fopen("output.pcm", "wb");
    fwrite(audioBuffer, sizeof(int16_t), bufferSize, fout);
    fclose(fout);

    // Free memory
    free(audioBuffer);

    return 0;
}