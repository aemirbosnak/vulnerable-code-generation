//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

typedef struct {
    float *buffer;
    int buffer_size;
    int read_index;
    int write_index;
} CircularBuffer;

void init_circular_buffer(CircularBuffer *buffer, int size) {
    buffer->buffer = (float *)malloc(size * sizeof(float));
    buffer->buffer_size = size;
    buffer->read_index = 0;
    buffer->write_index = 0;
}

void push_sample(CircularBuffer *buffer, float sample) {
    buffer->buffer[buffer->write_index] = sample;
    buffer->write_index = (buffer->write_index + 1) % buffer->buffer_size;
}

float pop_sample(CircularBuffer *buffer) {
    float sample = buffer->buffer[buffer->read_index];
    buffer->read_index = (buffer->read_index + 1) % buffer->buffer_size;
    return sample;
}

void process_buffer(CircularBuffer *buffer, float (*process_func)(float)) {
    int num_samples = buffer->write_index - buffer->read_index;
    if (num_samples > 0) {
        for (int i = 0; i < num_samples; i++) {
            float sample = pop_sample(buffer);
            float processed_sample = process_func(sample);
            push_sample(buffer, processed_sample);
        }
    }
}

float low_pass_filter(float sample) {
    static float alpha = 0.9;
    static float last_sample = 0.0;
    float filtered_sample = alpha * last_sample + (1.0 - alpha) * sample;
    last_sample = filtered_sample;
    return filtered_sample;
}

int main() {
    srand(time(NULL));

    CircularBuffer input_buffer, output_buffer;
    init_circular_buffer(&input_buffer, BUFFER_SIZE);
    init_circular_buffer(&output_buffer, BUFFER_SIZE);

    float noise = 0.0;
    while (1) {
        noise += (rand() % 1000) / 1000.0;
        push_sample(&input_buffer, noise);
        process_buffer(&input_buffer, low_pass_filter);
        float output_sample = pop_sample(&output_buffer);
        printf("%.4f\n", output_sample);
        fflush(stdout);
    }

    return 0;
}