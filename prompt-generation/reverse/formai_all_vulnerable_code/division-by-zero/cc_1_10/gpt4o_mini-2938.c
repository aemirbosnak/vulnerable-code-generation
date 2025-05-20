//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    char chunkID[4];
    uint32_t chunkSize;
    char format[4];
} RIFFHeader;

typedef struct {
    char subchunkID[4];
    uint32_t subchunkSize;
    uint16_t audioFormat;
    uint16_t numChannels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
} WAVHeader;

void apply_gain(int16_t *samples, size_t num_samples, float gain) {
    for (size_t i = 0; i < num_samples; i++) {
        int32_t sample = samples[i] * gain;
        if (sample > INT16_MAX) {
            samples[i] = INT16_MAX;
        } else if (sample < INT16_MIN) {
            samples[i] = INT16_MIN;
        } else {
            samples[i] = (int16_t)sample;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <gain>\n", argv[0]);
        return 1;
    }

    float gain = atof(argv[3]);
    if (gain < 0) {
        fprintf(stderr, "Gain must be non-negative.\n");
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        perror("Failed to open input file");
        return 1;
    }

    RIFFHeader riff;
    fread(&riff, sizeof(RIFFHeader), 1, input_file);
    if (strncmp(riff.chunkID, "RIFF", 4) != 0 || strncmp(riff.format, "WAVE", 4) != 0) {
        fprintf(stderr, "Not a valid WAV file.\n");
        fclose(input_file);
        return 1;
    }

    WAVHeader wav;
    fread(&wav, sizeof(WAVHeader), 1, input_file);
    if (wav.audioFormat != 1) {
        fprintf(stderr, "Unsupported audio format.\n");
        fclose(input_file);
        return 1;
    }

    size_t num_samples = wav.subchunkSize / (wav.bitsPerSample / 8);
    int16_t *samples = malloc(num_samples * sizeof(int16_t));
    if (!samples) {
        perror("Failed to allocate memory for samples");
        fclose(input_file);
        return 1;
    }

    fread(samples, sizeof(int16_t), num_samples, input_file);
    fclose(input_file);

    apply_gain(samples, num_samples, gain);

    FILE *output_file = fopen(argv[2], "wb");
    if (!output_file) {
        perror("Failed to open output file");
        free(samples);
        return 1;
    }

    fwrite(&riff, sizeof(RIFFHeader), 1, output_file);
    fwrite(&wav, sizeof(WAVHeader), 1, output_file);
    fwrite(samples, sizeof(int16_t), num_samples, output_file);

    fclose(output_file);
    free(samples);

    printf("Processed WAV file saved as '%s' with gain factor %f\n", argv[2], gain);
    return 0;
}