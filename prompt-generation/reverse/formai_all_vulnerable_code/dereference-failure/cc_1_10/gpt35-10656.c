//FormAI DATASET v1.0 Category: Digital signal processing ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants
#define PI 3.14159265

// Function prototypes
double* generateSineWave(int frequency, int sampleRate, int duration);
double* generateSquareWave(int frequency, int sampleRate, int duration);
double* addSignals(double* signal1, double* signal2, int length);
double* subtractSignals(double* signal1, double* signal2, int length);
double* multiplySignals(double* signal1, double* signal2, int length);

int main()
{
    // Generate sine wave with frequency 440Hz, sample rate 44000Hz, and duration 1 second.
    double *sineWave = generateSineWave(440, 44000, 1);

    // Generate square wave with frequency 220Hz, sample rate 44100Hz, and duration 0.5 seconds.
    double *squareWave = generateSquareWave(220, 44100, 0.5);

    // Add the two generated signals together
    double *summedSignal = addSignals(sineWave, squareWave, 44100);

    // Subtract the two generated signals from each other
    double *subtractedSignal = subtractSignals(sineWave, squareWave, 44000);

    // Multiply the two generated signals together
    double *multipliedSignal = multiplySignals(sineWave, squareWave, 22050);

    // Print out the first 10 elements of each signal
    printf("Sine wave:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%.6f ", sineWave[i]);
    }

    printf("\n\nSquare wave:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%.6f ", squareWave[i]);
    }

    printf("\n\nSummed signal:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%.6f ", summedSignal[i]);
    }

    printf("\n\nSubtracted signal:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%.6f ", subtractedSignal[i]);
    }

    printf("\n\nMultiplied signal:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%.6f ", multipliedSignal[i]);
    }

    // Free allocated memory
    free(sineWave);
    free(squareWave);
    free(summedSignal);
    free(subtractedSignal);
    free(multipliedSignal);

    return 0;
}

// Function to generate a sine wave of specified frequency, sample rate, and duration
double* generateSineWave(int frequency, int sampleRate, int duration)
{
    int numSamples = sampleRate * duration;
    double *wave = (double*) malloc(numSamples * sizeof(double));
    for (int i = 0; i < numSamples; i++)
    {
        double t = (double)i / sampleRate;
        wave[i] = sin(2 * PI * frequency * t);
    }
    return wave;
}

// Function to generate a square wave of specified frequency, sample rate, and duration
double* generateSquareWave(int frequency, int sampleRate, int duration)
{
    int numSamples = sampleRate * duration;
    double *wave = (double*) malloc(numSamples * sizeof(double));
    for (int i = 0; i < numSamples; i++)
    {
        double t = (double)i / sampleRate;
        wave[i] = sin(2 * PI * frequency * t) >= 0 ? 1.0 : -1.0;
    }
    return wave;
}

// Function to add two signals of equal length
double* addSignals(double* signal1, double* signal2, int length)
{
    double *summedSignal = (double*) malloc(length * sizeof(double));
    for (int i = 0; i < length; i++)
    {
        summedSignal[i] = signal1[i] + signal2[i];
    }
    return summedSignal;
}

// Function to subtract two signals of equal length
double* subtractSignals(double* signal1, double* signal2, int length)
{
    double *subtractedSignal = (double*) malloc(length * sizeof(double));
    for (int i = 0; i < length; i++)
    {
        subtractedSignal[i] = signal1[i] - signal2[i];
    }
    return subtractedSignal;
}

// Function to multiply two signals of equal length
double* multiplySignals(double* signal1, double* signal2, int length)
{
    double *multipliedSignal = (double*) malloc(length * sizeof(double));
    for (int i = 0; i < length; i++)
    {
        multipliedSignal[i] = signal1[i] * signal2[i];
    }
    return multipliedSignal;
}