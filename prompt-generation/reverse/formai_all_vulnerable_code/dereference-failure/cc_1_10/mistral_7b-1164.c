//MISTRAL-7B DATASET v1.0 Category: Audio processing ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265359

typedef struct {
    float x, y, z;
} vector3;

typedef struct {
    int id;
    float amplitude, frequency, phase;
} oscillator;

oscillator osc[4] = {
    {1, 440.0, 0.0},
    {2, 880.0, PI},
    {3, 220.0, PI * 2.0},
    {4, 1100.0, 0.0}
};

void processAudio(float** inputBuffer, float** outputBuffer, int numSamples) {
    vector3 sum = {0.0, 0.0, 0.0};

    for (int i = 0; i < numSamples; i++) {
        for (int j = 0; j < 4; j++) {
            float amplitude = osc[j].amplitude;
            float phase = osc[j].phase;
            float frequency = osc[j].frequency;

            sum.x += amplitude * sinf(phase + 2 * PI * frequency * i / 44100.0);
            sum.y += amplitude * cosf(phase + 2 * PI * frequency * i / 44100.0);
            sum.z += amplitude;
        }

        outputBuffer[0][i] = sum.x / 4.0;
        outputBuffer[1][i] = sum.y / 4.0;
        sum.x = sum.y = sum.z = 0.0;
    }
}

int main() {
    int numChannels = 2;
    int numSamples = 1024;
    int bufferSize = numChannels * numSamples * sizeof(float);

    float* inputBuffer = malloc(bufferSize);
    float* outputBuffer = malloc(bufferSize);

    for (int i = 0; i < numSamples; i++) {
        for (int j = 0; j < numChannels; j++) {
            inputBuffer[j * numSamples + i] = sinf(i / 10.0);
        }
    }

    processAudio(inputBuffer, outputBuffer, numSamples);

    for (int i = 0; i < numSamples; i++) {
        for (int j = 0; j < numChannels; j++) {
            printf("%.4f\n", outputBuffer[j * numSamples + i]);
        }
    }

    free(inputBuffer);
    free(outputBuffer);

    return 0;
}