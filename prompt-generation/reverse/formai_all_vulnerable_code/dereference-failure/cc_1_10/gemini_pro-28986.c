//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <portaudio.h>

#define SAMPLE_RATE 44100
#define NUM_CHANNELS 2
#define FRAMES_PER_BUFFER 1024

typedef struct {
    float* samples;
    int num_samples;
} audio_buffer;

audio_buffer* create_audio_buffer(int num_samples) {
    audio_buffer* buffer = malloc(sizeof(audio_buffer));
    buffer->samples = malloc(num_samples * sizeof(float));
    buffer->num_samples = num_samples;
    return buffer;
}

void destroy_audio_buffer(audio_buffer* buffer) {
    free(buffer->samples);
    free(buffer);
}

void fill_audio_buffer(audio_buffer* buffer, float* data, int num_samples) {
    memcpy(buffer->samples, data, num_samples * sizeof(float));
}

void play_audio_buffer(audio_buffer* buffer) {
    PaStream* stream;
    PaError err;
    err = Pa_Initialize();
    if (err != paNoError) {
        fprintf(stderr, "Error initializing PortAudio: %s\n", Pa_GetErrorText(err));
        return;
    }
    PaStreamParameters output_parameters;
    output_parameters.device = Pa_GetDefaultOutputDevice();
    if (output_parameters.device == paNoDevice) {
        fprintf(stderr, "Error getting default output device: %s\n", Pa_GetErrorText(err));
        Pa_Terminate();
        return;
    }
    output_parameters.channelCount = NUM_CHANNELS;
    output_parameters.sampleFormat = paFloat32;
    output_parameters.suggestedLatency = Pa_GetDeviceInfo(output_parameters.device)->defaultLowOutputLatency;
    output_parameters.hostApiSpecificStreamInfo = NULL;
    err = Pa_OpenStream(&stream, NULL, &output_parameters, SAMPLE_RATE, FRAMES_PER_BUFFER, paClipOff, NULL, NULL);
    if (err != paNoError) {
        fprintf(stderr, "Error opening stream: %s\n", Pa_GetErrorText(err));
        Pa_Terminate();
        return;
    }
    err = Pa_StartStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "Error starting stream: %s\n", Pa_GetErrorText(err));
        Pa_CloseStream(stream);
        Pa_Terminate();
        return;
    }
    int num_frames = buffer->num_samples / NUM_CHANNELS;
    for (int i = 0; i < num_frames; i++) {
        err = Pa_WriteStream(stream, buffer->samples + (i * NUM_CHANNELS), FRAMES_PER_BUFFER);
        if (err != paNoError) {
            fprintf(stderr, "Error writing to stream: %s\n", Pa_GetErrorText(err));
            Pa_StopStream(stream);
            Pa_CloseStream(stream);
            Pa_Terminate();
            return;
        }
    }
    err = Pa_StopStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "Error stopping stream: %s\n", Pa_GetErrorText(err));
        Pa_CloseStream(stream);
        Pa_Terminate();
        return;
    }
    err = Pa_CloseStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "Error closing stream: %s\n", Pa_GetErrorText(err));
        Pa_Terminate();
        return;
    }
    Pa_Terminate();
}

int main() {
    float data[] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    audio_buffer* buffer = create_audio_buffer(sizeof(data) / sizeof(float));
    fill_audio_buffer(buffer, data, sizeof(data) / sizeof(float));
    play_audio_buffer(buffer);
    destroy_audio_buffer(buffer);
    return 0;
}