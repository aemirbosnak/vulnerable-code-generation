//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 256
#define BLOCK_SIZE 64

void xor_key(unsigned char *plaintext, unsigned char *key, int length) {
    for (int i = 0; i < length; i++) {
        plaintext[i] ^= key[i % KEY_SIZE];
    }
}

void encrypt_block(unsigned char *plaintext, unsigned char *key) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        plaintext[i] ^= key[i];
    }
}

void write_file(const char *filename, unsigned char *data, int length) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fwrite(data, length, 1, file);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    unsigned char *input_file = malloc(strlen(argv[1]) + 1);
    strcpy(input_file, argv[1]);

    unsigned char *output_file = malloc(strlen(argv[2]) + 1);
    strcpy(output_file, argv[2]);

    unsigned char *key = malloc(KEY_SIZE);
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = i;
    }

    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        perror("Error opening input file");
        free(input_file);
        free(output_file);
        free(key);
        exit(EXIT_FAILURE);
    }

    fseek(input, 0, SEEK_END);
    int file_size = ftell(input);
    rewind(input);

    unsigned char *plaintext = malloc(file_size);
    fread(plaintext, file_size, 1, input);

    xor_key(plaintext, key, file_size);

    unsigned char *encrypted = malloc(file_size);
    for (int i = 0; i < file_size; i += BLOCK_SIZE) {
        encrypt_block(&plaintext[i], key);
        for (int j = 0; j < BLOCK_SIZE; j++) {
            encrypted[i + j] = plaintext[i + j];
        }
    }

    free(input_file);
    free(output_file);
    free(input);

    write_file(output_file, encrypted, file_size);

    free(plaintext);
    free(encrypted);
    free(key);

    printf("File %s encrypted and written to %s.\n", argv[1], argv[2]);

    return EXIT_SUCCESS;
}