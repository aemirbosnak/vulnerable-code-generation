//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

// Structure to hold the compressed data
typedef struct {
    char character;
    int count;
} CompressedData;

// Function to compress a string using a simple run-length encoding algorithm
CompressedData* compress(const char* input, int* out_size) {
    int len = strlen(input);
    CompressedData* compressed = (CompressedData*)malloc(len * sizeof(CompressedData));
    if (!compressed) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    int i, j = 0; // i for input index, j for compressed index
    for (i = 0; i < len; i++) {
        compressed[j].character = input[i];
        compressed[j].count = 1;

        while (i + 1 < len && input[i] == input[i + 1]) {
            compressed[j].count++;
            i++;
        }
        j++;
    }
    *out_size = j;
    return compressed;
}

// Function to decompress the data back from CompressedData
char* decompress(const CompressedData* compressed, int size) {
    // Max potential size (you might want to have a more elegant solution)
    char* decompressed = (char*)malloc(MAX_BUFFER_SIZE);
    if (!decompressed) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    int index = 0;
    for (int i = 0; i < size; i++) {
        for (int k = 0; k < compressed[i].count; k++) {
            decompressed[index++] = compressed[i].character;
            if (index >= MAX_BUFFER_SIZE) {
                fprintf(stderr, "Buffer overflow during decompression\n");
                free(decompressed);
                exit(1);
            }
        }
    }
    decompressed[index] = '\0'; // Null-terminate the decompressed string
    return decompressed;
}

// Function to print compressed data
void printCompressedData(const CompressedData* compressed, int size) {
    printf("Compressed Data: ");
    for (int i = 0; i < size; i++) {
        printf("(%c,%d) ", compressed[i].character, compressed[i].count);
    }
    printf("\n");
}

int main() {
    char input[MAX_BUFFER_SIZE];

    printf("Enter a string to compress: ");
    fgets(input, MAX_BUFFER_SIZE, stdin);
    input[strcspn(input, "\n")] = 0; // Remove trailing newline

    int compressed_size;
    CompressedData* compressed = compress(input, &compressed_size);
    
    printCompressedData(compressed, compressed_size);

    printf("Decompressing...\n");
    char* decompressed = decompress(compressed, compressed_size);
    printf("Decompressed String: %s\n", decompressed);

    // Clean up
    free(compressed);
    free(decompressed);

    return 0;
}