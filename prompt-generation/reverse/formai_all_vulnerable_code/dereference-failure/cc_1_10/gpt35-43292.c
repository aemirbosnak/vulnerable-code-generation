//FormAI DATASET v1.0 Category: Audio processing ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to create a sine wave signal
void generateSineWave(float frequency, int duration, int sampleRate, short int *buffer) {
    int numSamples = duration * sampleRate;
    float sampleTime = 1.0 / sampleRate;
    for (int i = 0; i < numSamples; i++) {
        float sampleValue = sin(2 * PI * frequency * i * sampleTime);
        buffer[i] = (short int)(32767 * sampleValue);
    }
}

// Function to apply low-pass filter to a signal
void applyLowPassFilter(short int *buffer, int numSamples, int cutoffFrequency, int sampleRate) {
    int RC = 1.0 / (2.0 * PI * cutoffFrequency);
    float dt = 1.0 / sampleRate;
    float alpha = dt / (dt + RC);
    short int prevSample = buffer[0];
    for (int i = 1; i < numSamples; i++) {
        short int currentSample = buffer[i];
        short int filteredSample = prevSample + alpha * (currentSample - prevSample);
        buffer[i] = filteredSample;
        prevSample = filteredSample;
    }
}

int main() {
    int duration = 5; // duration of signal in seconds
    int sampleRate = 44100; // sample rate in Hz
    int cutoffFrequency = 2000; // cutoff frequency in Hz

    int numSamples = duration * sampleRate;
    short int *buffer = (short int *)malloc(numSamples * sizeof(short int));

    // Generate a 1000 Hz sine wave signal
    generateSineWave(1000, duration, sampleRate, buffer);

    // Apply low-pass filter to the signal
    applyLowPassFilter(buffer, numSamples, cutoffFrequency, sampleRate);

    // Write the filtered signal to a WAV file
    FILE *file = fopen("filteredSignal.wav", "wb");
    if (!file) {
        printf("Error: Could not create output file.\n");
        exit(1);
    }

    unsigned int sampleRate_u = (unsigned int)sampleRate;
    unsigned int numChannels = 1;
    unsigned int bitsPerSample = 16;
    unsigned int byteRate = sampleRate_u * numChannels * bitsPerSample / 8;
    unsigned int blockAlign = numChannels * bitsPerSample / 8;
    unsigned int fileSize = 36 + numSamples * blockAlign;

    fwrite("RIFF", 1, 4, file);
    fwrite(&fileSize, 4, 1, file);
    fwrite("WAVE", 1, 4, file);

    fwrite("fmt ", 1, 4, file);
    unsigned int fmtSize = 16;
    fwrite(&fmtSize, 4, 1, file);
    unsigned short int audioFormat = 1; // PCM format
    fwrite(&audioFormat, 2, 1, file);
    fwrite(&numChannels, 2, 1, file);
    fwrite(&sampleRate_u, 4, 1, file);
    fwrite(&byteRate, 4, 1, file);
    fwrite(&blockAlign, 2, 1, file);
    fwrite(&bitsPerSample, 2, 1, file);

    fwrite("data", 1, 4, file);
    fwrite(&numSamples, 4, 1, file);
    fwrite(buffer, sizeof(short int), numSamples, file);

    fclose(file);

    free(buffer);

    return 0;
}