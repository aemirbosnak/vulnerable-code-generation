//FormAI DATASET v1.0 Category: Audio processing ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

void apply_gain(float *signal, int length, float gain) {
    for(int i=0; i<length; i++) {
        signal[i] *= gain;
    }
}

void apply_fade_in(float *signal, int length, int fade_length) {
    for(int i=0; i<fade_length; i++) {
        float fade_value = (float)i / (float)(fade_length-1);
        signal[i] *= fade_value;
    }
}

void apply_fade_out(float *signal, int length, int fade_length) {
    for(int i=0; i<fade_length; i++) {
        float fade_value = (float)(fade_length-i-1) / (float)(fade_length-1);
        signal[length-fade_length+i] *= fade_value;
    }
}

void apply_noise(float *signal, int length, float amplitude) {
    for(int i=0; i<length; i++) {
        signal[i] += (rand() / (float)RAND_MAX) * amplitude;
    }
}

void apply_lowpass_filter(float *signal, int length, float cutoff_freq, float sample_rate) {
    float omega = 2.0 * PI * cutoff_freq / sample_rate;
    float a = 1.0 + omega;
    float b = omega - 1.0;
    float c = omega / a;
    float d = 1.0 / a;
    float e = (1.0 - omega) / a;
    float f = (omega - 1.0) / a;

    float x1 = signal[0];
    float x2 = signal[1];
    float y1 = c * signal[0];
    float y2 = c * signal[1];

    for(int n=2; n<length; n++) {
        float x = signal[n];
        float y = d*(x + 2*x1 + x2) - e*y1 - f*y2;
        signal[n] = y;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
    }
}

int main() {
    // Generate a 1 second sine wave at 440Hz
    float sample_rate = 44100.0;
    int length = (int)sample_rate;
    float amplitude = 0.5;
    float frequency = 440.0;
    float *signal = (float*)malloc(length * sizeof(float));
    for(int n=0; n<length; n++) {
        float t = (float)n / sample_rate;
        signal[n] = amplitude * sin(2.0 * PI * frequency * t);
    }

    // Apply gain
    apply_gain(signal, length, 0.8);

    // Apply fade in and fade out
    int fade_length = (int)(0.05 * sample_rate);
    apply_fade_in(signal, length, fade_length);
    apply_fade_out(signal, length, fade_length);

    // Apply noise
    apply_noise(signal, length, 0.1);

    // Apply lowpass filter
    float cutoff_freq = 500.0;
    apply_lowpass_filter(signal, length, cutoff_freq, sample_rate);

    free(signal);
    return 0;
}