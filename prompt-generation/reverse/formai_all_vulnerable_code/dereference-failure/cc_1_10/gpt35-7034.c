//FormAI DATASET v1.0 Category: Compression algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress a string using the unique compression algorithm
char* compress(char* str) {
    int length = strlen(str);
    char curr_char, prev_char;
    int curr_count, i;
    char* compressed_str = (char*) malloc(sizeof(char) * length);
    int compressed_index = 0;

    if (compressed_str == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    if (length == 0) {
        printf("Empty string\n");
        return NULL;
    }

    curr_char = prev_char = str[0];
    curr_count = 1;

    for (i = 1; i <= length; i++) {
        curr_char = str[i];

        if (curr_char == prev_char) {
            curr_count++;
        } else {
            compressed_str[compressed_index++] = prev_char;
            compressed_str[compressed_index++] = (char) (curr_count + '0');
            curr_count = 1;
            prev_char = curr_char;
        }
    }

    compressed_str[compressed_index] = '\0';

    return compressed_str;
}

int main() {
    char* str = "aaabccddddde";
    char* compressed_str;

    compressed_str = compress(str);

    if (compressed_str == NULL) {
        return -1;
    }

    printf("Original string: %s\n", str);
    printf("Compressed string: %s\n", compressed_str);

    return 0;
}