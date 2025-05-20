//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    char chunkID[4];       // "RIFF"
    uint32_t chunkSize;
    char format[4];        // "WAVE"
    char subchunk1ID[4];   // "fmt "
    uint32_t subchunk1Size;
    uint16_t audioFormat;  // PCM = 1
    uint16_t numChannels;   // Mono = 1, Stereo = 2
    uint32_t sampleRate;    // Sample Rate
    uint32_t byteRate;      // Sample Rate * NumChannels * BitsPerSample/8
    uint16_t blockAlign;    // NumChannels * BitsPerSample/8
    uint16_t bitsPerSample;  // Bits per sample
    char subchunk2ID[4];    // "data"
    uint32_t subchunk2Size; // Size of the data
} WavHeader;
#pragma pack(pop)

void apply_gain(int16_t *buffer, size_t length, float gain) {
    for (size_t i = 0; i < length; i++) {
        float sample = buffer[i] * gain;
        if (sample > INT16_MAX) sample = INT16_MAX;
        if (sample < INT16_MIN) sample = INT16_MIN;
        buffer[i] = (int16_t)sample;
    }
}

void print_wav_info(WavHeader *header) {
    printf("WAV File Info:\n");
    printf("Format: %s\n", header->format);
    printf("Channels: %d\n", header->numChannels);
    printf("Sample Rate: %d\n", header->sampleRate);
    printf("Byte Rate: %d\n", header->byteRate);
    printf("Bits per Sample: %d\n", header->bitsPerSample);
    printf("Data Size: %d\n", header->subchunk2Size);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <gain>\n", argv[0]);
        return 1;
    }

    const char *inputFileName = argv[1];
    const char *outputFileName = argv[2];
    float gain = atof(argv[3]);

    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        perror("Error opening input file");
        return 1;
    }

    WavHeader header;
    fread(&header, sizeof(WavHeader), 1, inputFile);
    print_wav_info(&header);

    if (header.audioFormat != 1) {
        fprintf(stderr, "Unsupported audio format: %d\n", header.audioFormat);
        fclose(inputFile);
        return 1;
    }

    size_t numSamples = header.subchunk2Size / (header.bitsPerSample / 8);
    int16_t *audioBuffer = (int16_t *)malloc(header.subchunk2Size);
    if (!audioBuffer) {
        fprintf(stderr, "Memory allocation error\n");
        fclose(inputFile);
        return 1;
    }

    fread(audioBuffer, header.subchunk2Size, 1, inputFile);
    fclose(inputFile);

    apply_gain(audioBuffer, numSamples, gain);

    FILE *outputFile = fopen(outputFileName, "wb");
    if (!outputFile) {
        perror("Error opening output file");
        free(audioBuffer);
        return 1;
    }

    fwrite(&header, sizeof(WavHeader), 1, outputFile);
    fwrite(audioBuffer, header.subchunk2Size, 1, outputFile);
    fclose(outputFile);

    free(audioBuffer);
    printf("Successfully processed the WAV file with gain: %.2f\n", gain);

    return 0;
}