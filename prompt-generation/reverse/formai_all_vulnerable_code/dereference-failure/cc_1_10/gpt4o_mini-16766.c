//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: high level of detail
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SAMPLE_RATE 44100  // Samples per second
#define DURATION 5         // Duration of the signal in seconds
#define PI 3.14159265358979323846

// Function to generate a sine wave
void generateSineWave(double frequency, double amplitude, double *signal, int numSamples) {
    for (int i = 0; i < numSamples; i++) {
        signal[i] = amplitude * sin(2 * PI * frequency * (i / (double)SAMPLE_RATE));
    }
}

// Function to apply a simple low-pass filter
void lowPassFilter(double *inputSignal, double *outputSignal, int numSamples, double cutoffFrequency) {
    double RC = 1.0 / (cutoffFrequency * 2 * PI);
    double dt = 1.0 / SAMPLE_RATE;
    double alpha = dt / (RC + dt);
    
    outputSignal[0] = inputSignal[0]; // Initialize the first sample

    for (int i = 1; i < numSamples; i++) {
        outputSignal[i] = outputSignal[i - 1] + (alpha * (inputSignal[i] - outputSignal[i - 1]));
    }
}

// Function to write samples to a file
void writeSamplesToFile(const char *filename, double *signal, int numSamples) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numSamples; i++) {
        fprintf(file, "%lf\n", signal[i]);
    }

    fclose(file);
}

int main() {
    // Parameters for the sine wave
    double frequency = 440.0; // Frequency in Hz (A4 note)
    double amplitude = 0.5;    // Amplitude of the signal
    int numSamples = SAMPLE_RATE * DURATION;

    // Allocate memory for the signals
    double *sineWaveSignal = (double *)malloc(numSamples * sizeof(double));
    double *filteredSignal = (double *)malloc(numSamples * sizeof(double));

    if (sineWaveSignal == NULL || filteredSignal == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    // Generate the sine wave signal
    generateSineWave(frequency, amplitude, sineWaveSignal, numSamples);

    // Apply the low-pass filter
    double cutoffFrequency = 2000.0; // Cutoff frequency in Hz
    lowPassFilter(sineWaveSignal, filteredSignal, numSamples, cutoffFrequency);

    // Write the raw and filtered signals to files
    writeSamplesToFile("sine_wave.txt", sineWaveSignal, numSamples);
    writeSamplesToFile("filtered_signal.txt", filteredSignal, numSamples);

    // Cleanup
    free(sineWaveSignal);
    free(filteredSignal);

    printf("Sine wave and filtered signal generated and saved to files.\n");

    return 0;
}