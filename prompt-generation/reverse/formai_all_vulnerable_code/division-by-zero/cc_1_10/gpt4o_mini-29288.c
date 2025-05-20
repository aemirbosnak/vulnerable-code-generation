//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_VOLUME 200
#define MIN_VOLUME 0

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
} WAVHeader;

void adjustVolume(int16_t *samples, size_t numSamples, float volumeFactor) {
    for (size_t i = 0; i < numSamples; i++) {
        int32_t sample = (int32_t)(samples[i] * volumeFactor);
        if (sample > INT16_MAX) {
            samples[i] = INT16_MAX;
        } else if (sample < INT16_MIN) {
            samples[i] = INT16_MIN;
        } else {
            samples[i] = (int16_t)sample;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input.wav> <output.wav> <volume_factor>\n", argv[0]);
        return 1;
    }

    const char *inputFileName = argv[1];
    const char *outputFileName = argv[2];
    float volumeFactor = atof(argv[3]);

    if (volumeFactor < MIN_VOLUME || volumeFactor > MAX_VOLUME) {
        printf("Volume factor must be between %d and %d.\n", MIN_VOLUME, MAX_VOLUME);
        return 1;
    }

    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        perror("Failed to open input file");
        return 1;
    }

    WAVHeader header;
    fread(&header, sizeof(WAVHeader), 1, inputFile);

    if (strncmp(header.chunkID, "RIFF", 4) != 0 || strncmp(header.format, "WAVE", 4) != 0) {
        printf("Not a valid WAV file.\n");
        fclose(inputFile);
        return 1;
    }

    size_t numSamples = header.subchunk2Size / (header.bitsPerSample / 8);
    int16_t *samples = (int16_t *)malloc(numSamples * sizeof(int16_t));

    if (!samples) {
        perror("Failed to allocate memory for samples");
        fclose(inputFile);
        return 1;
    }

    fread(samples, sizeof(int16_t), numSamples, inputFile);
    fclose(inputFile);

    adjustVolume(samples, numSamples, volumeFactor);

    FILE *outputFile = fopen(outputFileName, "wb");
    if (!outputFile) {
        perror("Failed to open output file");
        free(samples);
        return 1;
    }

    fwrite(&header, sizeof(WAVHeader), 1, outputFile);
    fwrite(samples, sizeof(int16_t), numSamples, outputFile);
    fclose(outputFile);
    free(samples);

    printf("Volume adjusted and saved to %s successfully.\n", outputFileName);
    return 0;
}