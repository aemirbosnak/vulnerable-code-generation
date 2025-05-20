//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// WAV file header structure
#pragma pack(push, 1)
typedef struct {
    char RIFF[4];         // RIFF Header
    uint32_t ChunkSize;   // RIFF Size
    char WAVE[4];         // WAVE Header
    char fmt[4];          // FMT header
    uint32_t Subchunk1Size; // Format chunk size
    uint16_t AudioFormat; // Audio format (PCM)
    uint16_t NumChannels; // Number of channels
    uint32_t SampleRate;  // Sampling frequency (common values are 44100, 48000)
    uint32_t ByteRate;    // Bytes per second
    uint16_t BlockAlign;  // 2-byte alignment for audio data
    uint16_t BitsPerSample;// Bits per sample
    char Subchunk2ID[4];  // "data" header
    uint32_t Subchunk2Size; // Size of data section
} WAVHeader;
#pragma pack(pop)

// Function to apply gain to audio samples
void applyGain(int16_t *samples, size_t numSamples, float gain) {
    for (size_t i = 0; i < numSamples; i++) {
        int32_t temp = (int32_t)(samples[i] * gain);
        // Clamping the output samples to 16-bit signed integer range
        if (temp > 32767) temp = 32767;
        if (temp < -32768) temp = -32768;
        samples[i] = (int16_t)temp;
    }
}

// Main program
int main() {
    FILE *inputFile = fopen("input.wav", "rb");
    if (!inputFile) {
        fprintf(stderr, "Error opening input file.\n");
        return 1;
    }

    // Read the WAV header
    WAVHeader header;
    fread(&header, sizeof(WAVHeader), 1, inputFile);

    // Check if the file is in the correct format
    if (memcmp(header.RIFF, "RIFF", 4) != 0 || memcmp(header.WAVE, "WAVE", 4) != 0 ||
        memcmp(header.fmt, "fmt ", 4) != 0 || header.AudioFormat != 1) { // 1 means PCM
        fprintf(stderr, "Unsupported WAV format.\n");
        fclose(inputFile);
        return 1;
    }

    // Prepare to read samples
    size_t numSamples = header.Subchunk2Size / (header.BitsPerSample / 8);
    int16_t *samples = (int16_t *)malloc(numSamples * sizeof(int16_t));
    if (!samples) {
        fprintf(stderr, "Memory allocation failed.\n");
        fclose(inputFile);
        return 1;
    }

    // Read audio samples
    fread(samples, sizeof(int16_t), numSamples, inputFile);
    fclose(inputFile);

    // Gain factor
    float gain = 2.0f; // Example gain factor to double the volume
    applyGain(samples, numSamples, gain);

    // Write the modified samples to a new WAV file
    FILE *outputFile = fopen("output.wav", "wb");
    if (!outputFile) {
        fprintf(stderr, "Error opening output file.\n");
        free(samples);
        return 1;
    }

    fwrite(&header, sizeof(WAVHeader), 1, outputFile);
    fwrite(samples, sizeof(int16_t), numSamples, outputFile);
    fclose(outputFile);
    free(samples);

    printf("Audio processing complete. Output written to 'output.wav'.\n");
    return 0;
}