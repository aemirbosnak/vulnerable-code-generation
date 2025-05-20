//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16

unsigned char key[KEY_SIZE] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F };

void encrypt(unsigned char *data, size_t data_len) {
    for (size_t i = 0; i < data_len; i++) {
        data[i] ^= key[i % KEY_SIZE];
    }
}

void decrypt(unsigned char *data, size_t data_len) {
    for (size_t i = 0; i < data_len; i++) {
        data[i] ^= key[i % KEY_SIZE];
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file\n");
        return EXIT_FAILURE;
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening output file\n");
        return EXIT_FAILURE;
    }

    fseek(input_file, 0, SEEK_END);
    size_t input_file_len = ftell(input_file);
    rewind(input_file);

    unsigned char *data = malloc(input_file_len);
    if (data == NULL) {
        fprintf(stderr, "Error allocating memory for input file data\n");
        return EXIT_FAILURE;
    }

    fread(data, 1, input_file_len, input_file);
    fclose(input_file);

    encrypt(data, input_file_len);

    fwrite(data, 1, input_file_len, output_file);
    fclose(output_file);

    free(data);

    return EXIT_SUCCESS;
}