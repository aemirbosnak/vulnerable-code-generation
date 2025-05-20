//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1) // Ensuring there's no padding in structures
typedef struct {
    char riff[4]; // "RIFF"
    uint32_t overall_size;
    char wave[4]; // "WAVE"
    char fmt[4]; // "fmt "
    uint32_t length_of_fmt;
    uint16_t format_type;
    uint16_t channels;
    uint32_t sample_rate;
    uint32_t byterate;
    uint16_t block_align;
    uint16_t bits_per_sample;
} WavHeader;
#pragma pack(pop)

void apply_amplification(int16_t* buffer, size_t num_samples, float amplification_factor) {
    for (size_t i = 0; i < num_samples; i++) {
        int32_t sample = (int32_t)buffer[i] * amplification_factor;
        if (sample > INT16_MAX) sample = INT16_MAX;
        if (sample < INT16_MIN) sample = INT16_MIN;
        buffer[i] = (int16_t)sample;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <amplification_factor>\n", argv[0]);
        return 1;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];
    float amplification_factor = atof(argv[3]);

    FILE *input_file = fopen(input_filename, "rb");
    if (!input_file) {
        perror("Failed to open input file");
        return 1;
    }

    WavHeader header;
    fread(&header, sizeof(WavHeader), 1, input_file);
    if (strncmp(header.riff, "RIFF", 4) || strncmp(header.wave, "WAVE", 4)) {
        fprintf(stderr, "Not a valid WAV file\n");
        fclose(input_file);
        return 1;
    }

    size_t num_samples = (header.overall_size - sizeof(WavHeader)) / (header.bits_per_sample / 8);
    size_t data_size = num_samples * (header.bits_per_sample / 8);

    int16_t *buffer = (int16_t*)malloc(data_size);
    if (!buffer) {
        perror("Failed to allocate memory for audio buffer");
        fclose(input_file);
        return 1;
    }

    fseek(input_file, sizeof(WavHeader), SEEK_SET);
    fread(buffer, data_size, 1, input_file);
    fclose(input_file);

    apply_amplification(buffer, num_samples, amplification_factor);

    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        perror("Failed to open output file");
        free(buffer);
        return 1;
    }

    fwrite(&header, sizeof(WavHeader), 1, output_file);
    fwrite(buffer, data_size, 1, output_file);
    fclose(output_file);
    free(buffer);

    printf("Processed audio saved to %s with amplification factor %.2f\n", output_filename, amplification_factor);
    return 0;
}