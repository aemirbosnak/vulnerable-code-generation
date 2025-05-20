//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 1024
#define DELTA 3

// Structure to store compressed data
typedef struct {
    char *data;
    int len;
} compressed_data_t;

// Function to compress data
compressed_data_t *compress(char *data, int len) {
    int i, j, k;
    char *ptr, *temp;
    compressed_data_t *cd;

    // Step 1: Find repeated characters
    for (i = 0; i < len; i++) {
        if (data[i] == data[i + 1]) {
            // Repeat the character 'data[i]' for 'DELTA' times
            for (j = 1; j < DELTA; j++) {
                data[i + j] = data[i];
            }
            i += DELTA - 1;
        }
    }

    // Step 2: Find runs of identical characters
    for (i = 0; i < len; i++) {
        if (data[i] != data[i + 1]) {
            // Find the end of the run
            for (j = i + 1; j < len; j++) {
                if (data[j] == data[i]) {
                    // Compress the run
                    for (k = i; k < j; k++) {
                        data[k] = '!';
                    }
                    i = j;
                    break;
                }
            }
        }
    }

    // Step 3: Compress the remaining characters
    for (i = i; i < len; i++) {
        data[i] = '!';
    }

    // Allocate memory for the compressed data
    cd = (compressed_data_t *)malloc(sizeof(compressed_data_t));
    cd->data = data;
    cd->len = i;

    return cd;
}

// Function to decompress data
char *decompress(compressed_data_t *cd) {
    int i, j;
    char *ptr, *temp;

    // Step 1: Find the length of the compressed data
    int len = 0;
    for (i = 0; i < cd->len; i++) {
        if (cd->data[i] == '!') {
            len++;
        }
    }

    // Step 2: Decompress the data
    char *decompressed = (char *)malloc(len * sizeof(char));
    ptr = decompressed;
    for (i = 0; i < cd->len; i++) {
        if (cd->data[i] == '!') {
            *ptr = cd->data[i + 1];
            i++;
            ptr++;
        } else {
            *ptr = cd->data[i];
            ptr++;
        }
    }

    // Free the compressed data
    free(cd->data);

    return decompressed;
}

int main() {
    char data[] = "Hello World!";
    int len = strlen(data);

    // Compress the data
    compressed_data_t *cd = compress(data, len);

    // Decompress the data
    char *decompressed = decompress(cd);

    // Print the original and decompressed data
    printf("Original Data: %s\n", data);
    printf("Decompressed Data: %s\n", decompressed);

    return 0;
}