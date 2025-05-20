//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform run-length encoding compression
char* rle_compress(const char* input) {
    int length = strlen(input);
    if (length == 0) return strdup(""); // Return empty string if input is empty

    // Allocate initial memory for compressed string (worst case: 2x input size)
    char* compressed = (char*)malloc(2 * length + 1);
    if (!compressed) {
        perror("Failed to allocate memory for compressed string");
        exit(EXIT_FAILURE);
    }

    int count = 1; // Count occurrences of the current character
    int index = 0; // Index for the compressed string

    for (int i = 1; i <= length; i++) {
        if (input[i] == input[i - 1]) {
            count++;
        } else {
            // Write the previous character and its count to the compressed string
            index += sprintf(compressed + index, "%c%d", input[i - 1], count);
            count = 1; // Reset count for the new character
        }
    }

    // Null terminate the compressed string
    compressed[index] = '\0';
    return compressed;
}

// Function to perform run-length decoding
char* rle_decompress(const char* input) {
    int length = strlen(input);
    // Allocate memory for the decompressed string (worst case handling)
    char* decompressed = (char*)malloc(2 * length + 1);
    if (!decompressed) {
        perror("Failed to allocate memory for decompressed string");
        exit(EXIT_FAILURE);
    }

    int index = 0; // Index for the decompressed string

    for (int i = 0; i < length; i++) {
        char current_char = input[i];
        i++;

        // Read the count (assuming it consists of digits only)
        int count = 0;
        while (i < length && input[i] >= '0' && input[i] <= '9') {
            count = count * 10 + (input[i] - '0');
            i++;
        }
        i--; // Adjust because of the last increment in the loop

        // Expand the characters in the decompressed string
        for (int j = 0; j < count; j++) {
            decompressed[index++] = current_char;
        }
    }

    // Null terminate the decompressed string
    decompressed[index] = '\0';
    return decompressed;
}

// Main function to demonstrate the compression and decompression
int main() {
    char input[256]; // Buffer for user input

    printf("Enter a string to compress: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    char* compressed = rle_compress(input);
    printf("Original String: %s\n", input);
    printf("Compressed String: %s\n", compressed);

    char* decompressed = rle_decompress(compressed);
    printf("Decompressed String: %s\n", decompressed);

    // Free allocated memory
    free(compressed);
    free(decompressed);

    return 0;
}