//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void compress(const unsigned char *input, size_t input_len, unsigned char *output) {
    size_t i = 0;
    unsigned char current_byte = input[0];
    size_t byte_count = 1;

    // Initialize dynamic array with initial byte count
    size_t *byte_count_table = calloc(256, sizeof(size_t));
    byte_count_table[current_byte] = byte_count;

    for (; i < input_len; i++) {
        if (input[i] == current_byte) {
            byte_count++;
        } else {
            // Write byte count and current byte to output
            size_t bytes_written = 1;
            output[i - byte_count] = current_byte;
            bytes_written += sizeof(current_byte);
            bytes_written += sizeof(byte_count);

            // Update current byte and byte count
            current_byte = input[i];
            byte_count = 1;

            // Update byte count table
            byte_count_table[current_byte] = byte_count;
        }
    }

    // Write remaining byte and byte count to output
    size_t bytes_written = 1;
    output[i - byte_count] = current_byte;
    bytes_written += sizeof(current_byte);
    bytes_written += sizeof(byte_count);

    free(byte_count_table);

    // Adjust output size
    size_t output_len = i + bytes_written;
    memmove(output + bytes_written, output, output_len - bytes_written);

    // Set new output size
    output_len -= bytes_written;
    printf("Compressed %lu bytes to %lu bytes.\n", input_len, output_len);
}

int main() {
    unsigned char input[BUFFER_SIZE] = "AaaaaBbbbbCccccaabbbb";
    unsigned char output[BUFFER_SIZE];
    size_t input_len = strlen((const char *)input);

    compress(input, input_len, output);

    // Print compressed output
    for (size_t i = 0; i < BUFFER_SIZE; i++) {
        if (i > 0 && (i % 16) == 0) printf("\n");
        printf("%02X ", output[i]);
    }

    return 0;
}