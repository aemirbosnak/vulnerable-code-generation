//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: optimized
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_LEN 1024
#define BUFFER_SIZE 64

typedef struct {
    uint8_t *data;
    size_t len;
} buffer_t;

static inline uint8_t *next_byte(buffer_t *buffer) {
    return (uint8_t *)(buffer->data + buffer->len);
}

static inline size_t remaining(buffer_t *buffer) {
    return buffer->len - (size_t)((uint8_t *)buffer->data - buffer->data);
}

static inline void advance(buffer_t *buffer, size_t bytes) {
    buffer->len -= bytes;
    buffer->data += bytes;
}

static inline void compress(buffer_t *input, buffer_t *output) {
    size_t input_len = input->len;
    size_t output_len = 0;

    // Step 1: Find runs of identical bytes
    for (size_t i = 0; i < input_len; i++) {
        if (i > 0 && input->data[i] == input->data[i - 1]) {
            size_t run_len = 1;
            while (i + run_len < input_len && input->data[i + run_len] == input->data[i]) {
                run_len++;
            }
            output_len += run_len;
            advance(input, run_len);
        }
    }

    // Step 2: Compress runs of identical bytes
    for (size_t i = 0; i < output_len; i++) {
        if (i > 0 && output->data[i] == output->data[i - 1]) {
            size_t run_len = 1;
            while (i + run_len < output_len && output->data[i + run_len] == output->data[i]) {
                run_len++;
            }
            output_len -= run_len;
            advance(output, -run_len);
        }
    }

    // Step 3: Compress remaining bytes
    for (size_t i = 0; i < input_len; i++) {
        if (i < output_len) {
            output->data[i] = input->data[i];
        } else {
            output->data[i] = input->data[i] + (output_len - i);
        }
    }

    output->len = output_len;
}

int main() {
    buffer_t input = {
        .data = (uint8_t *)"Hello, world!",
        .len = strlen((char *)"Hello, world!")
    };

    buffer_t output = {
        .data = (uint8_t *)malloc(MAX_LEN),
        .len = 0
    };

    compress(&input, &output);

    printf("Compressed string: %s\n", (char *)output.data);

    free(output.data);

    return 0;
}