//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the input string using Run-Length Encoding
char* compress(const char* input) {
    int n = strlen(input);
    char* compressed = (char*)malloc(2 * n + 1);  // Maximum possible size
    if (compressed == NULL) {
        perror("Failed to allocate memory for compression");
        exit(EXIT_FAILURE);
    }

    int count = 1;
    int index = 0;

    for (int i = 1; i <= n; i++) {
        if (input[i] == input[i - 1]) {
            count++;
        } else {
            index += sprintf(compressed + index, "%c%d", input[i - 1], count);
            count = 1;
        }
    }

    compressed[index] = '\0';
    return compressed;
}

// Function to decompress the compressed string
char* decompress(const char* compressed) {
    char* decompressed = (char*)malloc(2 * strlen(compressed) + 1); // Max possible size
    if (decompressed == NULL) {
        perror("Failed to allocate memory for decompression");
        exit(EXIT_FAILURE);
    }

    int index = 0;
    for (int i = 0; compressed[i] != '\0'; i++) {
        char ch = compressed[i];
        i++;
        int count = 0;
        while (compressed[i] >= '0' && compressed[i] <= '9') {
            count = count * 10 + (compressed[i] - '0');
            i++;
        }
        i--; // to counter the last increment
        for (int j = 0; j < count; j++) {
            decompressed[index++] = ch;
        }
    }

    decompressed[index] = '\0';
    return decompressed;
}

int main() {
    char input[256];

    printf("Enter a string to compress: ");
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character if present
    input[strcspn(input, "\n")] = 0;

    // Compress the input
    char* compressed = compress(input);
    printf("Compressed: %s\n", compressed);

    // Decompress the compressed string
    char* decompressed = decompress(compressed);
    printf("Decompressed: %s\n", decompressed);

    // Clean up
    free(compressed);
    free(decompressed);
    
    return 0;
}