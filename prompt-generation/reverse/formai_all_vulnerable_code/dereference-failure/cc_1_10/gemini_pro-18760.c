//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char key[32]; // 256-bit key

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *input = fopen(argv[1], "rb");
    if (input == NULL) {
        perror("fopen(input)");
        exit(EXIT_FAILURE);
    }

    FILE *output = fopen(argv[2], "wb");
    if (output == NULL) {
        perror("fopen(output)");
        exit(EXIT_FAILURE);
    }

    // Read the file into memory
    fseek(input, 0, SEEK_END);
    long size = ftell(input);
    fseek(input, 0, SEEK_SET);

    unsigned char *buffer = malloc(size);
    if (buffer == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    if (fread(buffer, size, 1, input) != 1) {
        perror("fread");
        exit(EXIT_FAILURE);
    }

    fclose(input);

    // Encrypt the file
    for (long i = 0; i < size; i++) {
        buffer[i] ^= key[i % 32];
    }

    // Write the encrypted file to disk
    if (fwrite(buffer, size, 1, output) != 1) {
        perror("fwrite");
        exit(EXIT_FAILURE);
    }

    fclose(output);
    free(buffer);

    return EXIT_SUCCESS;
}