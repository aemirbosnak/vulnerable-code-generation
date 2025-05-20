//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#define MAX_AUDIO_DATA 1024
#define SAMPLERATE 44100
#define PI 3.1415926535

typedef struct {
    char riff[4];            // RIFF Header
    uint32_t overall_size;   // Overall size of file in bytes
    char wave[4];           // WAVE Header
    char fmt[4];            // FMT header
    uint32_t fmt_length;    // Length of the fmt data
    uint16_t format_type;    // Format type (1 is PCM)
    uint16_t channels;       // Number of channels
    uint32_t sample_rate;    // Sample Rate
    uint32_t bytes_per_second; // Bytes per second
    uint16_t block_align;    // Block alignment
    uint16_t bits_per_sample; // Bits per sample
    char data[4];           // DATA header
    uint32_t data_size;      // Size of the data
} WAVHeader;

void apply_low_pass_filter(int16_t *audio_data, size_t data_size, float cutoff_frequency) {
    float RC = 1.0 / (2 * PI * cutoff_frequency);
    float dt = 1.0 / SAMPLERATE;
    float alpha = dt / (RC + dt);
    int16_t previous_sample = audio_data[0];

    for (size_t i = 1; i < data_size; i++) {
        audio_data[i] = (int16_t)(previous_sample + (alpha * (audio_data[i] - previous_sample)));
        previous_sample = audio_data[i];
    }
}

void read_wav_file(const char *filename, WAVHeader *header, int16_t **audio_data, size_t *data_size) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open input file");
        exit(1);
    }

    fread(header, sizeof(WAVHeader), 1, file);
    *data_size = header->data_size / sizeof(int16_t);
    *audio_data = (int16_t *)malloc(header->data_size);
    fread(*audio_data, sizeof(int16_t), *data_size, file);
    fclose(file);
}

void write_wav_file(const char *filename, WAVHeader *header, int16_t *audio_data, size_t data_size) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Could not open output file");
        exit(1);
    }

    fwrite(header, sizeof(WAVHeader), 1, file);
    fwrite(audio_data, sizeof(int16_t), data_size, file);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input.wav> <output.wav> <cutoff_frequency>\n", argv[0]);
        return 1;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];
    float cutoff_frequency = atof(argv[3]);

    WAVHeader header;
    int16_t *audio_data;
    size_t data_size;

    read_wav_file(input_filename, &header, &audio_data, &data_size);
    apply_low_pass_filter(audio_data, data_size, cutoff_frequency);
    write_wav_file(output_filename, &header, audio_data, data_size);

    free(audio_data);
    printf("Processing complete! Filtered audio saved as %s\n", output_filename);
    return 0;
}