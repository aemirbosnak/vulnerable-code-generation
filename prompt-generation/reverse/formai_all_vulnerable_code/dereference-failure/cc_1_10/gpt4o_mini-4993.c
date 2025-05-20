//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846
#define SAMPLE_RATE 44100
#define DURATION 2 // in seconds

typedef struct {
    double *data;
    int length;
} Signal;

Signal generateSineWave(double frequency, double amplitude, int sampleRate, int duration) {
    int totalSamples = sampleRate * duration;
    Signal sineWave;
    sineWave.length = totalSamples;
    sineWave.data = (double *)malloc(totalSamples * sizeof(double));
    
    for (int n = 0; n < totalSamples; n++) {
        sineWave.data[n] = amplitude * sin(2 * PI * frequency * ((double)n / sampleRate));
    }
    return sineWave;
}

Signal applyHammingWindow(Signal input) {
    Signal windowedSignal;
    windowedSignal.length = input.length;
    windowedSignal.data = (double *)malloc(windowedSignal.length * sizeof(double));
    
    for (int n = 0; n < input.length; n++) {
        windowedSignal.data[n] = input.data[n] * (0.54 - 0.46 * cos(2 * PI * n / (input.length - 1)));
    }
    return windowedSignal;
}

void fft(double *x, int N) {
    // Basic Cooley-Tukey FFT implementation
    if (N <= 1) return;

    double *even = (double *)malloc(N / 2 * sizeof(double));
    double *odd = (double *)malloc(N / 2 * sizeof(double));

    for (int i = 0; i < N / 2; i++) {
        even[i] = x[2 * i];
        odd[i] = x[2 * i + 1];
    }

    fft(even, N / 2);
    fft(odd, N / 2);

    for (int i = 0; i < N / 2; i++) {
        double t = cos(2 * PI * i / N) * odd[i] - sin(2 * PI * i / N) * odd[i];
        x[i] = even[i] + t;
        x[i + N / 2] = even[i] - t;
    }

    free(even);
    free(odd);
}

void freeSignal(Signal sig) {
    free(sig.data);
}

int main() {
    // Step 1: Generate a Sine Wave
    double frequency = 440.0; // A4
    double amplitude = 0.5;
    Signal sineWave = generateSineWave(frequency, amplitude, SAMPLE_RATE, DURATION);
    
    // Step 2: Apply Hamming Window
    Signal windowedSignal = applyHammingWindow(sineWave);
    
    // Step 3: Perform FFT
    int N = windowedSignal.length;
    double *fftInput = (double *)malloc(N * sizeof(double));

    for (int i = 0; i < N; i++) {
        fftInput[i] = windowedSignal.data[i];
    }

    fft(fftInput, N);

    // Step 4: Display the FFT results
    printf("FFT Results:\n");
    for (int i = 0; i < N; i++) {
        printf("FFT[%d]: %f\n", i, fftInput[i]);
    }

    // Clean up
    freeSignal(sineWave);
    freeSignal(windowedSignal);
    free(fftInput);

    return 0;
}