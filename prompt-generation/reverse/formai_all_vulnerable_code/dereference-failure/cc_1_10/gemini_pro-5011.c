//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// XOR encryption/decryption
void xor_crypt(char *data, size_t len, char *key, size_t keylen) {
    for (size_t i = 0; i < len; i++) {
        data[i] ^= key[i % keylen];
    }
}

// Simple substitution encryption/decryption
void sub_crypt(char *data, size_t len, char *key) {
    for (size_t i = 0; i < len; i++) {
        data[i] = key[(int)data[i]];
    }
}

// Generate a random key
void generate_key(char *key, size_t len) {
    for (size_t i = 0; i < len; i++) {
        key[i] = rand() % 256;
    }
}

int main() {
    // Test data
    char data[] = "Hello, world!\n";
    printf("Original data: %s\n", data);

    // XOR encryption
    char key1[] = "secret";
    xor_crypt(data, strlen(data), key1, strlen(key1));
    printf("XOR encrypted: %s\n", data);

    // XOR decryption
    xor_crypt(data, strlen(data), key1, strlen(key1));
    printf("XOR decrypted: %s\n", data);

    // Substitution encryption
    char key2[] = "abcdefghijklmnopqrstuvwxyz";
    sub_crypt(data, strlen(data), key2);
    printf("Substitution encrypted: %s\n", data);

    // Substitution decryption
    sub_crypt(data, strlen(data), key2);
    printf("Substitution decrypted: %s\n", data);

    // Random key generation
    char random_key[16];
    generate_key(random_key, sizeof(random_key));
    printf("Random key: ");
    for (int i = 0; i < sizeof(random_key); i++) {
        printf("%02X ", random_key[i]);
    }
    printf("\n");

    return 0;
}