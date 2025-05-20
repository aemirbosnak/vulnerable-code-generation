//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define SAMPLE_RATE 44100
#define WINDOW_SIZE 1024
#define HOP_SIZE 512

void hann_window(float *window, int window_size) {
    for (int i = 0; i < window_size; i++) {
        window[i] = 0.5 * (1 - cos(2 * PI * i / (window_size - 1)));
    }
}

void fft(float *signal, int signal_size) {
    int log2_n = log2(signal_size);
    int n = 1 << log2_n;
    float *spectrum = malloc(signal_size * sizeof(float));
    for (int i = 0; i < signal_size; i++) {
        spectrum[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        float w = PI / n * i;
        float c = cos(w);
        float s = sin(w);
        for (int j = 0; j < signal_size; j++) {
            float x = signal[j];
            float y = x * c - signal[(j + n / 2) % signal_size] * s;
            signal[(j + n / 2) % signal_size] += x * s + y * c;
            signal[j] = y;
        }
    }
    for (int i = 0; i < signal_size; i++) {
        spectrum[i] = 2 * signal[i] / signal_size;
    }
    free(signal);
    signal = spectrum;
}

void apply_window(float *signal, int signal_size, float *window, int window_size) {
    for (int i = 0; i < signal_size; i++) {
        signal[i] *= window[i];
    }
}

void overlap_add(float *signal, int signal_size, float *window, int window_size, int hop_size) {
    int overlap = window_size - hop_size;
    for (int i = 0; i < signal_size; i++) {
        int j = i - overlap;
        if (j < 0) {
            j += signal_size;
        }
        signal[i] += signal[j];
    }
}

int main() {
    float *signal = malloc(SAMPLE_RATE * sizeof(float));
    float *window = malloc(WINDOW_SIZE * sizeof(float));
    for (int i = 0; i < SAMPLE_RATE; i++) {
        signal[i] = sin(2 * PI * i / SAMPLE_RATE);
    }
    hann_window(window, WINDOW_SIZE);
    int signal_size = SAMPLE_RATE / HOP_SIZE;
    for (int i = 0; i < signal_size; i++) {
        int start = i * HOP_SIZE;
        int end = start + WINDOW_SIZE;
        if (end > SAMPLE_RATE) {
            end = SAMPLE_RATE;
        }
        apply_window(signal + start, end - start, window, WINDOW_SIZE);
        fft(signal + start, end - start);
        overlap_add(signal + start, end - start, window, WINDOW_SIZE, HOP_SIZE);
    }
    free(signal);
    free(window);
    return 0;
}