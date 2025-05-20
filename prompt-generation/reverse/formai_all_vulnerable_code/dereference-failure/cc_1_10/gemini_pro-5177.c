//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom compression algorithm
unsigned char *compress(unsigned char *input, int input_size, int *output_size) {
    // Initialize output buffer
    unsigned char *output = malloc(input_size);
    *output_size = 0;

    // Initialize compression state
    int count = 1;
    unsigned char prev_byte = input[0];

    for (int i = 1; i < input_size; i++) {
        // Check if current byte is the same as previous byte
        if (input[i] == prev_byte) {
            count++;
        } else {
            // Write out count and byte
            output[*output_size] = count;
            (*output_size)++;
            output[*output_size] = prev_byte;
            (*output_size)++;

            // Reset count and update previous byte
            count = 1;
            prev_byte = input[i];
        }
    }

    // Write out final count and byte
    output[*output_size] = count;
    (*output_size)++;
    output[*output_size] = prev_byte;
    (*output_size)++;

    return output;
}

// Custom decompression algorithm
unsigned char *decompress(unsigned char *input, int input_size, int *output_size) {
    // Initialize output buffer
    unsigned char *output = malloc(input_size * 2);
    *output_size = 0;

    // Initialize decompression state
    int count = 0;
    unsigned char prev_byte = 0;

    for (int i = 0; i < input_size; i++) {
        // Read count and byte
        count = input[i];
        prev_byte = input[i + 1];
        i++;

        // Write out repeated bytes
        for (int j = 0; j < count; j++) {
            output[*output_size] = prev_byte;
            (*output_size)++;
        }
    }

    return output;
}

int main() {
    // Test data
    unsigned char input[] = "AAABBBCCCDDEEEE";
    int input_size = strlen(input);

    // Compress data
    int output_size;
    unsigned char *output = compress(input, input_size, &output_size);

    // Print compressed data
    printf("Compressed data:\n");
    for (int i = 0; i < output_size; i++) {
        printf("%02X ", output[i]);
    }
    printf("\n");

    // Decompress data
    unsigned char *decompressed = decompress(output, output_size, &output_size);

    // Print decompressed data
    printf("Decompressed data:\n");
    for (int i = 0; i < output_size; i++) {
        printf("%c", decompressed[i]);
    }
    printf("\n");

    // Free allocated memory
    free(output);
    free(decompressed);

    return 0;
}