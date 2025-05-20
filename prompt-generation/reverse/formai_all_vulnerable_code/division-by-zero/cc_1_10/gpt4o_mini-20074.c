//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define WAV_HEADER_SIZE 44

typedef struct {
    char chunkID[4];         // "RIFF"
    uint32_t chunkSize;      // FileSize - 8
    char format[4];          // "WAVE"
    char subchunk1ID[4];     // "fmt "
    uint32_t subchunk1Size;  // 16 for PCM
    uint16_t audioFormat;     // PCM = 1
    uint16_t numChannels;     // Mono = 1, Stereo = 2
    uint32_t sampleRate;     // Sample rate, e.g., 44100
    uint32_t byteRate;       // SampleRate * NumChannels * BitsPerSample/8
    uint16_t blockAlign;     // NumChannels * BitsPerSample/8
    uint16_t bitsPerSample;  // Number of bits per sample
    char subchunk2ID[4];     // "data"
    uint32_t subchunk2Size;  // Number of bytes in data
} WAVHeader;

void applyGain(int16_t* buffer, uint32_t numSamples, float gain) {
    for (uint32_t i = 0; i < numSamples; i++) {
        int32_t tempSample = (int32_t)(buffer[i] * gain);
        if (tempSample > INT16_MAX) {
            buffer[i] = INT16_MAX;
        } else if (tempSample < INT16_MIN) {
            buffer[i] = INT16_MIN;
        } else {
            buffer[i] = (int16_t)tempSample;
        }
    }
}

void processWav(const char* inputFile, const char* outputFile, float gain) {
    FILE* inFile = fopen(inputFile, "rb");
    if (!inFile) {
        fprintf(stderr, "Could not open input file: %s\n", inputFile);
        return;
    }
    
    WAVHeader header;
    fread(&header, sizeof(WAVHeader), 1, inFile);
    
    if (strncmp(header.chunkID, "RIFF", 4) != 0 || strncmp(header.format, "WAVE", 4) != 0) {
        fprintf(stderr, "Not a valid WAV file.\n");
        fclose(inFile);
        return;
    }
    
    uint32_t numSamples = header.subchunk2Size / (header.bitsPerSample / 8);
    int16_t* buffer = malloc(header.subchunk2Size);
    fread(buffer, header.subchunk2Size, 1, inFile);
    fclose(inFile);
    
    printf("File information:\n");
    printf("Channels: %u, Sample Rate: %u, Bits Per Sample: %u\n",
           header.numChannels, header.sampleRate, header.bitsPerSample);
    printf("Applying gain of %.2f...\n", gain);
    
    applyGain(buffer, numSamples, gain);
    
    FILE* outFile = fopen(outputFile, "wb");
    if (!outFile) {
        fprintf(stderr, "Could not open output file: %s\n", outputFile);
        free(buffer);
        return;
    }
    
    fwrite(&header, sizeof(WAVHeader), 1, outFile);
    fwrite(buffer, header.subchunk2Size, 1, outFile);
    fclose(outFile);
    
    printf("Processing complete; written to %s\n", outputFile);
    free(buffer);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <gain>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char* inputFile = argv[1];
    const char* outputFile = argv[2];
    float gain = atof(argv[3]);

    processWav(inputFile, outputFile, gain);
    
    return EXIT_SUCCESS;
}