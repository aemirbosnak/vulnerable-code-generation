//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 1024
#define NUM_CHANNELS 2

typedef struct {
    float *data;
    int capacity;
    int size;
} AudioBuffer;

void init_audio_buffer(AudioBuffer *buffer, int capacity) {
    buffer->data = (float *) malloc(capacity * sizeof(float));
    buffer->capacity = capacity;
    buffer->size = 0;
}

void push_audio_sample(AudioBuffer *buffer, float sample) {
    if (buffer->size == buffer->capacity) {
        printf("Error: Audio buffer is full.\n");
        return;
    }

    buffer->data[buffer->size] = sample;
    buffer->size++;
}

void process_audio_buffer(AudioBuffer *buffer, float (*process_function)(float)) {
    for (int i = 0; i < buffer->size; i++) {
        buffer->data[i] = process_function(buffer->data[i]);
    }
}

float add_gain(float sample, float gain) {
    return sample + gain;
}

int main() {
    AudioBuffer input_buffer, output_buffer;

    init_audio_buffer(&input_buffer, 44100 * 5); // 5 seconds of audio
    init_audio_buffer(&output_buffer, 44100 * 5);

    float gain = 0.5;

    for (int i = 0; i < 44100 * 5; i++) {
        float sample = sin(2 * M_PI * i / SAMPLE_RATE);
        push_audio_sample(&input_buffer, sample);
    }

    process_audio_buffer(&input_buffer, add_gain);

    for (int i = 0; i < input_buffer.size; i++) {
        push_audio_sample(&output_buffer, input_buffer.data[i]);
    }

    free(input_buffer.data);
    free(output_buffer.data);

    return 0;
}