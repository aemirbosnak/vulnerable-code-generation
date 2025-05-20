//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BUFFER_SIZE 4096 // Size of audio buffer

// Function prototypes
void apply_gain(int16_t *buffer, size_t samples, float gain);
void process_audio_file(const char *input_file, const char *output_file, float gain);

// Main function
int main(int argc, char *argv[]) {
    // Check for correct arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <gain>\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    float gain = atof(argv[3]);

    // Process the audio file
    process_audio_file(input_file, output_file, gain);
    
    return 0;
}

// Function to apply gain to audio buffer
void apply_gain(int16_t *buffer, size_t samples, float gain) {
    for (size_t i = 0; i < samples; i++) {
        int32_t temp = (int32_t)buffer[i] * gain;

        // Handle clipping
        if (temp > INT16_MAX) {
            buffer[i] = INT16_MAX;
        } else if (temp < INT16_MIN) {
            buffer[i] = INT16_MIN;
        } else {
            buffer[i] = (int16_t)temp;
        }
    }
}

// Function to process the audio file
void process_audio_file(const char *input_file, const char *output_file, float gain) {
    FILE *input_fp = fopen(input_file, "rb");
    FILE *output_fp = fopen(output_file, "wb");

    if (!input_fp) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    if (!output_fp) {
        perror("Error opening output file");
        fclose(input_fp);
        exit(EXIT_FAILURE);
    }

    int16_t buffer[BUFFER_SIZE];
    size_t samples_read;

    // Read the audio in chunks
    while ((samples_read = fread(buffer, sizeof(int16_t), BUFFER_SIZE, input_fp)) > 0) {
        // Apply gain to the buffer
        apply_gain(buffer, samples_read, gain);
        // Write the processed samples to the output file
        fwrite(buffer, sizeof(int16_t), samples_read, output_fp);
    }

    // Cleanup
    fclose(input_fp);
    fclose(output_fp);
    printf("Audio processing complete. Output saved to %s\n", output_file);
}