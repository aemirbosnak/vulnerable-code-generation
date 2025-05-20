//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_INPUT_SIZE 10000
#define BUF_SIZE 256

typedef struct {
    uint8_t data;
    uint8_t count;
} compress_t;

void compress(uint8_t *input, uint8_t *output, size_t len) {
    size_t i = 0, o = 0;
    compress_t *buf = calloc(1, BUF_SIZE * sizeof(compress_t));

    if (!buf) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(1);
    }

    while (i < len) {
        buf[o].data = input[i];
        buf[o].count = 1;

        while (++i < len && buf[o].data == input[i]) {
            buf[o].count++;
        }

        if (o < BUF_SIZE - 1) {
            o++;
        } else {
            while (o > 0 && buf[o - 1].count == 0) {
                output[o] = buf[o - 1].data;
                o--;
            }

            output[o++] = buf[o - 1].data;
            output[o++] = buf[o - 1].count;

            o = 0;
        }
    }

    while (o > 0 && buf[o - 1].count == 0) {
        output[o++] = buf[o - 1].data;
    }

    free(buf);

    if (o > 0) {
        output[o++] = buf[o - 1].data;
        output[o++] = buf[o - 1].count;
    }

    output[o] = '\0';
}

int main() {
    uint8_t input[MAX_INPUT_SIZE] = { 0 };
    uint8_t *output = NULL;
    size_t len = 0;

    printf("Enter the input data (up to %ld bytes):\n", MAX_INPUT_SIZE);
    fread(input, 1, MAX_INPUT_SIZE, stdin);

    len = sizeof(uint8_t) * (1 + ((input[0] >> 5) + 1) * (1 + (input[0] & 31)));
    output = calloc(1, len);

    compress(input, output, sizeof(input));

    printf("Compressed data size: %ld bytes\n", len);
    printf("Compressed data: ");
    fwrite(output, 1, len, stdout);
    free(output);

    return 0;
}