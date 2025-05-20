//FormAI DATASET v1.0 Category: Audio processing ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Define the structure for the complex number
typedef struct {
    double real;
    double imag;
} Complex;

// Define the structure for the audio signal
typedef struct {
    short* data;
    int length;
    int sample_rate;
} AudioSignal;

// Function to allocate memory for an audio signal
AudioSignal* allocate_signal(int length, int sample_rate) {
    AudioSignal* signal = (AudioSignal*)malloc(sizeof(AudioSignal));
    signal->data = (short*)malloc(length * sizeof(short));
    signal->length = length;
    signal->sample_rate = sample_rate;
    return signal;
}

// Function to generate a sine wave with given frequency and duration
AudioSignal* generate_sine_wave(double freq, double duration, int sample_rate) {
    int length = duration * sample_rate;
    AudioSignal* signal = allocate_signal(length, sample_rate);
    for (int i = 0; i < length; i++) {
        signal->data[i] = (short)(32767 * sin(2 * PI * freq * i / sample_rate));
    }
    return signal;
}

// Function to calculate the magnitude of the complex number
double complex_magnitude(Complex* c) {
    return sqrt(c->real * c->real + c->imag * c->imag);
}

// Function to perform Fourier Transform on the audio signal
Complex* fourier_transform(AudioSignal* signal) {
    int n = signal->length;
    Complex* fft_data = (Complex*)malloc(n * sizeof(Complex));
    for (int k = 0; k < n; k++) {
        fft_data[k].real = 0.0;
        fft_data[k].imag = 0.0;
        for (int t = 0; t < n; t++) {
            fft_data[k].real += signal->data[t] * cos(2 * PI * k * t / n);
            fft_data[k].imag -= signal->data[t] * sin(2 * PI * k * t / n);
        }
    }
    return fft_data;
}

// Function to get the frequency from index and window size 
double index_to_freq(int index, int window_size, int sample_rate) {
    return (double)index * sample_rate / window_size;
}

int main() {
    int sample_rate = 44100;
    double duration = 1.0;
    AudioSignal* signal = generate_sine_wave(1000.0, duration, sample_rate);
    Complex* fft_data = fourier_transform(signal);
    int window_size = signal->length;
    for (int i = 0; i < window_size; i++) {
        double freq = index_to_freq(i, window_size, sample_rate);
        double magnitude = complex_magnitude(&fft_data[i]);
        printf("Frequency: %.2f Hz  Magnitude: %.2f\n", freq, magnitude);
    }
    free(signal->data);
    free(signal);
    free(fft_data);
    return 0;
}