//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define BUFFER_SIZE 4096

typedef struct {
    char riff[4];         // "RIFF"
    uint32_t overall_size; // file size - 8
    char wave[4];        // "WAVE"
    char fmt[4];         // "fmt "
    uint32_t fmt_length; // length of format data
    uint16_t format_type; // format type
    uint16_t channels;    // number of channels
    uint32_t sample_rate; // sample rate
    uint32_t byte_rate;   // byte rate
    uint16_t block_align; // block align
    uint16_t bits_per_sample; // bits per sample
    char data[4];         // "data"
    uint32_t data_size;   // data size
} WavHeader;

void adjust_volume(int16_t *buffer, size_t size, float volume_factor) {
    for (size_t i = 0; i < size; i++) {
        int32_t sample = (int32_t)(buffer[i] * volume_factor);
        if (sample > INT16_MAX) {
            buffer[i] = INT16_MAX;
        } else if (sample < INT16_MIN) {
            buffer[i] = INT16_MIN;
        } else {
            buffer[i] = (int16_t)sample;
        }
    }
}

void process_audio(const char *input_filename, const char *output_filename, float volume_factor) {
    FILE *input_file = fopen(input_filename, "rb");
    if (!input_file) {
        fprintf(stderr, "Could not open input file %s\n", input_filename);
        return;
    }
    
    WavHeader header;
    fread(&header, sizeof(WavHeader), 1, input_file);
    
    if (strncmp(header.riff, "RIFF", 4) != 0 || strncmp(header.wave, "WAVE", 4) != 0) {
        fprintf(stderr, "Not a valid WAV file\n");
        fclose(input_file);
        return;
    }

    size_t num_samples = header.data_size / sizeof(int16_t);
    int16_t *buffer = malloc(num_samples * sizeof(int16_t));

    fread(buffer, sizeof(int16_t), num_samples, input_file);
    fclose(input_file);
    
    adjust_volume(buffer, num_samples, volume_factor);
    
    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        fprintf(stderr, "Could not open output file %s\n", output_filename);
        free(buffer);
        return;
    }
    
    fwrite(&header, sizeof(WavHeader), 1, output_file);
    fwrite(buffer, sizeof(int16_t), num_samples, output_file);
    fclose(output_file);
    free(buffer);

    printf("Processed audio saved to %s\n", output_filename);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <volume_factor>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];
    float volume_factor = atof(argv[3]);

    process_audio(input_filename, output_filename, volume_factor);

    return EXIT_SUCCESS;
}