//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Structure to hold the compressed data
typedef struct {
    char *data;
    int length;
} compressed_data;

// Function to compress the data
compressed_data *compress(char *data, int length) {
    // Step 1: Replace consecutive duplicates with a single duplicate
    int i, j, k;
    char dup_char = 'a';
    for (i = 0; i < length; i++) {
        if (data[i] == data[i + 1]) {
            data[i] = dup_char;
            length--;
            i++;
        }
    }

    // Step 2: Replace runs of identical characters with a single character
    for (i = 0; i < length; i++) {
        if (data[i] == data[i + 1]) {
            data[i] = 'x';
            length--;
            i++;
        }
    }

    // Step 3: Compress the data using a custom dictionary
    char dictionary[] = "abcdefghijklmnopqrstuvwxyz";
    int dictionary_size = sizeof(dictionary) - 1;
    compressed_data *cd = (compressed_data *) malloc(sizeof(compressed_data));
    int pos = 0;
    for (i = 0; i < length; i++) {
        if (strchr(dictionary, data[i]) != NULL) {
            cd->data[pos] = data[i];
            pos++;
        } else {
            cd->data[pos] = data[i];
            pos++;
            cd->length++;
        }
    }
    cd->length++;
    return cd;
}

// Function to decompress the data
char *decompress(compressed_data *cd) {
    char *data = (char *) malloc(cd->length * sizeof(char));
    int i, j;
    for (i = 0; i < cd->length; i++) {
        if (cd->data[i] == 'x') {
            data[i] = 'a' + (cd->data[i + 1] - 'a');
            i++;
        } else {
            data[i] = cd->data[i];
        }
    }
    return data;
}

int main() {
    char data[] = "Hello World!";
    int length = strlen(data);
    compressed_data *cd = compress(data, length);
    char *decompressed = decompress(cd);
    printf("Original: %s\nCompressed: %s\nDecompressed: %s\n", data, cd->data, decompressed);
    free(cd);
    free(decompressed);
    return 0;
}