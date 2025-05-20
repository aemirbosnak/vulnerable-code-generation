//FormAI DATASET v1.0 Category: Audio processing ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define CHANNELS 2
#define PI 3.14159265358979323846

void generateSineWave(float *buffer, int bufferSize, float frequency, float amplitude, int phaseShift) {
    if (buffer == NULL) {
        return;
    }
    
    float phaseShiftRadians = phaseShift * (2 * PI) / SAMPLE_RATE;
    float increment = 2 * PI * frequency / SAMPLE_RATE;
    
    for (int i = 0; i < bufferSize; i++) {
        float sample = amplitude * sin(i * increment + phaseShiftRadians);
        
        buffer[i] += sample;
    }
}

void applyTremolo(float *buffer, int bufferSize, float rate, float depth) {
    if (buffer == NULL) {
        return;
    }
    
    float tremolo = 0.5 * (1 - depth) + 0.5 * (1 + depth) * sin(2 * PI * rate / SAMPLE_RATE);
    
    for (int i = 0; i < bufferSize; i++) {
        buffer[i] *= tremolo;
    }
}

void applyReverb(float *buffer, int bufferSize, int delay, float mix) {
    if (buffer == NULL) {
        return;
    }
    
    int delaySamples = delay * SAMPLE_RATE / 1000;
    float *delayBuffer = (float *) malloc(delaySamples * sizeof(float));
    
    for (int i = 0; i < delaySamples; i++) {
        delayBuffer[i] = 0.0f;
    }
    
    for (int i = 0; i < bufferSize; i++) {
        float sample = buffer[i] + mix * delayBuffer[i % delaySamples];
        
        delayBuffer[i % delaySamples] = buffer[i];
        buffer[i] = sample;
    }
    
    free(delayBuffer);
}

int main(void) {
    int duration = 5;
    int bufferSize = duration * SAMPLE_RATE * CHANNELS;
    
    float *buffer = (float *) malloc(bufferSize * sizeof(float));
    
    for (int i = 0; i < bufferSize; i++) {
        buffer[i] = 0.0f;
    }
    
    generateSineWave(buffer, bufferSize, 440, 1.0f, 0);
    applyTremolo(buffer, bufferSize, 5, 0.5);
    applyReverb(buffer, bufferSize, 100, 0.3);
    
    FILE *outputFile = fopen("output.raw", "wb");
    
    if (outputFile == NULL) {
        return 1;
    }
    
    for (int i = 0; i < bufferSize; i++) {
        float sample = buffer[i];
        fwrite(&sample, sizeof(float), 1, outputFile);
    }
    
    fclose(outputFile);
    free(buffer);
    
    return 0;
}