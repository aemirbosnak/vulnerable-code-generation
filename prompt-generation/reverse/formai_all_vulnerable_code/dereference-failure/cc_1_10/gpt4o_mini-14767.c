//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    char riff[4];        // "RIFF"
    uint32_t size;      // File size
    char wave[4];       // "WAVE"
    char fmt[4];        // "fmt "
    uint32_t fmtSize;   // Format size
    uint16_t format;     // Format type
    uint16_t channels;   // Channels
    uint32_t sampleRate; // Sample rate
    uint32_t byteRate;   // bytes per second
    uint16_t blockAlign; // Block align
    uint16_t bitsPerSample; // Bits per sample
} WAVHeader;

typedef struct {
    char data[4];       // "data"
    uint32_t dataSize;  // Data size
} WAVDataHeader;
#pragma pack(pop)

void compressAudio(int16_t *samples, size_t size, float threshold, float ratio) {
    for (size_t i = 0; i < size; i++) {
        if (samples[i] > threshold * INT16_MAX) {
            samples[i] = (int16_t)(threshold * INT16_MAX + (samples[i] - threshold * INT16_MAX) / ratio);
        } else if (samples[i] < -threshold * INT16_MAX) {
            samples[i] = (int16_t)(-threshold * INT16_MAX + (samples[i] + threshold * INT16_MAX) / ratio);
        }
    }
}

void processWAV(const char *inputFile, const char *outputFile, float threshold, float ratio) {
    FILE *input = fopen(inputFile, "rb");
    if (!input) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    WAVHeader header;
    fread(&header, sizeof(header), 1, input);

    if (memcmp(header.riff, "RIFF", 4) != 0 || memcmp(header.wave, "WAVE", 4) != 0) {
        fprintf(stderr, "Not a valid WAV file!\n");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    WAVDataHeader dataHeader;
    fread(&dataHeader, sizeof(dataHeader), 1, input);

    if (memcmp(dataHeader.data, "data", 4) != 0) {
        fprintf(stderr, "No audio data found!\n");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    size_t sampleCount = dataHeader.dataSize / sizeof(int16_t);
    int16_t *samples = (int16_t *)malloc(dataHeader.dataSize);
    fread(samples, sizeof(int16_t), sampleCount, input);
    fclose(input);

    printf("The Sound Wizard is applying compression magic...\n");
    compressAudio(samples, sampleCount, threshold, ratio);

    FILE *output = fopen(outputFile, "wb");
    if (!output) {
        perror("Error opening output file");
        free(samples);
        exit(EXIT_FAILURE);
    }

    fwrite(&header, sizeof(header), 1, output);
    fwrite(&dataHeader, sizeof(dataHeader), 1, output);
    fwrite(samples, sizeof(int16_t), sampleCount, output);

    free(samples);
    fclose(output);
    printf("Enchanted audio saved to '%s'.\n", outputFile);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <threshold> <ratio>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *inputFile = argv[1];
    const char *outputFile = argv[2];
    float threshold = atof(argv[3]);
    float ratio = atof(argv[4]);

    if (threshold < 0 || threshold > 1 || ratio <= 1) {
        fprintf(stderr, "Threshold should be between 0 and 1, ratio should be greater than 1.\n");
        return EXIT_FAILURE;
    }

    processWAV(inputFile, outputFile, threshold, ratio);
    return EXIT_SUCCESS;
}