//FormAI DATASET v1.0 Category: modern Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16

void print_hex(unsigned char *buffer, size_t size) {
    for (int i = 0; i < size; i++) {
        printf("%02x", buffer[i]);
    }
    printf("\n");
}

unsigned char * generate_key() {
    unsigned char *key = calloc(KEY_SIZE, sizeof(unsigned char));
    srand(time(NULL));
    for(int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
    return key;
}

unsigned char * xor(unsigned char *a, unsigned char *b) {
    unsigned char *result = calloc(BLOCK_SIZE, sizeof(unsigned char));
    for(int i = 0; i < BLOCK_SIZE; i++) {
        result[i] = a[i] ^ b[i];
    }
    return result;
}

void encrypt(unsigned char *key, unsigned char *plaintext, unsigned char *ciphertext) {
    unsigned char *block = calloc(BLOCK_SIZE, sizeof(unsigned char));
    unsigned char *key_stream = calloc(BLOCK_SIZE, sizeof(unsigned char));
    memcpy(block, plaintext, BLOCK_SIZE);
    for(int i = 0; i < BLOCK_SIZE; i += KEY_SIZE) {
        memcpy(key_stream, key, KEY_SIZE);
        unsigned char *temp = xor(block + i, key_stream);
        memcpy(ciphertext + i, temp, BLOCK_SIZE);
        free(temp);
    }
    free(block);
    free(key_stream);
}

void decrypt(unsigned char *key, unsigned char *ciphertext, unsigned char *plaintext) {
    unsigned char *block = calloc(BLOCK_SIZE, sizeof(unsigned char));
    unsigned char *key_stream = calloc(BLOCK_SIZE, sizeof(unsigned char));
    memcpy(block, ciphertext, BLOCK_SIZE);
    for(int i = 0; i < BLOCK_SIZE; i += KEY_SIZE) {
        memcpy(key_stream, key, KEY_SIZE);
        unsigned char *temp = xor(block + i, key_stream);
        memcpy(plaintext + i, temp, BLOCK_SIZE);
        free(temp);
    }
    free(block);
    free(key_stream);
}

int main() {
    unsigned char *key = generate_key();
    unsigned char *plaintext = "This is a brave style example of modern encryption.";
    size_t len = strlen(plaintext);
    if (len % BLOCK_SIZE != 0) {
        printf("Plaintext must be multiple of %d bytes.\n", BLOCK_SIZE);
        return 1;
    }
    unsigned char *ciphertext = calloc(len, sizeof(unsigned char));
    encrypt(key, plaintext, ciphertext);
    printf("Key: ");
    print_hex(key, KEY_SIZE);
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: ");
    print_hex(ciphertext, len);
    unsigned char *decryptedtext = calloc(len, sizeof(unsigned char));
    decrypt(key, ciphertext, decryptedtext);
    printf("Decrypted text: %s\n", decryptedtext);
    free(key);
    free(ciphertext);
    free(decryptedtext);
    return 0;
}