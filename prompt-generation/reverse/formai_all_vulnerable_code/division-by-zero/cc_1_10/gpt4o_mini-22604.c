//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1) // Ensure struct packing
typedef struct {
    char riff[4];        // "RIFF"
    uint32_t overall_size; // Overall size of file in bytes
    char wave[4];       // "WAVE"
    char fmt[4];        // "fmt "
    uint32_t fmt_size;  // Size of this chunk
    uint16_t audio_format; // Audio format (1 for PCM)
    uint16_t num_channels; // Number of channels
    uint32_t sample_rate;  // Sampling frequency
    uint32_t byte_rate;     // Bytes per second
    uint16_t block_align;   // Bytes per sample frame
    uint16_t bits_per_sample; // Bits per sample
    char data[4];        // "data"
    uint32_t data_size;  // Size of the data chunk
} WAVHeader;
#pragma pack(pop)

void increase_volume(uint16_t *buffer, size_t size, float volume_factor) {
    for (size_t i = 0; i < size; i++) {
        int32_t temp = (int32_t)buffer[i] * volume_factor;
        if (temp > 65535) {
            buffer[i] = 65535; // Clamp to max value
        } else if (temp < 0) {
            buffer[i] = 0; // Clamp to min value
        } else {
            buffer[i] = (uint16_t)temp; // Assign scaled value
        }
    }
}

void process_wav_file(const char *input_file, const char *output_file, float volume_factor) {
    FILE *in = fopen(input_file, "rb");
    if (!in) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    WAVHeader header;
    fread(&header, sizeof(WAVHeader), 1, in);

    // Verify that it is a WAV file
    if (strncmp(header.riff, "RIFF", 4) != 0 || strncmp(header.wave, "WAVE", 4) != 0) {
        fprintf(stderr, "Not a valid WAV file\n");
        fclose(in);
        exit(EXIT_FAILURE);
    }

    size_t num_samples = header.data_size / (header.bits_per_sample / 8);
    uint16_t *samples = (uint16_t *)malloc(header.data_size);
    if (!samples) {
        perror("Memory allocation failed");
        fclose(in);
        exit(EXIT_FAILURE);
    }

    fread(samples, header.data_size, 1, in);
    fclose(in);

    // Increase volume
    increase_volume(samples, num_samples, volume_factor);

    // Write modified data to new file
    FILE *out = fopen(output_file, "wb");
    if (!out) {
        perror("Error opening output file");
        free(samples);
        exit(EXIT_FAILURE);
    }

    fwrite(&header, sizeof(WAVHeader), 1, out);
    fwrite(samples, header.data_size, 1, out);
    fclose(out);
    free(samples);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input wav file> <output wav file> <volume factor>\n", argv[0]);
        return EXIT_FAILURE;
    }

    float volume_factor = atof(argv[3]);
    if (volume_factor <= 0) {
        fprintf(stderr, "Volume factor must be greater than zero.\n");
        return EXIT_FAILURE;
    }

    process_wav_file(argv[1], argv[2], volume_factor);
    printf("Processed %s and created %s with volume factor of %.2f\n", argv[1], argv[2], volume_factor);

    return EXIT_SUCCESS;
}