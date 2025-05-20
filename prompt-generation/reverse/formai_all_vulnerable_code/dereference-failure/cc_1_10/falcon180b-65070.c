//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BLOCK_SIZE 512

typedef struct {
    float *data;
    int size;
} buffer_t;

buffer_t *create_buffer(int size) {
    buffer_t *buf = (buffer_t *)malloc(sizeof(buffer_t));
    buf->data = (float *)malloc(sizeof(float) * size);
    buf->size = size;
    return buf;
}

void destroy_buffer(buffer_t *buf) {
    free(buf->data);
    free(buf);
}

void fill_buffer(buffer_t *buf, float value) {
    int i;
    for (i = 0; i < buf->size; i++) {
        buf->data[i] = value;
    }
}

void copy_buffer(buffer_t *dst, buffer_t *src) {
    int i;
    for (i = 0; i < src->size; i++) {
        dst->data[i] = src->data[i];
    }
}

void mix_buffers(buffer_t *dst, buffer_t *src1, buffer_t *src2) {
    int i;
    for (i = 0; i < dst->size; i++) {
        dst->data[i] = src1->data[i] + src2->data[i];
    }
}

void apply_gain(buffer_t *buf, float gain) {
    int i;
    for (i = 0; i < buf->size; i++) {
        buf->data[i] *= gain;
    }
}

void apply_delay(buffer_t *buf, int delay) {
    int i, j;
    float *data = buf->data;
    for (i = 0; i < buf->size; i++) {
        j = (i - delay) % buf->size;
        data[i] = data[j];
    }
}

int main() {
    buffer_t *input_buffer = create_buffer(BLOCK_SIZE);
    buffer_t *output_buffer = create_buffer(BLOCK_SIZE);

    float input_data[BLOCK_SIZE];
    float output_data[BLOCK_SIZE];

    int i;
    for (i = 0; i < BLOCK_SIZE; i++) {
        input_data[i] = sin(2 * M_PI * i / SAMPLE_RATE);
    }

    fill_buffer(input_buffer, input_data[0]);
    fill_buffer(output_buffer, 0);

    int delay_samples = 100;
    float gain = 0.5;

    apply_gain(input_buffer, gain);

    apply_delay(input_buffer, delay_samples);

    mix_buffers(output_buffer, input_buffer, input_buffer);

    for (i = 0; i < BLOCK_SIZE; i++) {
        printf("%f\n", output_data[i]);
    }

    destroy_buffer(input_buffer);
    destroy_buffer(output_buffer);

    return 0;
}