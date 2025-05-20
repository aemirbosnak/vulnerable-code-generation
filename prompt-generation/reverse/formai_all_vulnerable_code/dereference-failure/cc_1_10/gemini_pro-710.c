//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a compressed string
typedef struct {
    char *str;
    int len;
} CompressedString;

// Function to compress a string using run-length encoding
CompressedString *compress(const char *str) {
    if (!str) {
        return NULL;
    }

    // Allocate memory for the compressed string
    CompressedString *compressed = malloc(sizeof(CompressedString));
    if (!compressed) {
        return NULL;
    }

    // Initialize the compressed string
    compressed->str = malloc(strlen(str) + 1);
    if (!compressed->str) {
        free(compressed);
        return NULL;
    }
    compressed->len = 0;

    // Iterate over the input string
    int i = 0;
    while (str[i]) {
        // Get the current character and its count
        char c = str[i];
        int count = 0;
        while (str[i] == c) {
            i++;
            count++;
        }

        // Append the character and its count to the compressed string
        sprintf(compressed->str + compressed->len, "%c%d", c, count);
        compressed->len += strlen(compressed->str + compressed->len);
    }

    // Terminate the compressed string
    compressed->str[compressed->len] = '\0';

    // Return the compressed string
    return compressed;
}

// Function to decompress a string compressed using run-length encoding
char *decompress(const CompressedString *compressed) {
    if (!compressed) {
        return NULL;
    }

    // Allocate memory for the decompressed string
    char *decompressed = malloc(compressed->len + 1);
    if (!decompressed) {
        return NULL;
    }
    int decompressed_len = 0;

    // Iterate over the compressed string
    int i = 0;
    while (compressed->str[i]) {
        // Get the current character and its count
        char c = compressed->str[i++];
        int count = 0;
        while (compressed->str[i] >= '0' && compressed->str[i] <= '9') {
            count = count * 10 + compressed->str[i++] - '0';
        }

        // Append the character to the decompressed string count times
        for (int j = 0; j < count; j++) {
            decompressed[decompressed_len++] = c;
        }
    }

    // Terminate the decompressed string
    decompressed[decompressed_len] = '\0';

    // Return the decompressed string
    return decompressed;
}

// Example usage
int main() {
    // Original string
    const char *str = "AAABBBCCCDDEEE";

    // Compress the string
    CompressedString *compressed = compress(str);

    // Print the compressed string
    printf("Compressed string: %s\n", compressed->str);

    // Decompress the string
    char *decompressed = decompress(compressed);

    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressed);

    // Free the memory allocated for the compressed and decompressed strings
    free(compressed->str);
    free(compressed);
    free(decompressed);

    return 0;
}