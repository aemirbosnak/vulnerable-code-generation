//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define WAV_HEADER_SIZE 44
#define AMPLIFICATION_FACTOR 2.0

void print_wav_header(const uint8_t *header) {
    printf("WAV Header Information:\n");
    printf("  RIFF Chunk ID: %.4s\n", header + 0);
    printf("  File Size: %u\n", *(uint32_t *)(header + 4));
    printf("  RIFF Type: %.4s\n", header + 8);
    printf("  Format: %.4s\n", header + 20);
    printf("  Number of Channels: %u\n", *(uint16_t *)(header + 22));
    printf("  Sample Rate: %u\n", *(uint32_t *)(header + 24));
    printf("  Byte Rate: %u\n", *(uint32_t *)(header + 28));
    printf("  Block Align: %u\n", *(uint16_t *)(header + 32));
    printf("  Bits per Sample: %u\n", *(uint16_t *)(header + 34));
}

void amplify_audio(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "rb");
    if (!input_file) {
        fprintf(stderr, "Error opening input file.\n");
        exit(EXIT_FAILURE);
    }

    uint8_t wav_header[WAV_HEADER_SIZE];
    fread(wav_header, sizeof(uint8_t), WAV_HEADER_SIZE, input_file);
    print_wav_header(wav_header);

    uint16_t num_channels = *(uint16_t *)(wav_header + 22);
    uint32_t sample_rate = *(uint32_t *)(wav_header + 24);
    uint16_t bits_per_sample = *(uint16_t *)(wav_header + 34);
    size_t sample_size = bits_per_sample / 8;
    size_t data_size = *(uint32_t *)(wav_header + 40);
    size_t total_samples = data_size / sample_size;

    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        fprintf(stderr, "Error opening output file.\n");
        fclose(input_file);
        exit(EXIT_FAILURE);
    }

    fwrite(wav_header, sizeof(uint8_t), WAV_HEADER_SIZE, output_file);

    int16_t *buffer = malloc(sample_size * total_samples);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed.\n");
        fclose(input_file);
        fclose(output_file);
        exit(EXIT_FAILURE);
    }

    fread(buffer, sample_size, total_samples, input_file);

    for (size_t i = 0; i < total_samples; i++) {
        int32_t amplified_sample = buffer[i] * AMPLIFICATION_FACTOR;

        // Clipping the value to avoid overflow
        if (amplified_sample > INT16_MAX) {
            buffer[i] = INT16_MAX;
        } else if (amplified_sample < INT16_MIN) {
            buffer[i] = INT16_MIN;
        } else {
            buffer[i] = (int16_t)amplified_sample;
        }
    }

    fwrite(buffer, sample_size, total_samples, output_file);

    free(buffer);
    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav>\n", argv[0]);
        return EXIT_FAILURE;
    }

    amplify_audio(argv[1], argv[2]);

    printf("Audio amplification complete. Output written to %s\n", argv[2]);
    return EXIT_SUCCESS;
}