//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(1)
typedef struct {
    char chunkID[4];        // "RIFF"
    uint32_t chunkSize;
    char format[4];         // "WAVE"
    char subchunk1ID[4];    // "fmt "
    uint32_t subchunk1Size;
    uint16_t audioFormat;    // PCM = 1
    uint16_t numChannels;     // Mono = 1, Stereo = 2
    uint32_t sampleRate;      // Sample Rate
    uint32_t byteRate;        // (Sample Rate * numChannels * bitsPerSample/8)
    uint16_t blockAlign;      // (numChannels * bitsPerSample/8)
    uint16_t bitsPerSample;   // bits per sample (e.g., 16 bits)
    char subchunk2ID[4];      // "data"
    uint32_t subchunk2Size;   // Sample data length
} WavHeader;

void apply_gain(int16_t *data, size_t num_samples, float gain) {
    for (size_t i = 0; i < num_samples; i++) {
        int32_t sample = data[i] * gain;
        // Clipping
        if (sample > INT16_MAX) {
            data[i] = INT16_MAX;
        } else if (sample < INT16_MIN) {
            data[i] = INT16_MIN;
        } else {
            data[i] = (int16_t)sample;
        }
    }
}

void process_wav(const char *input_filename, const char *output_filename, float gain) {
    FILE *input_file = fopen(input_filename, "rb");
    if (!input_file) {
        fprintf(stderr, "Error opening input file.\n");
        return;
    }

    WavHeader header;
    fread(&header, sizeof(header), 1, input_file);
    
    // Check if it's a valid WAV file
    if (strncmp(header.chunkID, "RIFF", 4) != 0 || strncmp(header.format, "WAVE", 4) != 0) {
        fprintf(stderr, "Not a valid WAV file.\n");
        fclose(input_file);
        return;
    }

    size_t num_samples = header.subchunk2Size / (header.bitsPerSample / 8);
    int16_t *data = malloc(header.subchunk2Size);
    if (!data) {
        fprintf(stderr, "Memory allocation failed.\n");
        fclose(input_file);
        return;
    }

    fread(data, header.subchunk2Size, 1, input_file);
    fclose(input_file);

    // Apply gain to the audio data
    apply_gain(data, num_samples, gain);

    // Write the processed data to a new WAV file
    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        fprintf(stderr, "Error opening output file.\n");
        free(data);
        return;
    }

    fwrite(&header, sizeof(header), 1, output_file);
    fwrite(data, header.subchunk2Size, 1, output_file);
    fclose(output_file);
    free(data);

    printf("Processing completed. Output saved to %s\n", output_filename);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <gain>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];
    float gain = atof(argv[3]);

    process_wav(input_filename, output_filename, gain);

    return EXIT_SUCCESS;
}