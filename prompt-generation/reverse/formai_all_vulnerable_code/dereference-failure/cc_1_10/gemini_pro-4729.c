//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress a string using run-length encoding
char *compress(char *str) {
    // Get the length of the string
    int len = strlen(str);

    // Create a new string to store the compressed string
    char *compressed = malloc(len * 2 + 1);

    // Set the index of the compressed string
    int idx = 0;

    // Iterate over the string
    for (int i = 0; i < len; i++) {
        // Get the current character
        char c = str[i];

        // Get the number of consecutive occurrences of the current character
        int count = 1;
        while (i + 1 < len && str[i + 1] == c) {
            count++;
            i++;
        }

        // Store the compressed string
        compressed[idx++] = c;
        compressed[idx++] = count + '0';
    }

    // Null-terminate the compressed string
    compressed[idx] = '\0';

    // Return the compressed string
    return compressed;
}

// Function to decompress a string using run-length encoding
char *decompress(char *str) {
    // Get the length of the string
    int len = strlen(str);

    // Create a new string to store the decompressed string
    char *decompressed = malloc(len * 2 + 1);

    // Set the index of the decompressed string
    int idx = 0;

    // Iterate over the string
    for (int i = 0; i < len; i++) {
        // Get the current character
        char c = str[i];

        // Get the number of consecutive occurrences of the current character
        int count = str[i + 1] - '0';

        // Store the decompressed string
        for (int j = 0; j < count; j++) {
            decompressed[idx++] = c;
        }

        // Increment the index
        i++;
    }

    // Null-terminate the decompressed string
    decompressed[idx] = '\0';

    // Return the decompressed string
    return decompressed;
}

// Main function
int main() {
    // Get the string to compress
    char *str = "AAAABBBCCCDDDD";

    // Compress the string
    char *compressed = compress(str);

    // Print the compressed string
    printf("Compressed string: %s\n", compressed);

    // Decompress the string
    char *decompressed = decompress(compressed);

    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressed);

    // Free the allocated memory
    free(compressed);
    free(decompressed);

    return 0;
}