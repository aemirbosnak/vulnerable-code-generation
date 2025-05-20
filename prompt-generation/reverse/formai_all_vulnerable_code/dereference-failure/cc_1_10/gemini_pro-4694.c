//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <portaudio.h>

#define SAMPLE_RATE (44100)
#define FRAMES_PER_BUFFER (1024)

typedef struct {
    float *samples;
    int num_samples;
} AudioBuffer;

AudioBuffer *create_buffer(int num_samples) {
    AudioBuffer *buffer = calloc(1, sizeof(AudioBuffer));
    buffer->samples = calloc(num_samples, sizeof(float));
    buffer->num_samples = num_samples;
    return buffer;
}

void free_buffer(AudioBuffer *buffer) {
    free(buffer->samples);
    free(buffer);
}

int callback(const void *inputBuffer, void *outputBuffer,
                unsigned long framesPerBuffer,
                const PaStreamCallbackTimeInfo* timeInfo,
                PaStreamCallbackFlags statusFlags,
                void *userData) {
    AudioBuffer *buffer = (AudioBuffer *)userData;
    float *output = (float *)outputBuffer;
    int i;
    for (i = 0; i < framesPerBuffer; i++) {
        output[i] = buffer->samples[i];
    }
    return paContinue;
}

int main() {
    PaStream *stream;
    PaError err;
    AudioBuffer *buffer;

    err = Pa_Initialize();
    if (err != paNoError) {
        printf("Error initializing PortAudio: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    buffer = create_buffer(FRAMES_PER_BUFFER);
    for (int i = 0; i < FRAMES_PER_BUFFER; i++) {
        buffer->samples[i] = (float)rand() / (float)RAND_MAX;
    }

    err = Pa_OpenDefaultStream(&stream, 0, 1, paFloat32, SAMPLE_RATE,
                                FRAMES_PER_BUFFER, callback, buffer);
    if (err != paNoError) {
        printf("Error opening stream: %s\n", Pa_GetErrorText(err));
        free_buffer(buffer);
        Pa_Terminate();
        return 1;
    }

    err = Pa_StartStream(stream);
    if (err != paNoError) {
        printf("Error starting stream: %s\n", Pa_GetErrorText(err));
        Pa_CloseStream(stream);
        free_buffer(buffer);
        Pa_Terminate();
        return 1;
    }

    getchar();

    err = Pa_StopStream(stream);
    if (err != paNoError) {
        printf("Error stopping stream: %s\n", Pa_GetErrorText(err));
    }

    err = Pa_CloseStream(stream);
    if (err != paNoError) {
        printf("Error closing stream: %s\n", Pa_GetErrorText(err));
    }

    free_buffer(buffer);
    Pa_Terminate();
    return 0;

}