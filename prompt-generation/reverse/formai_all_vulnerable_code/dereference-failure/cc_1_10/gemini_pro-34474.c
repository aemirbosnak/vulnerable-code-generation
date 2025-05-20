//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Function to compress a string using run-length encoding
char *compress(char *str) {
    int len = strlen(str);
    int outlen = 0;
    char *out = malloc(len * 2 + 1);  // Worst case: every character is unique

    char prev = str[0];
    int count = 1;
    for (int i = 1; i < len; i++) {
        if (str[i] == prev) {
            count++;
        } else {
            // If the character changes, encode the previous character
            sprintf(out + outlen, "%c%d", prev, count);
            outlen += strlen(out + outlen);
            prev = str[i];
            count = 1;
        }
    }

    // Encode the last character
    sprintf(out + outlen, "%c%d", prev, count);
    outlen += strlen(out + outlen);

    return out;
}

// Function to decompress a string compressed using run-length encoding
char *decompress(char *str) {
    int len = strlen(str);
    char *out = malloc(len * 2 + 1);  // Worst case: no compression

    int outlen = 0;
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) {  // Character
            count = str[i + 1] - '0';
        } else {  // Count
            for (int j = 0; j < count; j++) {
                out[outlen++] = str[i - 1];
            }
        }
    }

    return out;
}

int main() {
    char *str = "AAABBBCCCDDEEE";
    printf("Original string: %s\n", str);

    // Compress the string
    char *compressed = compress(str);
    printf("Compressed string: %s\n", compressed);

    // Decompress the string
    char *decompressed = decompress(compressed);
    printf("Decompressed string: %s\n", decompressed);

    free(compressed);
    free(decompressed);

    return 0;
}