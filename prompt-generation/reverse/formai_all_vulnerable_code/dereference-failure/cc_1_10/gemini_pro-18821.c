//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SAMPLES 1024
#define MAX_CHANNELS 2

typedef struct {
    int num_samples;
    int num_channels;
    double *samples;
} AudioBuffer;

AudioBuffer *read_audio_buffer(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    }

    AudioBuffer *buffer = malloc(sizeof(AudioBuffer));
    if (!buffer) {
        fclose(file);
        return NULL;
    }

    fread(&buffer->num_samples, sizeof(int), 1, file);
    fread(&buffer->num_channels, sizeof(int), 1, file);
    buffer->samples = malloc(buffer->num_samples * buffer->num_channels * sizeof(double));
    if (!buffer->samples) {
        fclose(file);
        free(buffer);
        return NULL;
    }

    fread(buffer->samples, sizeof(double), buffer->num_samples * buffer->num_channels, file);
    fclose(file);

    return buffer;
}

void write_audio_buffer(const AudioBuffer *buffer, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        return;
    }

    fwrite(&buffer->num_samples, sizeof(int), 1, file);
    fwrite(&buffer->num_channels, sizeof(int), 1, file);
    fwrite(buffer->samples, sizeof(double), buffer->num_samples * buffer->num_channels, file);
    fclose(file);
}

void free_audio_buffer(AudioBuffer *buffer) {
    free(buffer->samples);
    free(buffer);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    AudioBuffer *buffer = read_audio_buffer(argv[1]);
    if (!buffer) {
        printf("Error reading input file\n");
        return 1;
    }

    for (int i = 0; i < buffer->num_samples; i++) {
        for (int j = 0; j < buffer->num_channels; j++) {
            double volume = sqrt(buffer->samples[i * buffer->num_channels + j] * buffer->samples[i * buffer->num_channels + j]);
            volume = volume > 1.0 ? 1.0 : volume;
            buffer->samples[i * buffer->num_channels + j] = volume;
        }
    }

    write_audio_buffer(buffer, argv[2]);
    free_audio_buffer(buffer);

    return 0;
}