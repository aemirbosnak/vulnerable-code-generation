//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 1024

// Function to apply gain to a buffer of audio samples
void apply_gain(int16_t *buffer, size_t samples, float gain) {
    for (size_t i = 0; i < samples; i++) {
        int32_t temp = (int32_t)(buffer[i] * gain);
        buffer[i] = (int16_t)(temp > INT16_MAX ? INT16_MAX : (temp < INT16_MIN ? INT16_MIN : temp));
    }
}

// Function to process audio from input file and write to output file
int process_audio(const char* input_file, const char* output_file, float gain) {
    FILE *input = fopen(input_file, "rb");
    if (!input) {
        perror("Failed to open input file");
        return -1;
    }
    
    FILE *output = fopen(output_file, "wb");
    if (!output) {
        perror("Failed to open output file");
        fclose(input);
        return -1;
    }

    int16_t buffer[BUFFER_SIZE];
    size_t read_samples;

    while ((read_samples = fread(buffer, sizeof(int16_t), BUFFER_SIZE, input)) > 0) {
        apply_gain(buffer, read_samples, gain);
        fwrite(buffer, sizeof(int16_t), read_samples, output);
    }

    fclose(input);
    fclose(output);
    return 0;
}

// Main function to handle user input
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <gain>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    float gain = strtof(argv[3], NULL);

    if (errno == ERANGE) {
        fprintf(stderr, "Invalid gain value: %s\n", argv[3]);
        return EXIT_FAILURE;
    }

    if (gain < 0.0) {
        fprintf(stderr, "Gain must be a non-negative value.\n");
        return EXIT_FAILURE;
    }

    if (process_audio(input_file, output_file, gain) != 0) {
        return EXIT_FAILURE;
    }

    printf("Processing complete. Output saved to: %s\n", output_file);
    return EXIT_SUCCESS;
}