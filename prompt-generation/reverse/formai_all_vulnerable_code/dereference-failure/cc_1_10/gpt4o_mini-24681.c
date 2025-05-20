//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SAMPLES 1024
#define PI 3.14159265358979323846

// Function to generate a sine wave
void generateSineWave(float *data, int numSamples, float frequency, float sampleRate) {
    for (int i = 0; i < numSamples; i++) {
        data[i] = sin(2 * PI * frequency * i / sampleRate);
    }
}

// Function to perform FFT using Cooley-Tukey algorithm
void FFT(float* real, float* imag, int n) {
    if (n <= 1) return;

    float* evenReal = (float*)malloc(n / 2 * sizeof(float));
    float* evenImag = (float*)malloc(n / 2 * sizeof(float));
    float* oddReal = (float*)malloc(n / 2 * sizeof(float));
    float* oddImag = (float*)malloc(n / 2 * sizeof(float));

    for (int i = 0; i < n / 2; i++) {
        evenReal[i] = real[i * 2];
        evenImag[i] = imag[i * 2];
        oddReal[i] = real[i * 2 + 1];
        oddImag[i] = imag[i * 2 + 1];
    }

    FFT(evenReal, evenImag, n / 2);
    FFT(oddReal, oddImag, n / 2);

    for (int k = 0; k < n / 2; k++) {
        float tReal = cos(2 * PI * k / n) * oddReal[k] - sin(2 * PI * k / n) * oddImag[k];
        float tImag = sin(2 * PI * k / n) * oddReal[k] + cos(2 * PI * k / n) * oddImag[k];

        real[k] = evenReal[k] + tReal;
        imag[k] = evenImag[k] + tImag;
        real[k + n / 2] = evenReal[k] - tReal;
        imag[k + n / 2] = evenImag[k] - tImag;
    }

    free(evenReal);
    free(evenImag);
    free(oddReal);
    free(oddImag);
}

// Function to print the FFT results
void printFFTResult(float* real, float* imag, int n) {
    printf("FFT Results:\n");
    for (int i = 0; i < n; i++) {
        printf("Frequency Bin %d: Real: %f, Imaginary: %f\n", i, real[i], imag[i]);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Usage: %s <num_samples> <frequency> <sample_rate>\n", argv[0]);
        return 1;
    }

    int numSamples = atoi(argv[1]);
    float frequency = atof(argv[2]);
    float sampleRate = atof(argv[3]);

    if (numSamples > MAX_SAMPLES || numSamples <= 0) {
        printf("Please specify a valid number of samples (1 to %d).\n", MAX_SAMPLES);
        return 1;
    }

    float* sineWaveData = (float*)malloc(numSamples * sizeof(float));
    float* real = (float*)malloc(numSamples * sizeof(float));
    float* imag = (float*)malloc(numSamples * sizeof(float));

    // Generate Sine Wave
    generateSineWave(sineWaveData, numSamples, frequency, sampleRate);

    // Prepare for FFT
    for (int i = 0; i < numSamples; i++) {
        real[i] = sineWaveData[i];
        imag[i] = 0.0; // Imaginary part is 0 for real signals
    }

    // Perform FFT
    FFT(real, imag, numSamples);

    // Print FFT Result
    printFFTResult(real, imag, numSamples);

    // Clean up
    free(sineWaveData);
    free(real);
    free(imag);

    return 0;
}