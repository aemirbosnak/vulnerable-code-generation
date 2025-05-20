//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHAR 256
#define BUFFER_SIZE 4096

typedef struct {
    unsigned char *buffer;
    size_t size;
} Compressor;

void compress(const unsigned char *input, size_t input_len, Compressor *compressor) {
    unsigned char current_char, prev_char;
    size_t i = 0, pos = 0;

    if (compressor->size < input_len) {
        compressor->buffer = realloc(compressor->buffer, input_len + BUFFER_SIZE);
        compressor->size += BUFFER_SIZE;
    }

    current_char = input[0];
    compressor->buffer[pos++] = (unsigned char)(input_len | 0x80); // length prefix
    compressor->buffer[pos++] = current_char;

    for (i = 1; i < input_len; i++) {
        if (input[i] != prev_char) {
            compressor->buffer[pos++] = prev_char | 0x40; // previous character indicator
            compressor->buffer[pos++] = current_char;
            prev_char = current_char;
            current_char = input[i];
        }
    }

    compressor->buffer[pos++] = prev_char | 0x40; // previous character indicator

    compressor->size = pos;
}

int main() {
    const unsigned char test_data[] = "AABBBCCCCDDDEEEFFF";
    size_t test_data_len = sizeof(test_data) / sizeof(test_data[0]);
    Compressor compressor = {NULL, 0};

    compress(test_data, test_data_len, &compressor);

    size_t i;
    for (i = 0; i < compressor.size; i++) {
        printf("%02X ", compressor.buffer[i]);
    }
    printf("\n");

    free(compressor.buffer);
    return 0;
}