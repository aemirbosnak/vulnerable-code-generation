//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

// Function to compress the input string using a basic run-length encoding (RLE) algorithm
char* compress(const char* input) {
    int len = strlen(input);
    char* output = (char*)malloc(2 * len); // allocate maximum possible space
    if (!output) {
        fprintf(stderr, "Memory allocation failed!\n");
        return NULL;
    }

    int count = 1;
    int outputIndex = 0;

    for (int i = 0; i < len; i++) {
        // If the current character is the same as the next one, increase the count
        if (i < len - 1 && input[i] == input[i + 1]) {
            count++;
        } else {
            // Append current character and its count to output
            output[outputIndex++] = input[i];
            outputIndex += snprintf(output + outputIndex, 2, "%d", count);
            count = 1; // reset count for the new character
        }
    }
    
    output[outputIndex] = '\0'; // Null terminate the compressed string
    return output;
}

// Function to decompress the input string encoded in RLE
char* decompress(const char* input) {
    int len = strlen(input);
    char* output = (char*)malloc(MAX_LENGTH * len); // allocate enough space for decompression
    if (!output) {
        fprintf(stderr, "Memory allocation failed!\n");
        return NULL;
    }

    int outputIndex = 0;

    for (int i = 0; i < len; i++) {
        char currentChar = input[i];
        i++;
        int count = 0;

        // Read the count, which can be more than one digit
        while (i < len && input[i] >= '0' && input[i] <= '9') {
            count = count * 10 + (input[i] - '0');
            i++;
        }
        i--; // step back to adjust for the loop increment

        // Append the character 'count' times to output
        for (int j = 0; j < count; j++) {
            output[outputIndex++] = currentChar;
        }
    }
    
    output[outputIndex] = '\0'; // Null terminate the decompressed string
    return output;
}

// Main function to demonstrate the compression and decompression
int main() {
    char input[MAX_LENGTH];

    printf("Enter a string to compress (max %d characters): ", MAX_LENGTH - 1);
    fgets(input, MAX_LENGTH, stdin);
    // Remove newline character from input if present
    input[strcspn(input, "\n")] = 0;

    printf("\nOriginal String: %s\n", input);

    // Compress the input string
    char* compressed = compress(input);
    if (compressed) {
        printf("Compressed String: %s\n", compressed);
    } else {
        perror("Compression failed");
    }

    // Decompress and show the original string
    char* decompressed = decompress(compressed);
    if (decompressed) {
        printf("Decompressed String: %s\n", decompressed);
    } else {
        perror("Decompression failed");
    }

    // Free allocated memory
    free(compressed);
    free(decompressed);
    return 0;
}