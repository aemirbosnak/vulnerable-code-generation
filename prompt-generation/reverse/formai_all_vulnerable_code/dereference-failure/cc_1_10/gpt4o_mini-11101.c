//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024

// Function to compress the input string using RLE (Run Length Encoding)
char* compress(const char* input) {
    int length = strlen(input);
    char* output = (char*)malloc(MAX_BUFFER);
    if (!output) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    int count;
    int j = 0;

    for (int i = 0; i < length; i++) {
        // Count occurrences of the current character
        count = 1;

        while (i + 1 < length && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        // Store current character and its count
        j += sprintf(&output[j], "%c%d", input[i], count);
    }

    output[j] = '\0';
    return output;
}

// Function to decompress the previously compressed string
char* decompress(const char* input) {
    char* output = (char*)malloc(MAX_BUFFER);
    if (!output) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    int j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];
        i++;
        
        // Read the count of occurrences
        int count = 0;
        while (input[i] >= '0' && input[i] <= '9') {
            count = count * 10 + (input[i] - '0');
            i++;
        }
        // Increase index to point back to the last valid position
        i--;

        // Append the character 'count' times
        for (int k = 0; k < count; k++) {
            output[j++] = ch;
        }
    }
    
    output[j] = '\0';
    return output;
}

// Main function to test the compression and decompression
int main() {
    char input[MAX_BUFFER];
    printf("Enter a string to compress: ");
    fgets(input, MAX_BUFFER, stdin);
    
    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;

    // Compress the input string
    char* compressed = compress(input);
    printf("Compressed: %s\n", compressed);

    // Decompress the compressed string
    char* decompressed = decompress(compressed);
    printf("Decompressed: %s\n", decompressed);

    // Free allocated memory
    free(compressed);
    free(decompressed);

    return 0;
}