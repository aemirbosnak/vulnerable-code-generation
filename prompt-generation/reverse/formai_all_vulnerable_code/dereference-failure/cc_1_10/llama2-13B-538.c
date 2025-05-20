//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024
#define REPETITION_THRESHOLD 3

// Structure to hold the compressed data
typedef struct {
    char *data;
    int len;
} compressed_data_t;

// Function to compress the data
compressed_data_t* compress(char *data, int len) {
    // Step 1: Find the maximum repetition threshold
    int max_repetition = 0;
    for (int i = 0; i < len; i++) {
        if (data[i] > max_repetition) {
            max_repetition = data[i];
        }
    }

    // Step 2: Replace all repetitions with a reference to the repetition threshold
    compressed_data_t* compressed = (compressed_data_t*)calloc(1, sizeof(compressed_data_t));
    compressed->data = (char*)calloc(len, 1);
    int curr_idx = 0;
    for (int i = 0; i < len; i++) {
        if (data[i] == max_repetition) {
            compressed->data[curr_idx] = '*';
            curr_idx++;
        } else {
            compressed->data[curr_idx] = data[i];
        }
        curr_idx++;
    }
    compressed->len = curr_idx;

    return compressed;
}

// Function to decompress the data
char* decompress(compressed_data_t* compressed) {
    char* decompressed = (char*)calloc(compressed->len, 1);
    int curr_idx = 0;
    for (int i = 0; i < compressed->len; i++) {
        if (compressed->data[i] == '*') {
            decompressed[curr_idx] = compressed->data[i + 1];
            curr_idx++;
        } else {
            decompressed[curr_idx] = compressed->data[i];
        }
    }
    return decompressed;
}

int main() {
    char data[] = "AAAAAAABBBBBCCCCCC";
    int len = strlen(data);
    compressed_data_t* compressed = compress(data, len);
    char* decompressed = decompress(compressed);
    printf("Original data: %s\n", data);
    printf("Compressed data: %s\n", compressed->data);
    printf("Decompressed data: %s\n", decompressed);
    free(compressed);
    free(decompressed);
    return 0;
}