//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint8_t  chunkID[4];  // "RIFF"
    uint32_t chunkSize;
    uint8_t  format[4];    // "WAVE"
    uint8_t  subchunk1ID[4];// "fmt "
    uint32_t subchunk1Size;
    uint16_t audioFormat;
    uint16_t numChannels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
    uint8_t  subchunk2ID[4];// "data"
    uint32_t subchunk2Size;
} WAVHeader;

void applyLowPassFilter(int16_t *buffer, int bufferSize, int filterSize) {
    int16_t *outputBuffer = malloc(bufferSize * sizeof(int16_t));
    if (outputBuffer == NULL) {
        fprintf(stderr, "Error allocating memory for output buffer\n");
        exit(1);
    }

    for (int i = 0; i < bufferSize; i++) {
        int sum = 0;
        int count = 0;

        // Calculate moving average
        for (int j = 0; j < filterSize; j++) {
            if (i - j >= 0) {
                sum += buffer[i - j];
                count++;
            }
        }
        outputBuffer[i] = sum / count;
    }

    // Copy the filtered data back to the original buffer
    for (int i = 0; i < bufferSize; i++) {
        buffer[i] = outputBuffer[i];
    }

    free(outputBuffer);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <filter_size>\n", argv[0]);
        return 1;
    }

    const char *inputFileName = argv[1];
    const char *outputFileName = argv[2];
    int filterSize = atoi(argv[3]);

    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        fprintf(stderr, "Could not open input file %s\n", inputFileName);
        return 1;
    }

    WAVHeader header;
    fread(&header, sizeof(WAVHeader), 1, inputFile);

    if (header.audioFormat != 1) { // Check for PCM
        fprintf(stderr, "Only PCM WAV files are supported.\n");
        fclose(inputFile);
        return 1;
    }

    int bufferSize = header.subchunk2Size / (header.bitsPerSample / 8);
    int16_t *buffer = malloc(bufferSize * sizeof(int16_t));
    if (buffer == NULL) {
        fprintf(stderr, "Error allocating memory for audio buffer\n");
        fclose(inputFile);
        return 1;
    }

    fread(buffer, sizeof(int16_t), bufferSize, inputFile);
    fclose(inputFile);

    // Apply low-pass filter
    applyLowPassFilter(buffer, bufferSize, filterSize);

    FILE *outputFile = fopen(outputFileName, "wb");
    if (!outputFile) {
        fprintf(stderr, "Could not open output file %s\n", outputFileName);
        free(buffer);
        return 1;
    }

    fwrite(&header, sizeof(WAVHeader), 1, outputFile);
    fwrite(buffer, sizeof(int16_t), bufferSize, outputFile);
    
    fclose(outputFile);
    free(buffer);

    printf("Low-pass filtering completed. Output saved to %s\n", outputFileName);
    return 0;
}