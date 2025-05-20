//FormAI DATASET v1.0 Category: Compression algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024      // Maximum length of input string
#define CHUNK_SIZE 128      // Number of characters in each chunk

// Compression function to compress the input string
char* compress(char* input) {
    int input_len = strlen(input);      // Length of input string
    int num_chunks = input_len / CHUNK_SIZE + 1;    // Number of chunks
    char* compressed = (char*) malloc(num_chunks * sizeof(char));    // Allocate memory for compressed string
    int idx = 0;                        // Index of next position in compressed string
    
    // Iterate through each chunk of the input string
    for (int i = 0; i < input_len; i += CHUNK_SIZE) {
        int chunk_start = i;            // Starting position of the current chunk
        int chunk_end = i + CHUNK_SIZE; // Ending position of the current chunk
        
        // Make sure the ending position is not beyond the length of the input string
        if (chunk_end > input_len) {
            chunk_end = input_len;
        }
        
        // Calculate the difference between the maximum and minimum ASCII values
        int diff = 0;
        for (int j = chunk_start; j < chunk_end; j++) {
            diff += input[j];
        }
        diff %= 128;
        
        // Add the difference value to the compressed string
        compressed[idx++] = diff;
    }
    
    return compressed;
}

// Decompression function to decompress the compressed string
char* decompress(char* compressed) {
    int num_chunks = strlen(compressed);    // Number of chunks
    char* decompressed = (char*) malloc(num_chunks * CHUNK_SIZE * sizeof(char));    // Allocate memory for decompressed string
    int idx = 0;                            // Index of next position in decompressed string
    
    // Iterate through each chunk of the compressed string
    for (int i = 0; i < num_chunks; i++) {
        int diff = compressed[i];   // Difference value
        
        // Reconstruct the original chunk using the difference value
        for (int j = 0; j < CHUNK_SIZE; j++) {
            int original = diff + j;
            if (original > 127) {
                original -= 128;
            }
            decompressed[idx++] = original; // Add the original character to the decompressed string
        }
    }
    
    return decompressed;
}

int main() {
    char input[MAX_LENGTH];     // Input string
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);    // Read input string from user
    input[strcspn(input, "\n")] = 0;    // Remove trailing newline character
    
    // Compress the input string
    char* compressed = compress(input);
    printf("Compressed string: %s\n", compressed);
    
    // Decompress the compressed string
    char* decompressed = decompress(compressed);
    printf("Decompressed string: %s\n", decompressed);
    
    // Free memory allocated for compressed and decompressed strings
    free(compressed);
    free(decompressed);
    
    return 0;
}