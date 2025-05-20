//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a compressed string.
#define MAX_COMPRESSED_LENGTH 1024

// Compress a string using a simple run-length encoding algorithm.
char *compress(char *str) {
    // Allocate memory for the compressed string.
    char *compressed_str = malloc(MAX_COMPRESSED_LENGTH);
    if (compressed_str == NULL) {
        return NULL;
    }

    // Initialize the compressed string.
    int compressed_str_index = 0;

    // Loop through the input string.
    int i = 0;
    while (str[i] != '\0') {
        // Count the number of consecutive occurrences of the current character.
        int count = 1;
        while (str[i + count] == str[i]) {
            count++;
        }

        // Write the character and the count to the compressed string.
        compressed_str[compressed_str_index++] = str[i];
        compressed_str[compressed_str_index++] = count;

        // Move to the next character.
        i += count;
    }

    // Terminate the compressed string.
    compressed_str[compressed_str_index] = '\0';

    // Return the compressed string.
    return compressed_str;
}

// Decompress a string that was compressed using the run-length encoding algorithm.
char *decompress(char *compressed_str) {
    // Allocate memory for the decompressed string.
    char *decompressed_str = malloc(strlen(compressed_str) * 2 + 1);
    if (decompressed_str == NULL) {
        return NULL;
    }

    // Initialize the decompressed string.
    int decompressed_str_index = 0;

    // Loop through the compressed string.
    int i = 0;
    while (compressed_str[i] != '\0') {
        // Read the character and the count from the compressed string.
        char character = compressed_str[i++];
        int count = compressed_str[i++];

        // Write the character to the decompressed string the specified number of times.
        for (int j = 0; j < count; j++) {
            decompressed_str[decompressed_str_index++] = character;
        }
    }

    // Terminate the decompressed string.
    decompressed_str[decompressed_str_index] = '\0';

    // Return the decompressed string.
    return decompressed_str;
}

// Main function.
int main() {
    // Define a string to compress.
    char *str = "AAABBBCCCDDDEEEEE";

    // Compress the string.
    char *compressed_str = compress(str);
    if (compressed_str == NULL) {
        return 1;
    }

    // Print the compressed string.
    printf("Compressed string: %s\n", compressed_str);

    // Decompress the string.
    char *decompressed_str = decompress(compressed_str);
    if (decompressed_str == NULL) {
        return 1;
    }

    // Print the decompressed string.
    printf("Decompressed string: %s\n", decompressed_str);

    // Free the allocated memory.
    free(compressed_str);
    free(decompressed_str);

    return 0;
}