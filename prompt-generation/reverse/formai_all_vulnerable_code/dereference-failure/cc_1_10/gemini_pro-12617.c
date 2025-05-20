//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <portaudio.h>

#define NUM_CHANNELS 2
#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 1024

typedef struct {
    float *inputBuffer;
    float *outputBuffer;
} AudioData;

static int audioCallback(const void *inputBuffer, void *outputBuffer,
                         unsigned long framesPerBuffer,
                         const PaStreamCallbackTimeInfo* timeInfo,
                         PaStreamCallbackFlags statusFlags,
                         void *userData)
{
    AudioData *data = (AudioData *)userData;
    memcpy(data->inputBuffer, inputBuffer, framesPerBuffer * NUM_CHANNELS * sizeof(float));
    memset(data->outputBuffer, 0, framesPerBuffer * NUM_CHANNELS * sizeof(float));
    return paContinue;
}

int main()
{
    AudioData data;
    data.inputBuffer = (float *)malloc(FRAMES_PER_BUFFER * NUM_CHANNELS * sizeof(float));
    data.outputBuffer = (float *)malloc(FRAMES_PER_BUFFER * NUM_CHANNELS * sizeof(float));

    PaStream *stream;
    PaError paError;

    paError = Pa_Initialize();
    if (paError != paNoError) {
        fprintf(stderr, "Pa_Initialize() failed: %s\n", Pa_GetErrorText(paError));
        return 1;
    }

    paError = Pa_OpenDefaultStream(&stream, NUM_CHANNELS, NUM_CHANNELS, paFloat32, SAMPLE_RATE,
                                   FRAMES_PER_BUFFER, audioCallback, &data);
    if (paError != paNoError) {
        fprintf(stderr, "Pa_OpenDefaultStream() failed: %s\n", Pa_GetErrorText(paError));
        Pa_Terminate();
        return 1;
    }

    paError = Pa_StartStream(stream);
    if (paError != paNoError) {
        fprintf(stderr, "Pa_StartStream() failed: %s\n", Pa_GetErrorText(paError));
        Pa_CloseStream(stream);
        Pa_Terminate();
        return 1;
    }

    // Do something with the audio data here...

    paError = Pa_StopStream(stream);
    if (paError != paNoError) {
        fprintf(stderr, "Pa_StopStream() failed: %s\n", Pa_GetErrorText(paError));
        Pa_CloseStream(stream);
        Pa_Terminate();
        return 1;
    }

    paError = Pa_CloseStream(stream);
    if (paError != paNoError) {
        fprintf(stderr, "Pa_CloseStream() failed: %s\n", Pa_GetErrorText(paError));
        Pa_Terminate();
        return 1;
    }

    Pa_Terminate();
    free(data.inputBuffer);
    free(data.outputBuffer);
    return 0;
}