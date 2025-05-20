//FormAI DATASET v1.0 Category: File Encyptor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open input and output files
    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        fprintf(stderr, "Cannot open input file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (!output_file) {
        fprintf(stderr, "Cannot open output file: %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    // Generate encryption key
    unsigned char key = (unsigned char) rand() % 256;

    // Write key to output file
    fwrite(&key, sizeof(unsigned char), 1, output_file);

    // Encrypt and write input file to output file
    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, input_file)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            buffer[i] ^= key;
        }

        fwrite(buffer, sizeof(unsigned char), bytes_read, output_file);
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    return EXIT_SUCCESS;
}