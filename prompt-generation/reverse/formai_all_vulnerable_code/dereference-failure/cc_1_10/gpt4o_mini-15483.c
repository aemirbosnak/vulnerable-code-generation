//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265
#define SAMPLE_RATE 44100
#define DURATION 1.0  // Duration in seconds
#define FREQUENCY 440 // Frequency of the sine wave (A4)

void generateSineWave(double frequency, double duration, int sampleRate, double *buffer) {
    int totalSamples = (int)(duration * sampleRate);
    for (int i = 0; i < totalSamples; i++) {
        buffer[i] = sin(2 * PI * frequency * ((double)i / sampleRate));
    }
}

void applyHammingWindow(int sampleCount, double *buffer) {
    for (int i = 0; i < sampleCount; i++) {
        buffer[i] *= 0.54 - 0.46 * cos((2 * PI * i) / (sampleCount - 1));
    }
}

void computeFFT(int sampleCount, double *buffer) {
    // FFT implementation using Cooley-Tukey algorithm
    int n = sampleCount;
    int logN = log2(n);
    
    // Rearrange data
    double *tempBuffer = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        tempBuffer[i] = buffer[i];
    }

    for (int i = 0; i < n; i++) {
        int j = 0;
        for (int bit = 0; bit < logN; bit++) {
            j |= ((i >> bit) & 1) << (logN - 1 - bit);
        }
        buffer[j] = tempBuffer[i];
    }

    free(tempBuffer);

    // Compute FFT
    for (int s = 1; s <= logN; s++) {
        int m = 1 << s; // m = 2^s
        double wPhaseInc = -2.0 * PI / m;
        for (int k = 0; k < n; k += m) {
            double wPhase = 0.0;
            for (int j = 0; j < (m / 2); j++) {
                double wReal = cos(wPhase);
                double wImag = sin(wPhase);

                double tReal = wReal * buffer[k + j + (m / 2)] - wImag * buffer[k + j + (m / 2) + 1];
                double tImag = wReal * buffer[k + j + (m / 2) + 1] + wImag * buffer[k + j];

                buffer[k + j + (m / 2)] = buffer[k + j] - tReal;
                buffer[k + j + (m / 2) + 1] = buffer[k + j + 1] - tImag;
                buffer[k + j] += tReal;
                buffer[k + j + 1] += tImag;

                wPhase += wPhaseInc;
            }
        }
    }
}

void printFrequencySpectrum(int sampleCount, double *buffer) {
    printf("Frequency Spectrum:\n");
    for (int i = 0; i < sampleCount / 2; i++) {
        printf("Frequency bin %d: Magnitude = %f\n", i, sqrt(buffer[2 * i] * buffer[2 * i] + buffer[2 * i + 1] * buffer[2 * i + 1]));
    }
}

int main() {
    int totalSamples = (int)(DURATION * SAMPLE_RATE);
    double *buffer = malloc(totalSamples * sizeof(double));
    
    // Generate sine wave
    generateSineWave(FREQUENCY, DURATION, SAMPLE_RATE, buffer);
    
    // Apply Hamming window
    applyHammingWindow(totalSamples, buffer);

    // Compute FFT
    computeFFT(totalSamples, buffer);
    
    // Print frequency spectrum
    printFrequencySpectrum(totalSamples, buffer);

    free(buffer);
    return 0;
}