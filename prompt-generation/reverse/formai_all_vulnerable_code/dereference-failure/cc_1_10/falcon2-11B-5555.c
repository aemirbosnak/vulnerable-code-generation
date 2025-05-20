//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress a string
char* compress(char* str) {
    int len = strlen(str);
    char* compressed = (char*)malloc(len * sizeof(char));
    int i = 0;

    // Count the number of characters with the same value
    for (int j = 0; j < len - 1; j++) {
        if (str[j] == str[j + 1]) {
            i++;
        } else {
            compressed[i] = str[j];
            i = 1;
            compressed[i] = str[j + 1];
            i++;
        }
    }

    // Copy the last character
    compressed[i] = str[len - 1];

    return compressed;
}

// Function to decompress a string
char* decompress(char* str) {
    int len = strlen(str);
    char* decompressed = (char*)malloc(len * sizeof(char));
    int i = 0;

    // Decompress the string
    for (int j = 0; j < len; j++) {
        if (str[j] == '0') {
            decompressed[i++] = str[j + 1];
        } else {
            decompressed[i++] = str[j];
        }
    }

    // Copy the last character
    decompressed[i] = str[len];

    return decompressed;
}

int main() {
    char* str = "aaabbcc";
    char* compressed = compress(str);
    char* decompressed = decompress(compressed);

    printf("Compressed: %s\n", compressed);
    printf("Decompressed: %s\n", decompressed);

    free(compressed);
    free(decompressed);

    return 0;
}