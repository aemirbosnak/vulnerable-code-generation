//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define PI 3.14159265358979323846

typedef struct {
    int size;
    float *data;
} AudioBuffer;

AudioBuffer *create_buffer(int size) {
    AudioBuffer *buffer = (AudioBuffer *) malloc(sizeof(AudioBuffer));
    buffer->size = size;
    buffer->data = (float *) malloc(sizeof(float) * size);
    return buffer;
}

void destroy_buffer(AudioBuffer *buffer) {
    free(buffer->data);
    free(buffer);
}

void fill_buffer(AudioBuffer *buffer, float value) {
    int i;
    for (i = 0; i < buffer->size; i++) {
        buffer->data[i] = value;
    }
}

void generate_sine_wave(AudioBuffer *buffer, float frequency, float amplitude) {
    int i;
    float phase = 0.0;
    for (i = 0; i < buffer->size; i++) {
        buffer->data[i] = amplitude * sin(2 * PI * frequency * phase);
        phase += 2 * PI * frequency / SAMPLE_RATE;
    }
}

void apply_low_pass_filter(AudioBuffer *buffer, float cutoff_frequency) {
    int i;
    float alpha = 2.0 * cutoff_frequency / SAMPLE_RATE;
    for (i = 0; i < buffer->size - 1; i++) {
        buffer->data[i] += alpha * (buffer->data[i + 1] - buffer->data[i]);
    }
    buffer->data[buffer->size - 1] += alpha * (buffer->data[0] - buffer->data[buffer->size - 1]);
}

int main() {
    AudioBuffer *input_buffer = create_buffer(44100);
    AudioBuffer *output_buffer = create_buffer(44100);

    fill_buffer(input_buffer, 1.0);
    generate_sine_wave(input_buffer, 440.0, 0.5);

    apply_low_pass_filter(input_buffer, 1000.0);

    destroy_buffer(input_buffer);
    destroy_buffer(output_buffer);

    return 0;
}