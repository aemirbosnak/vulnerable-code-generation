//MISTRAL-7B DATASET v1.0 Category: Data recovery tool ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

void read_block(FILE *input, unsigned char *buffer) {
    size_t bytes_read;
    bytes_read = fread(buffer, 1, BLOCK_SIZE, input);
    if (bytes_read != BLOCK_SIZE) {
        perror("Error reading input file");
        exit(EXIT_FAILURE);
    }
}

void write_block(FILE *output, unsigned char *buffer) {
    size_t bytes_written;
    bytes_written = fwrite(buffer, 1, BLOCK_SIZE, output);
    if (bytes_written != BLOCK_SIZE) {
        perror("Error writing output file");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv) {
    FILE *input, *output;
    unsigned char buffer[BLOCK_SIZE];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    input = fopen(argv[1], "rb");
    if (input == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    output = fopen(argv[2], "wb");
    if (output == NULL) {
        fclose(input);
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    while (!feof(input)) {
        read_block(input, buffer);
        write_block(output, buffer);
    }

    fclose(input);
    fclose(output);

    printf("Data recovery completed successfully.\n");

    return EXIT_SUCCESS;
}