//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

// Compression algorithm: "Grateful Decomposition"

// Decomposition function:
int decomposite(char *str, int len) {
    int i, j, k, count = 0;
    char *ptr = str;

    // Step 1: Find all consecutive repeated characters
    for (i = 0; i < len; i++) {
        if (ptr[i] == ptr[i + 1]) {
            count++;
            ptr++;
        }
    }

    // Step 2: Replace repeated characters with a single character
    for (i = 0; i < len; i++) {
        if (ptr[i] == ptr[i + 1]) {
            ptr[i] = '*';
        }
    }

    // Step 3: Compress the string
    for (i = 0; i < len; i++) {
        if (ptr[i] == '*') {
            ptr[i] = count;
            count = 0;
        }
    }

    return len - count;
}

// Compression function:
int compress(char *str) {
    int len = strlen(str);
    char *decomposed = decomposite(str, len);
    return strlen(decomposed);
}

int main() {
    char str[] = "Hello World!";
    int len = strlen(str);
    char *decomposed = decomposite(str, len);
    printf("Original string: %s\n", str);
    printf("Decomposed string: %s\n", decomposed);
    printf("Compressed string: %s\n", compress(str));
    return 0;
}