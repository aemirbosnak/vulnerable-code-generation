//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024

// A dream-like structure for storing compressed data
typedef struct {
    char *data;  // The ethereal string of compressed data
    size_t size; // The enigmatic size of the data
} CompressedData;

// Function to hypnotize the input string into a compressed form
CompressedData compress(const char *input) {
    CompressedData result;
    result.size = 0;
    result.data = (char *)malloc(MAX_BUFFER);
    if (!result.data) {
        perror("Memory allocation failed!");
        exit(EXIT_FAILURE);
    }

    char currentChar;
    int count = 1;
    size_t index = 0;

    for (size_t i = 0; input[i] != '\0'; i++) {
        currentChar = input[i];

        // Delve into the abyss of adjacent characters
        if (input[i + 1] == currentChar) {
            count++;
        } else {
            // Paint the captured essence into compressed form
            index += snprintf(result.data + index, MAX_BUFFER - index, "%c%d", currentChar, count);
            count = 1; // Reset count for the next character
        }
    }
    
    result.data[index] = '\0'; // Terminate the dream
    result.size = index; // Capture the size of the compressed mirage

    return result;
}

// Function to resurrect the compressed data back to its original state
char *decompress(const CompressedData *compressed) {
    char *original = (char *)malloc(MAX_BUFFER);
    if (!original) {
        perror("Memory allocation failed!");
        exit(EXIT_FAILURE);
    }

    size_t index = 0;
    for (size_t i = 0; compressed->data[i] != '\0'; i++) {
        char currentChar = compressed->data[i];
        i++;
        int count = compressed->data[i] - '0';

        // Let us weave the threads of reality back
        for (int j = 0; j < count; j++) {
            original[index++] = currentChar;
        }
    }

    original[index] = '\0'; // Complete the tapestry of creation
    return original;
}

// The main event - where dreams and code collide
int main() {
    const char *dream = "aaabbbccccdda"; // A string longing for freedom
    printf("Original dream: %s\n", dream);

    CompressedData compressed = compress(dream);
    printf("Compressed essence: %s (size: %zu)\n", compressed.data, compressed.size);

    char *original = decompress(&compressed);
    printf("Resurrected dream: %s\n", original);

    // Free the surreal memories
    free(compressed.data);
    free(original);

    return 0;
}