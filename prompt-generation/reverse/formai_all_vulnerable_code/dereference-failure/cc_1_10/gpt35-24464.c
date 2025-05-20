//FormAI DATASET v1.0 Category: Audio processing ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define PI 3.14159265358979323846

float sine_wave(float freq, float duration) {
    int num_samples = (int) (duration * SAMPLE_RATE);
    float *buffer = (float *) malloc(num_samples * sizeof(float));

    for (int i = 0; i < num_samples; i++) {
        buffer[i] = sin(2 * PI * freq * i / SAMPLE_RATE);
    }

    FILE *output = fopen("sine_wave.pcm", "wb");
    fwrite(buffer, sizeof(float), num_samples, output);
    fclose(output);

    free(buffer);

    return duration;
}

float square_wave(float freq, float duty_cycle, float duration) {
    int num_samples = (int) (duration * SAMPLE_RATE);
    float *buffer = (float *) malloc(num_samples * sizeof(float));

    float period = 1 / freq;
    int high_samples = (int) (duty_cycle * period * SAMPLE_RATE);
    int low_samples = (int) ((1 - duty_cycle) * period * SAMPLE_RATE);

    for (int i = 0; i < num_samples; i++) {
        if (i % ((int) period * SAMPLE_RATE) < high_samples) {
            buffer[i] = 1.0;
        } else {
            buffer[i] = -1.0;
        }
    }

    FILE *output = fopen("square_wave.pcm", "wb");
    fwrite(buffer, sizeof(float), num_samples, output);
    fclose(output);

    free(buffer);

    return duration;
}

int main() {
    float freq = 440.0;
    float duration = 1.0;

    sine_wave(freq, duration);
    square_wave(freq, 0.5, duration);

    return 0;
}