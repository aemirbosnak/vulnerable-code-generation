//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: safe
#include <stdlib.h>
#include <stdio.h>
#include <portaudio.h>

#define NUM_CHANNELS 2
#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 1024

typedef struct {
    float *buffer;
    int bufferSize;
    int writeIndex;
} RingBuffer;

RingBuffer *createRingBuffer(int size) {
    RingBuffer *buffer = malloc(sizeof(RingBuffer));
    buffer->buffer = malloc(size * sizeof(float));
    buffer->bufferSize = size;
    buffer->writeIndex = 0;
    return buffer;
}

void destroyRingBuffer(RingBuffer *buffer) {
    free(buffer->buffer);
    free(buffer);
}

void writeRingBuffer(RingBuffer *buffer, float sample) {
    buffer->buffer[buffer->writeIndex++] = sample;
    buffer->writeIndex %= buffer->bufferSize;
}

float readRingBuffer(RingBuffer *buffer) {
    float sample = buffer->buffer[buffer->writeIndex];
    buffer->writeIndex--;
    buffer->writeIndex %= buffer->bufferSize;
    return sample;
}

int main() {
    // Initialize PortAudio
    PaError err = Pa_Initialize();
    if (err != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    // Open the default input and output devices
    PaStream *stream;
    err = Pa_OpenDefaultStream(&stream, NUM_CHANNELS, NUM_CHANNELS, paFloat32, SAMPLE_RATE, FRAMES_PER_BUFFER, NULL, NULL);
    if (err != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
        Pa_Terminate();
        return 1;
    }

    // Create a ring buffer to store the audio data
    RingBuffer *buffer = createRingBuffer(FRAMES_PER_BUFFER);

    // Start the stream
    err = Pa_StartStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
        Pa_CloseStream(stream);
        Pa_Terminate();
        return 1;
    }

    // Main processing loop
    while (1) {
        // Read audio data from the input device
        float input[FRAMES_PER_BUFFER * NUM_CHANNELS];
        err = Pa_ReadStream(stream, input, FRAMES_PER_BUFFER);
        if (err != paNoError) {
            fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
            Pa_CloseStream(stream);
            Pa_Terminate();
            return 1;
        }

        // Process the audio data
        for (int i = 0; i < FRAMES_PER_BUFFER * NUM_CHANNELS; i++) {
            writeRingBuffer(buffer, input[i]);
        }

        // Write the processed audio data to the output device
        float output[FRAMES_PER_BUFFER * NUM_CHANNELS];
        for (int i = 0; i < FRAMES_PER_BUFFER * NUM_CHANNELS; i++) {
            output[i] = readRingBuffer(buffer);
        }
        err = Pa_WriteStream(stream, output, FRAMES_PER_BUFFER);
        if (err != paNoError) {
            fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
            Pa_CloseStream(stream);
            Pa_Terminate();
            return 1;
        }
    }

    // Stop the stream
    err = Pa_StopStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
        Pa_CloseStream(stream);
        Pa_Terminate();
        return 1;
    }

    // Close the stream
    err = Pa_CloseStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
        Pa_Terminate();
        return 1;
    }

    // Terminate PortAudio
    Pa_Terminate();

    // Destroy the ring buffer
    destroyRingBuffer(buffer);

    return 0;
}