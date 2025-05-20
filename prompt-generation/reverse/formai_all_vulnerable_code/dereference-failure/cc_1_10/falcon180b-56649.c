//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

typedef struct {
    float *data;
    int size;
} AudioBuffer;

void create_buffer(AudioBuffer *buffer, int size) {
    buffer->data = (float *) malloc(size * sizeof(float));
    buffer->size = size;
}

void destroy_buffer(AudioBuffer *buffer) {
    free(buffer->data);
}

void fill_buffer(AudioBuffer *buffer, float value) {
    int i;
    for (i = 0; i < buffer->size; i++) {
        buffer->data[i] = value;
    }
}

void print_buffer(AudioBuffer *buffer) {
    int i;
    for (i = 0; i < buffer->size; i++) {
        printf("%f ", buffer->data[i]);
    }
    printf("\n");
}

void process_buffer(AudioBuffer *input, AudioBuffer *output, float gain) {
    int i;
    for (i = 0; i < input->size; i++) {
        output->data[i] = input->data[i] * gain;
    }
}

int main() {
    AudioBuffer input, output;
    create_buffer(&input, BUFFER_SIZE);
    create_buffer(&output, BUFFER_SIZE);

    fill_buffer(&input, 1.0);
    process_buffer(&input, &output, 0.5);

    print_buffer(&input);
    print_buffer(&output);

    destroy_buffer(&input);
    destroy_buffer(&output);

    return 0;
}