//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

typedef struct {
    float *data;
    int size;
} AudioBuffer;

void init_buffer(AudioBuffer *buffer, int size) {
    buffer->data = (float *)malloc(size * sizeof(float));
    buffer->size = size;
}

void free_buffer(AudioBuffer *buffer) {
    free(buffer->data);
}

void fill_buffer(AudioBuffer *buffer, float value) {
    int i;
    for (i = 0; i < buffer->size; i++) {
        buffer->data[i] = value;
    }
}

void process_buffer(AudioBuffer *input, AudioBuffer *output) {
    int i;
    for (i = 0; i < input->size; i++) {
        output->data[i] = input->data[i] * 2.0f;
    }
}

int main() {
    AudioBuffer input, output;
    init_buffer(&input, BUFFER_SIZE);
    init_buffer(&output, BUFFER_SIZE);

    float *input_data = input.data;
    float *output_data = output.data;

    int i;
    for (i = 0; i < BUFFER_SIZE; i++) {
        input_data[i] = sin(2.0f * M_PI * i / SAMPLE_RATE);
    }

    process_buffer(&input, &output);

    for (i = 0; i < BUFFER_SIZE; i++) {
        printf("%f ", output_data[i]);
    }

    free_buffer(&input);
    free_buffer(&output);

    return 0;
}