//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024
#define FREQUENCY 440.0
#define AMPLITUDE 32767

void generateSineWave(int16_t *buffer, size_t samples, double frequency, double amplitude, double sampleRate) {
    for (size_t i = 0; i < samples; i++) {
        buffer[i] = (int16_t)(amplitude * sin(2.0 * M_PI * frequency * ((double)i / sampleRate)));
    }
}

void applyLowPassFilter(int16_t *input, int16_t *output, size_t samples, double cutoff) {
    double RC = 1.0 / (cutoff * 2.0 * M_PI);
    double dt = 1.0 / SAMPLE_RATE;
    double alpha = dt / (RC + dt);
    
    output[0] = input[0];
    for (size_t i = 1; i < samples; i++) {
        output[i] = (int16_t)(output[i - 1] + alpha * (input[i] - output[i - 1]));
    }
}

void normalizeAudio(int16_t *buffer, size_t samples) {
    int16_t max = 0;
    for (size_t i = 0; i < samples; i++) {
        if (abs(buffer[i]) > max) {
            max = abs(buffer[i]);
        }
    }
    
    if (max == 0) return;

    for (size_t i = 0; i < samples; i++) {
        buffer[i] = (int16_t)((buffer[i] * AMPLITUDE) / max);
    }
}

void writeWavFile(const char *filename, int16_t *buffer, size_t samples) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    // WAV Header
    fwrite("RIFF", 1, 4, file);
    uint32_t chunkSize = 36 + samples * sizeof(int16_t);
    fwrite(&chunkSize, 4, 1, file);
    fwrite("WAVE", 1, 4, file);
    fwrite("fmt ", 1, 4, file);
    uint32_t subchunk1Size = 16;
    fwrite(&subchunk1Size, 4, 1, file);
    uint16_t audioFormat = 1; // PCM
    fwrite(&audioFormat, 2, 1, file);
    uint16_t numChannels = 1; // Mono
    fwrite(&numChannels, 2, 1, file);
    uint32_t sampleRate = SAMPLE_RATE;
    fwrite(&sampleRate, 4, 1, file);
    uint32_t byteRate = SAMPLE_RATE * numChannels * sizeof(int16_t);
    fwrite(&byteRate, 4, 1, file);
    uint16_t blockAlign = numChannels * sizeof(int16_t);
    fwrite(&blockAlign, 2, 1, file);
    uint16_t bitsPerSample = 16;
    fwrite(&bitsPerSample, 2, 1, file);
    
    // Data Chunk
    fwrite("data", 1, 4, file);
    uint32_t dataSize = samples * sizeof(int16_t);
    fwrite(&dataSize, 4, 1, file);
    fwrite(buffer, sizeof(int16_t), samples, file);
    
    fclose(file);
}

int main() {
    size_t numSamples = SAMPLE_RATE * 5; // 5 seconds
    int16_t *buffer = (int16_t *)calloc(numSamples, sizeof(int16_t));
    int16_t *filteredBuffer = (int16_t *)calloc(numSamples, sizeof(int16_t));
    
    if (!buffer || !filteredBuffer) {
        perror("Memory allocation failed");
        return -1;
    }

    generateSineWave(buffer, numSamples, FREQUENCY, AMPLITUDE, SAMPLE_RATE);
    applyLowPassFilter(buffer, filteredBuffer, numSamples, 1000.0);
    normalizeAudio(filteredBuffer, numSamples);

    writeWavFile("output.wav", filteredBuffer, numSamples);

    free(buffer);
    free(filteredBuffer);
    return 0;
}