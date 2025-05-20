//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <portaudio.h>

typedef struct {
    float *inBuffer;
    float *outBuffer;
    int numFrames;
    int numChannels;
    int fs;
    int gain;
} paData;

static int paCallback(const void *inputBuffer, void *outputBuffer,
                      unsigned long framesPerBuffer,
                      const PaStreamCallbackTimeInfo* timeInfo,
                      PaStreamCallbackFlags statusFlags,
                      void *userData) {
    paData *data = (paData*)userData;
    const float *in = (const float*)inputBuffer;
    float *out = (float*)outputBuffer;
    int i, c, s;
    for (s = 0; s < framesPerBuffer; ++s) {
        for (c = 0; c < data->numChannels; ++c) {
            float outSample = in[s * data->numChannels + c];
            *out++ = outSample * data->gain;
        }
    }
    return paContinue;
}

int main(int argc, char* argv[]) {
    PaStream *stream;
    PaError err;
    paData data;

    err = Pa_Initialize();
    if (err != paNoError) {
        fprintf(stderr, "Error: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    data.numChannels = 2;
    data.fs = 44100;
    data.numFrames = 1024;
    data.gain = 1.0;

    data.inBuffer = malloc(sizeof(float) * data.numChannels * data.numFrames);
    data.outBuffer = malloc(sizeof(float) * data.numChannels * data.numFrames);

    err = Pa_OpenStream(&stream,
                        paNoDevice,
                        data.numChannels,
                        paFloat32,
                        data.fs,
                        data.numFrames,
                        paCallback,
                        &data);
    if (err != paNoError) {
        fprintf(stderr, "Error: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    err = Pa_StartStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "Error: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    while (1) {
        // Process audio here
    }

    err = Pa_StopStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "Error: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    err = Pa_CloseStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "Error: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    Pa_Terminate();
    return 0;
}