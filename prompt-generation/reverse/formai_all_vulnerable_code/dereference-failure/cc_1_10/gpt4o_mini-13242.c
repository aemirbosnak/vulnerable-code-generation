//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define SAMPLERATE 44100
#define ECHO_DELAY 0.5 // seconds
#define ECHO_AMPLITUDE 0.6 // fraction of the original sound

typedef struct {
    uint32_t chunkID;
    uint32_t chunkSize;
    uint32_t format;
    uint32_t subchunk1ID;
    uint32_t subchunk1Size;
    uint16_t audioFormat;
    uint16_t numChannels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
    uint32_t subchunk2ID;
    uint32_t subchunk2Size;
    int16_t data[]; // Variable length array for audio samples
} WAVHeader;

void apply_echo(WAVHeader *header, int16_t *samples, size_t numSamples) {
    int delaySamples = (int)(SAMPLERATE * ECHO_DELAY);
    for (size_t i = 0; i < numSamples; i++) {
        if (i >= delaySamples) {
            samples[i] += (int16_t)(ECHO_AMPLITUDE * samples[i - delaySamples]);
        }
    }
}

void write_wav(const char *filename, WAVHeader *header) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("Failed to open output file");
        return;
    }

    fwrite(header, sizeof(WAVHeader) + header->subchunk2Size, 1, fp);
    fclose(fp);
}

WAVHeader *read_wav(const char *filename, size_t *numSamples) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("Failed to open input file");
        return NULL;
    }

    WAVHeader *header = malloc(sizeof(WAVHeader));
    fread(header, sizeof(WAVHeader), 1, fp);

    *numSamples = header->subchunk2Size / sizeof(int16_t);
    header = realloc(header, sizeof(WAVHeader) + header->subchunk2Size);
    fread(header->data, sizeof(int16_t), *numSamples, fp);
    fclose(fp);

    return header;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input.wav> <output.wav>\n", argv[0]);
        return 1;
    }

    size_t numSamples = 0;
    WAVHeader *header = read_wav(argv[1], &numSamples);
    if (!header) {
        return 1;
    }

    apply_echo(header, header->data, numSamples);
    write_wav(argv[2], header);

    free(header);
    printf("Echo effect applied and saved to %s!\n", argv[2]);
    return 0;
}