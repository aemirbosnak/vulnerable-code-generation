//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define PI 3.14159265358979323846

typedef struct {
    float *data;
    int length;
} AudioBuffer;

void create_buffer(AudioBuffer *buffer, int length) {
    buffer->data = (float*)malloc(length * sizeof(float));
    buffer->length = length;
}

void destroy_buffer(AudioBuffer *buffer) {
    free(buffer->data);
}

void fill_buffer(AudioBuffer *buffer, float value) {
    int i;
    for (i = 0; i < buffer->length; i++) {
        buffer->data[i] = value;
    }
}

void add_buffers(AudioBuffer *buffer1, AudioBuffer *buffer2) {
    int i;
    for (i = 0; i < buffer1->length; i++) {
        buffer1->data[i] += buffer2->data[i];
    }
}

void multiply_buffers(AudioBuffer *buffer1, AudioBuffer *buffer2) {
    int i;
    for (i = 0; i < buffer1->length; i++) {
        buffer1->data[i] *= buffer2->data[i];
    }
}

void sine_wave(AudioBuffer *buffer, float frequency, float amplitude) {
    int i;
    for (i = 0; i < buffer->length; i++) {
        buffer->data[i] = amplitude * sin(2 * PI * frequency * i / SAMPLE_RATE);
    }
}

int main() {
    AudioBuffer buffer1, buffer2;

    create_buffer(&buffer1, 44100);
    create_buffer(&buffer2, 44100);

    fill_buffer(&buffer1, 1.0);
    sine_wave(&buffer2, 440, 0.5);

    add_buffers(&buffer1, &buffer2);

    destroy_buffer(&buffer2);

    return 0;
}