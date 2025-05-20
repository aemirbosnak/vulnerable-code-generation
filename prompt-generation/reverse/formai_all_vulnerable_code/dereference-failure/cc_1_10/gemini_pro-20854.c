//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <portaudio.h>

#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 512

typedef struct {
    int16_t *buffer;
    unsigned int frame_index;
} audio_buffer_t;

static int audio_callback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *userData) {
    audio_buffer_t *buffer = (audio_buffer_t *)userData;

    (void)inputBuffer; // Prevent unused parameter warning

    const int16_t *in = buffer->buffer + buffer->frame_index;
    int16_t *out = (int16_t *)outputBuffer;

    for (unsigned int i = 0; i < framesPerBuffer; i++) {
        out[i] = *in++;
    }

    buffer->frame_index = buffer->frame_index + framesPerBuffer;
    return paContinue;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    int16_t buffer[FRAMES_PER_BUFFER * 2];
    audio_buffer_t audio_buffer = {
        .buffer = buffer,
        .frame_index = 0
    };

    PaStream *stream;
    PaError error = Pa_Initialize();
    if (error != paNoError) {
        fprintf(stderr, "Error initializing PortAudio: %s\n", Pa_GetErrorText(error));
        return EXIT_FAILURE;
    }

    error = Pa_OpenDefaultStream(&stream, 1, 1, paInt16, SAMPLE_RATE, FRAMES_PER_BUFFER, audio_callback, &audio_buffer);
    if (error != paNoError) {
        fprintf(stderr, "Error opening default stream: %s\n", Pa_GetErrorText(error));
        return EXIT_FAILURE;
    }

    error = Pa_StartStream(stream);
    if (error != paNoError) {
        fprintf(stderr, "Error starting stream: %s\n", Pa_GetErrorText(error));
        return EXIT_FAILURE;
    }

    int num_bytes = 0;
    while ((num_bytes = fread(buffer, sizeof(int16_t), FRAMES_PER_BUFFER * 2, file)) > 0) {
        if (num_bytes < FRAMES_PER_BUFFER * 2) {
            memset(buffer + num_bytes, 0, FRAMES_PER_BUFFER * 2 - num_bytes);
        }
    }

    error = Pa_StopStream(stream);
    if (error != paNoError) {
        fprintf(stderr, "Error stopping stream: %s\n", Pa_GetErrorText(error));
        return EXIT_FAILURE;
    }

    error = Pa_CloseStream(stream);
    if (error != paNoError) {
        fprintf(stderr, "Error closing stream: %s\n", Pa_GetErrorText(error));
        return EXIT_FAILURE;
    }

    Pa_Terminate();

    fclose(file);

    return EXIT_SUCCESS;
}