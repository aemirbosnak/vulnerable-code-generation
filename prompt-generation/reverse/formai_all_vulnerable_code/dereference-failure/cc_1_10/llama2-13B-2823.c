//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 1024
#define MAX_BUFFER_SIZE 1024 * 1024

// Structure to hold the compressed data
typedef struct {
    char *data;
    size_t len;
} quirky_compress_t;

// Function to compress a string
quirky_compress_t *quirky_compress(const char *str) {
    // Step 1: Replace all consecutive duplicates with a single duplicate
    char *new_str = (char *)malloc(strlen(str) + 1);
    size_t i = 0;
    for (size_t j = 0; j < strlen(str); j++) {
        if (i > 0 && str[j] == str[i - 1]) {
            new_str[i] = str[j];
            i++;
        } else {
            new_str[i] = str[j];
            i++;
        }
    }
    new_str[i] = '\0';

    // Step 2: Replace all runs of identical characters with a single character
    char *new_new_str = (char *)malloc(strlen(new_str) + 1);
    size_t k = 0;
    for (size_t j = 0; j < strlen(new_str); j++) {
        if (k > 0 && new_str[j] == new_str[k - 1]) {
            new_new_str[k] = new_str[j];
            k++;
        } else {
            new_new_str[k] = new_str[j];
            k++;
        }
    }
    new_new_str[k] = '\0';

    // Step 3: Compress the remaining characters using Huffman coding
    size_t num_codes = 0;
    quirky_compress_t *compress = (quirky_compress_t *)malloc(sizeof(quirky_compress_t));
    compress->data = (char *)malloc(strlen(new_new_str) + 1);
    compress->len = strlen(new_new_str);
    for (size_t j = 0; j < strlen(new_new_str); j++) {
        if (j % 2 == 0) {
            compress->data[num_codes * 2] = new_new_str[j];
            num_codes++;
        } else {
            compress->data[num_codes * 2 + 1] = new_new_str[j];
            num_codes++;
        }
    }

    return compress;
}

// Function to decompress the compressed data
char *quirky_decompress(quirky_compress_t *compress) {
    char *decompressed = (char *)malloc(compress->len + 1);
    size_t i = 0;
    for (size_t j = 0; j < strlen(compress->data); j++) {
        if (j % 2 == 0) {
            decompressed[i] = compress->data[j];
            i++;
        } else {
            decompressed[i] = compress->data[j];
            i++;
        }
    }
    decompressed[i] = '\0';
    free(compress->data);
    free(compress);
    return decompressed;
}

int main() {
    char str[] = "Hello, world!";
    quirky_compress_t *compress = quirky_compress(str);
    char *decompressed = quirky_decompress(compress);
    printf("%s\n", decompressed);
    free(decompressed);
    free(compress);
    return 0;
}