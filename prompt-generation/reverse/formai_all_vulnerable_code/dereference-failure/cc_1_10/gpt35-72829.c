//FormAI DATASET v1.0 Category: Compression algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Compresses a string using Run-length encoding.
 *
 * @param str The string to compress.
 * @return The compressed string or NULL if failed.
 */
char* compress_rle(const char* str) {
    if (str == NULL) {
        return NULL;
    }

    size_t len = strlen(str);
    char* out = (char*) malloc(sizeof(char) * (len * 2 + 1));
    if (out == NULL) {
        return NULL;
    }

    size_t idx = 0;
    char last_char = str[0];
    size_t count = 1;
    for (size_t i = 1; i <= len; i++) {
        if (str[i] == last_char && count < 255) {
            count++;
        } else {
            out[idx++] = last_char;
            out[idx++] = count;
            last_char = str[i];
            count = 1;
        }
    }

    return out;
}

/**
 * Decompresses a string that was compressed using Run-length encoding.
 *
 * @param str The compressed string.
 * @return The decompressed string or NULL if failed.
 */
char* decompress_rle(const char* str) {
    if (str == NULL) {
        return NULL;
    }

    size_t len = strlen(str) / 2;
    char* out = (char*) malloc(sizeof(char) * (len + 1));
    if (out == NULL) {
        return NULL;
    }

    size_t idx = 0;
    for (size_t i = 0; i < len; i++) {
        char ch = str[i * 2];
        char count = str[i * 2 + 1];
        for (size_t j = 0; j < count; j++) {
            out[idx++] = ch;
        }
    }
    out[idx] = '\0';

    return out;
}

/**
 * Main function.
 */
int main(void) {
    const char* str = "AAAAABBBCCCCCDDEEE";
    printf("Original string: %s\n", str);

    char* compressed = compress_rle(str);
    if (compressed == NULL) {
        printf("Failed to compress string.\n");
        return EXIT_FAILURE;
    }
    printf("Compressed string: %s\n", compressed);

    char* decompressed = decompress_rle(compressed);
    if (decompressed == NULL) {
        printf("Failed to decompress string.\n");
        return EXIT_FAILURE;
    }
    printf("Decompressed string: %s\n", decompressed);

    free(compressed);
    free(decompressed);

    return EXIT_SUCCESS;
}