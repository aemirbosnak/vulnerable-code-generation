//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024
#define BITS_PER_BYTE 8

// Structure to hold the compressed data
typedef struct {
    char *data;
    size_t size;
} compressed_data_t;

// Function to compress the data
compressed_data_t *compress(const char *input) {
    // Step 1: Count the frequency of each character
    unsigned char freq[256];
    for (size_t i = 0; i < strlen(input); i++) {
        freq[input[i]]++;
    }

    // Step 2: Create a bit vector for the compression
    unsigned char *bit_vector = calloc(256, sizeof(unsigned char));
    for (size_t i = 0; i < 256; i++) {
        bit_vector[i] = 0;
    }

    // Step 3: Compress the data
    for (size_t i = 0; i < strlen(input); i++) {
        char current = input[i];
        size_t j = freq[current] - 1;
        while (j >= 0) {
            bit_vector[j] = 1;
            j--;
        }
    }

    // Step 4: Encode the bit vector
    size_t encoded_size = 0;
    for (size_t i = 0; i < 256; i++) {
        if (bit_vector[i]) {
            encoded_size++;
        }
    }

    // Step 5: Allocate memory for the compressed data
    compressed_data_t *compressed = calloc(1, sizeof(compressed_data_t));
    compressed->data = calloc(1, encoded_size);
    compressed->size = encoded_size;

    // Step 6: Decode the bit vector and store the compressed data
    size_t current = 0;
    for (size_t i = 0; i < 256; i++) {
        if (bit_vector[i]) {
            compressed->data[current] = i;
            current++;
        }
    }

    return compressed;
}

// Function to decompress the data
char *decompress(const compressed_data_t *compressed) {
    // Step 1: Decode the bit vector
    size_t current = 0;
    for (size_t i = 0; i < 256; i++) {
        if (compressed->data[current] == i) {
            current++;
        }
    }

    // Step 2: Create a buffer for the decompressed data
    char *decompressed = calloc(1, strlen(compressed->data));

    // Step 3: Reconstruct the original data
    for (size_t i = 0; i < strlen(compressed->data); i++) {
        decompressed[i] = compressed->data[current];
        current++;
    }

    return decompressed;
}

int main() {
    char input[] = "Hello, world!";
    compressed_data_t *compressed = compress(input);
    char *decompressed = decompress(compressed);

    printf("Original: %s\n", input);
    printf("Compressed: %s\n", compressed->data);
    printf("Decompressed: %s\n", decompressed);

    free(compressed->data);
    free(compressed);
    free(decompressed);

    return 0;
}