//Gemma-7B DATASET v1.0 Category: Digital signal processing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

typedef struct DSP_BUFFER {
    short int *samples;
    int size;
    int fill_index;
    int drain_index;
} DSP_BUFFER;

DSP_BUFFER *dsp_buffer_alloc(int size) {
    DSP_BUFFER *buffer = malloc(sizeof(DSP_BUFFER));
    buffer->samples = malloc(sizeof(short int) * size);
    buffer->size = size;
    buffer->fill_index = 0;
    buffer->drain_index = 0;
    return buffer;
}

void dsp_buffer_free(DSP_BUFFER *buffer) {
    free(buffer->samples);
    free(buffer);
}

void dsp_buffer_write(DSP_BUFFER *buffer, short int sample) {
    buffer->samples[buffer->fill_index] = sample;
    buffer->fill_index = (buffer->fill_index + 1) % buffer->size;
}

short int dsp_buffer_read(DSP_BUFFER *buffer) {
    short int sample = buffer->samples[buffer->drain_index];
    buffer->drain_index = (buffer->drain_index + 1) % buffer->size;
    return sample;
}

int main() {
    DSP_BUFFER *buffer = dsp_buffer_alloc(BUFFER_SIZE);

    // Generate a tone
    for (int i = 0; i < BUFFER_SIZE; i++) {
        dsp_buffer_write(buffer, 128);
    }

    // Play the tone
    for (int i = 0; i < BUFFER_SIZE; i++) {
        short int sample = dsp_buffer_read(buffer);
        printf("%hi ", sample);
    }

    dsp_buffer_free(buffer);

    return 0;
}