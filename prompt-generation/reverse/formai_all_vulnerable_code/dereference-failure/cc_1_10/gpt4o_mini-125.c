//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define SAMPLE_RATE 44100     // Standard sample rate for audio
#define HEADER_SIZE 44        // Standard header size for WAV files

typedef struct {
    uint8_t riff[4];          // "RIFF" 
    uint32_t overall_size;    // Overall size of file in bytes
    uint8_t wave[4];          // "WAVE"
    uint8_t fmt[4];           // "fmt "
    uint32_t fmt_length;      // Length of the format data
    uint16_t format_type;     // Format type, 1 for PCM
    uint16_t channels;        // Number of channels
    uint32_t sample_rate;     // Sample rate
    uint32_t byte_rate;       // (Sample Rate * Block Align)
    uint16_t block_align;     // (Channels * BitsPerSample/8)
    uint16_t bits_per_sample; // Bits per sample
    uint8_t data[4];          // "data"
    uint32_t data_size;       // Size of the data section
} WAVHeader;

void adjust_amplitude(const char *input_file, const char *output_file, float factor) {
    FILE *input = fopen(input_file, "rb");
    if (!input) {
        perror("Error opening input file");
        exit(1);
    }

    WAVHeader header;
    fread(&header, sizeof(WAVHeader), 1, input);

    if (strncmp((char*)header.riff, "RIFF", 4) != 0 || 
        strncmp((char*)header.wave, "WAVE", 4) != 0) {
        fprintf(stderr, "Not a valid WAV file.\n");
        fclose(input);
        exit(1);
    }

    int16_t *buffer = malloc(header.data_size); 
    fread(buffer, header.data_size, 1, input);
    fclose(input);

    // Adjusting amplitude
    for (uint32_t i = 0; i < header.data_size / sizeof(int16_t); i++) {
        int32_t sample = (int32_t)(buffer[i] * factor);
        if (sample > INT16_MAX) {
            buffer[i] = INT16_MAX;
        } else if (sample < INT16_MIN) {
            buffer[i] = INT16_MIN;
        } else {
            buffer[i] = (int16_t)sample;
        }
    }

    FILE *output = fopen(output_file, "wb");
    if (!output) {
        perror("Error opening output file");
        free(buffer);
        exit(1);
    }

    fwrite(&header, sizeof(WAVHeader), 1, output);
    fwrite(buffer, header.data_size, 1, output);

    fclose(output);
    free(buffer);

    printf("Successfully adjusted amplitude by a factor of %.2f\n", factor);
}

void usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <input.wav> <output.wav> <amplitude_adjust_factor>\n", prog_name);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        usage(argv[0]);
    }

    float factor = atof(argv[3]);
    
    if (factor <= 0) {
        fprintf(stderr, "Amplitude adjust factor must be greater than zero.\n");
        exit(1);
    }

    adjust_amplitude(argv[1], argv[2], factor);
    return 0;
}