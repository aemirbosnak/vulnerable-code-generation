//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// WAV file format structure definitions
#pragma pack(1)
typedef struct {
    char chunkID[4];       // "RIFF"
    uint32_t chunkSize;    // File size - 8
    char format[4];        // "WAVE"
} WaveHeader;

typedef struct {
    char subchunk1ID[4];   // "fmt "
    uint32_t subchunk1Size; // Size of fmt chunk
    uint16_t audioFormat;   // Audio format (1 for PCM)
    uint16_t numChannels;    // Number of channels
    uint32_t sampleRate;    // Sample rate
    uint32_t byteRate;      // Byte rate
    uint16_t blockAlign;    // Block align
    uint16_t bitsPerSample; // Bits per sample
} FormatChunk;

typedef struct {
    char subchunk2ID[4];    // "data"
    uint32_t subchunk2Size;  // Size of data chunk
} DataChunk;

// Function to adjust the volume
void adjustVolume(int16_t *buffer, size_t samples, float volume) {
    for (size_t i = 0; i < samples; i++) {
        buffer[i] = (int16_t)(buffer[i] * volume);
        // Clamp values to the signed 16-bit range
        if (buffer[i] > 32767) buffer[i] = 32767;
        if (buffer[i] < -32768) buffer[i] = -32768;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input.wav> <output.wav> <volume>\n", argv[0]);
        return 1;
    }

    const char *inputFileName = argv[1];
    const char *outputFileName = argv[2];
    float volume = atof(argv[3]); // Volume adjustment factor
    if (volume < 0 || volume > 2) {
        printf("Volume must be between 0 and 2.\n");
        return 1;
    }

    // Open input WAV file
    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        perror("Could not open input file");
        return 1;
    }

    // Read headers
    WaveHeader waveHeader;
    FormatChunk formatChunk;
    DataChunk dataChunk;

    fread(&waveHeader, sizeof(waveHeader), 1, inputFile);
    fread(&formatChunk, sizeof(formatChunk), 1, inputFile);
    fread(&dataChunk, sizeof(dataChunk), 1, inputFile);

    if (strncmp(waveHeader.chunkID, "RIFF", 4) != 0 || 
        strncmp(waveHeader.format, "WAVE", 4) != 0) {
        printf("Not a valid WAV file.\n");
        fclose(inputFile);
        return 1;
    }

    printf("Input File: %s\n", inputFileName);
    printf("Channels: %d\n", formatChunk.numChannels);
    printf("Sample Rate: %d\n", formatChunk.sampleRate);
    printf("Bits per Sample: %d\n", formatChunk.bitsPerSample);
    printf("Data Size: %d bytes\n", dataChunk.subchunk2Size);

    // Read audio samples
    size_t numSamples = dataChunk.subchunk2Size / sizeof(int16_t);
    int16_t *buffer = (int16_t *)malloc(dataChunk.subchunk2Size);
    fread(buffer, sizeof(int16_t), numSamples, inputFile);
    fclose(inputFile);

    // Adjust volume
    adjustVolume(buffer, numSamples, volume);
    printf("Volume adjusted by a factor of %.2f!\n", volume);

    // Write output WAV file
    FILE *outputFile = fopen(outputFileName, "wb");
    if (!outputFile) {
        perror("Could not open output file");
        free(buffer);
        return 1;
    }

    fwrite(&waveHeader, sizeof(waveHeader), 1, outputFile);
    fwrite(&formatChunk, sizeof(formatChunk), 1, outputFile);
    fwrite(&dataChunk, sizeof(dataChunk), 1, outputFile);
    fwrite(buffer, sizeof(int16_t), numSamples, outputFile);

    printf("Output written successfully to %s!\n", outputFileName);

    // Cleanup
    fclose(outputFile);
    free(buffer);
    return 0;
}