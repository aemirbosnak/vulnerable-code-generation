//FormAI DATASET v1.0 Category: Audio processing ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* This program applies a tremolo effect to an input audio file */

typedef struct {
    char chunkID[4];
    unsigned int chunkSize;
    char format[4];
    char subchunk1ID[4];
    unsigned int subchunk1Size;
    unsigned short audioFormat;
    unsigned short numChannels;
    unsigned int sampleRate;
    unsigned int byteRate;
    unsigned short blockAlign;
    unsigned short bitsPerSample;
    char subchunk2ID[4];
    unsigned int subchunk2Size;
} WAV_HEADER;

// Function to apply tremolo effect to audio data
void tremoloEffect(float *audioData, unsigned int numSamples, float depth, float rate) {
    unsigned int i;
    for (i=0; i<numSamples; i++) {
        float t = (float)i / (float)numSamples * 2.0 * M_PI * rate;
        audioData[i] *= (1.0 - depth) + depth * sin(t);
    }
}

int main(int argc, char *argv[]) {

    if (argc != 5) {
        printf("Usage: %s input_file output_file depth rate\n", argv[0]);
        return 1;
    }

    // Read in file name and parameters
    char *inputFile = argv[1];
    char *outputFile = argv[2];
    float depth = atof(argv[3]);
    float rate = atof(argv[4]);

    // Open input file
    FILE *input = fopen(inputFile, "rb");
    if (!input) {
        printf("Error opening input file %s\n", inputFile);
        return 1;
    }

    // Read in WAV header
    WAV_HEADER header;
    fread(&header, sizeof(header), 1, input);

    // Check format is PCM
    if (header.audioFormat != 1) {
        printf("Error: Only PCM audio format is supported\n");
        fclose(input);
        return 1;
    }

    // Check number of channels is 1 (mono)
    if (header.numChannels != 1) {
        printf("Error: Only mono audio is supported\n");
        fclose(input);
        return 1;
    }

    // Check bits per sample is 32
    if (header.bitsPerSample != 32) {
        printf("Error: Only 32-bit floating point audio is supported\n");
        fclose(input);
        return 1;
    }

    // Read in audio data
    unsigned int numSamples = header.subchunk2Size / 4;
    float *audioData = (float*)malloc(sizeof(float) * numSamples);
    fread(audioData, sizeof(float), numSamples, input);

    // Apply tremolo effect
    tremoloEffect(audioData, numSamples, depth, rate);

    // Open output file
    FILE *output = fopen(outputFile, "wb");
    if (!output) {
        printf("Error opening output file %s\n", outputFile);
        free(audioData);
        fclose(input);
        return 1;
    }

    // Write WAV header to output file
    fwrite(&header, sizeof(header), 1, output);

    // Write modified audio data to output file
    fwrite(audioData, sizeof(float), numSamples, output);

    // Close files and free memory
    fclose(input);
    fclose(output);
    free(audioData);

    return 0;
}