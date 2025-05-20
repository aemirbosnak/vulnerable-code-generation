//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <portaudio.h>

#define NUM_CHANNELS (2)
#define SAMPLE_RATE (44100)
#define FRAMES_PER_BUFFER (64)

typedef struct {
    float *buffer;
    int frames_to_process;
    int frames_processed;
} CallbackData;

static int callback(const void *inputBuffer, void *outputBuffer,
                   unsigned long framesPerBuffer,
                   const PaStreamCallbackTimeInfo *timeInfo,
                   PaStreamCallbackFlags statusFlags,
                   void *userData) {
    CallbackData *data = (CallbackData *)userData;

    const float *in = (const float *)inputBuffer;
    float *out = (float *)outputBuffer;
    int frames_to_process = data->frames_to_process;

    for (int i = 0; i < frames_to_process; i++) {
        *out++ = *in++;
    }

    data->frames_to_process -= frames_to_process;
    data->frames_processed += frames_to_process;

    return paContinue;
}

int main(int argc, char **argv) {
    PaStream *stream;
    PaError err;

    CallbackData data;

    data.buffer = malloc(sizeof(float) * NUM_CHANNELS * FRAMES_PER_BUFFER);
    data.frames_to_process = NUM_CHANNELS * FRAMES_PER_BUFFER;
    data.frames_processed = 0;

    err = Pa_Initialize();
    if (err != paNoError) {
        goto error;
    }

    err = Pa_OpenStream(&stream,
                        0,
                        NUM_CHANNELS,
                        paFloat32,
                        SAMPLE_RATE,
                        FRAMES_PER_BUFFER,
                        callback,
                        &data);
    if (err != paNoError) {
        goto error;
    }

    err = Pa_StartStream(stream);
    if (err != paNoError) {
        goto error;
    }

    while (data.frames_processed < data.frames_to_process) {
        Pa_Sleep(100);
    }

    err = Pa_StopStream(stream);
    if (err != paNoError) {
        goto error;
    }

    err = Pa_CloseStream(stream);
    if (err != paNoError) {
        goto error;
    }

    Pa_Terminate();

    free(data.buffer);

    return 0;

error:
    Pa_Terminate();
    fprintf(stderr, "Error: %s\n", Pa_GetErrorText(err));
    return -1;
}