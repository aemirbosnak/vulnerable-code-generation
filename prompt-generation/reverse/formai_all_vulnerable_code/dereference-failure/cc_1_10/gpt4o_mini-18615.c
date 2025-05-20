//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

// Function to compress the input string using Run-Length Encoding
char* compress(const char* input) {
    int n = strlen(input);
    char* compressed = (char*)malloc(MAX_SIZE);
    if (!compressed) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    int count = 1, j = 0;

    for (int i = 1; i <= n; i++) {
        if (input[i] == input[i - 1]) {
            count++;
        } else {
            j += sprintf(&compressed[j], "%c%d", input[i - 1], count);
            count = 1;
        }
    }

    return compressed;
}

// Function to decompress the compressed string
char* decompress(const char* input) {
    char* decompressed = (char*)malloc(MAX_SIZE);
    if (!decompressed) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    int i = 0, j = 0;
    
    while (input[i]) {
        char ch = input[i++];
        int count = 0;

        // Read the number following the character
        while (input[i] >= '0' && input[i] <= '9') {
            count = count * 10 + (input[i++] - '0');
        }

        // Decompress the data
        for (int k = 0; k < count; k++) {
            decompressed[j++] = ch;
        }
    }
    decompressed[j] = '\0'; // Null terminate the string
    return decompressed;
}

// Main function to demonstrate compression and decompression
int main() {
    char input[MAX_SIZE];

    printf("Enter a string to be compressed: ");
    fgets(input, MAX_SIZE, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character if present

    printf("Original String: %s\n", input);
    
    char* compressed = compress(input);
    printf("Compressed String: %s\n", compressed);

    char* decompressed = decompress(compressed);
    printf("Decompressed String: %s\n", decompressed);
    
    // Free allocated memory
    free(compressed);
    free(decompressed);
    
    return 0;
}