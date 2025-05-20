//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// Function to perform run-length encoding compression
char* compress(const char* input) {
    int input_len = strlen(input);
    // Allocate enough memory for the worst case scenario
    char* compressed = (char*)malloc(MAX_LEN * sizeof(char));
    if (compressed == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    int index = 0; // Index to keep track of the position in compressed string

    for (int i = 0; i < input_len; i++) {
        // Count occurrences of current character
        int count = 1;

        while (i + 1 < input_len && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        // Store the character and its count in the compressed string
        index += sprintf(compressed + index, "%c%d", input[i], count);
    }

    // Null-terminate the compressed string
    compressed[index] = '\0';
    return compressed;
}

// Function to perform decompression
char* decompress(const char* input) {
    char* decompressed = (char*)malloc(MAX_LEN * sizeof(char));
    if (decompressed == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    int index = 0; // Index for the decompressed string

    for (int i = 0; i < strlen(input); i++) {
        char ch = input[i];
        i++;
        // Get the count (which might be more than one digit)
        int count = 0;
        while (i < strlen(input) && input[i] >= '0' && input[i] <= '9') {
            count = count * 10 + (input[i] - '0');
            i++;
        }
        i--; // Adjust i after the loop since it will be incremented again

        // Add the character 'ch', 'count' times to the decompressed string
        for (int j = 0; j < count; j++) {
            decompressed[index++] = ch;
        }
    }

    // Null-terminate the decompressed string
    decompressed[index] = '\0';
    return decompressed;
}

int main() {
    char input[MAX_LEN];

    // Get user input
    printf("Enter a string to compress: ");
    fgets(input, MAX_LEN, stdin);
    input[strcspn(input, "\n")] = 0; // Remove trailing newline

    // Perform compression
    char* compressed = compress(input);
    printf("Compressed string: %s\n", compressed);

    // Perform decompression
    char* decompressed = decompress(compressed);
    printf("Decompressed string: %s\n", decompressed);

    // Free allocated memory
    free(compressed);
    free(decompressed);

    return 0;
}