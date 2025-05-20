//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Structure to store the compressed data
typedef struct {
    int length;
    char data[BUFFER_SIZE];
} compressed_data_t;

// Function to compress the data
compressed_data_t* compress(const char* data) {
    // Step 1: Remove redundant characters
    char* buffer = (char*)malloc(BUFFER_SIZE * sizeof(char));
    int i = 0;
    for (int j = 0; j < strlen(data); j++) {
        if (data[j] == data[j + 1]) {
            buffer[i] = data[j];
            i++;
        }
    }
    compressed_data_t* compressed = (compressed_data_t*)malloc(sizeof(compressed_data_t));
    compressed->length = i;
    memcpy(compressed->data, buffer, i * sizeof(char));
    free(buffer);
    return compressed;
}

// Function to decompress the data
char* decompress(const compressed_data_t* compressed) {
    char* buffer = (char*)malloc(BUFFER_SIZE * sizeof(char));
    int i = 0;
    for (int j = 0; j < compressed->length; j++) {
        if (compressed->data[j] == compressed->data[j + 1]) {
            buffer[i] = compressed->data[j];
            i++;
        }
    }
    return buffer;
}

int main() {
    // Test data
    char data[] = "aaabaaaabaaaa";

    // Compress the data
    compressed_data_t* compressed = compress(data);

    // Decompress the data
    char* decompressed = decompress(compressed);

    // Print the original and decompressed data
    printf("Original data: %s\n", data);
    printf("Decompressed data: %s\n", decompressed);

    // Free the memory
    free(compressed);
    free(decompressed);

    return 0;
}