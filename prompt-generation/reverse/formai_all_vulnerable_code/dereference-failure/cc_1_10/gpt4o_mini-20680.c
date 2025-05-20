//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(1)
typedef struct {
    char riff[4];          // RIFF Header
    uint32_t overall_size; // Overall size of file in bytes
    char wave[4];         // WAVE Header
    char fmt[4];          // FMT header
    uint32_t length_hip;  // length of format data
    uint16_t format_type; // format type
    uint16_t channels;     // channels
    uint32_t sample_rate; // sampling rate
    uint32_t byte_rate;   // bytes per second
    uint16_t block_align; // 2=16bit mono, 4=16bit stereo
    uint16_t bits_per_sample; // bits per sample
    char data[4];         // DATA header
    uint32_t data_size;   // data size
} WavHeader;

void apply_gain(int16_t *samples, size_t num_samples, float gain) {
    for (size_t i = 0; i < num_samples; i++) {
        int32_t temp = (int32_t)samples[i] * gain;
        if (temp > INT16_MAX) {
            samples[i] = INT16_MAX;
        } else if (temp < INT16_MIN) {
            samples[i] = INT16_MIN;
        } else {
            samples[i] = (int16_t)temp;
        }
    }
}

void low_pass_filter(int16_t *samples, size_t num_samples, float alpha) {
    int16_t prev_sample = samples[0];
    for (size_t i = 1; i < num_samples; i++) {
        samples[i] = (int16_t)(alpha * samples[i] + (1 - alpha) * prev_sample);
        prev_sample = samples[i];
    }
}

void process_audio(const char *input_file, const char *output_file, float gain, float alpha) {
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    WavHeader header;
    fread(&header, sizeof(WavHeader), 1, input);
    
    size_t num_samples = header.data_size / sizeof(int16_t);
    int16_t *samples = malloc(header.data_size);
    fread(samples, sizeof(int16_t), num_samples, input);
    fclose(input);

    apply_gain(samples, num_samples, gain);
    low_pass_filter(samples, num_samples, alpha);

    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        perror("Error opening output file");
        free(samples);
        exit(EXIT_FAILURE);
    }

    fwrite(&header, sizeof(WavHeader), 1, output);
    fwrite(samples, sizeof(int16_t), num_samples, output);
    fclose(output);

    free(samples);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <input_file.wav> <output_file.wav> <gain> <alpha>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    float gain = atof(argv[3]);
    float alpha = atof(argv[4]);

    if(gain < 0 || gain > 2) {
        fprintf(stderr, "Gain must be between 0 and 2.\n");
        return EXIT_FAILURE;
    }

    if(alpha < 0 || alpha > 1) {
        fprintf(stderr, "Alpha must be between 0 and 1.\n");
        return EXIT_FAILURE;
    }

    process_audio(input_file, output_file, gain, alpha);

    printf("Processed audio file saved as: %s\n", output_file);
    return EXIT_SUCCESS;
}