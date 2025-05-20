//FormAI DATASET v1.0 Category: Digital signal processing ; Style: peaceful
/* A Digital Signal Processing Example: Implementing a Low Pass Filter */

#include <stdio.h>
#include <stdlib.h>

/* Define Filter Parameters */
#define SAMPLE_RATE 8000
#define CUTOFF_FREQ 1000
#define PI 3.14159265358979323846

/* Declare Function Prototypes */
float* generateSineWave(int, int, float);
float* lowPassFilter(float*, int, int, int, float*);
void printSignal(char*, float*, int);

/* Main Function */
int main() {

    /* Define Variables */
    int sampleSize = SAMPLE_RATE * 2; // 2 seconds worth of data
    float* inputSignal = generateSineWave(sampleSize, SAMPLE_RATE, 440);
    float* filteredSignal = lowPassFilter(inputSignal, sampleSize, SAMPLE_RATE, CUTOFF_FREQ, NULL);

    /* Print Results */
    printSignal("Input Signal", inputSignal, sampleSize);
    printSignal("Filtered Signal", filteredSignal, sampleSize);

    /* Free Allocated Memory */
    free(inputSignal);
    free(filteredSignal);

    return 0;
}

/* Function: generateSineWave
   Generates a sine wave with the specified frequency and
   sample rate for the specified number of samples */
float* generateSineWave(int numSamples, int sampleRate, float frequency) {

    /* Define Variables */
    float* outputSignal = malloc(numSamples * sizeof(float));
    int i;

    /* Generate Signal */
    for (i = 0; i < numSamples; i++) {
        outputSignal[i] = sin(2 * PI * frequency * i / sampleRate);
    }

    return outputSignal;
}

/* Function: lowPassFilter
   Implements a low pass filter with the specified cutoff frequency
   and sample rate, filtering the input signal */
float* lowPassFilter(float* inputSignal, int numSamples, int sampleRate,
                     int cutoffFreq, float* outputSignal) {

    /* Define Variables */
    float RC = 1.0 / (2 * PI * cutoffFreq);
    float dt = 1.0 / sampleRate;
    float alpha = dt / (RC + dt);
    int i;

    /* Allocate Output Signal Memory */
    if (outputSignal == NULL) {
        outputSignal = malloc(numSamples * sizeof(float));
    }

    /* Apply Filter */
    outputSignal[0] = inputSignal[0];
    for (i = 1; i < numSamples; i++) {
        outputSignal[i] = alpha * inputSignal[i] + (1 - alpha) * outputSignal[i - 1];
    }

    return outputSignal;
}

/* Function: printSignal
   Prints the specified signal to the console */
void printSignal(char* signalName, float* signal, int numSamples) {

    /* Print Signal Name */
    printf("%s: \n", signalName);

    /* Print Signal Values */
    int i;
    for (i = 0; i < numSamples; i++) {
        printf("%f ", signal[i]);
    }
    printf("\n\n");
}