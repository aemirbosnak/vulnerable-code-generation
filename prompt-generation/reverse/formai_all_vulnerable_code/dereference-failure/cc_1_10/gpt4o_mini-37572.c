//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#pragma pack(1) // To avoid padding issues

// WAV header structure
typedef struct {
    char riff[4]; // "RIFF"
    uint32_t overall_size; // Size of the file in bytes
    char wave[4]; // "WAVE"
    char fmt[4]; // "fmt "
    uint32_t size_of_fmt; // Size of fmt data
    uint16_t audio_format; // Audio format (1 for PCM)
    uint16_t num_channels; // Number of channels
    uint32_t sample_rate; // Sampling frequency (samples per second)
    uint32_t byte_rate; // Number of bytes per second
    uint16_t block_align; // Number of bytes per sample
    uint16_t bits_per_sample; // Number of bits per sample
    char data[4]; // "data"
    uint32_t data_size; // Size of the data section
} WAVHeader;

void increase_volume(int16_t *buffer, size_t samples, float volume_factor) {
    for (size_t i = 0; i < samples; i++) {
        int32_t temp = (int32_t)(buffer[i] * volume_factor);
        if (temp > INT16_MAX) {
            buffer[i] = INT16_MAX; // Cap to max value
        } else if (temp < INT16_MIN) {
            buffer[i] = INT16_MIN; // Cap to min value
        } else {
            buffer[i] = (int16_t)temp;
        }
    }
}

bool process_wav_file(const char *input_file, const char *output_file, float volume_factor) {
    FILE *input = fopen(input_file, "rb");
    if (!input) {
        printf("Could not open input file: %s\n", input_file);
        return false;
    }

    WAVHeader header;
    fread(&header, sizeof(WAVHeader), 1, input);
    
    // Check if it's a valid WAV file
    if (header.audio_format != 1) {
        printf("Unsupported audio format!\n");
        fclose(input);
        return false;
    }

    size_t samples = header.data_size / sizeof(int16_t);
    int16_t *buffer = malloc(header.data_size);
    fread(buffer, sizeof(int16_t), samples, input);
    fclose(input);

    increase_volume(buffer, samples, volume_factor);

    FILE *output = fopen(output_file, "wb");
    if (!output) {
        printf("Could not open output file: %s\n", output_file);
        free(buffer);
        return false;
    }

    fwrite(&header, sizeof(WAVHeader), 1, output);
    fwrite(buffer, sizeof(int16_t), samples, output);
    
    printf("Successfully processed the audio!\n");
    free(buffer);
    fclose(output);
    
    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input.wav> <output.wav> <volume_factor>\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    float volume_factor = atof(argv[3]);

    if (volume_factor < 0.0f || volume_factor > 3.0f) {
        printf("Volume factor should be between 0.0 and 3.0!\n");
        return 1;
    }

    if (process_wav_file(input_file, output_file, volume_factor)) {
        printf("Yay! Audio processing completed successfully! 🎉\n");
    } else {
        printf("Oops! Something went wrong! 🚫\n");
    }

    return 0;
}