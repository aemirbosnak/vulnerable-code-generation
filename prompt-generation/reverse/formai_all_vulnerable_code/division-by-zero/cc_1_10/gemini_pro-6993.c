//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <portaudio.h>

#define NUM_CHANNELS 2
#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 512

typedef struct {
    float *buffer;
    int buffer_size;
    int buffer_index;
} RingBuffer;

RingBuffer *RingBuffer_new(int size) {
    RingBuffer *rb = malloc(sizeof(RingBuffer));
    rb->buffer = malloc(sizeof(float) * size);
    rb->buffer_size = size;
    rb->buffer_index = 0;
    return rb;
}

void RingBuffer_free(RingBuffer *rb) {
    free(rb->buffer);
    free(rb);
}

void RingBuffer_write(RingBuffer *rb, float sample) {
    rb->buffer[rb->buffer_index] = sample;
    rb->buffer_index = (rb->buffer_index + 1) % rb->buffer_size;
}

float RingBuffer_read(RingBuffer *rb) {
    int index = (rb->buffer_index - 1 + rb->buffer_size) % rb->buffer_size;
    return rb->buffer[index];
}

int RingBuffer_num_samples(RingBuffer *rb) {
    return rb->buffer_size;
}

typedef struct {
    RingBuffer *buffer;
    float delay_time;
    float feedback;
    float wet_dry_mix;
} DelayLine;

DelayLine *DelayLine_new(int size, float delay_time, float feedback, float wet_dry_mix) {
    DelayLine *dl = malloc(sizeof(DelayLine));
    dl->buffer = RingBuffer_new(size);
    dl->delay_time = delay_time;
    dl->feedback = feedback;
    dl->wet_dry_mix = wet_dry_mix;
    return dl;
}

void DelayLine_free(DelayLine *dl) {
    RingBuffer_free(dl->buffer);
    free(dl);
}

void DelayLine_process(DelayLine *dl, float *input, float *output, int num_samples) {
    for (int i = 0; i < num_samples; i++) {
        float delayed_sample = RingBuffer_read(dl->buffer);
        float feedback_sample = delayed_sample * dl->feedback;
        RingBuffer_write(dl->buffer, input[i]);
        output[i] = (1 - dl->wet_dry_mix) * input[i] + dl->wet_dry_mix * (delayed_sample + feedback_sample);
    }
}

int main(int argc, char **argv) {
    PaStream *stream;
    PaError err;

    err = Pa_Initialize();
    if (err != paNoError) goto error;

    err = Pa_OpenDefaultStream(&stream, NUM_CHANNELS, NUM_CHANNELS, paFloat32, SAMPLE_RATE, FRAMES_PER_BUFFER, NULL, NULL);
    if (err != paNoError) goto error;

    err = Pa_StartStream(stream);
    if (err != paNoError) goto error;

    DelayLine *delay_line = DelayLine_new(SAMPLE_RATE * 1, 0.5, 0.5, 0.5);

    float input_buffer[FRAMES_PER_BUFFER * NUM_CHANNELS];
    float output_buffer[FRAMES_PER_BUFFER * NUM_CHANNELS];

    while (1) {
        err = Pa_ReadStream(stream, input_buffer, FRAMES_PER_BUFFER);
        if (err != paNoError) goto error;

        DelayLine_process(delay_line, input_buffer, output_buffer, FRAMES_PER_BUFFER);

        err = Pa_WriteStream(stream, output_buffer, FRAMES_PER_BUFFER);
        if (err != paNoError) goto error;
    }

error:
    Pa_Terminate();
    fprintf(stderr, "An error occurred: %s\n", Pa_GetErrorText(err));
    return err;
}