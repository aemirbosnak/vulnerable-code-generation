//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress a string using Run-Length Encoding (RLE)
char* compressRLE(const char* input) {
    int len = strlen(input);
    char* compressed = malloc(2 * len + 1); // Allocate maximum possible size
    if (!compressed) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    int index = 0;
    for (int i = 0; i < len; i++) {
        // Count occurrences of the current character
        int count = 1;
        while (i + 1 < len && input[i] == input[i + 1]) {
            count++;
            i++;
        }
        // Store the character and its count
        index += sprintf(compressed + index, "%c%d", input[i], count);
    }
    compressed[index] = '\0'; // Null-terminate the string

    return compressed;
}

// Function to decompress a string encoded with Run-Length Encoding (RLE)
char* decompressRLE(const char* compressed) {
    int len = strlen(compressed);
    char* decompressed = malloc(2 * len + 1); // Allocate maximum possible size
    if (!decompressed) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    int index = 0;
    for (int i = 0; i < len; i++) {
        char currentChar = compressed[i];
        i++;
        int count = 0;

        // Read the number of occurrences
        while (i < len && compressed[i] >= '0' && compressed[i] <= '9') {
            count = count * 10 + (compressed[i] - '0');
            i++;
        }
        i--; // Adjust for the outer loop increment

        // Append the expanded characters to decompressed string
        for (int j = 0; j < count; j++) {
            decompressed[index++] = currentChar;
        }
    }
    decompressed[index] = '\0'; // Null-terminate the string

    return decompressed;
}

int main() {
    char input[256];

    printf("Enter a string to compress: ");
    fgets(input, sizeof(input), stdin);
    // Remove newline character if it exists
    size_t length = strlen(input);
    if (length > 0 && input[length - 1] == '\n') {
        input[length - 1] = '\0';
    }

    char* compressed = compressRLE(input);
    printf("Compressed string: %s\n", compressed);

    char* decompressed = decompressRLE(compressed);
    printf("Decompressed string: %s\n", decompressed);

    // Free allocated memory
    free(compressed);
    free(decompressed);

    return 0;
}