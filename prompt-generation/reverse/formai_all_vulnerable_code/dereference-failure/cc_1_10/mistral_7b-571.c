//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void compress(unsigned char *input, size_t length, unsigned char *output) {
    size_t index = 0;
    unsigned char current = input[0];
    unsigned char count = 1;

    output[index++] = current;

    for (size_t i = 1; i < length; i++) {
        if (input[i] == current) {
            count++;
        } else {
            output[index++] = current;
            if (count > 1) {
                output[index++] = count;
                count = 0;
            }
            current = input[i];
        }
    }

    if (count > 0) {
        output[index++] = current;
        if (count > 1) {
            output[index++] = count;
        }
    }
}

int main() {
    unsigned char input_buffer[BUFFER_SIZE];
    unsigned char output_buffer[BUFFER_SIZE];
    size_t input_length = 0;

    while (fread(input_buffer, sizeof(unsigned char), BUFFER_SIZE, stdin) > 0) {
        input_length += BUFFER_SIZE;
    }

    rewind(stdin);

    unsigned char *input = malloc(input_length);
    unsigned char *output = malloc(input_length * 2); // 1 byte for each input byte + 1 byte for each count byte

    size_t bytes_read = 0;

    while (bytes_read < input_length) {
        size_t read = fread(&input[bytes_read], sizeof(unsigned char), BUFFER_SIZE, stdin);
        bytes_read += read;
    }

    compress(input, bytes_read, output);

    fwrite(output, sizeof(unsigned char), bytes_read * 2, stdout);

    free(input);
    free(output);

    return 0;
}