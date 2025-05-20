//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double *samples;
    int length;
} Waveform;

Waveform *create_waveform(int length) {
    Waveform *waveform = malloc(sizeof(Waveform));
    waveform->samples = malloc(length * sizeof(double));
    waveform->length = length;
    return waveform;
}

void free_waveform(Waveform *waveform) {
    free(waveform->samples);
    free(waveform);
}

void generate_sine_wave(Waveform *waveform, double frequency, double amplitude) {
    for (int i = 0; i < waveform->length; i++) {
        waveform->samples[i] = amplitude * sin(2 * M_PI * frequency * i / waveform->length);
    }
}

void generate_sawtooth_wave(Waveform *waveform, double frequency, double amplitude) {
    for (int i = 0; i < waveform->length; i++) {
        waveform->samples[i] = amplitude * (2 * (i % waveform->length) / waveform->length - 1);
    }
}

void generate_square_wave(Waveform *waveform, double frequency, double amplitude) {
    for (int i = 0; i < waveform->length; i++) {
        waveform->samples[i] = amplitude * (i % waveform->length < waveform->length / 2 ? 1 : -1);
    }
}

void generate_triangle_wave(Waveform *waveform, double frequency, double amplitude) {
    for (int i = 0; i < waveform->length; i++) {
        waveform->samples[i] = amplitude * (fabs(2 * (i % waveform->length) / waveform->length - 1) - 1);
    }
}

void generate_noise(Waveform *waveform, double amplitude) {
    for (int i = 0; i < waveform->length; i++) {
        waveform->samples[i] = amplitude * (2 * ((double)rand() / RAND_MAX) - 1);
    }
}

void play_waveform(Waveform *waveform) {
    for (int i = 0; i < waveform->length; i++) {
        printf("%.2f\n", waveform->samples[i]);
    }
}

int main() {
    Waveform *waveform = create_waveform(44100);
    generate_sine_wave(waveform, 440, 0.5);
    play_waveform(waveform);
    free_waveform(waveform);
    return 0;
}