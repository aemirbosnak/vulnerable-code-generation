//FormAI DATASET v1.0 Category: Audio processing ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants
#define PI 3.14159265358979323846
#define TWO_PI 6.283185307179586


// Generate a sine wave
void sineWave(int length, double *signal, double frequency, double sampleRate) {
    int i;

    for (i = 0; i < length; i++) {
        signal[i] = sin(TWO_PI * frequency * i / sampleRate);
    }
}


// Add two signals together
// Note: Both signals must be of the same length
void addSignals(int length, double *signal1, double *signal2, double *result) {
    int i;

    for (i = 0; i < length; i++) {
        result[i] = signal1[i] + signal2[i];
    }
}


// Apply an amplitude envelope to a signal
void applyEnvelope(int length, double *signal, double *envelope) {
    int i;

    for (i = 0; i < length; i++) {
        signal[i] *= envelope[i];
    }
}


// Normalize a signal to a specified peak value
void normalizeSignal(int length, double *signal, double peakValue) {
    int i;
    double max = 0.0;

    // Find maximum value in the signal
    for (i = 0; i < length; i++) {
        if (abs(signal[i]) > max) {
            max = abs(signal[i]);
        }
    }

    // Normalize signal to peak value
    if (max > 0.0) {
        for (i = 0; i < length; i++) {
            signal[i] *= peakValue / max;
        }
    }
}


// Save a signal to a file
void saveToFile(int length, double *signal, char *filename) {
    int i;
    FILE *file = fopen(filename, "w");

    for (i = 0; i < length; i++) {
        fprintf(file, "%f\n", signal[i]);
    }

    fclose(file);
}


int main() {
    int i, length = 48000;
    double sampleRate = 48000.0;
    double frequency1 = 440.0, frequency2 = 880.0;
    double *signal1 = malloc(length * sizeof(double));
    double *signal2 = malloc(length * sizeof(double));
    double *result, *envelope;

    sineWave(length, signal1, frequency1, sampleRate);
    sineWave(length, signal2, frequency2, sampleRate);

    result = malloc(length * sizeof(double));
    addSignals(length, signal1, signal2, result);

    envelope = malloc(length * sizeof(double));
    for (i = 0; i < length; i++) {
        envelope[i] = sin(i * PI / length);
    }
    applyEnvelope(length, result, envelope);

    normalizeSignal(length, result, 0.5);

    saveToFile(length, result, "output.txt");

    free(signal1);
    free(signal2);
    free(result);
    free(envelope);

    return 0;
}