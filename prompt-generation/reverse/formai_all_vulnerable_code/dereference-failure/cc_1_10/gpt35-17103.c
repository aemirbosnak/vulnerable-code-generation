//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// function to perform run-length encoding compression
void RLE_compress(uint8_t *input, size_t input_len, uint8_t *output, size_t *output_len) {
    uint8_t current, next;
    size_t count, i, j;

    for (i = 0, j = 0; i < input_len; i += count, j += 2) {
        current = input[i];
        count = 1;

        while ((i + count) < input_len && input[i + count] == current) {
            count++;
        }

        output[j] = current;
        output[j + 1] = count;

        if (j + 1 >= *output_len) {
            printf("Error: Output buffer too small for compression\n");
            exit(EXIT_FAILURE);
        }
    }

    *output_len = j;
}

// function to perform run-length decoding decompression
void RLE_decompress(uint8_t *input, size_t input_len, uint8_t *output, size_t *output_len) {
    uint8_t current;
    size_t count, i, j;

    for (i = 0, j = 0; i < input_len; i += 2, j += count) {
        current = input[i];
        count = input[i + 1];

        // check for buffer overflow
        if (j + count >= *output_len) {
            printf("Error: Output buffer too small for decompression\n");
            exit(EXIT_FAILURE);
        }

        for (size_t k = 0; k < count; k++) {
            output[j + k] = current;
        }
    }

    *output_len = j;
}

int main() {
    uint8_t original[] = { 1, 2, 2, 2, 3, 3, 4 };
    uint8_t compressed[7];
    uint8_t decompressed[7];
    size_t original_len = sizeof(original);
    size_t compressed_len = sizeof(compressed);
    size_t decompressed_len = sizeof(decompressed);

    RLE_compress(original, original_len, compressed, &compressed_len);
    printf("Original: ");
    for (size_t i = 0; i < original_len; i++) {
        printf("%d ", original[i]);
    }
    printf("\n");
    printf("Compressed: ");
    for (size_t i = 0; i < compressed_len; i++) {
        printf("%d ", compressed[i]);
    }
    printf("\n");

    RLE_decompress(compressed, compressed_len, decompressed, &decompressed_len);
    printf("Decompressed: ");
    for (size_t i = 0; i < decompressed_len; i++) {
        printf("%d ", decompressed[i]);
    }
    printf("\n");

    return 0;
}