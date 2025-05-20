//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define FRAME_SIZE 1024

typedef struct {
    float *data;
    int capacity;
    int size;
} Buffer;

void init_buffer(Buffer *buffer, int capacity) {
    buffer->data = (float *)malloc(capacity * sizeof(float));
    buffer->capacity = capacity;
    buffer->size = 0;
}

void push_sample(Buffer *buffer, float sample) {
    if (buffer->size == buffer->capacity) {
        printf("Buffer overflow!\n");
        return;
    }
    buffer->data[buffer->size] = sample;
    buffer->size++;
}

void process_buffer(Buffer *buffer, float (*process_function)(float)) {
    for (int i = 0; i < buffer->size; i++) {
        buffer->data[i] = process_function(buffer->data[i]);
    }
}

float square(float x) {
    return x * x;
}

float sawtooth(float x) {
    return 2 * x - 1;
}

int main() {
    Buffer input_buffer, output_buffer;

    init_buffer(&input_buffer, FRAME_SIZE);
    init_buffer(&output_buffer, FRAME_SIZE);

    while (1) {
        for (int i = 0; i < FRAME_SIZE; i++) {
            float sample = (float)rand() / RAND_MAX;
            push_sample(&input_buffer, sample);
        }

        process_buffer(&input_buffer, square);
        process_buffer(&input_buffer, sawtooth);

        for (int i = 0; i < input_buffer.size; i++) {
            printf("%f ", input_buffer.data[i]);
        }
        printf("\n");
    }

    return 0;
}