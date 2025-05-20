//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <portaudio.h>

#define SAMPLE_RATE  (44100)
#define FRAMES_PER_BUFFER  (512)

typedef struct {
    float* buffer;
    int buffer_size;
} SineWaveGenerator;

SineWaveGenerator* sine_wave_generator_new(float frequency, float amplitude) {
    SineWaveGenerator* generator = malloc(sizeof(SineWaveGenerator));
    generator->buffer_size = FRAMES_PER_BUFFER;
    generator->buffer = malloc(generator->buffer_size * sizeof(float));
    for (int i = 0; i < generator->buffer_size; i++) {
        generator->buffer[i] = amplitude * sinf(2 * M_PI * frequency * i / SAMPLE_RATE);
    }
    return generator;
}

void sine_wave_generator_delete(SineWaveGenerator* generator) {
    free(generator->buffer);
    free(generator);
}

int callback(const void* inputBuffer, void* outputBuffer,
                unsigned long framesPerBuffer,
                const PaStreamCallbackTimeInfo* timeInfo,
                PaStreamCallbackFlags statusFlags,
                void* userData) {
    SineWaveGenerator* generator = (SineWaveGenerator*) userData;
    float* output = (float*) outputBuffer;
    for (int i = 0; i < framesPerBuffer; i++) {
        *output++ = generator->buffer[i % generator->buffer_size];
    }
    return paContinue;
}

int main(int argc, char* argv[]) {
    PaStreamParameters outputParameters;
    PaStream* stream;
    SineWaveGenerator* generator;

    // Initialize PortAudio
    PaError error = Pa_Initialize();
    if (error != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(error));
        return 1;
    }

    // Open an output stream
    outputParameters.device = Pa_GetDefaultOutputDevice();
    outputParameters.channelCount = 1;
    outputParameters.sampleFormat = paFloat32;
    outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultLowOutputLatency;
    outputParameters.hostApiSpecificStreamInfo = NULL;

    error = Pa_OpenStream(&stream, NULL, &outputParameters, SAMPLE_RATE, FRAMES_PER_BUFFER, paClipOff, callback, generator);
    if (error != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(error));
        Pa_Terminate();
        return 1;
    }

    // Create a sine wave generator
    generator = sine_wave_generator_new(440.0f, 0.5f);

    // Start the stream
    error = Pa_StartStream(stream);
    if (error != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(error));
        sine_wave_generator_delete(generator);
        Pa_CloseStream(stream);
        Pa_Terminate();
        return 1;
    }

    // Wait for a key press to stop the stream
    printf("Press any key to stop the sine wave.\n");
    getchar();

    // Stop the stream
    error = Pa_StopStream(stream);
    if (error != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(error));
        sine_wave_generator_delete(generator);
        Pa_CloseStream(stream);
        Pa_Terminate();
        return 1;
    }

    // Clean up
    sine_wave_generator_delete(generator);
    Pa_CloseStream(stream);
    Pa_Terminate();

    return 0;
}