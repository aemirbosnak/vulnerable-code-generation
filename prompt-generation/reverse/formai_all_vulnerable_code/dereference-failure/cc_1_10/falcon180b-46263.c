//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024
#define NUM_SAMPLES 1000000

typedef struct {
    double *data;
    int size;
} Buffer;

void init_buffer(Buffer *buffer) {
    buffer->data = malloc(buffer->size * sizeof(double));
    for (int i = 0; i < buffer->size; i++) {
        buffer->data[i] = 0.0;
    }
}

void free_buffer(Buffer *buffer) {
    free(buffer->data);
}

void process_audio(Buffer *input_buffer, Buffer *output_buffer) {
    for (int i = 0; i < input_buffer->size; i++) {
        output_buffer->data[i] = sin(input_buffer->data[i]);
    }
}

int main() {
    Buffer input_buffer, output_buffer;
    init_buffer(&input_buffer);
    init_buffer(&output_buffer);

    for (int i = 0; i < NUM_SAMPLES; i++) {
        double sample = (double)i / SAMPLE_RATE;
        for (int j = 0; j < BUFFER_SIZE; j++) {
            input_buffer.data[j] = sample;
        }
        process_audio(&input_buffer, &output_buffer);
        for (int j = 0; j < BUFFER_SIZE; j++) {
            printf("%f\n", output_buffer.data[j]);
        }
    }

    free_buffer(&input_buffer);
    free_buffer(&output_buffer);

    return 0;
}