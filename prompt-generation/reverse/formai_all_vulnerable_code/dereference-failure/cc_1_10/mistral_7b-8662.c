//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void compress_rle(unsigned char *input, size_t size, unsigned char *output) {
    unsigned char current = input[0];
    unsigned char count = 1;

    for (size_t i = 1; i < size; i++) {
        if (input[i] == current) {
            count++;
        } else {
            output[i] = current;
            if (count > 1) {
                output[i + 1] = count & 0xFF;
                i++;
            }
            current = input[i];
            count = 1;
        }
    }

    // Output the last character and count
    output[size] = current;
    if (count > 1) {
        output[size + 1] = count & 0xFF;
    }
}

int main() {
    unsigned char input[BUFFER_SIZE];
    unsigned char output[BUFFER_SIZE * 2];
    size_t size = 0;

    FILE *input_file = fopen("input.raw", "rb");

    if (input_file == NULL) {
        perror("Error opening input file");
        return 1;
    }

    while (fread(input, 1, BUFFER_SIZE, input_file) > 0) {
        size += BUFFER_SIZE;
    }

    fclose(input_file);

    compress_rle(input, size, output);

    FILE *output_file = fopen("output.raw", "wb");

    if (output_file == NULL) {
        perror("Error opening output file");
        return 1;
    }

    fwrite(output, 1, size + (size % 2 == 0 ? 1 : 0), output_file);

    fclose(output_file);

    free(output);

    printf("Compression completed.\n");

    return 0;
}