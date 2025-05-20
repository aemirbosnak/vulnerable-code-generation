//FormAI DATASET v1.0 Category: Digital signal processing ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// This program generates a sine wave and low-pass filters it

#define SAMPLE_RATE 44100     // Hz (CD quality)
#define SIGNAL_FREQ 500       // Hz
#define FILTER_CUTOFF 2000    // Hz
#define FILTER_ORDER 4

double sine(double freq, double time) {
    return sin(2 * M_PI * freq * time);
}

double lowPassFilter(double sample, double cutoff, double sampleRate, double *buffer, int order) {
    double RC = 1.0 / (cutoff * 2 * M_PI);
    double dt = 1.0 / sampleRate;
    double alpha = dt / (RC + dt);
    double output = alpha * sample + (1 - alpha) * buffer[0];
    for (int i = 1; i < order; i++) {
        buffer[i-1] = alpha * output + (1 - alpha) * buffer[i];
    }
    buffer[order-1] = output;
    return output;
}

int main() {
    // Generate a sine wave
    double duration = 10.0;     // seconds
    int numSamples = duration * SAMPLE_RATE;
    double *samples = (double *) malloc(numSamples * sizeof(double));
    for (int i = 0; i < numSamples; i++) {
        double time = (double) i / SAMPLE_RATE;
        samples[i] = sine(SIGNAL_FREQ, time);
    }
    
    // Low-pass filter the sine wave
    double *buffer = (double *) calloc(FILTER_ORDER, sizeof(double));
    for (int i = 0; i < numSamples; i++) {
        samples[i] = lowPassFilter(samples[i], FILTER_CUTOFF, SAMPLE_RATE, buffer, FILTER_ORDER);
    }
    
    // Write the output to a file
    FILE *file = fopen("output.raw", "wb");
    for (int i = 0; i < numSamples; i++) {
        short int output = (short int) (samples[i] * 32767);   // Convert to 16-bit signed integer
        fwrite(&output, sizeof(output), 1, file);
    }
    fclose(file);
    
    printf("Done!\n");
    return 0;
}