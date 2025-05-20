//MISTRAL-7B DATASET v1.0 Category: Cryptography Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BUFFER_SIZE 256

void print_hex(unsigned char* data, int length) {
    int i;
    for (i = 0; i < length; i++) {
        printf("%02X", data[i]);
    }
    printf("\n");
}

void encrypt(unsigned char* key, unsigned char* plaintext, unsigned char* ciphertext, int length) {
    int i;
    for (i = 0; i < length; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % KEY_SIZE];
    }
}

void decrypt(unsigned char* key, unsigned char* ciphertext, unsigned char* plaintext, int length) {
    int i;
    for (i = 0; i < length; i++) {
        plaintext[i] = ciphertext[i] ^ key[i % KEY_SIZE];
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s <key> <plaintext> <ciphertext>\n", argv[0]);
        return 1;
    }

    unsigned char* key = (unsigned char*)malloc(KEY_SIZE);
    unsigned char* plaintext = (unsigned char*)malloc(BUFFER_SIZE);
    unsigned char* ciphertext = (unsigned char*)malloc(BUFFER_SIZE);

    int key_length = fread(key, sizeof(unsigned char), KEY_SIZE, stdin);
    if (key_length != KEY_SIZE) {
        printf("Error: Invalid key.\n");
        free(key);
        free(plaintext);
        free(ciphertext);
        return 1;
    }

    int plaintext_length = fread(plaintext, sizeof(unsigned char), BUFFER_SIZE, stdin);
    if (plaintext_length > BUFFER_SIZE) {
        printf("Error: Plaintext too long.\n");
        free(key);
        free(plaintext);
        free(ciphertext);
        return 1;
    }

    encrypt(key, plaintext, ciphertext, plaintext_length);

    print_hex(key, KEY_SIZE);
    print_hex(plaintext, plaintext_length);
    print_hex(ciphertext, plaintext_length);

    int ciphertext_length = fwrite(ciphertext, sizeof(unsigned char), plaintext_length, stdout);
    if (ciphertext_length != plaintext_length) {
        printf("Error: Failed to write ciphertext.\n");
        free(key);
        free(plaintext);
        free(ciphertext);
        return 1;
    }

    decrypt(key, ciphertext, plaintext, plaintext_length);

    print_hex(key, KEY_SIZE);
    print_hex(ciphertext, plaintext_length);
    print_hex(plaintext, plaintext_length);

    free(key);
    free(plaintext);
    free(ciphertext);

    return 0;
}