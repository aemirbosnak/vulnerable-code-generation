//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform Run-Length Encoding compression
char* rleCompress(const char* input) {
    int length = strlen(input);
    char* compressed = (char*)malloc(length * 2); // Allocate double the memory assuming worst case
    if (compressed == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    
    int count = 1;  // To count occurrences of each character
    int index = 0;  // Index for the compressed string

    for (int i = 1; i <= length; i++) {
        if (input[i] == input[i - 1]) {
            count++;
        } else {
            // Store the character and its count
            index += sprintf(&compressed[index], "%c%d", input[i - 1], count);
            count = 1; // Reset the count
        }
    }
    compressed[index] = '\0'; // Null-terminate the string

    return compressed;
}

// Function to perform Run-Length Encoding decompression
char* rleDecompress(const char* compressed) {
    int length = strlen(compressed);
    char* decompressed = (char*)malloc(length * 10); // Allocate memory generously
    if (decompressed == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    
    int index = 0;  // Index for the decompressed string
    for (int i = 0; i < length; i++) {
        char ch = compressed[i]; // Character
        int count = 0;           // To store the number of occurrences
        
        // Read the number after the character
        while (i + 1 < length && compressed[i + 1] >= '0' && compressed[i + 1] <= '9') {
            count = count * 10 + (compressed[++i] - '0');
        }

        // Append the character `count` times
        for (int j = 0; j < count; j++) {
            decompressed[index++] = ch;
        }
    }
    decompressed[index] = '\0'; // Null terminate the string

    return decompressed;
}

// Main function to demonstrate RLE compression and decompression
int main() {
    char input[100]; // Array to hold user input
    printf("Welcome to the RLE Compression Program! 🎉\n");
    printf("Please enter a string to compress: ");
    scanf("%99s", input); // Read user input safely

    // Compression
    char* compressed = rleCompress(input);
    printf("Compressed: %s\n", compressed);

    // Decompression
    char* decompressed = rleDecompress(compressed);
    printf("Decompressed: %s\n", decompressed);

    // Free allocated memory
    free(compressed);
    free(decompressed);
    
    return 0;
}