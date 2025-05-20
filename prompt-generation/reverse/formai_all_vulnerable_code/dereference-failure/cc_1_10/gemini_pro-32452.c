//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <portaudio.h>

#define NUM_SECONDS   2
#define SAMPLE_RATE   44100
#define NUM_CHANNELS  2
#define CHANNEL_1     0
#define CHANNEL_2     1
#define FRAMES_PER_BUFFER  64

typedef struct {
    float *leftChannel;
    float *rightChannel;
    int numFrames;
} SoundData;

SoundData* soundData = NULL;
SoundData* processedSoundData = NULL;

void printAudioInfo() {
    printf("Sound data:\n");
    printf("  Num frames: %d\n", soundData->numFrames);
    printf("  Sample rate: %d\n", SAMPLE_RATE);
    printf("  Num channels: %d\n", NUM_CHANNELS);
    printf("  Duration: %f seconds\n", (float)soundData->numFrames / SAMPLE_RATE);
}

void processAudio(void) {
    processedSoundData = malloc(sizeof(SoundData));

    int numSamples = soundData->numFrames * NUM_CHANNELS;
    processedSoundData->numFrames = soundData->numFrames;
    processedSoundData->leftChannel = malloc(sizeof(float) * soundData->numFrames);
    processedSoundData->rightChannel = malloc(sizeof(float) * soundData->numFrames);

    for (int i = 0; i < numSamples; i++) {
        processedSoundData->leftChannel[i] = soundData->leftChannel[i] * 0.5;
        processedSoundData->rightChannel[i] = soundData->rightChannel[i] * 0.5;
    }
}

void freeMemory() {
    free(soundData->leftChannel);
    free(soundData->rightChannel);
    free(soundData);
    free(processedSoundData->leftChannel);
    free(processedSoundData->rightChannel);
    free(processedSoundData);
}

static int callback(const void* inputBuffer, void* outputBuffer,
        unsigned long framesPerBuffer,
        const PaStreamCallbackTimeInfo* timeInfo,
        PaStreamCallbackFlags statusFlags,
        void* userData) {
    SoundData* soundData = (SoundData*)userData;
    float* out = (float*)outputBuffer;

    for (int i = 0; i < framesPerBuffer * NUM_CHANNELS; i++) {
        *out++ = soundData->leftChannel[i];
        *out++ = soundData->rightChannel[i];
    }

    return paContinue;
}

int main(int argc, char* argv[]) {
    PaStream* stream;
    PaError err;

    err = Pa_Initialize();
    if (err != paNoError) {
        fprintf(stderr, "Error initializing PortAudio: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    // Open an audio file
    FILE* file = fopen("audio.wav", "rb");
    if (!file) {
        fprintf(stderr, "Error opening audio file\n");
        return 1;
    }

    // Read the WAV header
    char header[44];
    fread(header, sizeof(header), 1, file);

    // Check if the file is a WAV file
    if (strncmp(header, "RIFF", 4) != 0) {
        fprintf(stderr, "Error: File is not a WAV file\n");
        return 1;
    }

    // Read the WAV data
    int numBytes = *(int*)(header + 4) - 8;
    soundData = malloc(sizeof(SoundData));
    soundData->numFrames = numBytes / (NUM_CHANNELS * sizeof(float));
    soundData->leftChannel = malloc(sizeof(float) * soundData->numFrames);
    soundData->rightChannel = malloc(sizeof(float) * soundData->numFrames);
    fread(soundData->leftChannel, sizeof(float), soundData->numFrames, file);
    fread(soundData->rightChannel, sizeof(float), soundData->numFrames, file);

    fclose(file);

    // Print the audio info
    printAudioInfo();

    processAudio();

    err = Pa_OpenDefaultStream(&stream, 0, NUM_CHANNELS, paFloat32, SAMPLE_RATE, FRAMES_PER_BUFFER, callback, soundData);
    if (err != paNoError) {
        fprintf(stderr, "Error opening stream: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    err = Pa_StartStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "Error starting stream: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    while (Pa_IsStreamActive(stream)) {
        Pa_Sleep(1000);
    }

    err = Pa_StopStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "Error stopping stream: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    err = Pa_CloseStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "Error closing stream: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    Pa_Terminate();

    freeMemory();

    return 0;
}