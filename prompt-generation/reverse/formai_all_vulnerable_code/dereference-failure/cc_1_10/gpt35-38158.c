//FormAI DATASET v1.0 Category: Audio processing ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to apply Low Pass Filter
void lowPassFilter(double *inputBuffer, double *outputBuffer, double sampleRate, int numSamples, double cutoffFrequency) {
    double RC = 1.0 / (2.0 * M_PI * cutoffFrequency);
    double dt = 1.0 / sampleRate;
    double alpha = dt / (RC + dt);
    outputBuffer[0] = inputBuffer[0];
    for(int i=1; i<numSamples; i++) {
        outputBuffer[i] = alpha * inputBuffer[i] + (1.0 - alpha) * outputBuffer[i-1];
    }
}

// Function to apply High Pass Filter
void highPassFilter(double *inputBuffer, double *outputBuffer, double sampleRate, int numSamples, double cutoffFrequency) {
    double RC = 1.0 / (2.0 * M_PI * cutoffFrequency);
    double dt = 1.0 / sampleRate;
    double alpha = RC / (RC + dt);
    outputBuffer[0] = inputBuffer[0];
    for(int i=1; i<numSamples; i++) {
        outputBuffer[i] = alpha * (outputBuffer[i-1] + inputBuffer[i] - inputBuffer[i-1]);
    }
}

// Function to apply Normalization
void normalize(double *inputBuffer, double *outputBuffer, int numSamples) {
    double maxSample = 0.0;
    for(int i=0; i<numSamples; i++) {
        if(fabs(inputBuffer[i]) > maxSample) {
            maxSample = fabs(inputBuffer[i]);
        }
    }
    double scale = 1.0 / maxSample;
    for(int i=0; i<numSamples; i++) {
        outputBuffer[i] = inputBuffer[i] * scale;
    }
}

int main() {
    FILE *inputFile = fopen("input.wav", "rb");
    if(!inputFile) {
        printf("Error opening input file!\n");
        return 0;
    }

    char riffID[4];
    fread(riffID, 1, 4, inputFile);
    if(riffID[0] != 'R' || riffID[1] != 'I' || riffID[2] != 'F' || riffID[3] != 'F') {
        printf("Invalid WAV file format!\n");
        return 0;
    }

    fseek(inputFile, 22, SEEK_SET);
    short numChannels;
    fread(&numChannels, 2, 1, inputFile);
    if(numChannels != 1) {
        printf("Expected mono audio file!\n");
        return 0;
    }

    int sampleRate;
    fread(&sampleRate, 4, 1, inputFile);

    fseek(inputFile, 34, SEEK_SET);
    short bitsPerSample;
    fread(&bitsPerSample, 2, 1, inputFile);

    fseek(inputFile, 44, SEEK_SET);
    const int BUFFER_SIZE = 8192;
    double inputBuffer[BUFFER_SIZE];
    double outputBuffer[BUFFER_SIZE];
    int numSamplesRead = 0;
    int totalSamplesRead = 0;
    while((numSamplesRead = fread(inputBuffer, 8, BUFFER_SIZE / 2, inputFile))) {
        totalSamplesRead += numSamplesRead;
        normalize(inputBuffer, inputBuffer, numSamplesRead);
        lowPassFilter(inputBuffer, outputBuffer, sampleRate, numSamplesRead, 2000);
        highPassFilter(outputBuffer, outputBuffer, sampleRate, numSamplesRead, 20);
        normalize(outputBuffer, outputBuffer, numSamplesRead);
        fwrite(outputBuffer, 8, numSamplesRead, stdout);
    }
    fclose(inputFile);
    return 0;
}