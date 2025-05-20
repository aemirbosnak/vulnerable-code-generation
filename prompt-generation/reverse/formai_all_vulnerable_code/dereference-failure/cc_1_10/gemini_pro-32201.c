//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input and output buffers
#define MAX_BUFFER_SIZE 1024

// Function to compress a string using run-length encoding (RLE)
char* compressRLE(char* input) {
    // Allocate memory for the output buffer
    char* output = malloc(MAX_BUFFER_SIZE);

    // Initialize the output buffer
    int outputIndex = 0;

    // Iterate over the input string
    for (int i = 0; i < strlen(input); i++) {
        // Count the number of consecutive occurrences of the current character
        int count = 1;
        while (i + count < strlen(input) && input[i] == input[i + count]) {
            count++;
        }

        // Store the character and its count in the output buffer
        output[outputIndex++] = input[i];
        output[outputIndex++] = count + '0';

        // Skip the consecutive occurrences of the current character
        i += count - 1;
    }

    // Terminate the output buffer with a null character
    output[outputIndex] = '\0';

    // Return the compressed string
    return output;
}

// Function to decompress a string using run-length encoding (RLE)
char* decompressRLE(char* input) {
    // Allocate memory for the output buffer
    char* output = malloc(MAX_BUFFER_SIZE);

    // Initialize the output buffer
    int outputIndex = 0;

    // Iterate over the input string
    for (int i = 0; i < strlen(input); i += 2) {
        // Extract the character and its count from the input buffer
        char character = input[i];
        int count = input[i + 1] - '0';

        // Repeat the character in the output buffer
        for (int j = 0; j < count; j++) {
            output[outputIndex++] = character;
        }
    }

    // Terminate the output buffer with a null character
    output[outputIndex] = '\0';

    // Return the decompressed string
    return output;
}

int main() {
    // Get the input string from the user
    char input[MAX_BUFFER_SIZE];
    printf("Enter the string to be compressed: ");
    scanf("%s", input);

    // Compress the input string using RLE
    char* compressedString = compressRLE(input);

    // Print the compressed string
    printf("Compressed string: %s\n", compressedString);

    // Decompress the compressed string using RLE
    char* decompressedString = decompressRLE(compressedString);

    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressedString);

    // Free the allocated memory
    free(compressedString);
    free(decompressedString);

    return 0;
}