//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress a string
char *compress(char *str) {
    // Find the length of the string
    int len = strlen(str);

    // Create a buffer to store the compressed string
    char *compressed = malloc(len * sizeof(char));

    // Initialize the compressed string
    compressed[0] = '\0';

    // Compress the string
    int i, j, count;
    for (i = 0, j = 0; i < len; i++) {
        // Count the number of consecutive occurrences of the current character
        count = 1;
        while (i + 1 < len && str[i] == str[i + 1]) {
            count++;
            i++;
        }

        // Append the character and its count to the compressed string
        compressed[j++] = str[i];
        compressed[j++] = '0' + count;
    }

    // Return the compressed string
    return compressed;
}

// Function to decompress a string
char *decompress(char *str) {
    // Find the length of the string
    int len = strlen(str);

    // Create a buffer to store the decompressed string
    char *decompressed = malloc(len * sizeof(char));

    // Initialize the decompressed string
    decompressed[0] = '\0';

    // Decompress the string
    int i, j, count;
    for (i = 0, j = 0; i < len; i += 2) {
        // Get the character and its count
        char character = str[i];
        count = str[i + 1] - '0';

        // Append the character to the decompressed string count times
        for (int k = 0; k < count; k++) {
            decompressed[j++] = character;
        }
    }

    // Return the decompressed string
    return decompressed;
}

// Main function
int main() {
    // Get the string to be compressed
    char str[100];
    printf("Enter the string to be compressed: ");
    scanf("%s", str);

    // Compress the string
    char *compressed = compress(str);

    // Print the compressed string
    printf("Compressed string: %s\n", compressed);

    // Decompress the compressed string
    char *decompressed = decompress(compressed);

    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressed);

    return 0;
}