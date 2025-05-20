//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: calm
// A Simple Compression Algorithm in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input data
#define MAX_INPUT_SIZE 1024

// Define the maximum size of the compressed data
#define MAX_COMPRESSED_SIZE (MAX_INPUT_SIZE + (MAX_INPUT_SIZE / 10))

// Define the compression ratio
#define COMPRESSION_RATIO 0.9

// Compress the input data
int compress(const char *input, char *output) {
    int input_size = strlen(input);
    int output_size = 0;

    // Initialize the output buffer
    memset(output, 0, MAX_COMPRESSED_SIZE);

    // Iterate over the input data
    for (int i = 0; i < input_size; i++) {
        // Get the current character and its frequency
        char character = input[i];
        int frequency = 1;
        while (i + 1 < input_size && input[i + 1] == character) {
            frequency++;
            i++;
        }

        // Encode the character and its frequency
        output[output_size++] = character;
        output[output_size++] = frequency;
    }

    // Return the size of the compressed data
    return output_size;
}

// Decompress the compressed data
int decompress(const char *input, char *output) {
    int input_size = strlen(input);
    int output_size = 0;

    // Initialize the output buffer
    memset(output, 0, MAX_INPUT_SIZE);

    // Iterate over the compressed data
    for (int i = 0; i < input_size; i += 2) {
        // Get the character and its frequency
        char character = input[i];
        int frequency = input[i + 1];

        // Repeat the character frequency times
        for (int j = 0; j < frequency; j++) {
            output[output_size++] = character;
        }
    }

    // Return the size of the decompressed data
    return output_size;
}

// Print the usage information
void usage() {
    printf("Usage: compress <input_file> <output_file>\n");
    printf("       decompress <input_file> <output_file>\n");
}

// Main function
int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 4) {
        usage();
        return 1;
    }

    // Get the input and output file names
    char *input_file = argv[2];
    char *output_file = argv[3];

    // Open the input file
    FILE *input = fopen(input_file, "r");
    if (input == NULL) {
        perror("Error opening the input file");
        return 1;
    }

    // Open the output file
    FILE *output = fopen(output_file, "w");
    if (output == NULL) {
        perror("Error opening the output file");
        return 1;
    }

    // Get the input data size
    fseek(input, 0, SEEK_END);
    int input_size = ftell(input);
    rewind(input);

    // Allocate memory for the input and output data
    char *input_data = malloc(input_size);
    char *output_data = malloc(MAX_COMPRESSED_SIZE);

    // Read the input data
    fread(input_data, 1, input_size, input);

    // Compress the input data
    int compressed_size = compress(input_data, output_data);

    // Write the compressed data to the output file
    fwrite(output_data, 1, compressed_size, output);

    // Close the input and output files
    fclose(input);
    fclose(output);

    // Free the allocated memory
    free(input_data);
    free(output_data);

    // Print the compression ratio
    printf("Compression ratio: %f\n", (float)compressed_size / (float)input_size);

    return 0;
}