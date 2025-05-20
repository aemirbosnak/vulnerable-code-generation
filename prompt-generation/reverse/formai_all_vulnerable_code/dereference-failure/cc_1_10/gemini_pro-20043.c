//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_BUFFER_SIZE 1024

// Function to compress a string using Run-Length Encoding (RLE)
char *rle_compress(char *input) {
    // Allocate memory for the compressed string
    char *compressed = malloc(strlen(input) + 1);
    if (!compressed) {
        return NULL;
    }

    // Initialize the compressed string
    compressed[0] = '\0';

    // Iterate over the input string
    int i = 0;
    int count = 1;
    while (input[i]) {
        // Check if the current character is the same as the previous character
        if (input[i] == input[i + 1]) {
            // Increment the count
            count++;
        } else {
            // Append the current character and the count to the compressed string
            sprintf(compressed, "%s%c%d", compressed, input[i], count);

            // Reset the count
            count = 1;
        }

        // Move to the next character
        i++;
    }

    // Return the compressed string
    return compressed;
}

// Function to decompress a string using Run-Length Encoding (RLE)
char *rle_decompress(char *compressed) {
    // Allocate memory for the decompressed string
    char *decompressed = malloc(strlen(compressed) * 2 + 1);
    if (!decompressed) {
        return NULL;
    }

    // Initialize the decompressed string
    decompressed[0] = '\0';

    // Iterate over the compressed string
    int i = 0;
    int count = 0;
    while (compressed[i]) {
        // Check if the current character is a digit
        if (compressed[i] >= '0' && compressed[i] <= '9') {
            // Convert the digit to a number and add it to the count
            count = count * 10 + (compressed[i] - '0');
        } else {
            // Append the current character to the decompressed string
            while (count--) {
                strcat(decompressed, &compressed[i]);
            }

            // Reset the count
            count = 0;
        }

        // Move to the next character
        i++;
    }

    // Return the decompressed string
    return decompressed;
}

// Main function
int main() {
    // Get the input string from the user
    char *input = malloc(MAX_BUFFER_SIZE);
    if (!input) {
        return 1;
    }
    printf("Enter a string to compress: ");
    fgets(input, MAX_BUFFER_SIZE, stdin);

    // Compress the string using RLE
    char *compressed = rle_compress(input);
    if (!compressed) {
        return 1;
    }

    // Print the compressed string
    printf("Compressed string: %s\n", compressed);

    // Decompress the string using RLE
    char *decompressed = rle_decompress(compressed);
    if (!decompressed) {
        return 1;
    }

    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressed);

    // Free the allocated memory
    free(input);
    free(compressed);
    free(decompressed);

    return 0;
}