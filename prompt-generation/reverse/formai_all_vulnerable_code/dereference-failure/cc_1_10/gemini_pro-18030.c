//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A very funny compression algorithm
char *compress(char *str) {
    int i, j, k;
    int len = strlen(str);
    char *compressed = malloc(len + 1);

    // Copy the first character
    compressed[0] = str[0];

    // Compress the rest of the string
    for (i = 1; i < len; i++) {
        // Check if the current character is the same as the previous character
        if (str[i] == str[i - 1]) {
            // If it is, count the number of consecutive same characters
            j = i;
            while (str[j] == str[j - 1] && j < len) {
                j++;
            }

            // Store the count of consecutive same characters
            compressed[k++] = j - i;

            // Copy the last consecutive character
            compressed[k++] = str[i];

            // Skip to the next character
            i = j;
        } else {
            // If the current character is not the same as the previous character, just copy it
            compressed[k++] = str[i];
        }
    }

    // Null-terminate the compressed string
    compressed[k] = '\0';

    // Return the compressed string
    return compressed;
}

// A very funny decompression algorithm
char *decompress(char *compressed) {
    int i, j, k;
    int len = strlen(compressed);
    char *decompressed = malloc(len * 2 + 1);

    // Copy the first character
    decompressed[0] = compressed[0];

    // Decompress the rest of the string
    for (i = 1; i < len; i++) {
        // If the current character is a count of consecutive same characters
        if (compressed[i] >= 2) {
            // Get the count of consecutive same characters
            j = compressed[i];

            // Copy the last consecutive character j times
            for (k = 0; k < j; k++) {
                decompressed[k + 1] = compressed[i + 1];
            }

            // Skip to the next character
            i += 2;
        } else {
            // If the current character is just a single character, just copy it
            decompressed[k++] = compressed[i];
        }
    }

    // Null-terminate the decompressed string
    decompressed[k] = '\0';

    // Return the decompressed string
    return decompressed;
}

int main() {
    char *str = "Hello, world!";
    char *compressed = compress(str);
    char *decompressed = decompress(compressed);

    printf("Original string: %s\n", str);
    printf("Compressed string: %s\n", compressed);
    printf("Decompressed string: %s\n", decompressed);

    return 0;
}