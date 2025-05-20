//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    char riff[4];
    uint32_t overall_size;
    char wave[4];
    char fmt[4];
    uint32_t fmt_size;
    uint16_t audio_format;
    uint16_t num_channels;
    uint32_t sample_rate;
    uint32_t byte_rate;
    uint16_t block_align;
    uint16_t bits_per_sample;
} WAVHeader;
#pragma pack(pop)

void print_usage() {
    printf("Usage: audio_processor <input.wav> <output.wav> <gain>\n");
}

WAVHeader* load_wav_header(FILE *file) {
    WAVHeader *header = (WAVHeader *)malloc(sizeof(WAVHeader));
    fread(header, sizeof(WAVHeader), 1, file);
    return header;
}

void process_audio_samples(FILE *input, FILE *output, WAVHeader *header, float gain) {
    int samples_count = header->overall_size / (header->bits_per_sample / 8);
    int16_t *buffer = (int16_t *)malloc(samples_count * sizeof(int16_t));
    
    fread(buffer, sizeof(int16_t), samples_count, input);

    for (int i = 0; i < samples_count; i++) {
        float sample = (float)buffer[i] * gain;
        if (sample > INT16_MAX) sample = INT16_MAX;
        if (sample < INT16_MIN) sample = INT16_MIN;
        buffer[i] = (int16_t)sample;
    }

    fwrite(buffer, sizeof(int16_t), samples_count, output);
    free(buffer);
}

void free_wav_header(WAVHeader *header) {
    free(header);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage();
        return 1;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];
    float gain = atof(argv[3]);

    FILE *input = fopen(input_filename, "rb");
    if (!input) {
        fprintf(stderr, "Could not open input file %s\n", input_filename);
        return 1;
    }

    FILE *output = fopen(output_filename, "wb");
    if (!output) {
        fprintf(stderr, "Could not open output file %s\n", output_filename);
        fclose(input);
        return 1;
    }

    WAVHeader *header = load_wav_header(input);
    if (header->audio_format != 1) {
        fprintf(stderr, "Unsupported audio format. Only PCM is supported.\n");
        free_wav_header(header);
        fclose(input);
        fclose(output);
        return 1;
    }

    process_audio_samples(input, output, header, gain);

    free_wav_header(header);
    fclose(input);
    fclose(output);
    printf("Audio processing completed. Output written to %s\n", output_filename);
    return 0;
}