//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <portaudio.h>
#include <memory.h>

#define FRAMES_PER_BUFFER 1024
#define NUM_BUFFERS 50

typedef struct
{
    float left_gain;
    float right_gain;
    int sample_rate;
    short *sample_data;
    int sample_data_size;
} audio_buffer;

audio_buffer *create_audio_buffer(float left_gain, float right_gain, int sample_rate, short *sample_data, int sample_data_size)
{
    audio_buffer *buffer = malloc(sizeof(audio_buffer));
    buffer->left_gain = left_gain;
    buffer->right_gain = right_gain;
    buffer->sample_rate = sample_rate;
    buffer->sample_data = sample_data;
    buffer->sample_data_size = sample_data_size;
    return buffer;
}

void free_audio_buffer(audio_buffer *buffer)
{
    free(buffer->sample_data);
    free(buffer);
}

int main()
{
    audio_buffer *buffers[NUM_BUFFERS];
    int i;

    for (i = 0; i < NUM_BUFFERS; i++)
    {
        short *sample_data = malloc(FRAMES_PER_BUFFER * sizeof(short));
        memset(sample_data, 0, FRAMES_PER_BUFFER * sizeof(short));
        buffers[i] = create_audio_buffer(0.5, 0.5, 44100, sample_data, FRAMES_PER_BUFFER);
    }

    PaStream *stream;
    PaError err;

    err = Pa_Initialize();
    if (err != paNoError)
    {
        fprintf(stderr, "Error initializing PortAudio: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    PaStreamParameters output_parameters;
    output_parameters.device = Pa_GetDefaultOutputDevice();
    output_parameters.channelCount = 2;
    output_parameters.sampleFormat = paInt16;
    output_parameters.suggestedLatency = Pa_GetDeviceInfo(output_parameters.device)->defaultLowInputLatency;
    output_parameters.hostApiSpecificStreamInfo = NULL;

    err = Pa_OpenStream(&stream, NULL, &output_parameters, 44100, FRAMES_PER_BUFFER, paClipOff, NULL, NULL);
    if (err != paNoError)
    {
        fprintf(stderr, "Error opening output stream: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    err = Pa_StartStream(stream);
    if (err != paNoError)
    {
        fprintf(stderr, "Error starting stream: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    int buffer_index = 0;
    while (1)
    {
        err = Pa_WriteStream(stream, buffers[buffer_index]->sample_data, FRAMES_PER_BUFFER);
        if (err != paNoError)
        {
            fprintf(stderr, "Error writing to stream: %s\n", Pa_GetErrorText(err));
            return 1;
        }

        buffer_index = (buffer_index + 1) % NUM_BUFFERS;
    }

    err = Pa_StopStream(stream);
    if (err != paNoError)
    {
        fprintf(stderr, "Error stopping stream: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    err = Pa_CloseStream(stream);
    if (err != paNoError)
    {
        fprintf(stderr, "Error closing stream: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    Pa_Terminate();

    for (i = 0; i < NUM_BUFFERS; i++)
    {
        free_audio_buffer(buffers[i]);
    }

    return 0;
}