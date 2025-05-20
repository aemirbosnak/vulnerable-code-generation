//FormAI DATASET v1.0 Category: Compression algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold compressed data and size
typedef struct {
    char* data;
    size_t size;
} CompressedData;


// Function to compress a given string using RLE
CompressedData compressRLE(char* str) {
    char* compressed = malloc(sizeof(char));
    size_t compressedSize = 0;
    int currentCount = 1;
    char currentChar = str[0];
    for (int i = 1; i <= strlen(str) + 1; i++) {
        if (str[i] == currentChar) {
            currentCount++;
        } else {
            compressedSize += sprintf(&compressed[compressedSize], "%c%i", currentChar, currentCount);
            currentCount = 1;
            currentChar = str[i];
        }
    }
    CompressedData output = {compressed, compressedSize};
    return output;
}


// Function to decompress a given string using RLE
char* decompressRLE(char* str) {
    char* decompressed = malloc(sizeof(char));
    size_t decompressedSize = 0;
    for (int i = 0; i < strlen(str); i += 2) {
        int count = str[i+1] - '0';
        for (int j = 0; j < count; j++) {
            decompressedSize += sprintf(&decompressed[decompressedSize], "%c", str[i]);
        }
    }
    return decompressed;
}

int main() {
    // Compress and decompress a test string
    char* test = "AAABBBCCCDDD";
    printf("Original string: %s\n", test);
    CompressedData compressed = compressRLE(test);
    printf("Compressed string: %s\n", compressed.data);
    char* decompressed = decompressRLE(compressed.data);
    printf("Decompressed string: %s\n", decompressed);
    free(compressed.data);
    free(decompressed);

    return 0;
}