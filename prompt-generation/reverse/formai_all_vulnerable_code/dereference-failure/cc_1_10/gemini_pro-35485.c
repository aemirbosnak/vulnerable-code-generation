//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// A post-apocalyptic compression algorithm!
// It works by replacing a sequence of identical chars with a single char & a count.
// e.g. "aaabbbb" becomes "a3b4"

char *compress(char *input) {
    int i, j, count;
    char *compressed;

    // Pass 1: Count the number of characters in the compressed string
    count = 1;
    for (i = 1; input[i] != '\0'; i++) {
        if (input[i] == input[i - 1]) {
            count++;
        } else {
            count = 1;
        }
    }

    // Allocate memory for the compressed string
    compressed = (char *)malloc(count + 1);

    // Pass 2: Compress the string
    j = 0;
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] == input[i + 1]) {
            count++;
        } else {
            compressed[j++] = input[i];
            if (count > 1) {
                compressed[j++] = count + '0';
            }
            count = 1;
        }
    }
    compressed[j] = '\0';

    return compressed;
}

int main() {
    char *input = "aaabbbbcccdddeeeefff";
    char *compressed;

    // Compress the string
    compressed = compress(input);

    // Print the compressed string
    printf("%s\n", compressed);

    free(compressed);
    return 0;
}