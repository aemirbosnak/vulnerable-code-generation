//FormAI DATASET v1.0 Category: Digital signal processing ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

float sampleRate = 44100;
float frequency = 440;
float amplitude = 0.5;
float duration = 3;
float angularFrequency = 0;
float *samples;
int bufferSize = 0;

void generateSineWave()
{
    angularFrequency = 2 * PI * frequency;
    bufferSize = sampleRate * duration;
    samples = (float *) malloc(bufferSize * sizeof(float));

    for(int i = 0; i < bufferSize; i++)
    {
        float t = i / sampleRate;
        samples[i] = amplitude * sin(angularFrequency * t);
    }
}

void filterSignal()
{
    int numTaps = 31;
    float cutoffFrequency = 5000;
    float nyquistFrequency = sampleRate / 2;
    float normalizedCutoff = cutoffFrequency / nyquistFrequency;

    float *coefficients = (float *) malloc(numTaps * sizeof(float));
    float *filteredSamples = (float *) malloc(bufferSize * sizeof(float));

    for (int i = 0; i < numTaps; i++)
    {
        if (i == numTaps / 2)
            coefficients[i] = 2 * normalizedCutoff;
        else
            coefficients[i] = sin(2 * PI * normalizedCutoff * (i - numTaps / 2)) / (PI * (i - numTaps / 2));
    }

    for(int i = numTaps - 1; i < bufferSize; i++)
    {
        filteredSamples[i] = 0;
        for(int j = 0; j < numTaps; j++)
        {
            filteredSamples[i] += samples[i - j] * coefficients[j];
        }
    }

    for(int i = 0; i < bufferSize; i++)
    {
        samples[i] = filteredSamples[i];
    }

    free(coefficients);
    free(filteredSamples);
}

int main()
{
    generateSineWave();
    filterSignal();

    for(int i = 0; i < bufferSize; i++)
    {
        printf("%f\n", samples[i]);
    }

    free(samples);

    return 0;
}