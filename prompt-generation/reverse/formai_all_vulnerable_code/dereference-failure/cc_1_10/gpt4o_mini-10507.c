//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

// Function to perform Run-Length Encoding
char* rle_compress(const char* input) {
    int n = strlen(input);
    char* compressed = (char*)malloc(MAX_LEN * sizeof(char));
    if (!compressed) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int count = 1;
    int j = 0;

    for (int i = 1; i <= n; i++) {
        if (input[i] == input[i - 1] && i < n) {
            count++;
        } else {
            j += sprintf(&compressed[j], "%c%d", input[i - 1], count);
            count = 1;
        }
    }

    compressed[j] = '\0';
    return compressed;
}

// Function to perform Run-Length Decoding
char* rle_decompress(const char* input) {
    char* decompressed = (char*)malloc(MAX_LEN * sizeof(char));
    if (!decompressed) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int j = 0;
    int len = strlen(input);

    for (int i = 0; i < len; i++) {
        char ch = input[i];
        i++;

        // Read number of occurrences
        int count = 0;
        while (i < len && isdigit(input[i])) {
            count = count * 10 + (input[i] - '0');
            i++;
        }

        // Append the character 'count' times
        for (int k = 0; k < count; k++) {
            decompressed[j++] = ch;
        }

        i--; // Adjust the index after the last increment
    }

    decompressed[j] = '\0';
    return decompressed;
}

// Main function
int main() {
    char input[MAX_LEN];

    // Get input string from user
    printf("Enter a string to compress: ");
    fgets(input, MAX_LEN, stdin);
    // Remove newline character
    input[strcspn(input, "\n")] = 0;

    // Compression
    char* compressed = rle_compress(input);
    printf("Compressed string: %s\n", compressed);

    // Decompression
    char* decompressed = rle_decompress(compressed);
    printf("Decompressed string: %s\n", decompressed);

    // Free allocated memory
    free(compressed);
    free(decompressed);

    return 0;
}