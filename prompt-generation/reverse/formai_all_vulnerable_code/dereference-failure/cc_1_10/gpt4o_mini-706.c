//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <fftw3.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

typedef struct {
    char riff[4];
    int fileSize;
    char wave[4];
    char fmt[4];
    int fmtLength;
    short formatType;
    short channels;
    int sampleRate;
    int byteRate;
    short blockAlign;
    short bitsPerSample;
    char data[4];
    int dataSize;
} WavHeader;

void applyEqualizer(float *buffer, int size) {
    for (int i = 0; i < size; i++) {
        if (i < 200) {  // Boost bass
            buffer[i] *= 1.5;
        }
        if (i > 8000) {  // Boost treble
            buffer[i] *= 1.5;
        }
    }
}

void readWavHeader(FILE *file, WavHeader *header) {
    fread(header, sizeof(WavHeader), 1, file);
}

void writeWavHeader(FILE *file, WavHeader *header) {
    fwrite(header, sizeof(WavHeader), 1, file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input.wav> <output.wav>\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "rb");
    if (!inputFile) {
        printf("Error opening input file.\n");
        return 1;
    }

    WavHeader header;
    readWavHeader(inputFile, &header);

    if (header.bitsPerSample != 16) {
        printf("Only 16-bit WAV files are supported.\n");
        fclose(inputFile);
        return 1;
    }

    int sampleCount = header.dataSize / (header.bitsPerSample / 8);
    float *buffer = (float *)malloc(sampleCount * sizeof(float));
    short *rawData = (short *)malloc(sampleCount * sizeof(short));

    fread(rawData, sizeof(short), sampleCount, inputFile);
    fclose(inputFile);

    // Convert short samples to float
    for (int i = 0; i < sampleCount; i++) {
        buffer[i] = rawData[i] / 32768.0;  // Normalizing
    }

    // Apply equalizer
    applyEqualizer(buffer, sampleCount);

    FILE *outputFile = fopen(argv[2], "wb");
    if (!outputFile) {
        printf("Error opening output file.\n");
        free(buffer);
        free(rawData);
        return 1;
    }

    writeWavHeader(outputFile, &header);

    // Convert float samples back to short
    for (int i = 0; i < sampleCount; i++) {
        rawData[i] = (short)(buffer[i] * 32768.0);
    }

    fwrite(rawData, sizeof(short), sampleCount, outputFile);
    
    fclose(outputFile);
    free(buffer);
    free(rawData);
    
    printf("Equalization applied successfully!\n");
    return 0;
}