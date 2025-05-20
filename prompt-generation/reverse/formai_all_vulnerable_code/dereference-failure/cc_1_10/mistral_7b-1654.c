//MISTRAL-7B DATASET v1.0 Category: Performance-Critical Component ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BUFFER_SIZE 256

typedef unsigned char byte;
typedef struct {
    byte buffer[BUFFER_SIZE];
    size_t read_index;
    size_t write_index;
} CircularBuffer;

void compress(const byte* input, size_t length, byte* output) {
    CircularBuffer cb;
    byte current = input[0];
    size_t count = 0;

    cb.read_index = 0;
    cb.write_index = 0;

    output[cb.write_index++] = current;

    for (size_t i = 1; i < length; ++i) {
        if (input[i] == current) {
            ++count;
        } else {
            cb.buffer[cb.write_index++] = (byte)(count & 0xFF);
            current = input[i];
            count = 1;
        }
    }

    cb.buffer[cb.write_index++] = (byte)(count & 0xFF);

    for (size_t i = 0; i < cb.write_index; ++i) {
        output[i] = cb.buffer[i];
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.bin> <output.bin>\n", argv[0]);
        return 1;
    }

    FILE* input_file = fopen(argv[1], "rb");
    if (!input_file) {
        perror("Error opening input file");
        return 1;
    }

    size_t file_size = sizeof(size_t);
    fread(&file_size, file_size, 1, input_file);

    byte* input = malloc(file_size);
    fread(input, file_size, 1, input_file);
    fclose(input_file);

    byte* output = malloc(file_size + 256); // + buffer size

    compress(input, file_size, output);

    FILE* output_file = fopen(argv[2], "wb");
    if (!output_file) {
        perror("Error opening output file");
        free(output);
        free(input);
        return 1;
    }

    size_t written = fwrite(output, file_size + 256, 1, output_file);
    if (written != 1) {
        perror("Error writing to output file");
        free(output);
        free(input);
        fclose(output_file);
        return 1;
    }

    free(output);
    free(input);
    fclose(output_file);

    return 0;
}