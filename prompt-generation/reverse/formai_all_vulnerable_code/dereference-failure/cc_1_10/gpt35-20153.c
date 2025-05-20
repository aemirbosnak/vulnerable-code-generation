//FormAI DATASET v1.0 Category: Audio processing ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<omp.h>
#define PI 3.14159265358979323846

//Function to generate sine wave
void generateSine(float* buffer, int sampleRate, float frequency, float duration) {
    int numberOfSamples = sampleRate * duration;
    float angularFrequency = 2 * PI * frequency;
    #pragma omp parallel for
    for(int i = 0; i < numberOfSamples; i++) {
        float time = (float)i / sampleRate;
        buffer[i] = sin(angularFrequency * time);
    }
}


//Function to pad zeros
void padZeros(float* buffer, int inputSize, int newOutputSize) {
    #pragma omp parallel for
    for(int i = inputSize; i < newOutputSize; i++) {
        buffer[i] = 0;
    }
}

//Function to apply low pass filter
void applyLowPassFilter(float* inputBuffer, float* outputBuffer, int inputSize, int outputSize, int cutOffFrequency) {
    //Calculating parameters required for low pass filter
    float RC = 1.0 / (2 * PI * cutOffFrequency);
    float dt = 1.0 / outputSize;
    float alpha = dt / (RC + dt);

    outputBuffer[0] = inputBuffer[0];
    #pragma omp parallel for
    for(int i = 1; i < outputSize; i++) {
        outputBuffer[i] = alpha * inputBuffer[i] + (1 - alpha) * outputBuffer[i-1];
    }
}

int main() {
    int sampleRate = 44100;
    float frequency = 400;
    float duration = 1;

    int cutOffFrequency = 1000;

    //Generating sine wave
    float* sineWave = (float*) malloc(sampleRate * sizeof(float));
    generateSine(sineWave, sampleRate, frequency, duration);

    //Padding zeroes to make it power of 2 to take advantage of FFT algorithm
    int newSize = 1;
    while(newSize < sampleRate) {
        newSize *= 2;
    }
    float* inputBuffer = (float*) calloc(newSize, sizeof(float));
    for(int i = 0; i < sampleRate; i++) {
        inputBuffer[i] = sineWave[i];
    }

    //Applying low pass filter
    float* outputBuffer = (float*) calloc(newSize, sizeof(float));
    applyLowPassFilter(inputBuffer, outputBuffer, sampleRate, newSize, cutOffFrequency);

    //Printing results
    for(int i = 0; i < 10; i++) {
        printf("%f\n", inputBuffer[i]);
    }
    printf("\n");
    for(int i = 0; i < 10; i++) {
        printf("%f\n", outputBuffer[i]);
    }

    free(sineWave);
    free(inputBuffer);
    free(outputBuffer);
    return 0;
}