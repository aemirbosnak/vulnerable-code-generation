//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress a string
char* compressString(char* str) {
    char* compressedString = (char*)malloc(strlen(str) * sizeof(char));
    char* currentChar = compressedString;
    int count = 1;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == str[i+1]) {
            count++;
        } else {
            *currentChar = str[i];
            currentChar++;
            count = 1;
        }
    }
    *currentChar = '\0';
    return compressedString;
}

// Function to decompress a string
char* decompressString(char* str) {
    char* decompressedString = (char*)malloc(strlen(str) * sizeof(char));
    char* currentChar = decompressedString;
    int count = 1;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == str[i+1]) {
            count++;
        } else {
            *currentChar = str[i];
            currentChar++;
            count = 1;
        }
    }
    *currentChar = '\0';
    return decompressedString;
}

int main() {
    char* str = "aaaaaaaaaa";
    char* compressed = compressString(str);
    printf("Compressed string: %s\n", compressed);
    char* decompressed = decompressString(compressed);
    printf("Decompressed string: %s\n", decompressed);
    free(compressed);
    free(decompressed);
    return 0;
}