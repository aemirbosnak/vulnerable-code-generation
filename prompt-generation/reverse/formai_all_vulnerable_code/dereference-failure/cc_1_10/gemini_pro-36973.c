//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the compressed data
typedef struct {
    char *data;
    int size;
} compressed_data;

// Function to compress the data
compressed_data compress(char *data, int size) {
    // Create a new compressed data structure
    compressed_data compressed;

    // Allocate memory for the compressed data
    compressed.data = malloc(size);

    // Compress the data using a simple algorithm
    int compressed_size = 0;
    for (int i = 0; i < size; i++) {
        // Check if the current character is the same as the previous character
        if (i > 0 && data[i] == data[i - 1]) {
            // If so, increment the count of consecutive characters
            compressed.data[compressed_size - 1]++;
        } else {
            // If not, add the character and a count of 1 to the compressed data
            compressed.data[compressed_size] = data[i];
            compressed.data[compressed_size + 1] = 1;
            compressed_size += 2;
        }
    }

    // Set the size of the compressed data
    compressed.size = compressed_size;

    // Return the compressed data
    return compressed;
}

// Function to decompress the data
char *decompress(compressed_data compressed) {
    // Allocate memory for the decompressed data
    char *decompressed = malloc(compressed.size * 2);

    // Decompress the data using the simple algorithm
    int decompressed_size = 0;
    for (int i = 0; i < compressed.size; i += 2) {
        // Get the character and count from the compressed data
        char character = compressed.data[i];
        int count = compressed.data[i + 1];

        // Add the character to the decompressed data count times
        for (int j = 0; j < count; j++) {
            decompressed[decompressed_size++] = character;
        }
    }

    // Set the size of the decompressed data
    decompressed[decompressed_size] = '\0';

    // Return the decompressed data
    return decompressed;
}

// Main function
int main() {
    // Get the data to compress
    char *data = "Hello, world!";
    int size = strlen(data);

    // Compress the data
    compressed_data compressed = compress(data, size);

    // Print the compressed data
    printf("Compressed data: %s\n", compressed.data);

    // Decompress the data
    char *decompressed = decompress(compressed);

    // Print the decompressed data
    printf("Decompressed data: %s\n", decompressed);

    // Free the allocated memory
    free(compressed.data);
    free(decompressed);

    return 0;
}