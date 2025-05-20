//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024
#define MAGIC_NUMBER 0x12345678

// Compression function
void compress(char* input, int len) {
    int i, j, k;
    char *output = malloc(len * 2);

    // Step 1: Replace consecutive duplicates with a single duplicate
    for (i = 0; i < len; i++) {
        if (i < len - 1 && input[i] == input[i + 1]) {
            output[j] = input[i];
            j++;
        } else {
            output[j] = input[i];
            j++;
        }
    }

    // Step 2: Replace runs of identical characters with a single character
    for (i = 0; i < len; i++) {
        if (i < len - 1 && output[i] == output[i + 1]) {
            output[j] = output[i];
            j++;
        } else {
            output[j] = output[i];
            j++;
        }
    }

    // Step 3: XOR all the characters with a magic number
    for (i = 0; i < len; i++) {
        output[j] = output[i] ^ MAGIC_NUMBER;
        j++;
    }

    // Step 4: Pad the output with zeros to make it a multiple of 4
    while (j % 4 != 0) {
        output[j] = 0;
        j++;
    }

    // Step 5: Print the compressed data
    printf("Compressed data (%d bytes):\n%s\n", j, output);

    // Free the memory
    free(output);
}

// Decompression function
void decompress(char* input, int len) {
    int i, j, k;
    char *output = malloc(len * 2);

    // Step 1: XOR all the characters with the magic number
    for (i = 0; i < len; i++) {
        output[j] = input[i] ^ MAGIC_NUMBER;
        j++;
    }

    // Step 2: Unpad the output
    while (j % 4 != 0) {
        output[j] = 0;
        j++;
    }

    // Step 3: Replace runs of identical characters with the original character
    for (i = 0; i < len; i++) {
        if (i < len - 1 && output[i] == output[i + 1]) {
            output[j] = output[i];
            j++;
        } else {
            output[j] = output[i];
            j++;
        }
    }

    // Step 4: Replace consecutive duplicates with the original character
    for (i = 0; i < len; i++) {
        if (i < len - 1 && output[i] == output[i + 1]) {
            output[j] = output[i];
            j++;
        } else {
            output[j] = output[i];
            j++;
        }
    }

    // Step 5: Print the decompressed data
    printf("Decompressed data (%d bytes):\n%s\n", j, output);

    // Free the memory
    free(output);
}

int main() {
    char input[] = "Hello, World!";
    int len = strlen(input);

    // Compress the data
    compress(input, len);

    // Decompress the data
    decompress(input, len);

    return 0;
}