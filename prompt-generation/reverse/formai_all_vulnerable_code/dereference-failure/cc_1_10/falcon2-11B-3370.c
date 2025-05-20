//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress a string using RLE
void compressString(char* str, int* compressedSize) {
    int length = strlen(str);
    int count = 1;
    int i;
    for (i = 1; i < length; i++) {
        if (str[i] == str[i - 1]) {
            count++;
        } else {
            *compressedSize = (*compressedSize) + 1;
            printf("compressed size: %d\n", *compressedSize);
            if (*compressedSize > 100) {
                // Handle large compressed size
                // Implement your solution here
                break;
            }
            count = 1;
            str[(*compressedSize - 1)] = str[i];
        }
    }
    if (count > 1) {
        str[(*compressedSize - 1)] = str[i];
    }
    *compressedSize = *compressedSize + 1;
    printf("compressed size: %d\n", *compressedSize);
}

// Function to decompress a compressed string using RLE
void decompressString(char* compressed, int compressedSize, char* str) {
    int i;
    for (i = 0; i < compressedSize; i++) {
        if (compressed[i]!= '0') {
            str[i] = compressed[i];
        } else {
            int count = 0;
            for (; count < compressed[i + 1]; count++) {
                str[i] = compressed[i + 2 * count];
            }
        }
    }
}

int main() {
    char str[1000];
    int compressedSize = 0;
    compressString(str, &compressedSize);
    printf("compressed size: %d\n", compressedSize);
    decompressString(compressedSize * 2, compressedSize, str);
    printf("decompressed string: %s\n", str);
    return 0;
}