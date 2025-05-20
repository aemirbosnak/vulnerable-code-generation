//Falcon2-11B DATASET v1.0 Category: Audio processing ; Style: decentralized
#include <stdio.h>
#include <portaudio.h>

#define SAMPLE_RATE 44100
#define SAMPLE_WIDTH 2

typedef struct {
    int nChannels;
    int nSamples;
    float* pData;
} PortAudioStream;

int main() {
    PortAudioStream stream;
    PaStream* streamHandle;
    PaError err;

    stream.pData = (float*)malloc(stream.nSamples * stream.nChannels * sizeof(float));
    stream.nSamples = (int)(SAMPLE_RATE * 0.1); // record for 0.1 seconds
    stream.nChannels = 1; // mono
    err = Pa_Initialize(); // initialize PortAudio
    if (err!= paNoError) {
        printf("PortAudio initialization failed: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    err = Pa_OpenDefaultStream(&streamHandle, 0, &stream, SAMPLE_RATE, 0, 0, paClipOff, 0); // open audio stream
    if (err!= paNoError) {
        printf("PortAudio stream open failed: %s\n", Pa_GetErrorText(err));
        Pa_Terminate();
        return 1;
    }

    printf("Recording...\n");
    fflush(stdout);
    Pa_StartStream(streamHandle);
    Pa_Sleep(stream.nSamples * SAMPLE_RATE); // sleep for 0.1 seconds
    Pa_StopStream(streamHandle);
    Pa_CloseStream(streamHandle);
    Pa_Terminate();

    printf("Playing back...\n");
    fflush(stdout);
    err = Pa_OpenDefaultStream(&streamHandle, 0, &stream, SAMPLE_RATE, 0, 0, paClipOff, 0); // open audio stream
    if (err!= paNoError) {
        printf("PortAudio stream open failed: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    Pa_StartStream(streamHandle);
    Pa_Sleep(stream.nSamples * SAMPLE_RATE); // sleep for 0.1 seconds
    Pa_StopStream(streamHandle);
    Pa_CloseStream(streamHandle);
    Pa_Terminate();

    free(stream.pData);

    printf("Done!\n");
    return 0;
}