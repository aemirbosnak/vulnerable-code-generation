//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

typedef struct {
    float *data;
    int size;
} buffer_t;

buffer_t *create_buffer(int size) {
    buffer_t *buffer = (buffer_t *)malloc(sizeof(buffer_t));
    buffer->data = (float *)malloc(sizeof(float) * size);
    buffer->size = size;
    return buffer;
}

void destroy_buffer(buffer_t *buffer) {
    free(buffer->data);
    free(buffer);
}

void fill_buffer(buffer_t *buffer, float value) {
    int i;
    for (i = 0; i < buffer->size; i++) {
        buffer->data[i] = value;
    }
}

void add_buffers(buffer_t *dest, buffer_t *src1, buffer_t *src2) {
    int i;
    for (i = 0; i < dest->size; i++) {
        dest->data[i] = src1->data[i] + src2->data[i];
    }
}

void multiply_buffer(buffer_t *buffer, float factor) {
    int i;
    for (i = 0; i < buffer->size; i++) {
        buffer->data[i] *= factor;
    }
}

void apply_lowpass_filter(buffer_t *buffer, float cutoff_frequency) {
    int i;
    float omega = 2 * M_PI * cutoff_frequency / SAMPLE_RATE;
    for (i = 0; i < buffer->size; i++) {
        buffer->data[i] = buffer->data[i] * (1 - cos(omega * i));
    }
}

int main() {
    buffer_t *input_buffer = create_buffer(BUFFER_SIZE);
    buffer_t *output_buffer = create_buffer(BUFFER_SIZE);

    fill_buffer(input_buffer, 1.0);

    apply_lowpass_filter(input_buffer, 1000);

    multiply_buffer(input_buffer, 2.0);

    add_buffers(output_buffer, input_buffer, input_buffer);

    destroy_buffer(input_buffer);
    destroy_buffer(output_buffer);

    return 0;
}