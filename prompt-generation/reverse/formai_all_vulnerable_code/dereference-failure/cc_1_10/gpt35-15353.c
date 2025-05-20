//FormAI DATASET v1.0 Category: Audio processing ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define PI 3.14159265

// Function to generate a sine wave
void generateSineWave(double frequency, double amplitude, double duration, double *buffer) {
    int samples = duration * SAMPLE_RATE;

    for(int i=0; i<samples; i++) {
        buffer[i] = amplitude * sin(2 * PI * frequency * i / SAMPLE_RATE);
    }
}

// Function to apply delay effect to audio signal
void addDelay(double *input, int size, double delayTime, double decay) {
    int delaySamples = delayTime * SAMPLE_RATE;

    double *delayBuffer = (double*) malloc(sizeof(double) * delaySamples);
    for(int i=0; i<delaySamples; i++) {
        delayBuffer[i] = 0;
    }

    for(int i=0; i<size; i++) {
        double delayedSample = delayBuffer[i % delaySamples];
        delayBuffer[i % delaySamples] = decay * input[i] + delayedSample * (1 - decay);
        input[i] += delayedSample;
    }

    free(delayBuffer);
}

int main() {
    double frequency = 440; // A4 note
    double amplitude = 0.8;
    double duration = 5;
    double delayTime = 0.5;
    double decay = 0.6;

    int bufferLength = duration * SAMPLE_RATE;
    double *audioBuffer = (double*) malloc(sizeof(double) * bufferLength);

    generateSineWave(frequency, amplitude, duration, audioBuffer);
    addDelay(audioBuffer, bufferLength, delayTime, decay);

    FILE *outputFile;
    outputFile = fopen("audioOutput.txt", "w");

    for(int i=0; i<bufferLength; i++) {
        fprintf(outputFile, "%f\n", audioBuffer[i]);
    }

    fclose(outputFile);
    free(audioBuffer);

    return 0;
}