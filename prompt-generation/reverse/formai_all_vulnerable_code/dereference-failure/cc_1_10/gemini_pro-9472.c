//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024

// Function to compress a string using run-length encoding
char* compress(char* str) {
    int str_len = strlen(str);
    char* compressed_str = malloc(str_len + 1); // +1 for null-terminator
    int compressed_idx = 0;

    int count = 1;
    char prev_char = str[0];
    for (int i = 1; i < str_len; i++) {
        char curr_char = str[i];

        if (curr_char != prev_char) {
            compressed_str[compressed_idx++] = prev_char;
            compressed_str[compressed_idx++] = count + '0'; // Convert count to char
            count = 1;
            prev_char = curr_char;
        } else {
            count++;
        }
    }

    compressed_str[compressed_idx++] = prev_char;
    compressed_str[compressed_idx++] = count + '0'; // Convert count to char
    compressed_str[compressed_idx] = '\0';

    return compressed_str;
}

// Function to decompress a string using run-length encoding
char* decompress(char* compressed_str) {
    int compressed_len = strlen(compressed_str);
    char* decompressed_str = malloc(compressed_len * 3); // Worst case: each char is repeated 3 times
    int decompressed_idx = 0;

    for (int i = 0; i < compressed_len; i++) {
        char curr_char = compressed_str[i];
        int repeat_count = compressed_str[i + 1] - '0'; // Convert char to int

        for (int j = 0; j < repeat_count; j++) {
            decompressed_str[decompressed_idx++] = curr_char;
        }

        i++; // Skip the repeat count
    }

    decompressed_str[decompressed_idx] = '\0';

    return decompressed_str;
}

int main() {
    char str[] = "AAABBBCCCDDDDD";
    printf("Original string: %s\n", str);

    char* compressed_str = compress(str);
    printf("Compressed string: %s\n", compressed_str);

    char* decompressed_str = decompress(compressed_str);
    printf("Decompressed string: %s\n", decompressed_str);

    free(compressed_str);
    free(decompressed_str);

    return 0;
}