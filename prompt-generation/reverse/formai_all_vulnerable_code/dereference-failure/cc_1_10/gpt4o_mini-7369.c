//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// WAV file header structure
typedef struct {
    char chunkId[4];
    uint32_t chunkSize;
    char format[4];
    char subchunk1Id[4];
    uint32_t subchunk1Size;
    uint16_t audioFormat;
    uint16_t numChannels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
    char subchunk2Id[4];
    uint32_t subchunk2Size;
} WavHeader;

// Function to apply gain to audio samples
void apply_gain(int16_t *samples, uint32_t numSamples, float gain) {
    for (uint32_t i = 0; i < numSamples; i++) {
        samples[i] = (int16_t)(samples[i] * gain);
        // Clipping
        if (samples[i] > INT16_MAX) samples[i] = INT16_MAX;
        if (samples[i] < INT16_MIN) samples[i] = INT16_MIN;
    }
}

// Function to read a WAV file and return the header and samples
int read_wav(const char *filename, WavHeader *header, int16_t **samples) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening WAV file");
        return -1;
    }

    fread(header, sizeof(WavHeader), 1, file);
    uint32_t numSamples = header->subchunk2Size / sizeof(int16_t);

    *samples = (int16_t *)malloc(numSamples * sizeof(int16_t));
    fread(*samples, sizeof(int16_t), numSamples, file);

    fclose(file);
    return numSamples;
}

// Function to write a WAV file with the modified samples
void write_wav(const char *filename, WavHeader *header, int16_t *samples, uint32_t numSamples) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error creating WAV file");
        return;
    }

    fwrite(header, sizeof(WavHeader), 1, file);
    fwrite(samples, sizeof(int16_t), numSamples, file);

    fclose(file);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <gain>\n", argv[0]);
        return 1;
    }

    const char *inputFile = argv[1];
    const char *outputFile = argv[2];
    float gain = atof(argv[3]);

    WavHeader header;
    int16_t *samples = NULL;

    // Read the WAV file
    int numSamples = read_wav(inputFile, &header, &samples);
    if (numSamples < 0) {
        return 1;
    }

    // Apply gain to the samples
    apply_gain(samples, numSamples, gain);

    // Write the modified samples to a new WAV file
    write_wav(outputFile, &header, samples, numSamples);

    // Clean up
    free(samples);
    printf("Processing complete. Output written to %s\n", outputFile);

    return 0;
}