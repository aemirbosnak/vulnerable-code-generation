//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(const char *input, char *output) {
    int len = strlen(input);
    int count;
    char lastChar = input[0];
    int outputIndex = 0;

    for (int i = 0; i < len; i++) {
        count = 1;

        // Count occurrences of the current character
        while (i + 1 < len && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        // Store the character and its count in the output
        outputIndex += sprintf(&output[outputIndex], "%c%d", lastChar, count);
        if (i + 1 < len) {
            lastChar = input[i + 1];
        }
    }
    output[outputIndex] = '\0'; // Null-terminate the output string
}

void decompress(const char *input, char *output) {
    int outputIndex = 0;
    char currentChar;
    int count;
    char *ptr = (char*)input;

    while (*ptr) {
        currentChar = *ptr++;
        count = 0;

        // Read the count value
        while (*ptr >= '0' && *ptr <= '9') {
            count = count * 10 + (*ptr - '0');
            ptr++;
        }

        // Expand the character into the output
        for (int i = 0; i < count; i++) {
            output[outputIndex++] = currentChar;
        }
    }
    output[outputIndex] = '\0'; // Null-terminate the output string
}

int main() {
    char input[100];
    char compressed[200];
    char decompressed[100];

    printf("Enter a string to compress: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    // Compression
    compress(input, compressed);
    printf("Compressed: %s\n", compressed);

    // Decompression
    decompress(compressed, decompressed);
    printf("Decompressed: %s\n", decompressed);

    return 0;
}