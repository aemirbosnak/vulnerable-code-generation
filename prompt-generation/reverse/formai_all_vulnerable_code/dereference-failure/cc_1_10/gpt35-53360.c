//FormAI DATASET v1.0 Category: Audio processing ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define NUM_SAMPLES 44100

float sawtooth(float x) {
    return 2 * fmodf(x, 1.0f) - 1.0f;
}

void clip(float* buffer, float threshold, int size) {
    for (int i = 0; i < size; i++) {
        if (buffer[i] > threshold) {
            buffer[i] = threshold;
        } else if (buffer[i] < -threshold) {
            buffer[i] = -threshold;
        }
    }
}

void normalize(float* buffer, float threshold, int size) {
    clip(buffer, threshold, size);
    float max_amp = 0;
    for (int i = 0; i < size; i++) {
        max_amp = fmaxf(max_amp, fabsf(buffer[i]));
    }
    for (int i = 0; i < size; i++) {
        buffer[i] *= threshold / max_amp;
    }
}

float* mix(float* buffer1, float* buffer2, int size) {
    float* result = (float*) malloc(size * sizeof(float));
    for (int i = 0; i < size; i++) {
        result[i] = buffer1[i] + buffer2[i];
    }
    return result;
}

int main() {
    float* buffer = (float*) malloc(NUM_SAMPLES * sizeof(float));
    float* saw_buffer = (float*) malloc(NUM_SAMPLES * sizeof(float));
    float* mix_buffer = NULL;

    for (int i = 0; i < NUM_SAMPLES; i++) {
        buffer[i] = sinf(2 * M_PI * 440 * i / NUM_SAMPLES);
        float saw_value = sawtooth(440 * i / NUM_SAMPLES);
        saw_buffer[i] = saw_value;
    }

    mix_buffer = mix(buffer, saw_buffer, NUM_SAMPLES);
    normalize(mix_buffer, 0.8f, NUM_SAMPLES);

    FILE* f = fopen("output.pcm", "wb");
    fwrite(mix_buffer, sizeof(float), NUM_SAMPLES, f);
    fclose(f);

    free(buffer);
    free(saw_buffer);
    free(mix_buffer);

    return 0;
}