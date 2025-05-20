//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16

// Generate a random key
void generate_key(unsigned char *key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = (unsigned char)rand();
    }
}

// Encrypt a message
void encrypt(const char *message, unsigned char *key) {
    int i, j;
    unsigned char *encrypted;
    int message_len = strlen(message);
    int encrypted_len = message_len + (message_len / 2);
    encrypted = calloc(1, encrypted_len);
    for (i = 0; i < message_len; i++) {
        for (j = 0; j < KEY_SIZE; j++) {
            encrypted[i * KEY_SIZE + j] = (message[i] + key[j]) % 256;
        }
    }
    printf("Encrypted message: %s\n", encrypted);
}

// Decrypt an encrypted message
void decrypt(const char *encrypted, unsigned char *key) {
    int i, j;
    char *message;
    int message_len = strlen(encrypted);
    int key_len = KEY_SIZE;
    message = calloc(1, message_len);
    for (i = 0; i < message_len; i++) {
        for (j = 0; j < key_len; j++) {
            message[i] = (encrypted[i] - key[j]) % 256;
        }
    }
    printf("Decrypted message: %s\n", message);
}

int main() {
    unsigned char key[KEY_SIZE];
    generate_key(key);
    char message[] = "Hello, World!";
    encrypt(message, key);
    decrypt(message, key);
    return 0;
}