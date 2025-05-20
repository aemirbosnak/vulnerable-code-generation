//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_MODE "rb+b"
#define BUFFER_SIZE 256
#define KEY 3

void encrypt_byte(unsigned char *byte) {
    *byte = (*byte + KEY > 255) ? (*byte + KEY - 255) : (*byte + KEY);
}

void encrypt_file(const char *input_file, const char *output_file) {
    FILE *input, *output;
    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;

    input = fopen(input_file, FILE_MODE);
    output = fopen(output_file, "wb");

    if (input == NULL || output == NULL) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    while ((bytes_read = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, input)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            encrypt_byte(&buffer[i]);
        }

        fwrite(buffer, sizeof(unsigned char), bytes_read, output);
    }

    fclose(input);
    fclose(output);
}

void decrypt_byte(unsigned char *byte) {
    *byte = (*byte - KEY < 0) ? (*byte - KEY + 255) : (*byte - KEY);
}

void decrypt_file(const char *input_file, const char *output_file) {
    FILE *input, *output;
    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;

    input = fopen(input_file, FILE_MODE);
    output = fopen(output_file, "wb");

    if (input == NULL || output == NULL) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    while ((bytes_read = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, input)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            decrypt_byte(&buffer[i]);
        }

        fwrite(buffer, sizeof(unsigned char), bytes_read, output);
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "-e") == 0) {
        encrypt_file(argv[2], argv[3]);
    } else if (strcmp(argv[1], "-d") == 0) {
        decrypt_file(argv[2], argv[3]);
    } else {
        fprintf(stderr, "Invalid option: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}