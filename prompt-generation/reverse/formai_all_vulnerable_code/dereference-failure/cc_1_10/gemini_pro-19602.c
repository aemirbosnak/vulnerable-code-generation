//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_SAMPLES 1024
#define SAMPLE_RATE 44100

typedef struct {
    float *samples;
    int num_samples;
} sound_buffer;

sound_buffer *new_sound_buffer() {
    sound_buffer *buffer = malloc(sizeof(sound_buffer));
    buffer->samples = malloc(MAX_SAMPLES * sizeof(float));
    buffer->num_samples = 0;
    return buffer;
}

void free_sound_buffer(sound_buffer *buffer) {
    free(buffer->samples);
    free(buffer);
}

void add_sample(sound_buffer *buffer, float sample) {
    if (buffer->num_samples < MAX_SAMPLES) {
        buffer->samples[buffer->num_samples++] = sample;
    }
}

void play_sound_buffer(sound_buffer *buffer) {
    for (int i = 0; i < buffer->num_samples; i++) {
        printf("%f\n", buffer->samples[i]);
    }
}

int main() {
    srand(time(NULL));

    sound_buffer *buffer = new_sound_buffer();

    for (int i = 0; i < MAX_SAMPLES; i++) {
        float sample = (float)rand() / (float)RAND_MAX;
        add_sample(buffer, sample);
    }

    play_sound_buffer(buffer);

    free_sound_buffer(buffer);

    return 0;
}