//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress a string using Run-Length Encoding
char* compress(const char* input) {
    int length = strlen(input);
    // Allocate enough space for the compressed string
    char* compressed = malloc(length * 2 + 1); // Worst case scenario
    int count = 1, index = 0;
    
    for (int i = 0; i < length; i++) {
        // Count occurrences of the current character
        if (i + 1 < length && input[i] == input[i + 1]) {
            count++;
        } else {
            // Write the character and its count to the compressed string
            index += sprintf(compressed + index, "%c%d", input[i], count);
            count = 1; // Reset count for the next character
        }
    }
    
    return compressed;
}

// Function to decompress a string encoded with Run-Length Encoding
char* decompress(const char* compressed) {
    int length = strlen(compressed);
    char* decompressed = malloc(length * 2); // Allocate space for decompressed string
    int index = 0, i = 0;

    while (i < length) {
        char ch = compressed[i++];
        int count = 0;
        
        // Capture the digit which indicates how many times 'ch' occurred
        while (i < length && '0' <= compressed[i] && compressed[i] <= '9') {
            count = count * 10 + (compressed[i] - '0');
            i++;
        }

        // Append the character 'ch' to decompressed string 'count' times
        memset(decompressed + index, ch, count);
        index += count;
    }
    decompressed[index] = '\0'; // Null-terminate the decompressed string

    return decompressed;
}

int main() {
    char input[256];
    
    printf("Enter a string to compress: ");
    fgets(input, sizeof(input), stdin);
    
    // Remove the newline character read by fgets
    input[strcspn(input, "\n")] = '\0';
    
    // Compress the input string
    char* compressed = compress(input);
    printf("Compressed string: %s\n", compressed);
    
    // Decompress the compressed string
    char* decompressed = decompress(compressed);
    printf("Decompressed string: %s\n", decompressed);
    
    // Clean up allocated memory
    free(compressed);
    free(decompressed);
    
    return 0;
}