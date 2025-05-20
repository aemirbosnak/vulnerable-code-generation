//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: invasive
#include <stdlib.h>
#include <stdio.h>
#include <portaudio.h>

typedef struct {
    float *inputBuffer;
    float *outputBuffer;
    int numSamples;
    int numChannels;
} AudioData;

static int audioCallback(const void *inputBuffer, void *outputBuffer,
                         unsigned long framesPerBuffer,
                         const PaStreamCallbackTimeInfo* timeInfo,
                         PaStreamCallbackFlags statusFlags,
                         void *userData)
{
    AudioData *data = (AudioData*) userData;

    float *in = (float*) inputBuffer;
    float *out = (float*) outputBuffer;

    for (int i = 0; i < data->numSamples; i++) {
        for (int j = 0; j < data->numChannels; j++) {
            out[i * data->numChannels + j] = in[i * data->numChannels + j];
        }
    }

    return paContinue;
}

int main(int argc, char *argv[])
{
    PaStreamParameters inputParameters, outputParameters;
    PaStream *stream;
    AudioData data;

    data.numSamples = 1024;
    data.numChannels = 2;
    data.inputBuffer = (float*) malloc(sizeof(float) * data.numSamples * data.numChannels);
    data.outputBuffer = (float*) malloc(sizeof(float) * data.numSamples * data.numChannels);

    PaError err = Pa_Initialize();
    if (err != paNoError) goto error;

    inputParameters.device = Pa_GetDefaultInputDevice();
    if (inputParameters.device == paNoDevice) goto error;
    inputParameters.channelCount = data.numChannels;
    inputParameters.sampleFormat = paFloat32;
    inputParameters.suggestedLatency = Pa_GetDeviceInfo(inputParameters.device)->defaultLowInputLatency;
    inputParameters.hostApiSpecificStreamInfo = NULL;

    outputParameters.device = Pa_GetDefaultOutputDevice();
    if (outputParameters.device == paNoDevice) goto error;
    outputParameters.channelCount = data.numChannels;
    outputParameters.sampleFormat = paFloat32;
    outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultLowOutputLatency;
    outputParameters.hostApiSpecificStreamInfo = NULL;

    err = Pa_OpenStream(&stream, &inputParameters, &outputParameters, 44100, data.numSamples, paNoFlag, audioCallback, &data);
    if (err != paNoError) goto error;

    err = Pa_StartStream(stream);
    if (err != paNoError) goto error;

    printf("Press enter to stop the stream...\n");
    getchar();

    err = Pa_StopStream(stream);
    if (err != paNoError) goto error;

    err = Pa_CloseStream(stream);
    if (err != paNoError) goto error;

    Pa_Terminate();

    free(data.inputBuffer);
    free(data.outputBuffer);

    return 0;

error:
    Pa_Terminate();
    fprintf(stderr, "An error occurred: %s\n", Pa_GetErrorText(err));
    return -1;
}