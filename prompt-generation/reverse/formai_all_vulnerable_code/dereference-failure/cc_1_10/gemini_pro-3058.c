//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <portaudio.h>

#define NUM_CHANNELS 2
#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 1024

typedef struct {
    float *buffer;
    int bufferSize;
    int bufferIndex;
} AudioBuffer;

AudioBuffer *createAudioBuffer(int size) {
    AudioBuffer *buffer = malloc(sizeof(AudioBuffer));
    buffer->buffer = malloc(sizeof(float) * size);
    buffer->bufferSize = size;
    buffer->bufferIndex = 0;
    return buffer;
}

void destroyAudioBuffer(AudioBuffer *buffer) {
    free(buffer->buffer);
    free(buffer);
}

void writeAudioBufferToFile(AudioBuffer *buffer, const char *filename) {
    FILE *file = fopen(filename, "wb");
    fwrite(buffer->buffer, sizeof(float), buffer->bufferSize, file);
    fclose(file);
}

void readAudioBufferFromFile(AudioBuffer *buffer, const char *filename) {
    FILE *file = fopen(filename, "rb");
    fread(buffer->buffer, sizeof(float), buffer->bufferSize, file);
    fclose(file);
}

PaStream *openAudioStream(AudioBuffer *buffer) {
    PaStream *stream;
    PaError err;

    err = Pa_Initialize();
    if (err != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
        return NULL;
    }

    err = Pa_OpenDefaultStream(&stream, NUM_CHANNELS, NUM_CHANNELS, paFloat32, SAMPLE_RATE, FRAMES_PER_BUFFER, NULL, NULL);
    if (err != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
        return NULL;
    }

    return stream;
}

void closeAudioStream(PaStream *stream) {
    Pa_CloseStream(stream);
    Pa_Terminate();
}

int main() {
    AudioBuffer *buffer = createAudioBuffer(FRAMES_PER_BUFFER * NUM_CHANNELS);
    PaStream *stream = openAudioStream(buffer);

    if (stream == NULL) {
        fprintf(stderr, "Error opening audio stream.\n");
        return 1;
    }

    while (1) {
        // Read audio data from the input stream into the buffer
        PaError err = Pa_ReadStream(stream, buffer->buffer, FRAMES_PER_BUFFER);
        if (err != paNoError) {
            fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
            break;
        }

        // Process the audio data in the buffer
        for (int i = 0; i < FRAMES_PER_BUFFER * NUM_CHANNELS; i++) {
            buffer->buffer[i] += 0.1 * sin(2 * M_PI * 440 * i / SAMPLE_RATE);
        }

        // Write the processed audio data from the buffer to the output stream
        err = Pa_WriteStream(stream, buffer->buffer, FRAMES_PER_BUFFER);
        if (err != paNoError) {
            fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
            break;
        }
    }

    closeAudioStream(stream);
    destroyAudioBuffer(buffer);

    return 0;
}