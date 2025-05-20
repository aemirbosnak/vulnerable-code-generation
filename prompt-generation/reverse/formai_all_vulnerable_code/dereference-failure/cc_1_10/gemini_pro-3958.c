//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <portaudio.h>

#define SAMPLE_RATE  (44100)
#define FRAMES_PER_BUFFER  (64)

typedef struct {
    float *samples;
    int num_samples;
} SoundBuffer;

SoundBuffer *create_sound_buffer(int num_samples) {
    SoundBuffer *buffer = malloc(sizeof(SoundBuffer));
    buffer->samples = malloc(sizeof(float) * num_samples);
    buffer->num_samples = num_samples;
    return buffer;
}

void destroy_sound_buffer(SoundBuffer *buffer) {
    free(buffer->samples);
    free(buffer);
}

SoundBuffer *load_sound_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    SoundBuffer *buffer = create_sound_buffer(file_size / sizeof(float));
    fread(buffer->samples, sizeof(float), buffer->num_samples, file);
    fclose(file);

    return buffer;
}

void write_sound_file(const char *filename, SoundBuffer *buffer) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    fwrite(buffer->samples, sizeof(float), buffer->num_samples, file);
    fclose(file);
}

void play_sound_buffer(SoundBuffer *buffer) {
    PaStream *stream;
    PaError err;

    err = Pa_Initialize();
    if (err != paNoError) {
        fprintf(stderr, "Error: could not initialize PortAudio: %s\n", Pa_GetErrorText(err));
        return;
    }

    err = Pa_OpenDefaultStream(&stream, 0, 1, paFloat32, SAMPLE_RATE, FRAMES_PER_BUFFER, NULL, NULL);
    if (err != paNoError) {
        fprintf(stderr, "Error: could not open default stream: %s\n", Pa_GetErrorText(err));
        Pa_Terminate();
        return;
    }

    err = Pa_StartStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "Error: could not start stream: %s\n", Pa_GetErrorText(err));
        Pa_CloseStream(stream);
        Pa_Terminate();
        return;
    }

    int num_frames = buffer->num_samples / FRAMES_PER_BUFFER;
    for (int i = 0; i < num_frames; i++) {
        err = Pa_WriteStream(stream, &buffer->samples[i * FRAMES_PER_BUFFER], FRAMES_PER_BUFFER);
        if (err != paNoError) {
            fprintf(stderr, "Error: could not write to stream: %s\n", Pa_GetErrorText(err));
            break;
        }
    }

    err = Pa_StopStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "Error: could not stop stream: %s\n", Pa_GetErrorText(err));
    }

    err = Pa_CloseStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "Error: could not close stream: %s\n", Pa_GetErrorText(err));
    }

    Pa_Terminate();
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input.wav>\n", argv[0]);
        return 1;
    }

    SoundBuffer *buffer = load_sound_file(argv[1]);
    if (buffer == NULL) {
        return 1;
    }

    play_sound_buffer(buffer);

    destroy_sound_buffer(buffer);

    return 0;
}