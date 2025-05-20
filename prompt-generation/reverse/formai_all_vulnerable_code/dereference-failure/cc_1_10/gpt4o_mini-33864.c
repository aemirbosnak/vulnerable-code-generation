//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SAMPLE_RATE 44100
#define DURATION 5 // Duration in seconds
#define FREQUENCY_A 440.0 // Frequency in Hz for A4
#define FREQUENCY_C 261.63 // Frequency in Hz for C4
#define PI 3.14159265358979323846

// Function to generate a sine wave
void generateSineWave(double *buffer, int bufferSize, double frequency) {
    for(int i = 0; i < bufferSize; i++) {
        buffer[i] = sin(2 * PI * frequency * (i / (double) SAMPLE_RATE));
    }
}

// Function to mix two audio buffers
void mixBuffers(double *buffer1, double *buffer2, double *outputBuffer, int bufferSize, double volume1, double volume2) {
    for(int i = 0; i < bufferSize; i++) {
        outputBuffer[i] = (buffer1[i] * volume1) + (buffer2[i] * volume2);
    }
}

// Function to write the buffer to a WAV file
void writeWAV(const char *filename, double *buffer, int bufferSize) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Could not open file for writing\n");
        return;
    }

    // WAV header
    const int headerSize = 44;
    char header[headerSize];
    memset(header, 0, headerSize);
    memcpy(header + 0, "RIFF", 4);
    memcpy(header + 8, "WAVE", 4);
    memcpy(header + 12, "fmt ", 4);
    *(int*)(header + 16) = 16; 
    *(short*)(header + 20) = 1; 
    *(short*)(header + 22) = 1; 
    *(int*)(header + 24) = SAMPLE_RATE; 
    *(int*)(header + 28) = SAMPLE_RATE * sizeof(short); 
    *(short*)(header + 32) = sizeof(short); 
    *(short*)(header + 34) = 16; 
    memcpy(header + 36, "data", 4);
    *(int*)(header + 40) = bufferSize * sizeof(short);

    // Write header
    fwrite(header, sizeof(char), headerSize, file);

    // Convert double buffer to short and write
    for(int i = 0; i < bufferSize; i++) {
        short sample = (short)(buffer[i] * 32767); // Convert to 16-bit PCM
        fwrite(&sample, sizeof(short), 1, file);
    }

    fclose(file);
}

// Main function to create and save a sine wave harmonics
int main() {
    int numSamples = SAMPLE_RATE * DURATION;
    double *sineWaveA = (double *)malloc(numSamples * sizeof(double));
    double *sineWaveC = (double *)malloc(numSamples * sizeof(double));
    double *mixedBuffer = (double *)malloc(numSamples * sizeof(double));

    if (!sineWaveA || !sineWaveC || !mixedBuffer) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Generate sine wave for A and C frequencies
    generateSineWave(sineWaveA, numSamples, FREQUENCY_A);
    generateSineWave(sineWaveC, numSamples, FREQUENCY_C);

    // Mix the two waves together with different volumes
    mixBuffers(sineWaveA, sineWaveC, mixedBuffer, numSamples, 0.5, 0.5);

    // Write the mixed buffer to a WAV file
    writeWAV("output.wav", mixedBuffer, numSamples);

    printf("WAV file generated successfully: output.wav\n");

    // Cleanup
    free(sineWaveA);
    free(sineWaveC);
    free(mixedBuffer);

    return 0;
}