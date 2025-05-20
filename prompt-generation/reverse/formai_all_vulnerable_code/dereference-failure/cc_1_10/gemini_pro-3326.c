//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <portaudio.h>

#define SAMPLE_RATE (44100)
#define FRAMES_PER_BUFFER (1024)

typedef struct {
    float *samples;
    int num_samples;
} audio_buffer;

audio_buffer *create_buffer(int num_samples) {
    audio_buffer *buffer = malloc(sizeof(audio_buffer));
    buffer->samples = malloc(num_samples * sizeof(float));
    buffer->num_samples = num_samples;
    return buffer;
}

void free_buffer(audio_buffer *buffer) {
    free(buffer->samples);
    free(buffer);
}

void play_buffer(audio_buffer *buffer) {
    PaStream *stream;
    PaError err;

    err = Pa_Initialize();
    if (err != paNoError) goto error;

    err = Pa_OpenDefaultStream(&stream, 0, 1, paFloat32, SAMPLE_RATE, FRAMES_PER_BUFFER, NULL, NULL);
    if (err != paNoError) goto error;

    err = Pa_StartStream(stream);
    if (err != paNoError) goto error;

    err = Pa_WriteStream(stream, buffer->samples, buffer->num_samples);
    if (err != paNoError) goto error;

    err = Pa_StopStream(stream);
    if (err != paNoError) goto error;

    err = Pa_CloseStream(stream);
    if (err != paNoError) goto error;

    Pa_Terminate();
    return;

error:
    Pa_Terminate();
    fprintf(stderr, "An error occurred: %s\n", Pa_GetErrorText(err));
    exit(1);
}

int main() {
    audio_buffer *buffer = create_buffer(SAMPLE_RATE * 10);

    for (int i = 0; i < buffer->num_samples; i++) {
        buffer->samples[i] = sin(2 * M_PI * 440 * i / SAMPLE_RATE);
    }

    play_buffer(buffer);

    free_buffer(buffer);
    return 0;
}