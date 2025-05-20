//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    char chunkID[4];
    uint32_t chunkSize;
    char format[4];
} RIFFHeader;

typedef struct {
    char subchunkID[4];
    uint32_t subchunkSize;
    uint16_t audioFormat;
    uint16_t numChannels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
} fmtSubchunk;

typedef struct {
    char subchunkID[4];
    uint32_t subchunkSize;
} dataSubchunk;

void modifyAmplitude(int16_t *buffer, size_t numSamples, float factor) {
    for (size_t i = 0; i < numSamples; i++) {
        int32_t temp = (int32_t)(buffer[i] * factor);
        if (temp > INT16_MAX) {
            buffer[i] = INT16_MAX;
        } else if (temp < INT16_MIN) {
            buffer[i] = INT16_MIN;
        } else {
            buffer[i] = (int16_t)temp;
        }
    }
}

void printWAVHeader(RIFFHeader riff, fmtSubchunk fmt, dataSubchunk data) {
    printf("RIFF Header:\n");
    printf("  Chunk ID: %.4s\n", riff.chunkID);
    printf("  Chunk Size: %u\n", riff.chunkSize);
    printf("  Format: %.4s\n", riff.format);
    printf("fmt Subchunk:\n");
    printf("  Subchunk ID: %.4s\n", fmt.subchunkID);
    printf("  Subchunk Size: %u\n", fmt.subchunkSize);
    printf("  Audio Format: %u\n", fmt.audioFormat);
    printf("  Number of Channels: %u\n", fmt.numChannels);
    printf("  Sample Rate: %u\n", fmt.sampleRate);
    printf("  Byte Rate: %u\n", fmt.byteRate);
    printf("  Block Align: %u\n", fmt.blockAlign);
    printf("  Bits per Sample: %u\n", fmt.bitsPerSample);
    printf("data Subchunk:\n");
    printf("  Subchunk ID: %.4s\n", data.subchunkID);
    printf("  Subchunk Size: %u\n", data.subchunkSize);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s input.wav output.wav amplitude_factor\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *inputFile = fopen(argv[1], "rb");
    if (!inputFile) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE *outputFile = fopen(argv[2], "wb");
    if (!outputFile) {
        perror("Error opening output file");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    float amplitudeFactor = atof(argv[3]);

    RIFFHeader riff;
    fread(&riff, sizeof(RIFFHeader), 1, inputFile);
    fmtSubchunk fmt;
    fread(&fmt, sizeof(fmtSubchunk), 1, inputFile);
    dataSubchunk data;
    fread(&data, sizeof(dataSubchunk), 1, inputFile);
    
    printWAVHeader(riff, fmt, data);

    size_t numSamples = data.subchunkSize / (fmt.bitsPerSample / 8);
    int16_t *buffer = malloc(numSamples * sizeof(int16_t));
    
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(inputFile);
        fclose(outputFile);
        return EXIT_FAILURE;
    }

    fread(buffer, sizeof(int16_t), numSamples, inputFile);
    modifyAmplitude(buffer, numSamples, amplitudeFactor);
    
    fwrite(&riff, sizeof(RIFFHeader), 1, outputFile);
    fwrite(&fmt, sizeof(fmtSubchunk), 1, outputFile);
    fwrite(&data, sizeof(dataSubchunk), 1, outputFile);
    fwrite(buffer, sizeof(int16_t), numSamples, outputFile);

    free(buffer);
    fclose(inputFile);
    fclose(outputFile);

    printf("Audio processing complete. Output saved to %s\n", argv[2]);
    
    return EXIT_SUCCESS;
}