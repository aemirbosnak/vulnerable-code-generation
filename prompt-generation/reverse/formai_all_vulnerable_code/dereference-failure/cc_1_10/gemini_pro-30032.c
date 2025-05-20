//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <portaudio.h>

#define NUM_CHANNELS 2
#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 1024

typedef struct {
    float *buffer;
    int buffer_size;
    int buffer_index;
} RingBuffer;

RingBuffer *ring_buffer_create(int size) {
    RingBuffer *buffer = malloc(sizeof(RingBuffer));
    buffer->buffer = malloc(sizeof(float) * size);
    buffer->buffer_size = size;
    buffer->buffer_index = 0;
    return buffer;
}

void ring_buffer_free(RingBuffer *buffer) {
    free(buffer->buffer);
    free(buffer);
}

void ring_buffer_push(RingBuffer *buffer, float value) {
    buffer->buffer[buffer->buffer_index] = value;
    buffer->buffer_index = (buffer->buffer_index + 1) % buffer->buffer_size;
}

float ring_buffer_pop(RingBuffer *buffer) {
    float value = buffer->buffer[buffer->buffer_index];
    buffer->buffer_index = (buffer->buffer_index - 1 + buffer->buffer_size) % buffer->buffer_size;
    return value;
}

int pa_callback(const void *input_buffer, void *output_buffer,
        unsigned long frames_per_buffer,
        const PaStreamCallbackTimeInfo* time_info,
        PaStreamCallbackFlags status_flags,
        void *user_data) {
    RingBuffer *buffer = (RingBuffer *)user_data;

    float *in = (float *)input_buffer;
    float *out = (float *)output_buffer;

    for (int i = 0; i < frames_per_buffer; i++) {
        float sample = in[i * NUM_CHANNELS];
        ring_buffer_push(buffer, sample);
        out[i * NUM_CHANNELS] = sample;
        out[i * NUM_CHANNELS + 1] = sample;
    }

    return paContinue;
}

int main(int argc, char **argv) {
    PaStream *stream;
    PaError err;

    RingBuffer *buffer = ring_buffer_create(FRAMES_PER_BUFFER * NUM_CHANNELS);

    err = Pa_Initialize();
    if (err != paNoError) goto error;

    err = Pa_OpenDefaultStream(&stream, NUM_CHANNELS, NUM_CHANNELS, paFloat32, SAMPLE_RATE, FRAMES_PER_BUFFER, pa_callback, buffer);
    if (err != paNoError) goto error;

    err = Pa_StartStream(stream);
    if (err != paNoError) goto error;

    printf("Press Enter to quit.\n");
    getchar();

    err = Pa_StopStream(stream);
    if (err != paNoError) goto error;

    err = Pa_CloseStream(stream);
    if (err != paNoError) goto error;

    Pa_Terminate();
    ring_buffer_free(buffer);
    return 0;

error:
    Pa_Terminate();
    ring_buffer_free(buffer);
    fprintf(stderr, "An error occurred: %s\n", Pa_GetErrorText(err));
    return -1;
}