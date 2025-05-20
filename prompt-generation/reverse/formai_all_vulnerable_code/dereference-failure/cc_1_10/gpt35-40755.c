//FormAI DATASET v1.0 Category: Audio processing ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Global Variables
const int SAMPLE_RATE = 44100;
int n;

// Function Prototypes
void printDetails();
void applyReverb(float buffer[]);
void applyDelay(float buffer[]);
void applyLowPassFilter(float buffer[]);
void mixChannels(float left[], float right[], float output[]);

int main() {
    // Allocate memory for audio buffer
    float *audioBuffer = malloc(10*SAMPLE_RATE*sizeof(float));

    // Load audio sample
    FILE *file = fopen("romantic.wav", "rb");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Get file info
    char chunkID[4];
    unsigned int chunkSize;
    char format[4];
    char subchunk1ID[4];
    unsigned int subchunk1Size;
    unsigned short audioFormat;
    unsigned short numChannels;
    unsigned int sampleRate;
    unsigned int byteRate;
    unsigned short blockAlign;
    unsigned short bitsPerSample;
    char subchunk2ID[4];
    unsigned int subchunk2Size;

    fread(&chunkID, sizeof(chunkID), 1, file);
    fread(&chunkSize, sizeof(chunkSize), 1, file);
    fread(&format, sizeof(format), 1, file);
    fread(&subchunk1ID, sizeof(subchunk1ID), 1, file);
    fread(&subchunk1Size, sizeof(subchunk1Size), 1, file);
    fread(&audioFormat, sizeof(audioFormat), 1, file);
    fread(&numChannels, sizeof(numChannels), 1, file);
    fread(&sampleRate, sizeof(sampleRate), 1, file);
    fread(&byteRate, sizeof(byteRate), 1, file);
    fread(&blockAlign, sizeof(blockAlign), 1, file);
    fread(&bitsPerSample, sizeof(bitsPerSample), 1, file);
    fread(&subchunk2ID, sizeof(subchunk2ID), 1, file);
    fread(&subchunk2Size, sizeof(subchunk2Size), 1, file);

    // Read data into audio buffer
    int i;
    for (i = 0; i < subchunk2Size/2; i++) {
        short data;
        fread(&data, sizeof(data), 1, file);
        audioBuffer[i] = (float)data/32768.0;
    }

    // Close file
    fclose(file);

    // Apply reverb effect
    applyReverb(audioBuffer);

    // Apply delay effect
    applyDelay(audioBuffer);

    // Apply low pass filter
    applyLowPassFilter(audioBuffer);

    // Mix channels to mono
    float *monoBuffer = malloc(subchunk2Size/2*sizeof(float));
    mixChannels(audioBuffer, audioBuffer, monoBuffer);

    // Output file
    FILE *outputFile = fopen("romantic_processed.wav", "wb");
    fwrite(&chunkID, sizeof(chunkID), 1, outputFile);
    fwrite(&chunkSize, sizeof(chunkSize), 1, outputFile);
    fwrite(&format, sizeof(format), 1, outputFile);
    fwrite(&subchunk1ID, sizeof(subchunk1ID), 1, outputFile);
    fwrite(&subchunk1Size, sizeof(subchunk1Size), 1, outputFile);
    fwrite(&audioFormat, sizeof(audioFormat), 1, outputFile);
    fwrite(&numChannels, sizeof(numChannels), 1, outputFile);
    fwrite(&sampleRate, sizeof(sampleRate), 1, outputFile);
    fwrite(&byteRate, sizeof(byteRate), 1, outputFile);
    fwrite(&blockAlign, sizeof(blockAlign), 1, outputFile);
    fwrite(&bitsPerSample, sizeof(bitsPerSample), 1, outputFile);
    fwrite(&subchunk2ID, sizeof(subchunk2ID), 1, outputFile);
    fwrite(&subchunk2Size, sizeof(subchunk2Size), 1, outputFile);

    short outputData;
    for (i = 0; i < subchunk2Size/2; i++) {
        outputData = (short)(monoBuffer[i]*32768.0);
        fwrite(&outputData, sizeof(outputData), 1, outputFile);
    }

    // Close output file
    fclose(outputFile);

    // Free memory
    free(audioBuffer);
    free(monoBuffer);

    printDetails();

    return 0;
}

void printDetails() {
    printf("Sample Rate: %d\n", SAMPLE_RATE);
    printf("Number of Samples: %d\n", n);
}

void applyReverb(float buffer[]) {
    // Generate impulse response
    const int impulseSize = 1000;
    float impulse[impulseSize];
    float attenuation = 0.3;
    int i;
    for (i = 0; i < impulseSize; i++) {
        impulse[i] = (float)rand()/RAND_MAX*2-1;
    }
    for (i = 0; i < n; i++) {
        int j;
        for (j = 0; j < impulseSize; j++) {
            int k = i+j;
            if (k >= n) break;
            buffer[k] += impulse[j]*attenuation;
        }
    }
}

void applyDelay(float buffer[]) {
    // Generate delayed signal
    const int delaySize = 5000;
    float delayedBuffer[n+delaySize];
    int i;
    for (i = 0; i < n+delaySize; i++) {
        if (i < delaySize) {
            delayedBuffer[i] = buffer[i];
        } else {
            delayedBuffer[i] = buffer[i]+buffer[i-delaySize]*0.3;
        }
    }
    for (i = 0; i < n; i++) {
        buffer[i] = delayedBuffer[i+delaySize]*0.7 + buffer[i]*0.3;
    }
}

void applyLowPassFilter(float buffer[]) {
    // Generate filter coefficients
    float fc = 3000.0/SAMPLE_RATE;
    float p = tan(M_PI * fc);
    float a0 = 1.0/(1.0 + p);
    float b1 = (1.0 - p)/(1.0 + p);
    float a1 = (1.0 - p)/(1.0 + p);

    // Apply filter to signal
    float x1 = 0.0;
    float y1 = 0.0;
    int i;
    for (i = 0; i < n; i++) {
        float x = buffer[i];
        float y = a0*x + a1*x1 - b1*y1;
        buffer[i] = y;
        x1 = x;
        y1 = y;
    }
}

void mixChannels(float left[], float right[], float output[]) {
    int i;
    for (i = 0; i < n; i++) {
        output[i] = 0.5*left[i]+0.5*right[i];
    }
}