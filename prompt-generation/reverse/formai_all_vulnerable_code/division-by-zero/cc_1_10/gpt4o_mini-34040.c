//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define BUFFER_SIZE 4096

typedef struct {
    char chunkID[4];
    uint32_t chunkSize;
    char format[4];
    char subchunk1ID[4];
    uint32_t subchunk1Size;
    uint16_t audioFormat;
    uint16_t numChannels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
    char subchunk2ID[4];
    uint32_t subchunk2Size;
} WAVHeader;

void apply_gain(int16_t *buffer, size_t samples, float gain) {
    for (size_t i = 0; i < samples; i++) {
        buffer[i] = (int16_t)(buffer[i] * gain);
    }
}

void process_wav(const char *input_file, const char *output_file, float gain) {
    FILE *input = fopen(input_file, "rb");
    if (!input) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    WAVHeader header;
    fread(&header, sizeof(WAVHeader), 1, input);

    if (strncmp(header.chunkID, "RIFF", 4) != 0 || strncmp(header.format, "WAVE", 4) != 0) {
        fprintf(stderr, "Not a valid WAV file\n");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    // Print WAV header information
    printf("Audio Format: %d\n", header.audioFormat);
    printf("Number of Channels: %d\n", header.numChannels);
    printf("Sample Rate: %d\n", header.sampleRate);
    printf("Bits per Sample: %d\n", header.bitsPerSample);

    size_t num_samples = header.subchunk2Size / (header.bitsPerSample / 8);
    int16_t *buffer = malloc(num_samples * sizeof(int16_t));

    if (!buffer) {
        perror("Memory allocation failed");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    fread(buffer, sizeof(int16_t), num_samples, input);
    fclose(input);

    // Apply gain
    apply_gain(buffer, num_samples, gain);

    // Write to output file
    FILE *output = fopen(output_file, "wb");
    if (!output) {
        perror("Error opening output file");
        free(buffer);
        exit(EXIT_FAILURE);
    }

    fwrite(&header, sizeof(WAVHeader), 1, output);
    fwrite(buffer, sizeof(int16_t), num_samples, output);
    fclose(output);
    free(buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <gain>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    float gain = atof(argv[3]);

    process_wav(input_file, output_file, gain);

    printf("Processing completed. Output saved to %s\n", output_file);

    return 0;
}