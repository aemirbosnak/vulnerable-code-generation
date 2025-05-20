//FormAI DATASET v1.0 Category: Digital signal processing ; Style: mind-bending
// This mind-bending DSP program uses complex numbers to perform frequency shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to generate a complex sinusoidal signal
void generateSignal(float *real, float *imag, int N, float freq)
{
    float w = 2 * M_PI * freq / N;
    for (int i = 0; i < N; i++)
    {
        real[i] = sin(w * i);
        imag[i] = cos(w * i);
    }
}

// Function to perform frequency shifting
void frequencyShift(float *real, float *imag, int N, float shift)
{
    for (int i = 0; i < N; i++)
    {
        float w = 2 * M_PI * shift / N;
        float re = real[i];
        float im = imag[i];
        real[i] = re * cos(w) + im * sin(w);
        imag[i] = im * cos(w) - re * sin(w);
    }
}

int main()
{
    int N = 64;     // Number of samples
    float freq = 8; // Frequency of original signal
    float shift = 4; // Amount to shift frequency
    
    // Allocate memory for arrays
    float *real = (float *) malloc(N * sizeof(float));
    float *imag = (float *) malloc(N * sizeof(float));
    
    // Generate original signal
    generateSignal(real, imag, N, freq);
    
    // Frequency shift signal
    frequencyShift(real, imag, N, shift);
    
    // Print results
    printf("Frequency shifted signal:\n");
    for (int i = 0; i < N; i++)
    {
        printf("%f + %fi\n", real[i], imag[i]);
    }
    
    // Free memory
    free(real);
    free(imag);
    
    return 0;
}