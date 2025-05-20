//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

typedef struct {
    float* buffer;
    int size;
} AudioBuffer;

void initialize_buffer(AudioBuffer* buffer, int size) {
    buffer->buffer = malloc(size * sizeof(float));
    buffer->size = size;
    for (int i = 0; i < size; i++) {
        buffer->buffer[i] = 0.0f;
    }
}

void destroy_buffer(AudioBuffer* buffer) {
    free(buffer->buffer);
}

void generate_sine_wave(AudioBuffer* buffer, int frequency, int duration) {
    int num_samples = duration * SAMPLE_RATE / 1000;
    for (int i = 0; i < num_samples; i++) {
        float angle = (2.0f * M_PI * i * frequency) / SAMPLE_RATE;
        buffer->buffer[i] = sin(angle);
    }
}

void process_audio(AudioBuffer* input, AudioBuffer* output, int duration) {
    int num_samples = duration * SAMPLE_RATE / 1000;
    for (int i = 0; i < num_samples; i++) {
        output->buffer[i] = input->buffer[i] * 2.0f;
    }
}

int main() {
    AudioBuffer input, output;
    initialize_buffer(&input, BUFFER_SIZE);
    initialize_buffer(&output, BUFFER_SIZE);

    generate_sine_wave(&input, 440, 5000);
    process_audio(&input, &output, 5000);

    for (int i = 0; i < BUFFER_SIZE; i++) {
        printf("%f\n", output.buffer[i]);
    }

    destroy_buffer(&input);
    destroy_buffer(&output);

    return 0;
}