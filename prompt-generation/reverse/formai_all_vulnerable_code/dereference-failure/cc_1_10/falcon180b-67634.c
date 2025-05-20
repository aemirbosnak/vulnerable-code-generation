//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 512

typedef struct {
    float *data;
    int size;
} AudioBuffer;

void init_buffer(AudioBuffer *buffer, int size) {
    buffer->data = (float *)malloc(size * sizeof(float));
    buffer->size = size;
}

void destroy_buffer(AudioBuffer *buffer) {
    free(buffer->data);
}

void fill_buffer(AudioBuffer *buffer, int size, float value) {
    for (int i = 0; i < size; i++) {
        buffer->data[i] = value;
    }
}

void apply_gain(AudioBuffer *buffer, float gain) {
    for (int i = 0; i < buffer->size; i++) {
        buffer->data[i] *= gain;
    }
}

void apply_pan(AudioBuffer *buffer, float pan) {
    float gain_left = cos(pan * M_PI / 2);
    float gain_right = sin(pan * M_PI / 2);

    AudioBuffer left_buffer;
    init_buffer(&left_buffer, buffer->size);
    AudioBuffer right_buffer;
    init_buffer(&right_buffer, buffer->size);

    for (int i = 0; i < buffer->size; i++) {
        left_buffer.data[i] = buffer->data[i] * gain_left;
        right_buffer.data[i] = buffer->data[i] * gain_right;
    }

    destroy_buffer(buffer);
    *buffer = left_buffer;
}

int main() {
    AudioBuffer buffer;
    init_buffer(&buffer, BUFFER_SIZE);

    fill_buffer(&buffer, BUFFER_SIZE, 0.5);
    apply_gain(&buffer, 2);
    apply_pan(&buffer, 0.7);

    for (int i = 0; i < buffer.size; i++) {
        printf("%f\n", buffer.data[i]);
    }

    destroy_buffer(&buffer);
    return 0;
}