//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SAMPLE_RATE 44100
#define FRAME_SIZE 1024
#define NUM_FRAMES 10

typedef struct {
    float *data;
    int capacity;
    int size;
} AudioBuffer;

void init_buffer(AudioBuffer *buffer, int capacity) {
    buffer->data = (float *) malloc(capacity * sizeof(float));
    buffer->capacity = capacity;
    buffer->size = 0;
}

void push_sample(AudioBuffer *buffer, float sample) {
    if (buffer->size >= buffer->capacity) {
        printf("Buffer overflow!\n");
        return;
    }
    buffer->data[buffer->size++] = sample;
}

void process_buffer(AudioBuffer *buffer, float (*process_func)(float)) {
    for (int i = 0; i < buffer->size; i++) {
        buffer->data[i] = process_func(buffer->data[i]);
    }
}

float add_noise(float sample) {
    return sample + (rand() % 100) / 100.0;
}

int main() {
    srand(time(NULL));

    AudioBuffer input_buffer, output_buffer;
    init_buffer(&input_buffer, FRAME_SIZE * NUM_FRAMES);
    init_buffer(&output_buffer, FRAME_SIZE * NUM_FRAMES);

    for (int i = 0; i < NUM_FRAMES; i++) {
        for (int j = 0; j < FRAME_SIZE; j++) {
            float sample = sin(2 * M_PI * 440 * (float) j / SAMPLE_RATE);
            push_sample(&input_buffer, sample);
        }
    }

    process_buffer(&input_buffer, add_noise);

    for (int i = 0; i < NUM_FRAMES; i++) {
        for (int j = 0; j < FRAME_SIZE; j++) {
            float sample = input_buffer.data[(i * FRAME_SIZE) + j];
            push_sample(&output_buffer, sample);
        }
    }

    for (int i = 0; i < output_buffer.size; i++) {
        printf("%f ", output_buffer.data[i]);
    }

    return 0;
}