//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SAMPLE_RATE 44100
#define PI 3.14159265358979323846
#define SIGNAL_LENGTH 44100 // 1 second of audio

void generateSignal(double *signal, int length, double frequency) {
    for (int i = 0; i < length; i++) {
        signal[i] = 0.5 * sin(2 * PI * frequency * i / SAMPLE_RATE); // Amplitude of 0.5
    }
}

void addNoise(double *signal, int length, double noiseAmplitude) {
    for (int i = 0; i < length; i++) {
        signal[i] += ((double)rand() / RAND_MAX) * noiseAmplitude - (noiseAmplitude / 2.0); // Uniform noise
    }
}

void applyFourierTransform(double *signal, double *real, double *imag, int length) {
    for (int k = 0; k < length; k++) {
        real[k] = 0;
        imag[k] = 0;
        for (int n = 0; n < length; n++) {
            real[k] += signal[n] * cos(2 * PI * k * n / length);
            imag[k] += -signal[n] * sin(2 * PI * k * n / length);
        }
    }
}

void outputSpectrum(double *real, double *imag, int length) {
    printf("Frequency Spectrum:\n");
    for (int i = 0; i < length; i++) {
        double magnitude = sqrt(real[i] * real[i] + imag[i] * imag[i]);
        printf("Frequency %d Hz: Magnitude = %.5f\n", i, magnitude);
    }
}

int main() {
    // Setting the scene, dear Watson
    printf("Welcome to 221B Baker Street's Audio Detective Program!\n");
    printf("We shall investigate a mysterious signal...\n\n");

    // Prepare signal and noise
    double *signal = malloc(SIGNAL_LENGTH * sizeof(double));
    double *real = malloc(SIGNAL_LENGTH * sizeof(double));
    double *imag = malloc(SIGNAL_LENGTH * sizeof(double));

    if (signal == NULL || real == NULL || imag == NULL) {
        fprintf(stderr, "Memory allocation failed. Adequate resources are non-existent!\n");
        return EXIT_FAILURE;
    }

    double frequency = 440.0; // A4 note, 440 Hz
    printf("Generating a clean sine wave of frequency %.2f Hz...\n", frequency);
    generateSignal(signal, SIGNAL_LENGTH, frequency);

    double noiseAmplitude = 0.2; // Adding some noise
    printf("Adding noise with amplitude %.2f...\n", noiseAmplitude);
    addNoise(signal, SIGNAL_LENGTH, noiseAmplitude);

    // Utilizing the Fast Fourier Transform
    printf("Applying Fourier Transform to unveil the frequencies...\n");
    applyFourierTransform(signal, real, imag, SIGNAL_LENGTH);

    // Reporting findings
    outputSpectrum(real, imag, SIGNAL_LENGTH);

    // Clean up resources
    free(signal);
    free(real);
    free(imag);

    printf("\nThe mystery of the audio signal has been resolved, Watson.\n");
    printf("This concludes our auditory investigation.\n");

    return EXIT_SUCCESS;
}