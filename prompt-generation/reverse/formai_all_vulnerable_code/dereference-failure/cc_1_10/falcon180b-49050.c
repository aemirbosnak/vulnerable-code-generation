//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define FRAME_SIZE 1024
#define NUM_CHANNELS 2

typedef struct {
    float *data;
    int size;
} AudioBuffer;

void init_buffer(AudioBuffer *buffer, int size) {
    buffer->data = (float *) malloc(sizeof(float) * size);
    buffer->size = size;
    for (int i = 0; i < size; i++) {
        buffer->data[i] = 0.0;
    }
}

void free_buffer(AudioBuffer *buffer) {
    free(buffer->data);
}

void process_audio(AudioBuffer *input_buffer, AudioBuffer *output_buffer) {
    for (int i = 0; i < input_buffer->size; i++) {
        output_buffer->data[i] = input_buffer->data[i] * 2.0;
    }
}

int main() {
    AudioBuffer input_buffer, output_buffer;
    init_buffer(&input_buffer, FRAME_SIZE);
    init_buffer(&output_buffer, FRAME_SIZE);

    while (1) {
        for (int i = 0; i < NUM_CHANNELS; i++) {
            for (int j = 0; j < FRAME_SIZE; j++) {
                input_buffer.data[j] = sin(i * j * 2.0 * M_PI / SAMPLE_RATE);
            }
            process_audio(&input_buffer, &output_buffer);
            for (int j = 0; j < FRAME_SIZE; j++) {
                printf("%f ", output_buffer.data[j]);
            }
            printf("\n");
        }
    }

    free_buffer(&input_buffer);
    free_buffer(&output_buffer);

    return 0;
}