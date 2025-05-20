//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    char riff[4];
    uint32_t overall_size;
    char wave[4];
    char fmt[4];
    uint32_t fmt_chunk_size;
    uint16_t audio_format;
    uint16_t num_channels;
    uint32_t sample_rate;
    uint32_t byte_rate;
    uint16_t block_align;
    uint16_t bits_per_sample;
} WavHeader;
#pragma pack(pop)

// Function to print header details
void print_header_info(WavHeader *header) {
    printf("WAV File Information:\n");
    printf("Audio Format: %d\n", header->audio_format);
    printf("Channels: %d\n", header->num_channels);
    printf("Sample Rate: %d\n", header->sample_rate);
    printf("Bit Depth: %d\n", header->bits_per_sample);
    printf("Overall Size: %d\n", header->overall_size);
    printf("\nLet's amplify the happiness!\n");
}

// Function to amplify the audio
void amplify_audio(int16_t *buffer, size_t size, float factor) {
    for (size_t i = 0; i < size; i++) {
        int32_t temp = (int32_t)(buffer[i] * factor); // Temporary to avoid overflow
        buffer[i] = (temp > INT16_MAX) ? INT16_MAX : (temp < INT16_MIN) ? INT16_MIN : (int16_t)temp;
    }
}

// Function to read a WAV file
WavHeader read_wav_file(const char *filename, int16_t **buffer, size_t *size) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open WAV file");
        exit(EXIT_FAILURE);
    }

    WavHeader header;
    fread(&header, sizeof(WavHeader), 1, file);

    // Check if WAV format
    if (header.audio_format != 1) {
        fprintf(stderr, "Unsupported audio format\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    *size = header.overall_size / sizeof(int16_t) - sizeof(WavHeader) / sizeof(int16_t);
    *buffer = malloc(*size * sizeof(int16_t));

    fseek(file, sizeof(WavHeader), SEEK_SET);
    fread(*buffer, sizeof(int16_t), *size, file);
    fclose(file);

    print_header_info(&header);
    return header;
}

// Function to write a WAV file
void write_wav_file(const char *filename, WavHeader *header, int16_t *buffer, size_t size) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Could not open WAV file");
        exit(EXIT_FAILURE);
    }

    fwrite(header, sizeof(WavHeader), 1, file);
    fwrite(buffer, sizeof(int16_t), size, file);
    fclose(file);
    printf("Successfully saved your happy audio to: %s\n", filename);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <volume_factor>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];
    float volume_factor = atof(argv[3]);

    // Reading the input WAV file
    int16_t *audio_buffer = NULL;
    size_t audio_size = 0;
    WavHeader header = read_wav_file(input_filename, &audio_buffer, &audio_size);

    // Amplifying audio
    printf("Amplifying the joy by a factor of %.2f!\n", volume_factor);
    amplify_audio(audio_buffer, audio_size, volume_factor);

    // Writing output WAV file
    write_wav_file(output_filename, &header, audio_buffer, audio_size);

    // Clean up and waving goodbye
    free(audio_buffer);
    printf("Happily finished processing the audio! 🎉\n");
    return EXIT_SUCCESS;
}