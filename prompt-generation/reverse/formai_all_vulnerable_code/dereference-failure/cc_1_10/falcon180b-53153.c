//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define SAMPLE_RATE 44100
#define NUM_SECONDS 5
#define NUM_SAMPLES (SAMPLE_RATE * NUM_SECONDS)

typedef struct {
    float *data;
    int length;
} AudioBuffer;

AudioBuffer *create_buffer(int length) {
    AudioBuffer *buffer = (AudioBuffer *)malloc(sizeof(AudioBuffer));
    buffer->data = (float *)malloc(sizeof(float) * length);
    buffer->length = length;
    return buffer;
}

void destroy_buffer(AudioBuffer *buffer) {
    free(buffer->data);
    free(buffer);
}

void fill_buffer_with_noise(AudioBuffer *buffer) {
    for (int i = 0; i < buffer->length; i++) {
        buffer->data[i] = rand() % 100;
    }
}

void print_buffer(AudioBuffer *buffer) {
    for (int i = 0; i < buffer->length; i++) {
        printf("%f ", buffer->data[i]);
    }
    printf("\n");
}

int main() {
    AudioBuffer *input_buffer = create_buffer(NUM_SAMPLES);
    AudioBuffer *output_buffer = create_buffer(NUM_SAMPLES);

    fill_buffer_with_noise(input_buffer);

    for (int i = 0; i < NUM_SAMPLES; i++) {
        output_buffer->data[i] = input_buffer->data[i] * 2;
    }

    print_buffer(input_buffer);
    print_buffer(output_buffer);

    destroy_buffer(input_buffer);
    destroy_buffer(output_buffer);

    return 0;
}