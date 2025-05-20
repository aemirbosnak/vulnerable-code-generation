//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define PI 3.14159265359
#define TWO_PI 6.28318530718

// Function prototypes
void generate_sine_wave(float *buffer, int buffer_size);
void apply_lowpass_filter(float *buffer, int buffer_size, float cutoff_frequency);

int main() {
    int buffer_size = SAMPLE_RATE / 1000; // 1 second of audio at 44.1kHz
    float *buffer = (float *)malloc(buffer_size * sizeof(float));
    float cutoff_frequency = 1000; // Hz

    generate_sine_wave(buffer, buffer_size);
    apply_lowpass_filter(buffer, buffer_size, cutoff_frequency);

    free(buffer);
    return 0;
}

// Generate a sine wave of specified frequency and amplitude
void generate_sine_wave(float *buffer, int buffer_size) {
    float frequency = 440; // Hz
    float amplitude = 0.5;

    for (int i = 0; i < buffer_size; i++) {
        float theta = (i * frequency * TWO_PI) / SAMPLE_RATE;
        buffer[i] = amplitude * sin(theta);
    }
}

// Apply a lowpass filter to the audio buffer
void apply_lowpass_filter(float *buffer, int buffer_size, float cutoff_frequency) {
    float a = 2 * cutoff_frequency * PI / SAMPLE_RATE;
    float b = -a;

    for (int i = 0; i < buffer_size; i++) {
        float y = buffer[i];
        float x1 = buffer[i - 1];
        float x2 = buffer[i + 1];

        float x = (x1 + x2) / 2;
        float xm = x - cutoff_frequency / SAMPLE_RATE;

        float ym = (a * y + b * xm) / (1 + a * b);
        buffer[i] = ym;
    }
}