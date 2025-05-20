//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

// Function to compress the input string
char* compress(const char* input) {
    int length = strlen(input);
    char* compressed = (char*)malloc(MAX_LENGTH);
    if (!compressed) {
        perror("Failed to allocate memory for compressed string");
        exit(EXIT_FAILURE);
    }

    int count = 1;
    int j = 0; // Index for compressed string

    for (int i = 1; i <= length; i++) {
        if (input[i] == input[i - 1]) {
            count++;
        } else {
            j += sprintf(&compressed[j], "%c%d", input[i - 1], count);
            count = 1;
        }
    }
    
    compressed[j] = '\0'; // Null terminate the compressed string
    return compressed;
}

// Function to decompress the compressed string
char* decompress(const char* compressed) {
    char* decompressed = (char*)malloc(MAX_LENGTH);
    if (!decompressed) {
        perror("Failed to allocate memory for decompressed string");
        exit(EXIT_FAILURE);
    }

    int j = 0; // Index for decompressed string

    for (int i = 0; compressed[i] != '\0'; i += 2) {
        char character = compressed[i];
        int count = compressed[i + 1] - '0'; // Convert char digit to int

        for (int k = 0; k < count; k++) {
            decompressed[j++] = character;
        }
    }
    
    decompressed[j] = '\0'; // Null terminate the decompressed string
    return decompressed;
}

// Main function to demonstrate the RLE compression and decompression
int main() {
    char input[MAX_LENGTH];

    // Futuristic intro
    printf("=== Welcome to the Quantum Compression Engine 3000 ===\n");
    printf("Please enter the string to compress: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    // Compress the input
    char* compressedData = compress(input);
    printf("Compressed String: %s\n", compressedData);

    // Decompress the data
    char* decompressedData = decompress(compressedData);
    printf("Decompressed String: %s\n\n", decompressedData);

    // Free allocated memory
    free(compressedData);
    free(decompressedData);

    // Futuristic outro
    printf("=== Thank you for using the Quantum Compression Engine 3000 ===\n");
    return 0;
}