//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_COMPRESSION_LENGTH 2048

// Define the data structure for storing compressed data
typedef struct {
    char *data;
    size_t size;
} CompressedData;

// Function to generate a unique key based on current timestamp and random number
uint32_t generateKey() {
    return (uint32_t)(time(NULL) ^ rand());
}

// A color-coded logging function to provide feedback in a cyberpunk style
void logMessage(const char *message, const char *color) {
    printf("%s%s\033[0m\n", color, message);
}

// Function to perform run-length encoding (RLE) compression
CompressedData compressRLE(const char *input) {
    CompressedData compressed;
    compressed.data = malloc(MAX_COMPRESSION_LENGTH);
    if (!compressed.data) {
        logMessage("Memory allocation failed!", "\033[31m"); // Red color for error
        exit(EXIT_FAILURE);
    }

    size_t inputLength = strlen(input);
    size_t index = 0;

    for (size_t i = 0; i < inputLength; i++) {
        char currentChar = input[i];
        size_t count = 1;

        while (i + 1 < inputLength && input[i + 1] == currentChar) {
            count++;
            i++;
        }

        index += snprintf(compressed.data + index, MAX_COMPRESSION_LENGTH - index, "%c%zu", currentChar, count);
    }

    compressed.size = index;
    return compressed;
}

// Function to decompress the RLE compressed data
char *decompressRLE(const CompressedData compressed) {
    char *decompressed = malloc(MAX_INPUT_LENGTH);
    if (!decompressed) {
        logMessage("Memory allocation failed!", "\033[31m"); // Red color for error
        exit(EXIT_FAILURE);
    }

    size_t index = 0;
    for (size_t i = 0; i < compressed.size; i++) {
        char currentChar = compressed.data[i++];
        size_t count = compressed.data[i] - '0';
        for (size_t j = 0; j < count; j++) {
            decompressed[index++] = currentChar;
        }
    }
    decompressed[index] = '\0'; // Null-terminate the string

    return decompressed;
}

// Function to display the compression ratio
void displayCompressionRatio(const char *input, const CompressedData compressed) {
    size_t originalSize = strlen(input);
    float ratio = (float)compressed.size / originalSize;
    printf("\033[1;36mCompression Ratio:\033[0m %0.2f\n", ratio); // Cyan color for info
}

// Main function to orchestrate input, compression, and output
int main() {
    char input[MAX_INPUT_LENGTH];

    logMessage("Welcome to the Cyberpunk RLE Compressor!", "\033[1;35m"); // Magenta color for title

    printf("\033[1;32mEnter the text to compress (max %d characters):\033[0m ", MAX_INPUT_LENGTH);
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove the newline character

    CompressedData compressed = compressRLE(input);
    logMessage("Compression successful!", "\033[1;34m"); // Blue color for success

    printf("\033[1;33mCompressed Data:\033[0m %s\n", compressed.data);
    displayCompressionRatio(input, compressed);

    char *decompressed = decompressRLE(compressed);
    printf("\033[1;37mDecompressed Data:\033[0m %s\n", decompressed);
    
    // Clean up memory
    free(compressed.data);
    free(decompressed);

    logMessage("Exiting the Cyberpunk RLE Compressor.", "\033[1;31m"); // Red color for exit
    return 0;
}