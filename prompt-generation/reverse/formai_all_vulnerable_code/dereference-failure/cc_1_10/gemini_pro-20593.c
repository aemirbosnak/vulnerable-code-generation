//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 32

void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, int key_len) {
    for (int i = 0; i < plaintext_len; i++) {
        plaintext[i] ^= key[i % key_len];
    }
}

void decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, int key_len) {
    for (int i = 0; i < ciphertext_len; i++) {
        ciphertext[i] ^= key[i % key_len];
    }
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s plaintext key ciphertext\n", argv[0]);
        return EXIT_FAILURE;
    }

    int plaintext_len = strlen(argv[1]);
    int key_len = strlen(argv[2]);
    int ciphertext_len = strlen(argv[3]);

    if (key_len > MAX_KEY_LEN) {
        fprintf(stderr, "Key length must be less than or equal to %d\n", MAX_KEY_LEN);
        return EXIT_FAILURE;
    }

    unsigned char *plaintext = malloc(plaintext_len + 1);
    unsigned char *key = malloc(key_len + 1);
    unsigned char *ciphertext = malloc(ciphertext_len + 1);

    strcpy(plaintext, argv[1]);
    strcpy(key, argv[2]);
    strcpy(ciphertext, argv[3]);

    encrypt(plaintext, plaintext_len, key, key_len);

    printf("Encrypted plaintext: %s\n", plaintext);

    decrypt(ciphertext, ciphertext_len, key, key_len);

    printf("Decrypted ciphertext: %s\n", ciphertext);

    free(plaintext);
    free(key);
    free(ciphertext);

    return EXIT_SUCCESS;
}