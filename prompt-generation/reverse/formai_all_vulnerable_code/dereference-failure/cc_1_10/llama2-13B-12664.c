//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Structure to hold the compressed data
typedef struct {
    char *data;
    size_t size;
} compressed_data_t;

// Function to compress data using a custom algorithm
compressed_data_t *compress(const char *data, size_t size) {
    // Step 1: Remove repeated characters
    char *new_data = malloc(size + 1);
    for (size_t i = 0; i < size; i++) {
        if (i > 0 && data[i] == data[i - 1]) {
            // Repeat the previous character
            for (size_t j = 0; j < 3; j++) {
                new_data[i + j] = data[i - j];
            }
            i += 2;
        } else {
            new_data[i] = data[i];
        }
    }

    // Step 2: Replace consecutive identical runs with a single character
    for (size_t i = 0; i < size; i++) {
        if (i > 0 && new_data[i] == new_data[i - 1]) {
            new_data[i] = 'x';
        }
    }

    // Step 3: Compress the remaining runs of identical characters
    for (size_t i = 0; i < size; i++) {
        if (i > 0 && new_data[i] == new_data[i - 1]) {
            size_t j = i + 1;
            while (j < size && new_data[j] == new_data[i]) {
                j++;
            }
            new_data[i] = 'x';
            i = j - 1;
        }
    }

    // Step 4: Store the compressed data
    compressed_data_t *cd = malloc(sizeof(compressed_data_t));
    cd->data = new_data;
    cd->size = size;
    return cd;
}

// Function to decompress data using the custom algorithm
char *decompress(const compressed_data_t *cd) {
    // Step 1: Remove 'x' characters and repeat the previous character
    char *decompressed = malloc(cd->size + 1);
    size_t i = 0;
    while (i < cd->size) {
        if (cd->data[i] == 'x') {
            decompressed[i] = cd->data[i - 1];
            i++;
        } else {
            decompressed[i] = cd->data[i];
        }
        i++;
    }

    // Step 2: Replace consecutive identical runs with the original character
    for (size_t i = 0; i < cd->size; i++) {
        if (decompressed[i] == 'x') {
            decompressed[i] = cd->data[i - 1];
        }
    }

    // Step 3: Return the decompressed data
    return decompressed;
}

int main() {
    char data[] = "Hello, world!";
    size_t size = strlen(data);
    compressed_data_t *cd = compress(data, size);
    char *decompressed = decompress(cd);
    printf("%s\n", decompressed);
    free(decompressed);
    free(cd);
    return 0;
}