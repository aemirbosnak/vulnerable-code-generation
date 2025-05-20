//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <portaudio.h>
#include <math.h>

#define SAMPLING_RATE (44100)
#define CHANNELS (2)
#define STREAM_FLAGS (paClipOff | paDitherOff)

typedef struct
{
    float accumulator;
    float* buffer;
    long bufferSize;
} ChorusEffect;

ChorusEffect* newChorusEffect(long bufferSize)
{
    ChorusEffect* chorus = (ChorusEffect*)malloc(sizeof(ChorusEffect));
    chorus->accumulator = 0.0f;
    chorus->buffer = (float*)calloc(bufferSize, sizeof(float));
    chorus->bufferSize = bufferSize;
    return chorus;
}

void deleteChorusEffect(ChorusEffect* chorus)
{
    free(chorus->buffer);
    free(chorus);
}

void chorus(float* input, float* output, long frameCount, ChorusEffect* chorus)
{
    for (long i = 0; i < frameCount; i++)
    {
        chorus->accumulator += 0.01f;
        float delay = 50.0f * sinf(chorus->accumulator);
        long delayIndex = (long)delay + chorus->bufferSize;
        delayIndex %= chorus->bufferSize;
        chorus->buffer[i] = input[i] + chorus->buffer[delayIndex];

        output[i] = chorus->buffer[i];
    }
}

static int audioCallback(const void* inputBuffer, void* outputBuffer, unsigned long framesPerBuffer,
                         const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void* userData)
{
    (void)timeInfo;
    (void)statusFlags;

    float* input = (float*)inputBuffer;
    float* output = (float*)outputBuffer;

    for (unsigned long i = 0; i < framesPerBuffer; i++)
    {
        for (int j = 0; j < CHANNELS; j++)
        {
            output[i * CHANNELS + j] = input[i * CHANNELS + j];
        }

        chorus(input + i * CHANNELS, output + i * CHANNELS, 1, (ChorusEffect*)userData);
    }

    return 0;
}

int main(int argc, char* argv[])
{
    PaError err;
    err = Pa_Initialize();
    if (err != paNoError) goto error;

    PaStreamParameters inputParameters, outputParameters;
    inputParameters.device = Pa_GetDefaultInputDevice();
    if (inputParameters.device == paNoDevice) goto error;
    inputParameters.channelCount = CHANNELS;
    inputParameters.sampleFormat = paFloat32;
    inputParameters.suggestedLatency = Pa_GetDeviceInfo(inputParameters.device)->defaultHighInputLatency;
    inputParameters.hostApiSpecificStreamInfo = NULL;

    outputParameters.device = Pa_GetDefaultOutputDevice();
    if (outputParameters.device == paNoDevice) goto error;
    outputParameters.channelCount = CHANNELS;
    outputParameters.sampleFormat = paFloat32;
    outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultHighOutputLatency;
    outputParameters.hostApiSpecificStreamInfo = NULL;

    PaStream* stream;
    err = Pa_OpenStream(&stream, &inputParameters, &outputParameters, SAMPLING_RATE, 512, STREAM_FLAGS, audioCallback, newChorusEffect(512));
    if (err != paNoError) goto error;

    err = Pa_StartStream(stream);
    if (err != paNoError) goto error;

    printf("Hit ENTER to stop playback.\n");
    getchar();

    err = Pa_StopStream(stream);
    if (err != paNoError) goto error;

    err = Pa_CloseStream(stream);
    if (err != paNoError) goto error;

    Pa_Terminate();
    return 0;

error:
    Pa_Terminate();
    fprintf(stderr, "An error occurred: %s\n", Pa_GetErrorText(err));
    return -1;
}