//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom data structure for storing compressed data
typedef struct {
    unsigned char *data;
    unsigned int length;
} CompressedData;

// Function to compress a string using run-length encoding (RLE)
CompressedData *rleCompress(const char *str, unsigned int length) {
    CompressedData *compressed = malloc(sizeof(CompressedData));
    unsigned char *out = malloc(length);
    unsigned int outIdx = 0;

    // Iterate over the input string
    unsigned int i = 0;
    while (i < length) {
        unsigned int count = 1;

        // Count consecutive occurrences of the current character
        while (i + count < length && str[i] == str[i + count]) {
            count++;
        }

        // Store the character and its count in the compressed data
        out[outIdx++] = str[i];
        out[outIdx++] = count;

        // Advance to the next character
        i += count;
    }

    compressed->data = out;
    compressed->length = outIdx;
    return compressed;
}

// Function to decompress RLE-compressed data
char *rleDecompress(const CompressedData *compressed) {
    char *out = malloc(compressed->length);
    unsigned int outIdx = 0;

    // Iterate over the compressed data
    unsigned int i = 0;
    while (i < compressed->length) {
        // Repeat the character the specified number of times
        unsigned int count = compressed->data[i + 1];
        for (unsigned int j = 0; j < count; j++) {
            out[outIdx++] = compressed->data[i];
        }

        // Advance to the next character
        i += 2;
    }

    return out;
}

// Function to test the compression and decompression algorithms
int main() {
    char *input = "AABBCCCDDEEE";
    unsigned int length = strlen(input);

    // Compress the string
    CompressedData *compressed = rleCompress(input, length);

    // Decompress the compressed data
    char *decompressed = rleDecompress(compressed);

    // Print the original, compressed, and decompressed strings
    printf("Original: %s\n", input);
    printf("Compressed: ");
    for (unsigned int i = 0; i < compressed->length; i++) {
        printf("%02X", compressed->data[i]);
    }
    printf("\n");
    printf("Decompressed: %s\n", decompressed);

    // Free the allocated memory
    free(compressed->data);
    free(compressed);
    free(decompressed);

    return 0;
}