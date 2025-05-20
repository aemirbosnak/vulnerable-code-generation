//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    char riff[4];        // "RIFF"
    uint32_t overall_size; // Overall size of file
    char wave[4];       // "WAVE"
    char fmt[4];        // "fmt "
    uint32_t fmt_size;  // Size of the fmt chunk
    uint16_t format_type; // Audio format 1=PCM
    uint16_t channels;   // Number of channels
    uint32_t sample_rate;    // Sampling Frequency in Hz
    uint32_t byterate;   // Bytes per second
    uint16_t block_align; // 2=16-bit mono
    uint16_t bits_per_sample; // Number of bits per sample
    char data[4];        // "data"
    uint32_t data_size;  // Size of data section
} WavHeader;
#pragma pack(pop)

void apply_gain(int16_t *buffer, int32_t num_samples, float gain) {
    for (int32_t i = 0; i < num_samples; i++) {
        int32_t temp = (int32_t)(buffer[i] * gain);
        // Clamp to int16_t range
        if (temp > INT16_MAX) {
            buffer[i] = INT16_MAX;
        } else if (temp < INT16_MIN) {
            buffer[i] = INT16_MIN;
        } else {
            buffer[i] = (int16_t)temp;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <gain>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];
    float gain = atof(argv[3]);

    FILE *input_file = fopen(input_filename, "rb");
    if (!input_file) {
        perror("Failed to open input file");
        return EXIT_FAILURE;
    }

    WavHeader header;
    fread(&header, sizeof(WavHeader), 1, input_file);

    if (strncmp(header.riff, "RIFF", 4) != 0 || strncmp(header.wave, "WAVE", 4) != 0) {
        fprintf(stderr, "Not a valid WAV file.\n");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    int32_t num_samples = header.data_size / (header.bits_per_sample / 8);
    int16_t *buffer = malloc(header.data_size);
    if (!buffer) {
        perror("Failed to allocate memory for audio buffer");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    fread(buffer, header.data_size, 1, input_file);
    fclose(input_file);

    apply_gain(buffer, num_samples, gain);

    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        perror("Failed to open output file");
        free(buffer);
        return EXIT_FAILURE;
    }

    fwrite(&header, sizeof(WavHeader), 1, output_file);
    fwrite(buffer, header.data_size, 1, output_file);

    fclose(output_file);
    free(buffer);

    printf("Processing complete. Output written to %s\n", output_filename);
    return EXIT_SUCCESS;
}