//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: portable
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
} AudioBuffer;

AudioBuffer *audio_buffer_new(int size) {
    AudioBuffer *buffer = malloc(sizeof(AudioBuffer));
    buffer->buffer = malloc(sizeof(float) * size);
    buffer->buffer_size = size;
    buffer->buffer_index = 0;
    return buffer;
}

void audio_buffer_free(AudioBuffer *buffer) {
    free(buffer->buffer);
    free(buffer);
}

void audio_buffer_write(AudioBuffer *buffer, float *data, int size) {
    if (buffer->buffer_index + size > buffer->buffer_size) {
        fprintf(stderr, "Error: Buffer overflow\n");
        return;
    }
    memcpy(buffer->buffer + buffer->buffer_index, data, sizeof(float) * size);
    buffer->buffer_index += size;
}

float audio_buffer_read(AudioBuffer *buffer) {
    if (buffer->buffer_index >= buffer->buffer_size) {
        fprintf(stderr, "Error: Buffer underrun\n");
        return 0.0f;
    }
    return buffer->buffer[buffer->buffer_index++];
}

void audio_callback(void *outputBuffer, void *inputBuffer, unsigned long framesPerBuffer,
        const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void *userData) {
    AudioBuffer *buffer = (AudioBuffer *)userData;
    float *out = (float *)outputBuffer;

    for (int i = 0; i < framesPerBuffer; i++) {
        out[i * NUM_CHANNELS] = audio_buffer_read(buffer);
        out[i * NUM_CHANNELS + 1] = audio_buffer_read(buffer);
    }
}

int main() {
    PaStream *stream;
    PaError err;

    err = Pa_Initialize();
    if (err != paNoError) {
        fprintf(stderr, "Error: %s\n", Pa_GetErrorText(err));
        return EXIT_FAILURE;
    }

    AudioBuffer *buffer = audio_buffer_new(FRAMES_PER_BUFFER * NUM_CHANNELS);

    PaStreamParameters outputParameters;
    outputParameters.device = Pa_GetDefaultOutputDevice();
    outputParameters.channelCount = NUM_CHANNELS;
    outputParameters.sampleFormat = paFloat32;
    outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultLowOutputLatency;
    outputParameters.hostApiSpecificStreamInfo = NULL;

    err = Pa_OpenStream(&stream, NULL, &outputParameters, SAMPLE_RATE, FRAMES_PER_BUFFER, paClipOff, audio_callback, buffer);
    if (err != paNoError) {
        fprintf(stderr, "Error: %s\n", Pa_GetErrorText(err));
        audio_buffer_free(buffer);
        Pa_Terminate();
        return EXIT_FAILURE;
    }

    err = Pa_StartStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "Error: %s\n", Pa_GetErrorText(err));
        Pa_StopStream(stream);
        Pa_CloseStream(stream);
        audio_buffer_free(buffer);
        Pa_Terminate();
        return EXIT_FAILURE;
    }

    // Generate a sine wave
    float freq = 440.0f;
    float amplitude = 0.5f;
    for (int i = 0; i < 100000; i++) {
        float value = amplitude * sin(2.0f * M_PI * freq * (float)i / SAMPLE_RATE);
        audio_buffer_write(buffer, &value, 1);
    }

    while (Pa_IsStreamActive(stream)) {
        Pa_Sleep(100);
    }

    err = Pa_StopStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "Error: %s\n", Pa_GetErrorText(err));
        Pa_CloseStream(stream);
        audio_buffer_free(buffer);
        Pa_Terminate();
        return EXIT_FAILURE;
    }

    err = Pa_CloseStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "Error: %s\n", Pa_GetErrorText(err));
        audio_buffer_free(buffer);
        Pa_Terminate();
        return EXIT_FAILURE;
    }

    audio_buffer_free(buffer);

    Pa_Terminate();

    return EXIT_SUCCESS;
}