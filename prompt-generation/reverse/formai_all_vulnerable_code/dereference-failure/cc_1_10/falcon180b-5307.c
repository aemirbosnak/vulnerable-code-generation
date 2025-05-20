//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_SAMPLES 10000
#define SAMPLE_RATE 44100
#define PI 3.14159265358979323846

typedef struct {
    float *buffer;
    int size;
    int pos;
} AudioBuffer;

typedef struct {
    AudioBuffer input;
    AudioBuffer output;
} AudioStream;

void init_buffer(AudioBuffer *buffer, int size) {
    buffer->buffer = (float *)malloc(size * sizeof(float));
    buffer->size = size;
    buffer->pos = 0;
}

void free_buffer(AudioBuffer *buffer) {
    free(buffer->buffer);
}

void push_sample(AudioBuffer *buffer, float sample) {
    buffer->buffer[buffer->pos] = sample;
    buffer->pos = (buffer->pos + 1) % buffer->size;
}

float pop_sample(AudioBuffer *buffer) {
    float sample = buffer->buffer[buffer->pos];
    buffer->pos = (buffer->pos + 1) % buffer->size;
    return sample;
}

void process_stream(AudioStream *stream, float (*process_func)(float)) {
    int i;
    for (i = 0; i < stream->input.size; i++) {
        float input_sample = pop_sample(&stream->input);
        float output_sample = process_func(input_sample);
        push_sample(&stream->output, output_sample);
    }
}

float sine_wave(float x) {
    return sin(2 * PI * x * SAMPLE_RATE / SAMPLE_RATE);
}

int main() {
    AudioStream stream;
    init_buffer(&stream.input, MAX_SAMPLES);
    init_buffer(&stream.output, MAX_SAMPLES);

    int i;
    for (i = 0; i < MAX_SAMPLES; i++) {
        push_sample(&stream.input, sine_wave(i / SAMPLE_RATE));
    }

    process_stream(&stream, sine_wave);

    float *output_buffer = stream.output.buffer;
    for (i = 0; i < MAX_SAMPLES; i++) {
        printf("%f\n", output_buffer[i]);
    }

    free_buffer(&stream.input);
    free_buffer(&stream.output);

    return 0;
}