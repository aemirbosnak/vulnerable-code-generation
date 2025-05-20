//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <portaudio.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 1024
#define NUM_CHANNELS 1

// Callback function that will be called by PortAudio to generate audio samples
static int fillBuffer(const void *inputBuffer, void *outputBuffer,
                      unsigned long framesPerBuffer,
                      const PaStreamCallbackTimeInfo *timeInfo,
                      PaStreamCallbackFlags statusFlags,
                      void *userData) {
    // Get the pointer to the output buffer
    float *out = (float *)outputBuffer;

    // Loop through the frames and generate a sine wave
    for (int i = 0; i < framesPerBuffer; i++) {
        // Generate a sine wave with a frequency of 440 Hz
        *out++ = sin(2 * M_PI * 440 * i / SAMPLE_RATE);
    }

    // Return success
    return paContinue;
}

// Main function
int main() {
    // Initialize PortAudio
    PaError err = Pa_Initialize();
    if (err != paNoError) {
        fprintf(stderr, "Error initializing PortAudio: %s\n", Pa_GetErrorText(err));
        return EXIT_FAILURE;
    }

    // Open a stream to play the audio
    PaStreamParameters outputParameters;
    outputParameters.device = Pa_GetDefaultOutputDevice();
    if (outputParameters.device == paNoDevice) {
        fprintf(stderr, "Error getting default output device\n");
        Pa_Terminate();
        return EXIT_FAILURE;
    }
    outputParameters.channelCount = NUM_CHANNELS;
    outputParameters.sampleFormat = paFloat32;
    outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultLowOutputLatency;
    outputParameters.hostApiSpecificStreamInfo = NULL;

    PaStream *stream;
    err = Pa_OpenStream(&stream,
                        NULL,
                        &outputParameters,
                        SAMPLE_RATE,
                        FRAMES_PER_BUFFER,
                        paClipOff,
                        fillBuffer,
                        NULL);
    if (err != paNoError) {
        fprintf(stderr, "Error opening stream: %s\n", Pa_GetErrorText(err));
        Pa_Terminate();
        return EXIT_FAILURE;
    }

    // Start the stream
    err = Pa_StartStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "Error starting stream: %s\n", Pa_GetErrorText(err));
        Pa_Terminate();
        return EXIT_FAILURE;
    }

    // Keep the program running until the user presses a key
    printf("Press any key to stop the sound.\n");
    getchar();

    // Stop the stream
    err = Pa_StopStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "Error stopping stream: %s\n", Pa_GetErrorText(err));
        Pa_Terminate();
        return EXIT_FAILURE;
    }

    // Close the stream
    err = Pa_CloseStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "Error closing stream: %s\n", Pa_GetErrorText(err));
        Pa_Terminate();
        return EXIT_FAILURE;
    }

    // Terminate PortAudio
    Pa_Terminate();

    return EXIT_SUCCESS;
}