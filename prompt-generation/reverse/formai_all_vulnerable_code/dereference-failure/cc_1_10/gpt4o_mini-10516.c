//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(1) // Ensures that the structure is packed without padding

typedef struct {
    char riff[4];           // RIFF Header
    uint32_t overall_size;  // File size
    char wave[4];          // WAVE Header
    char fmt[4];           // FMT Header
    uint32_t fmt_size;     // Size of the fmt
    uint16_t format_type;  // Format type
    uint16_t channels;     // Number of channels
    uint32_t sample_rate;  // Sampling Rate
    uint32_t byte_rate;    // Bytes per second
    uint16_t block_align;  // 2=.channels * 16/8
    uint16_t bits_per_sample; // Bits per sample
    char data[4];          // DATA Header
    uint32_t data_size;    // Size of the data
} WAVHeader;

void adjust_volume(uint8_t *buffer, uint32_t data_size, float volume) {
    for (uint32_t i = 0; i < data_size; i++) {
        int16_t sample = *(int16_t*)(buffer + i);
        sample = (int16_t)(sample * volume); // Apply volume adjustment
        if (sample > 32767) sample = 32767;   // Clamp to max int16
        if (sample < -32768) sample = -32768; // Clamp to min int16
        *(int16_t*)(buffer + i) = sample;
        i += 1; // Move to next sample
    }
}

WAVHeader read_wav_header(FILE *file) {
    WAVHeader header;
    if (fread(&header, sizeof(WAVHeader), 1, file) != 1) {
        fprintf(stderr, "Error reading WAV header.\n");
        exit(EXIT_FAILURE);
    }
    return header;
}

void write_wav_header(FILE *file, WAVHeader *header) {
    if (fwrite(header, sizeof(WAVHeader), 1, file) != 1) {
        fprintf(stderr, "Error writing WAV header.\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <volume_factor>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    float volume_factor = strtof(argv[3], NULL);
    if (volume_factor < 0 || volume_factor > 2) {
        fprintf(stderr, "Volume factor must be in range [0.0, 2.0]\n");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    WAVHeader header = read_wav_header(input_file);

    if (strncmp(header.riff, "RIFF", 4) != 0 || strncmp(header.wave, "WAVE", 4) != 0) {
        fprintf(stderr, "Invalid WAV file format.\n");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    uint8_t *buffer = (uint8_t *)malloc(header.data_size);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed.\n");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    if (fread(buffer, sizeof(uint8_t), header.data_size, input_file) != header.data_size) {
        fprintf(stderr, "Error reading audio data.\n");
        free(buffer);
        fclose(input_file);
        return EXIT_FAILURE;
    }
    fclose(input_file);

    adjust_volume(buffer, header.data_size, volume_factor);

    FILE *output_file = fopen(argv[2], "wb");
    if (!output_file) {
        perror("Error opening output file");
        free(buffer);
        return EXIT_FAILURE;
    }

    write_wav_header(output_file, &header);
    if (fwrite(buffer, sizeof(uint8_t), header.data_size, output_file) != header.data_size) {
        fprintf(stderr, "Error writing audio data.\n");
        free(buffer);
        fclose(output_file);
        return EXIT_FAILURE;
    }

    free(buffer);
    fclose(output_file);

    printf("Successfully processed audio. Volume adjusted by factor of %.2f\n", volume_factor);
    return EXIT_SUCCESS;
}