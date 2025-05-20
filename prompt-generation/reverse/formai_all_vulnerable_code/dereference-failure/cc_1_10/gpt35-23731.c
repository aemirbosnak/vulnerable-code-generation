//FormAI DATASET v1.0 Category: Audio processing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// The FFT function
void fft(float* x, float* y, int n, int sign)
{
    if(n == 1)
        return;

    float *xr = malloc(n/2 * sizeof(float));
    float *xi = malloc(n/2 * sizeof(float));
    float *yr = malloc(n/2 * sizeof(float));
    float *yi = malloc(n/2 * sizeof(float));

    for(int i=0; i<n/2; i++)
    {
        xr[i] = x[2*i];
        xi[i] = x[2*i+1];
        yr[i] = y[2*i];
        yi[i] = y[2*i+1];
    }

    fft(xr, xi, n/2, sign);
    fft(yr, yi, n/2, sign);

    float theta = sign * 2 * M_PI / n;

    float wtemp = sin(0.5 * theta);
    float wpr = -2.0 * wtemp * wtemp;
    float wpi = sin(theta);
    float wr = 1.0;
    float wi = 0.0;

    for(int i=0; i<n/2; i++)
    {
        float tr = xr[i];
        float ti = xi[i];

        xr[i] = tr + wr * yr[i] - wi * yi[i];
        xi[i] = ti + wr * yi[i] + wi * yr[i];

        yr[i] = tr - wr * yr[i] + wi * yi[i];
        yi[i] = ti - wr * yi[i] - wi * yr[i];

        float temp = wr;
        wr = wr * wpr - wi * wpi + wr;
        wi = wi * wpr + temp * wpi + wi;
    }

    free(xr);
    free(xi);
    free(yr);
    free(yi);
}

// The audio processing function
void processAudio(float* samples, int numSamples, float freq)
{
    // Compute the time it takes to play one sample
    float timePerSample = 1.0 / freq;

    // Compute the maximum frequency in the signal
    float maxFreq = freq / 2.0;

    // Compute the FFT size that will fit the input signal
    int fftSize = 1;
    while(fftSize < numSamples)
        fftSize *= 2;

    // Allocate memory for the input and output data
    float *realIn = calloc(fftSize, sizeof(float));
    float *imagIn = calloc(fftSize, sizeof(float));
    float *realOut = calloc(fftSize, sizeof(float));
    float *imagOut = calloc(fftSize, sizeof(float));

    // Copy the input samples to the input buffer
    for(int i=0; i<numSamples; i++)
        realIn[i] = samples[i];

    // Compute the FFT of the input data
    fft(realIn, imagIn, fftSize, 1);

    // Compute the magnitude spectrum of the FFT
    for(int i=0; i<fftSize/2+1; i++)
    {
        float freq = i * maxFreq / (fftSize/2);
        float magnitude = sqrt(realIn[i]*realIn[i] + imagIn[i]*imagIn[i]);
        printf("%f Hz: %f\n", freq, magnitude);
    }

    free(realIn);
    free(imagIn);
    free(realOut);
    free(imagOut);
}

int main()
{
    // Generate a sine wave with frequency 440 Hz at 44100 Hz sampling rate
    float samplingRate = 44100.0;
    float frequency = 440.0;
    float duration = 1.0;
    int numSamples = (int)(duration * samplingRate);
    float *samples = malloc(numSamples * sizeof(float));
    for(int i=0; i<numSamples; i++)
        samples[i] = sin(2.0 * M_PI * frequency * i / samplingRate);

    // Process the audio
    processAudio(samples, numSamples, samplingRate);

    free(samples);

    return 0;
}