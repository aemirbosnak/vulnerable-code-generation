//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define FRAME_SIZE 1024
#define MAX_DELAY 1000 // in milliseconds

typedef struct {
    float *data;
    int size;
} AudioBuffer;

void init_buffer(AudioBuffer *buffer, int size) {
    buffer->data = (float *) malloc(size * sizeof(float));
    buffer->size = size;
}

void free_buffer(AudioBuffer *buffer) {
    free(buffer->data);
}

void delay(AudioBuffer *input, AudioBuffer *output, int delay_ms) {
    int delay_samples = (int) round(delay_ms * SAMPLE_RATE / 1000);
    int read_index = 0;
    int write_index = delay_samples;

    while (write_index < input->size) {
        output->data[write_index] = input->data[read_index];
        read_index++;
        write_index++;
    }
}

void reverb(AudioBuffer *input, AudioBuffer *output, float decay) {
    int i, j;
    float *input_data = input->data;
    float *output_data = output->data;
    const int frame_size_ms = FRAME_SIZE / SAMPLE_RATE;

    for (i = 0; i < input->size; i++) {
        output_data[i] = input_data[i] + decay * input_data[i];

        for (j = 1; j < MAX_DELAY; j++) {
            int delay_samples = (int) round((j * frame_size_ms / 1000) * SAMPLE_RATE);
            int index = (i - delay_samples + input->size) % input->size;
            output_data[i] += input_data[index] * decay * (1 - (float) j / MAX_DELAY);
        }
    }
}

int main() {
    AudioBuffer input, output;
    init_buffer(&input, SAMPLE_RATE * FRAME_SIZE);
    init_buffer(&output, SAMPLE_RATE * FRAME_SIZE);

    float decay = 0.5;
    int delay_ms = 500;

    delay(&input, &output, delay_ms);
    reverb(&output, &input, decay);

    free_buffer(&input);
    free_buffer(&output);

    return 0;
}