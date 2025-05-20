//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input string
#define MAX_INPUT_SIZE 1024

// Define the maximum size of the compressed string
#define MAX_COMPRESSED_SIZE (MAX_INPUT_SIZE * 2)

// Function to compress a string using run-length encoding
char *compress(char *input) {
    // Allocate memory for the compressed string
    char *compressed = malloc(MAX_COMPRESSED_SIZE);

    // Initialize the compressed string
    int compressed_length = 0;

    // Iterate over the input string
    int i = 0;
    while (input[i] != '\0') {
        // Count the number of consecutive occurrences of the current character
        int count = 1;
        while (input[i] == input[i + 1]) {
            count++;
            i++;
        }

        // Store the character and its count in the compressed string
        compressed[compressed_length++] = input[i];
        compressed[compressed_length++] = count;

        // Increment the index
        i++;
    }

    // Terminate the compressed string
    compressed[compressed_length] = '\0';

    // Return the compressed string
    return compressed;
}

// Function to decompress a string using run-length encoding
char *decompress(char *compressed) {
    // Allocate memory for the decompressed string
    char *decompressed = malloc(MAX_INPUT_SIZE);

    // Initialize the decompressed string
    int decompressed_length = 0;

    // Iterate over the compressed string
    int i = 0;
    while (compressed[i] != '\0') {
        // Get the character and its count
        char character = compressed[i++];
        int count = compressed[i++];

        // Append the character to the decompressed string the specified number of times
        for (int j = 0; j < count; j++) {
            decompressed[decompressed_length++] = character;
        }
    }

    // Terminate the decompressed string
    decompressed[decompressed_length] = '\0';

    // Return the decompressed string
    return decompressed;
}

// Main function
int main() {
    // Get the input string from the user
    char input[MAX_INPUT_SIZE];
    printf("Enter the string to compress: ");
    scanf("%s", input);

    // Compress the input string
    char *compressed = compress(input);

    // Print the compressed string
    printf("Compressed string: %s\n", compressed);

    // Decompress the compressed string
    char *decompressed = decompress(compressed);

    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressed);

    // Free the allocated memory
    free(compressed);
    free(decompressed);

    return 0;
}