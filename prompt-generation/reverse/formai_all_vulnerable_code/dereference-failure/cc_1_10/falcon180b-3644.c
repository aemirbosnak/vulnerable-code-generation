//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024
#define NUM_CHANNELS 2

typedef struct {
    float *data;
    int size;
} AudioBuffer;

void generate_sine_wave(float *buffer, int size, float frequency) {
    for (int i = 0; i < size; i++) {
        float t = (float)i / SAMPLE_RATE;
        buffer[i] = sin(2 * M_PI * frequency * t);
    }
}

void mix_channels(AudioBuffer *buffer1, AudioBuffer *buffer2, AudioBuffer *output) {
    for (int i = 0; i < buffer1->size; i++) {
        output->data[i] = buffer1->data[i] + buffer2->data[i];
    }
}

void apply_gain(AudioBuffer *buffer, float gain) {
    for (int i = 0; i < buffer->size; i++) {
        buffer->data[i] *= gain;
    }
}

void apply_reverb(AudioBuffer *buffer, float decay) {
    float *reverb_buffer = malloc(buffer->size * sizeof(float));
    reverb_buffer[0] = buffer->data[0];

    for (int i = 1; i < buffer->size; i++) {
        reverb_buffer[i] = reverb_buffer[i - 1] * decay + buffer->data[i];
    }

    for (int i = 0; i < buffer->size; i++) {
        buffer->data[i] += reverb_buffer[i];
    }

    free(reverb_buffer);
}

int main() {
    AudioBuffer buffer1, buffer2, output;

    buffer1.data = malloc(BUFFER_SIZE * sizeof(float));
    buffer1.size = BUFFER_SIZE;

    buffer2.data = malloc(BUFFER_SIZE * sizeof(float));
    buffer2.size = BUFFER_SIZE;

    output.data = malloc(BUFFER_SIZE * sizeof(float));
    output.size = BUFFER_SIZE;

    generate_sine_wave(buffer1.data, BUFFER_SIZE, 440);
    generate_sine_wave(buffer2.data, BUFFER_SIZE, 880);

    mix_channels(&buffer1, &buffer2, &output);

    apply_gain(&output, 0.5);

    apply_reverb(&output, 0.7);

    for (int i = 0; i < output.size; i++) {
        printf("%f\n", output.data[i]);
    }

    return 0;
}