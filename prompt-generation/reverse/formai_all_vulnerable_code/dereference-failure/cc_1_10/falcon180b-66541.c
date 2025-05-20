//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

typedef struct {
    float *data;
    int capacity;
    int size;
} Buffer;

void init_buffer(Buffer *buffer) {
    buffer->data = (float *) malloc(BUFFER_SIZE * sizeof(float));
    buffer->capacity = BUFFER_SIZE;
    buffer->size = 0;
}

void push_sample(Buffer *buffer, float sample) {
    if (buffer->size == buffer->capacity) {
        fprintf(stderr, "Buffer overflow\n");
        exit(1);
    }
    buffer->data[buffer->size++] = sample;
}

float pop_sample(Buffer *buffer) {
    if (buffer->size == 0) {
        fprintf(stderr, "Buffer underflow\n");
        exit(1);
    }
    return buffer->data[--buffer->size];
}

void process_buffer(Buffer *buffer, float (*func)(float)) {
    for (int i = 0; i < buffer->size; i++) {
        buffer->data[i] = func(buffer->data[i]);
    }
}

float square(float x) {
    return x * x;
}

int main() {
    Buffer input_buffer, output_buffer;

    init_buffer(&input_buffer);
    init_buffer(&output_buffer);

    float sample;

    while (1) {
        sample = getchar();
        if (sample == EOF) {
            break;
        }
        push_sample(&input_buffer, sample);
    }

    process_buffer(&input_buffer, square);

    while (input_buffer.size > 0) {
        putchar((int) pop_sample(&input_buffer));
    }

    return 0;
}