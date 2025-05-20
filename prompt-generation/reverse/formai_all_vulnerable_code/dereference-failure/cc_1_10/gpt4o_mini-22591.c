//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define HEADER_SIZE 44
#define SAMPLE_RATE 44100
#define ECHO_DELAY_MS 500
#define ECHO_DECAY 0.5

void apply_echo(int16_t *samples, size_t num_samples, double decay, int delay) {
    int delay_samples = (int)(SAMPLE_RATE * (delay / 1000.0));
    for (size_t i = delay_samples; i < num_samples; i++) {
        samples[i] += (int16_t)(samples[i - delay_samples] * decay);
    }
}

int read_wav(const char *filename, int16_t **samples) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Unable to open input file.\n");
        return -1;
    }

    unsigned char header[HEADER_SIZE];
    fread(header, sizeof(unsigned char), HEADER_SIZE, file);

    size_t data_size;
    memcpy(&data_size, header + 40, sizeof(size_t));

    *samples = (int16_t *)malloc(data_size);
    fread(*samples, sizeof(int16_t), data_size / sizeof(int16_t), file);

    fclose(file);
    return data_size / sizeof(int16_t);
}

void write_wav(const char *filename, int16_t *samples, size_t num_samples) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Unable to open output file.\n");
        return;
    }

    unsigned char header[HEADER_SIZE] = {
        'R', 'I', 'F', 'F',
        0, 0, 0, 0,
        'W', 'A', 'V', 'E',
        'f', 'm', 't', ' ',
        16, 0, 0, 0,
        1, 0, 1, 0,
        SAMPLE_RATE & 0xff, (SAMPLE_RATE >> 8) & 0xff, (SAMPLE_RATE >> 16) & 0xff, (SAMPLE_RATE >> 24) & 0xff,
        SAMPLE_RATE * 2, 0, 2, 0,
        16, 0,
        'd', 'a', 't', 'a',
        0, 0, 0, 0
    };

    size_t data_size = num_samples * sizeof(int16_t);
    *(int32_t *)(header + 4) = HEADER_SIZE - 8 + data_size; // Correcting the RIFF chunk size.
    *(int32_t *)(header + 40) = data_size; // Correcting the data chunk size.

    fwrite(header, sizeof(unsigned char), HEADER_SIZE, file);
    fwrite(samples, sizeof(int16_t), num_samples, file);

    fclose(file);
}

int main() {
    int16_t *samples = NULL;
    size_t num_samples = read_wav("input.wav", &samples);
    if (num_samples < 0) return 1;

    printf("Processing audio with an Echo effect...\n");
    apply_echo(samples, num_samples, ECHO_DECAY, ECHO_DELAY_MS);

    write_wav("output.wav", samples, num_samples);
    printf("Echo effect applied. Output saved as 'output.wav'\n");

    free(samples);
    return 0;
}