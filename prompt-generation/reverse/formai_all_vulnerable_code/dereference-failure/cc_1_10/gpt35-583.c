//FormAI DATASET v1.0 Category: Audio processing ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct WAV {
    char chunkId[4];        // "RIFF"
    int32_t chunkSize;
    char format[4];         // "WAVE"

    char subchunk1Id[4];    // "fmt "
    int32_t subchunk1Size;
    int16_t audioFormat;
    int16_t numChannels;
    int32_t sampleRate;
    int32_t byteRate;
    int16_t blockAlign;
    int16_t bitsPerSample;

    char subchunk2Id[4];    // "data"
    int32_t subchunk2Size;

    uint8_t *data;
} WAV;

WAV* loadWAV(const char* filename) {
    FILE* file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Error: Unable to open file\n");
        return NULL;
    }

    WAV* wav = (WAV*)malloc(sizeof(WAV));

    fread(wav, sizeof(WAV), 1, file);

    wav->data = (uint8_t*)malloc(wav->subchunk2Size);

    fread(wav->data, wav->subchunk2Size, 1, file);

    fclose(file);

    return wav;
}

void saveWAV(WAV* wav, const char* filename) {
    FILE* file = fopen(filename, "wb");

    if (file == NULL) {
        printf("Error: Unable to open file\n");
        return;
    }

    fwrite(wav, sizeof(WAV), 1, file);

    fwrite(wav->data, wav->subchunk2Size, 1, file);

    fclose(file);
}

void printWAVInfo(WAV* wav) {
    printf("Chunk ID: %s\n", wav->chunkId);
    printf("Chunk size: %d\n", wav->chunkSize);
    printf("Format: %s\n", wav->format);

    printf("Subchunk 1 ID: %s\n", wav->subchunk1Id);
    printf("Subchunk 1 size: %d\n", wav->subchunk1Size);
    printf("Audio format: %d\n", wav->audioFormat);
    printf("Num channels: %d\n", wav->numChannels);
    printf("Sample rate: %d\n", wav->sampleRate);
    printf("Byte rate: %d\n", wav->byteRate);
    printf("Block alignment: %d\n", wav->blockAlign);
    printf("Bits per sample: %d\n", wav->bitsPerSample);

    printf("Subchunk 2 ID: %s\n", wav->subchunk2Id);
    printf("Subchunk 2 size: %d\n", wav->subchunk2Size);
}

int main() {
    WAV* wav = loadWAV("example.wav");

    if (wav == NULL) {
        return -1;
    }

    // Do some audio processing here...

    saveWAV(wav, "output.wav");

    free(wav->data);
    free(wav);

    return 0;
}