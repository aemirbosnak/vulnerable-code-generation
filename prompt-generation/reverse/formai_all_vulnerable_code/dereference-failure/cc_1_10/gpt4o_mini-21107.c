//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(1) // Ensure structures are packed without padding

typedef struct {
    uint16_t id[4];       // "RIFF"
    uint32_t fileSize;    // File size in bytes
    uint16_t format[2];   // "WAVE"
} RIFFHeader;

typedef struct {
    uint16_t chunkID[4];  // "fmt "
    uint32_t chunkSize;    // Size of this chunk
    uint16_t audioFormat;   // Audio format (1 for PCM)
    uint16_t numChannels;   // Number of channels (1 for mono, 2 for stereo)
    uint32_t sampleRate;    // Sample rate in Hz
    uint32_t byteRate;      // Bytes per second
    uint16_t blockAlign;    // Number of bytes per sample
    uint16_t bitsPerSample;  // Bits per sample (8, 16, etc.)
} FmtChunk;

typedef struct {
    uint16_t chunkID[4];   // "data"
    uint32_t chunkSize;     // Size of the data chunk
} DataChunk;

void apply_gain(int16_t *samples, int num_samples, float gain) {
    for (int i = 0; i < num_samples; i++) {
        int32_t sample = (int32_t)(samples[i] * gain);
        if (sample > INT16_MAX) {
            samples[i] = INT16_MAX;
        } else if (sample < INT16_MIN) {
            samples[i] = INT16_MIN;
        } else {
            samples[i] = (int16_t)sample;
        }
    }
}

void read_wave_file(const char *filename, int16_t **samples, int *num_samples) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    RIFFHeader riff;
    fread(&riff, sizeof(RIFFHeader), 1, file);

    FmtChunk fmt;
    fread(&fmt, sizeof(FmtChunk), 1, file);

    DataChunk data;
    fread(&data, sizeof(DataChunk), 1, file);

    *num_samples = data.chunkSize / sizeof(int16_t);
    *samples = (int16_t *)malloc(data.chunkSize);
    fread(*samples, sizeof(int16_t), *num_samples, file);

    fclose(file);
}

void write_wave_file(const char *filename, int16_t *samples, int num_samples, const FmtChunk *fmt) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error opening file for writing: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    RIFFHeader riff = {{'R', 'I', 'F', 'F'}, sizeof(RIFFHeader) + sizeof(FmtChunk) + sizeof(DataChunk) + num_samples * sizeof(int16_t) - 8, {'W', 'A', 'V', 'E'}};
    fwrite(&riff, sizeof(RIFFHeader), 1, file);
    
    fwrite(fmt, sizeof(FmtChunk), 1, file);

    DataChunk data = {{'d', 'a', 't', 'a'}, num_samples * sizeof(int16_t)};
    fwrite(&data, sizeof(DataChunk), 1, file);
    
    fwrite(samples, sizeof(int16_t), num_samples, file);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <gain>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];
    float gain = atof(argv[3]);

    int16_t *samples = NULL;
    int num_samples = 0;
    FmtChunk fmt;

    // Read the WAV file
    read_wave_file(input_filename, &samples, &num_samples);

    // Apply gain
    apply_gain(samples, num_samples, gain);

    // Determine format based on the input file header (skipped for brevity)
    // Assume parameters of the waveform format are retrieved correctly
    // Populate 'fmt' based on the original file read

    // Write the modified WAV file
    write_wave_file(output_filename, samples, num_samples, &fmt);

    free(samples);
    return EXIT_SUCCESS;
}