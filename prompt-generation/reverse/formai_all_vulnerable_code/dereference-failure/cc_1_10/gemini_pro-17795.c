//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input and output buffers
#define MAX_BUFFER_SIZE 1024

// Define the compression and decompression functions
int compress(char *input, char *output);
int decompress(char *input, char *output);

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has provided enough arguments
    if (argc < 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the input and output files
    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }
    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        perror("Error opening output file");
        return EXIT_FAILURE;
    }

    // Read the input file into a buffer
    char input_buffer[MAX_BUFFER_SIZE];
    size_t input_size = fread(input_buffer, 1, MAX_BUFFER_SIZE, input_file);

    // Compress the input buffer
    char output_buffer[MAX_BUFFER_SIZE];
    size_t output_size = compress(input_buffer, output_buffer);

    // Write the compressed output to the output file
    fwrite(output_buffer, 1, output_size, output_file);

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    return EXIT_SUCCESS;
}

// Compression function
int compress(char *input, char *output) {
    // Initialize the output buffer
    size_t output_index = 0;

    // Iterate over the input buffer
    for (size_t i = 0; i < strlen(input); i++) {
        // Get the current character and its frequency
        char character = input[i];
        size_t frequency = 1;
        while (i + 1 < strlen(input) && input[i + 1] == character) {
            frequency++;
            i++;
        }

        // Encode the character and frequency to the output buffer
        output[output_index++] = character;
        output[output_index++] = frequency;
    }

    // Return the size of the compressed output
    return output_index;
}

// Decompression function
int decompress(char *input, char *output) {
    // Initialize the output buffer
    size_t output_index = 0;

    // Iterate over the input buffer
    for (size_t i = 0; i < strlen(input); i += 2) {
        // Get the current character and its frequency
        char character = input[i];
        size_t frequency = input[i + 1];

        // Repeat the character in the output buffer according to its frequency
        for (size_t j = 0; j < frequency; j++) {
            output[output_index++] = character;
        }
    }

    // Return the size of the decompressed output
    return output_index;
}