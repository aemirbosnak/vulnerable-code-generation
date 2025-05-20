//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SALT_SIZE 8

void encrypt(char *plaintext, char *key, char *salt, size_t n) {
    int i;
    for (i = 0; i < n; i++) {
        plaintext[i] ^= key[i] ^ salt[i];
    }
}

void decrypt(char *ciphertext, char *key, char *salt, size_t n) {
    int i;
    for (i = 0; i < n; i++) {
        ciphertext[i] ^= key[i] ^ salt[i];
    }
}

void generate_salt(char *salt) {
    int i;
    for (i = 0; i < SALT_SIZE; i++) {
        salt[i] = rand() % 256;
    }
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s plaintext key ciphertext\n", argv[0]);
        return 1;
    }

    char *plaintext = argv[1];
    char *key = argv[2];
    char *ciphertext = argv[3];

    size_t n = strlen(plaintext);

    char salt[SALT_SIZE];
    generate_salt(salt);

    encrypt(plaintext, key, salt, n);
    puts("Encrypted ciphertext:");
    puts(ciphertext);

    decrypt(ciphertext, key, salt, n);
    puts("Decrypted plaintext:");
    puts(plaintext);

    return 0;
}