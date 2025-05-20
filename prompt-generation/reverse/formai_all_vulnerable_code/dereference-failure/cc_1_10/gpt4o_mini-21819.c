//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define SAMPLE_RATE 44100
#define MAX_DELAY 22050 // 0.5 seconds delay

typedef struct {
    char riff[4];
    uint32_t chunkSize;
    char wave[4];
    char fmt[4];
    uint32_t subChunk1Size;
    uint16_t audioFormat;
    uint16_t numChannels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
    char data[4];
    uint32_t dataSize;
} WavHeader;

// Recursive function to apply delay effect on audio samples
void apply_delay(int16_t *samples, int position, int delay_time, int current_delay) {
    if (position >= delay_time) {
        samples[position] += samples[position - current_delay];
    }
    
    if (position < delay_time + 1) {
        return; // Base case: Stop when we reach one past the end of delay
    }
    
    apply_delay(samples, position + 1, delay_time, current_delay); // Recursive call
}

void process_audio(const char *input_file, const char *output_file, int delay_time) {
    WavHeader header;
    FILE *input = fopen(input_file, "rb");
    if (!input) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }

    fread(&header, sizeof(WavHeader), 1, input);
    int16_t *samples = malloc(header.dataSize);
    fread(samples, sizeof(int16_t), header.dataSize / sizeof(int16_t), input);
    fclose(input);

    // Apply the delay effect
    apply_delay(samples, 0, delay_time, delay_time / 2); // Half the delay time as the delay duration

    FILE *output = fopen(output_file, "wb");
    if (!output) {
        perror("Failed to open output file");
        free(samples);
        exit(EXIT_FAILURE);
    }

    fwrite(&header, sizeof(WavHeader), 1, output);
    fwrite(samples, sizeof(int16_t), header.dataSize / sizeof(int16_t), output);
    
    fclose(output);
    free(samples);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <delay_ms>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    int delay_time = atoi(argv[3]) * SAMPLE_RATE / 1000; // Convert ms to samples

    if (delay_time < 0 || delay_time > MAX_DELAY) {
        fprintf(stderr, "Delay time must be between 0 and 500 ms.\n");
        return EXIT_FAILURE;
    }

    process_audio(input_file, output_file, delay_time);
    printf("Processed audio saved to %s with a delay of %d ms.\n", output_file, delay_time * 1000 / SAMPLE_RATE);
    return EXIT_SUCCESS;
}