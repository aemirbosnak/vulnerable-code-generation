//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

void encrypt(byte* plaintext, byte* key, byte* ciphertext, size_t length) {
    for (size_t i = 0; i < length; ++i) {
        ciphertext[i] = plaintext[i] ^ key[i % strlen((char*)key)];
    }
}

void decrypt(byte* ciphertext, byte* key, byte* plaintext, size_t length) {
    encrypt(ciphertext, key, plaintext, length);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s plaintext key ciphertext\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE* plaintext_file = fopen(argv[1], "rb");
    if (plaintext_file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    FILE* key_file = fopen(argv[2], "rb");
    if (key_file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    FILE* ciphertext_file = fopen(argv[3], "wb");
    if (ciphertext_file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    fseek(plaintext_file, 0, SEEK_END);
    size_t plaintext_size = ftell(plaintext_file);
    rewind(plaintext_file);

    fseek(key_file, 0, SEEK_END);
    size_t key_size = ftell(key_file);
    rewind(key_file);

    byte* plaintext = malloc(plaintext_size);
    if (plaintext == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    byte* key = malloc(key_size);
    if (key == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    byte* ciphertext = malloc(plaintext_size);
    if (ciphertext == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    fread(plaintext, 1, plaintext_size, plaintext_file);
    fread(key, 1, key_size, key_file);

    encrypt(plaintext, key, ciphertext, plaintext_size);

    fwrite(ciphertext, 1, plaintext_size, ciphertext_file);

    free(plaintext);
    free(key);
    free(ciphertext);

    fclose(plaintext_file);
    fclose(key_file);
    fclose(ciphertext_file);

    return EXIT_SUCCESS;
}