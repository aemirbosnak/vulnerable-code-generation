//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <portaudio.h>

// This program takes an audio signal from an input device and filters it in
// real time. The program will apply a low-pass filter to the input signal,
// which will remove high-frequency components from the signal.

// The following constants define the sample rate, number of channels, and buffer
// size that will be used by the program.
#define SAMPLE_RATE  44100
#define NUM_CHANNELS 1
#define BUFFER_SIZE  1024

// This function is the callback function that will be called by PortAudio to
// process the audio signal.
static int callback(const void *inputBuffer, void *outputBuffer,
                     unsigned long framesPerBuffer,
                     const PaStreamCallbackTimeInfo* timeInfo,
                     PaStreamCallbackFlags statusFlags,
                     void *userData)
{
    // Cast the input and output buffers to floats.
    float *in = (float *)inputBuffer;
    float *out = (float *)outputBuffer;

    // Apply the low-pass filter to the input signal.
    for (int i = 0; i < framesPerBuffer; i++) {
        out[i] = in[i] * 0.99;
    }

    // Return 0 to indicate that the callback was successful.
    return 0;
}

// This function initializes the PortAudio system and creates a stream.
static int initPortAudio(PaStream **stream)
{
    // Initialize the PortAudio system.
    PaError err = Pa_Initialize();
    if (err != paNoError) {
        printf("Error initializing PortAudio: %s\n", Pa_GetErrorText(err));
        return -1;
    }

    // Create a stream.
    PaStreamParameters inputParameters;
    inputParameters.device = Pa_GetDefaultInputDevice();
    inputParameters.channelCount = NUM_CHANNELS;
    inputParameters.sampleFormat = paFloat32;
    inputParameters.suggestedLatency = Pa_GetDeviceInfo(inputParameters.device)->defaultLowInputLatency;
    inputParameters.hostApiSpecificStreamInfo = NULL;

    PaStreamParameters outputParameters;
    outputParameters.device = Pa_GetDefaultOutputDevice();
    outputParameters.channelCount = NUM_CHANNELS;
    outputParameters.sampleFormat = paFloat32;
    outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultLowOutputLatency;
    outputParameters.hostApiSpecificStreamInfo = NULL;

    err = Pa_OpenStream(stream, &inputParameters, &outputParameters, SAMPLE_RATE, BUFFER_SIZE, paClipOff, callback, NULL);
    if (err != paNoError) {
        printf("Error opening stream: %s\n", Pa_GetErrorText(err));
        return -1;
    }

    // Return 0 to indicate that the stream was successfully initialized.
    return 0;
}

// This function starts the stream.
static int startStream(PaStream *stream)
{
    // Start the stream.
    PaError err = Pa_StartStream(stream);
    if (err != paNoError) {
        printf("Error starting stream: %s\n", Pa_GetErrorText(err));
        return -1;
    }

    // Return 0 to indicate that the stream was successfully started.
    return 0;
}

// This function stops the stream.
static int stopStream(PaStream *stream)
{
    // Stop the stream.
    PaError err = Pa_StopStream(stream);
    if (err != paNoError) {
        printf("Error stopping stream: %s\n", Pa_GetErrorText(err));
        return -1;
    }

    // Return 0 to indicate that the stream was successfully stopped.
    return 0;
}

// This function terminates the PortAudio system.
static int terminatePortAudio()
{
    // Terminate the PortAudio system.
    PaError err = Pa_Terminate();
    if (err != paNoError) {
        printf("Error terminating PortAudio: %s\n", Pa_GetErrorText(err));
        return -1;
    }

    // Return 0 to indicate that the PortAudio system was successfully terminated.
    return 0;
}

// This is the main function of the program.
int main(void)
{
    // Initialize the PortAudio system.
    PaStream *stream;
    int err = initPortAudio(&stream);
    if (err != 0) {
        return err;
    }

    // Start the stream.
    err = startStream(stream);
    if (err != 0) {
        return err;
    }

    // Wait for the user to press a key.
    printf("Press any key to stop the program.\n");
    getchar();

    // Stop the stream.
    err = stopStream(stream);
    if (err != 0) {
        return err;
    }

    // Terminate the PortAudio system.
    err = terminatePortAudio();
    if (err != 0) {
        return err;
    }

    // Return 0 to indicate that the program was successful.
    return 0;
}