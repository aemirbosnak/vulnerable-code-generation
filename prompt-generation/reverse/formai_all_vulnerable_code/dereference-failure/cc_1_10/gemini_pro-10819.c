//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <portaudio.h>

#define SAMPLE_RATE (44100)
#define FRAMES_PER_BUFFER (1024)

typedef struct {
    float* buffer;
    int bufferSize;
    int readIndex;
    int writeIndex;
} RingBuffer;

RingBuffer* createRingBuffer(int size) {
    RingBuffer* buffer = malloc(sizeof(RingBuffer));
    buffer->buffer = malloc(sizeof(float) * size);
    buffer->bufferSize = size;
    buffer->readIndex = 0;
    buffer->writeIndex = 0;
    return buffer;
}

void destroyRingBuffer(RingBuffer* buffer) {
    free(buffer->buffer);
    free(buffer);
}

void writeRingBuffer(RingBuffer* buffer, float sample) {
    buffer->buffer[buffer->writeIndex] = sample;
    buffer->writeIndex = (buffer->writeIndex + 1) % buffer->bufferSize;
    if (buffer->writeIndex == buffer->readIndex) {
        buffer->readIndex = (buffer->readIndex + 1) % buffer->bufferSize;
    }
}

float readRingBuffer(RingBuffer* buffer) {
    float sample = buffer->buffer[buffer->readIndex];
    buffer->readIndex = (buffer->readIndex + 1) % buffer->bufferSize;
    return sample;
}

int callback(
    const void* inputBuffer, void* outputBuffer,
    unsigned long framesPerBuffer,
    const PaStreamCallbackTimeInfo* timeInfo,
    PaStreamCallbackFlags statusFlags,
    void* userData) {
    RingBuffer* buffer = (RingBuffer*) userData;
    float* in = (float*) inputBuffer;
    float* out = (float*) outputBuffer;
    for (unsigned int i = 0; i < framesPerBuffer; i++) {
        float sample = readRingBuffer(buffer);
        *out++ = sample;
        *in++;
        sample += 0.0001 * rand() / (RAND_MAX + 1.0);
        writeRingBuffer(buffer, sample);
    }
    return 0;
}

int main() {
    PaStream* stream;
    RingBuffer* buffer = createRingBuffer(FRAMES_PER_BUFFER);
    PaError err = Pa_Initialize();
    if (err != paNoError) {
        fprintf(stderr, "Error: %s\n", Pa_GetErrorText(err));
        return 1;
    }
    err = Pa_OpenDefaultStream(
        &stream, 1, 1, paFloat32, SAMPLE_RATE,
        FRAMES_PER_BUFFER, callback, buffer);
    if (err != paNoError) {
        fprintf(stderr, "Error: %s\n", Pa_GetErrorText(err));
        return 1;
    }
    for (int i = 0; i < FRAMES_PER_BUFFER; i++) {
        writeRingBuffer(buffer, 0.0);
    }
    err = Pa_StartStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "Error: %s\n", Pa_GetErrorText(err));
        return 1;
    }
    printf("Press Enter to quit.\n");
    getchar();
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
    destroyRingBuffer(buffer);
    return 0;
}