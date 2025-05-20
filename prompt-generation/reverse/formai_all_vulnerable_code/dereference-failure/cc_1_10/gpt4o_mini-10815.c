//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100 // Sampling rate in Hz
#define FREQUENCY 440.0   // Frequency of the sine wave (A4 pitch)
#define DURATION 5        // Duration in seconds
#define PI 3.14159265358979323846
#define FILTER_TAP_LENGTH 10 // Length of the filter taps

// Function Declarations
void generateSineWave(double *signal, int length, double frequency);
void applyLowPassFilter(double *input, double *output, int length, double *filterTaps);
void printSignal(const char *label, double *signal, int length);
double* createLowPassFilter(double cutoffFrequency, double sampleRate, int tapLength);

int main() {
    int totalSamples = SAMPLE_RATE * DURATION;
    double *sineWave = (double *) malloc(totalSamples * sizeof(double));
    double *filteredSignal = (double *) malloc(totalSamples * sizeof(double));
    
    // Generate the sine wave signal
    generateSineWave(sineWave, totalSamples, FREQUENCY);
    
    // Create a low pass filter
    double *filterTaps = createLowPassFilter(1000.0, SAMPLE_RATE, FILTER_TAP_LENGTH);
    
    // Apply low pass filter
    applyLowPassFilter(sineWave, filteredSignal, totalSamples, filterTaps);
    
    // Print Original and Filtered Signals
    printSignal("Original Sine Wave Signal", sineWave, totalSamples);
    printSignal("Filtered Signal", filteredSignal, totalSamples);
    
    // Cleanup
    free(sineWave);
    free(filteredSignal);
    free(filterTaps);
    
    return 0;
}

void generateSineWave(double *signal, int length, double frequency) {
    for (int i = 0; i < length; ++i) {
        signal[i] = sin(2 * PI * frequency * ((double)i / SAMPLE_RATE));
    }
}

double* createLowPassFilter(double cutoffFrequency, double sampleRate, int tapLength) {
    double *filterTaps = (double *) malloc(tapLength * sizeof(double));
    double normCutoff = cutoffFrequency / sampleRate;
    double sum = 0.0;
    
    for (int n = 0; n < tapLength; ++n) {
        if (n == (tapLength - 1) / 2) {
            filterTaps[n] = normCutoff; // Delta function at center
        } else {
            filterTaps[n] = sin(2 * PI * normCutoff * (n - (tapLength - 1) / 2)) / (PI * (n - (tapLength - 1) / 2));
        }
        sum += filterTaps[n];
    }
    
    // Normalize the filter taps
    for (int n = 0; n < tapLength; ++n) {
        filterTaps[n] /= sum;
    }

    return filterTaps;
}

void applyLowPassFilter(double *input, double *output, int length, double *filterTaps) {
    for (int n = 0; n < length; ++n) {
        output[n] = 0.0;
        for (int k = 0; k < FILTER_TAP_LENGTH; ++k) {
            if (n - k >= 0) {
                output[n] += filterTaps[k] * input[n - k];
            }
        }
    }
}

void printSignal(const char *label, double *signal, int length) {
    printf("%s:\n", label);
    for (int i = 0; i < length; i += length / 10) { // Print 10 sample points
        printf("%d: %lf\n", i, signal[i]);
    }
    printf("\n");
}