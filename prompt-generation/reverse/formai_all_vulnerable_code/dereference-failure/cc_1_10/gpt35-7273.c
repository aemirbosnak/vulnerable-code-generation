//FormAI DATASET v1.0 Category: Audio processing ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Define our file header struct
typedef struct {
    char riff[4];
    int fileSize;
    char wave[4];
    char fmt[4];
    int fmtSize;
    short audioFormat;
    short numChannels;
    int sampleRate;
    int byteRate;
    short blockAlign;
    short bitsPerSample;
    char data[4];
    int dataSize;
} WavHeader;

// Method to swap the byte order of a short
short swapShort(short num) {
    unsigned char byte1, byte2;
    byte1 = num & 255;
    byte2 = num >> 8;
    return (byte1 << 8) | byte2;
}

// Method to swap the byte order of an int
int swapInt(int num) {
    unsigned char byte1, byte2, byte3, byte4;
    byte1 = num & 255;
    byte2 = (num >> 8) & 255;
    byte3 = (num >> 16) & 255;
    byte4 = (num >> 24) & 255;
    return (byte1 << 24) | (byte2 << 16) | (byte3 << 8) | byte4;
}

// Method to load a wave file and print some header info
short* loadWavFile(char* filePath, WavHeader* header) {
    // Open our file and ensure it exists
    FILE *file = fopen(filePath, "rb");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return NULL;
    }

    // Read in our header
    fread(header->riff, sizeof(header->riff), 1, file);
    fread(&header->fileSize, sizeof(header->fileSize), 1, file);
    fread(header->wave, sizeof(header->wave), 1, file);
    fread(header->fmt, sizeof(header->fmt), 1, file);
    fread(&header->fmtSize, sizeof(header->fmtSize), 1, file);
    fread(&header->audioFormat, sizeof(header->audioFormat), 1, file);
    fread(&header->numChannels, sizeof(header->numChannels), 1, file);
    fread(&header->sampleRate, sizeof(header->sampleRate), 1, file);
    fread(&header->byteRate, sizeof(header->byteRate), 1, file);
    fread(&header->blockAlign, sizeof(header->blockAlign), 1, file);
    fread(&header->bitsPerSample, sizeof(header->bitsPerSample), 1, file);
    fread(header->data, sizeof(header->data), 1, file);
    fread(&header->dataSize, sizeof(header->dataSize), 1, file);

    // Print some header info
    printf("Sample rate: %dHz\n", header->sampleRate);
    printf("Channels: %d\n", header->numChannels);
    printf("Bits per sample: %d\n", header->bitsPerSample);
    printf("Data size: %d\n", header->dataSize);

    // Allocate memory for our audio samples
    short* samples = (short*) malloc(header->dataSize);

    // Read in our audio samples
    fread(samples, sizeof(short), header->dataSize / sizeof(short), file);

    // Close our file and return our samples
    fclose(file);
    return samples;
}

// Method to save a wave file given its header info and samples
void saveWavFile(char* filePath, WavHeader header, short* samples) {
    // Open our file for writing and ensure it exists
    FILE* file = fopen(filePath, "wb");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return;
    }

    // Write our header out to the file
    fwrite(&header.riff, sizeof(header.riff), 1, file);
    fwrite(&header.fileSize, sizeof(header.fileSize), 1, file);
    fwrite(&header.wave, sizeof(header.wave), 1, file);
    fwrite(&header.fmt, sizeof(header.fmt), 1, file);
    fwrite(&header.fmtSize, sizeof(header.fmtSize), 1, file);
    fwrite(&header.audioFormat, sizeof(header.audioFormat), 1, file);
    fwrite(&header.numChannels, sizeof(header.numChannels), 1, file);
    fwrite(&header.sampleRate, sizeof(header.sampleRate), 1, file);
    fwrite(&header.byteRate, sizeof(header.byteRate), 1, file);
    fwrite(&header.blockAlign, sizeof(header.blockAlign), 1, file);
    fwrite(&header.bitsPerSample, sizeof(header.bitsPerSample), 1, file);
    fwrite(&header.data, sizeof(header.data), 1, file);
    fwrite(&header.dataSize, sizeof(header.dataSize), 1, file);

    // Write our audio samples
    fwrite(samples, sizeof(short), header.dataSize / sizeof(short), file);

    // Close our file
    fclose(file);
}

// Method to apply an echo effect to our audio samples
void applyEcho(short* samples, int numSamples, float delaySeconds, float decay) {
    // Allocate memory for our echoed samples
    short* echoedSamples = (short*) malloc(numSamples * sizeof(short));

    // Calculate the delay in number of samples
    int delaySamples = (int) (delaySeconds * 44100);

    // Loop through our samples and apply the echo
    for (int i = 0; i < numSamples; i++) {
        if (i < delaySamples) {
            echoedSamples[i] = samples[i];
        } else {
            short origSample = samples[i];
            short delayedSample = samples[i - delaySamples];
            echoedSamples[i] = origSample + decay * delayedSample;
        }
    }

    // Copy the echoed samples back into our original samples array
    memcpy(samples, echoedSamples, numSamples * sizeof(short));

    // Free the memory for the echoed samples
    free(echoedSamples);
}

int main() {
    // Load our input wave file
    WavHeader header;
    short* samples = loadWavFile("input.wav", &header);

    // Apply our audio effect (echo)
    applyEcho(samples, header.dataSize / sizeof(short), 0.75, 0.5);

    // Save our output wave file
    saveWavFile("output.wav", header, samples);

    // Free our allocated memory
    free(samples);

    return 0;
}