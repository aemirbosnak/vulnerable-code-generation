//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

void compress_rle(uint8_t* data, size_t length) {
    size_t index = 0;
    size_t current_byte_index = 0;
    uint8_t current_byte = data[0];
    size_t count = 1;

    while (index < length) {
        if (data[index] == current_byte) {
            count++;
        } else {
            data[current_byte_index] = current_byte;
            current_byte = data[index];
            if (count > 1) {
                data[current_byte_index + 1] = (uint8_t)count;
                current_byte_index++;
            }
            current_byte_index = index;
            count = 1;
        }
        index++;
    }

    // Store the last byte and its count
    data[current_byte_index] = current_byte;
    if (count > 1) {
        data[current_byte_index + 1] = (uint8_t)count;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE* input_file = fopen(argv[1], "rb");
    if (!input_file) {
        perror("Error opening input file");
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    size_t file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    uint8_t* buffer = malloc(BUFFER_SIZE > file_size ? file_size : BUFFER_SIZE);
    size_t bytes_read = fread(buffer, 1, file_size, input_file);
    fclose(input_file);

    compress_rle(buffer, bytes_read);

    // Print the compressed data to stdout
    for (size_t i = 0; i < bytes_read; i++) {
        printf("%02x", buffer[i]);
    }

    free(buffer);
    return 0;
}