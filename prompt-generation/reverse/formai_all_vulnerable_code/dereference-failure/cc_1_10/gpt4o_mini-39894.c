//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define SAMPLE_RATE 44100
#define ECHO_DELAY 0.2 // in seconds
#define MAX_ECHO 32767 // Maximum for 16-bit PCM

typedef struct {
    char chunkID[4];
    uint32_t chunkSize;
    char format[4];
    char subchunk1ID[4];
    uint32_t subchunk1Size;
    uint16_t audioFormat;
    uint16_t numChannels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
    char subchunk2ID[4];
    uint32_t subchunk2Size;
} WavHeader;

void applyEcho(int16_t *samples, uint32_t numSamples, float delay, uint16_t channels) {
    uint32_t delaySamples = (uint32_t)(delay * SAMPLE_RATE);
    for (uint32_t i = delaySamples; i < numSamples; i++) {
        for (uint16_t ch = 0; ch < channels; ch++) {
            int index = i * channels + ch;
            int echoIndex = (i - delaySamples) * channels + ch;
            int32_t echoedValue = samples[echoIndex] / 2; // Halve the echo to avoid overflow
            samples[index] = (int16_t)(samples[index] + echoedValue);
            // Clamping the value to prevent overflow
            if (samples[index] > MAX_ECHO) samples[index] = MAX_ECHO;
            if (samples[index] < -MAX_ECHO) samples[index] = -MAX_ECHO;
        }
    }
}

void readWav(const char *filename, WavHeader *header, int16_t **samples, uint32_t *numSamples) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fread(header, sizeof(WavHeader), 1, file);
    *numSamples = header->subchunk2Size / (header->bitsPerSample / 8);
    *samples = (int16_t *)malloc(*numSamples * sizeof(int16_t) * header->numChannels);
    
    if (!(*samples)) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    fread(*samples, sizeof(int16_t) * header->numChannels, *numSamples, file);
    fclose(file);
}

void writeWav(const char *filename, WavHeader *header, int16_t *samples, uint32_t numSamples) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    header->subchunk2Size = numSamples * sizeof(int16_t) * header->numChannels;
    header->chunkSize = 36 + header->subchunk2Size;

    fwrite(header, sizeof(WavHeader), 1, file);
    fwrite(samples, sizeof(int16_t) * header->numChannels, numSamples, file);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav>\n", argv[0]);
        return 1;
    }

    WavHeader header;
    int16_t *samples = NULL;
    uint32_t numSamples;

    readWav(argv[1], &header, &samples, &numSamples);
    applyEcho(samples, numSamples, ECHO_DELAY, header.numChannels);
    writeWav(argv[2], &header, samples, numSamples);

    free(samples);
    printf("With a touch of love, the echoes resonate in your heart... 🎶\n");
    return 0;
}