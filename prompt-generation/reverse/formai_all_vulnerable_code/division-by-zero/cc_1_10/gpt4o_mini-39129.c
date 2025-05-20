//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define BUFFER_SIZE 4096
#define VOLUME_FACTOR 1.5

// WAV file header structure
#pragma pack(push, 1)
typedef struct {
    char riff[4];               // RIFF Header
    uint32_t overall_size;      // Overall size of file in bytes
    char wave[4];               // WAVE Header
    char fmt[4];                // FMT Header
    uint32_t fmt_length;        // Length of the format data
    uint16_t format_type;       // Format type (1 for PCM)
    uint16_t channels;          // Number of channels
    uint32_t sample_rate;       // Sampling Frequency in Hz
    uint32_t byte_rate;         // Bytes per second
    uint16_t block_align;       // 2-Byte block
    uint16_t bits_per_sample;   // Number of bits per sample
    char data[4];               // DATA Header
    uint32_t data_size;         // Size of the data section
} WAVHeader;
#pragma pack(pop)

void print_usage(const char *program_name) {
    printf("Usage: %s <input.wav> <output.wav>\n", program_name);
}

void adjust_volume(const char *input_file, const char *output_file) {
    FILE *in_fp = fopen(input_file, "rb");
    if (!in_fp) {
        perror("Could not open input file");
        return;
    }

    WAVHeader header;
    fread(&header, sizeof(WAVHeader), 1, in_fp);

    if (strncmp(header.riff, "RIFF", 4) != 0 || strncmp(header.wave, "WAVE", 4) != 0) {
        printf("Not a valid WAV file.\n");
        fclose(in_fp);
        return;
    }

    FILE *out_fp = fopen(output_file, "wb");
    if (!out_fp) {
        perror("Could not open output file");
        fclose(in_fp);
        return;
    }

    // Write the WAV header to the output file
    fwrite(&header, sizeof(WAVHeader), 1, out_fp);

    size_t sample_size = header.bits_per_sample / 8;
    int16_t buffer[BUFFER_SIZE / 2];  // Buffer for stereo audio
    size_t read_samples;

    while ((read_samples = fread(buffer, sample_size, BUFFER_SIZE / sample_size, in_fp)) > 0) {
        for (size_t i = 0; i < read_samples; ++i) {
            int32_t sample = (int32_t)(buffer[i] * VOLUME_FACTOR);
            // Clamp the value to the range of int16_t
            if (sample > INT16_MAX) {
                sample = INT16_MAX;
            } else if (sample < INT16_MIN) {
                sample = INT16_MIN;
            }
            buffer[i] = (int16_t)sample;
        }
        fwrite(buffer, sample_size, read_samples, out_fp);
    }

    fclose(in_fp);
    fclose(out_fp);
    printf("Volume adjusted and saved to %s\n", output_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    adjust_volume(argv[1], argv[2]);
    return EXIT_SUCCESS;
}