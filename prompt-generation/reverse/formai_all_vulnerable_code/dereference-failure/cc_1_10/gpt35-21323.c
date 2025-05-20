//FormAI DATASET v1.0 Category: Compression algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define the maximum length of a run
#define MAX_RUN_LENGTH 255

// A struct to represent a run
struct run {
    unsigned char value;  // The value of the run
    unsigned char length; // The length of the run (max 255)
};

// A function to compress an array of bytes using run-length encoding
void compress(unsigned char *input, int input_size, unsigned char **output, int *output_size) {
    // Allocate memory for the output buffer (should be less than or equal to the input size)
    *output = malloc(input_size * sizeof(unsigned char));
    *output_size = 0;

    // Iterate over the input buffer, finding runs and encoding them
    int i = 0;
    while (i < input_size) {
        // Find the length of the current run
        int j = i + 1;
        while (j < input_size && input[j] == input[i] && j - i <= MAX_RUN_LENGTH) {
            j++;
        }

        // Create a run struct and add it to the output buffer
        struct run current_run = {input[i], j - i};
        (*output)[(*output_size)++] = current_run.value;
        (*output)[(*output_size)++] = current_run.length;

        // Move to the next segment of the input buffer
        i = j;
    }
}

// A function to decompress an array of bytes that was compressed using run-length encoding
void decompress(unsigned char *input, int input_size, unsigned char **output, int *output_size) {
    // Allocate memory for the output buffer (should be larger than the input size)
    *output = malloc(input_size * MAX_RUN_LENGTH * sizeof(unsigned char));
    *output_size = 0;

    // Iterate over the input buffer, decoding runs and adding them to the output buffer
    int i = 0;
    while (i < input_size) {
        struct run current_run = {input[i++], input[i++]};
        for (int j = 0; j < current_run.length; j++) {
            (*output)[(*output_size)++] = current_run.value;
        }
    }
}

// A helper function to print out a buffer in hex format
void print_hex(unsigned char *buffer, int buffer_size) {
    for (int i = 0; i < buffer_size; i++) {
        printf("%02X ", buffer[i]);
    }
    printf("\n");
}

// Test the compression and decompression algorithms
int main() {
    // Create an input buffer with a simple pattern
    unsigned char input[] = {1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1};
    int input_size = sizeof(input) / sizeof(input[0]);

    // Compress the input buffer
    unsigned char *compressed_output;
    int compressed_output_size;
    compress(input, input_size, &compressed_output, &compressed_output_size);

    // Print the compressed output in hex format
    printf("Compressed output:\n");
    print_hex(compressed_output, compressed_output_size);

    // Decompress the compressed output
    unsigned char *decompressed_output;
    int decompressed_output_size;
    decompress(compressed_output, compressed_output_size, &decompressed_output, &decompressed_output_size);

    // Print the decompressed output in hex format
    printf("Decompressed output:\n");
    print_hex(decompressed_output, decompressed_output_size);

    // Check that the decompressed output matches the original input buffer
    int success = (input_size == decompressed_output_size) && (memcmp(input, decompressed_output, input_size) == 0);
    printf("Test %s\n", success ? "succeeded" : "failed");

    // Free memory allocated for buffers
    free(compressed_output);
    free(decompressed_output);

    return 0;
}