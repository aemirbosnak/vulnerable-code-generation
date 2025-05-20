//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress a string using Run-Length Encoding
char* compress(const char* input) {
    int n = strlen(input);
    char* compressed = malloc(n * 2 + 1); // worst case scenario
    if (!compressed) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    int count = 1;
    int j = 0;

    for (int i = 1; i <= n; i++) {
        if (input[i] == input[i - 1]) {
            count++;
        } else {
            j += sprintf(compressed + j, "%c%d", input[i - 1], count);
            count = 1;
        }
    }

    compressed[j] = '\0';
    return compressed;
}

// Function to decompress a string using Run-Length Encoding
char* decompress(const char* input) {
    char* decompressed = malloc(strlen(input) * 10 + 1); // arbitrary upper limit
    if (!decompressed) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    int j = 0;
    for (int i = 0; i < strlen(input); i += 2) {
        char ch = input[i];
        int count = input[i + 1] - '0'; // convert character to integer

        for (int k = 0; k < count; k++) {
            decompressed[j++] = ch;
        }
    }

    decompressed[j] = '\0';
    return decompressed;
}

// Function to demonstrate compression and decompression
void demonstrate_rle(const char* original) {
    printf("Original: %s\n", original);

    char* compressed = compress(original);
    printf("Compressed: %s\n", compressed);

    char* decompressed = decompress(compressed);
    printf("Decompressed: %s\n", decompressed);

    // Clean up memory
    free(compressed);
    free(decompressed);
}

// Main function
int main() {
    const char* input_string = "aaabbbcccaaa";
    
    demonstrate_rle(input_string);

    return 0;
}