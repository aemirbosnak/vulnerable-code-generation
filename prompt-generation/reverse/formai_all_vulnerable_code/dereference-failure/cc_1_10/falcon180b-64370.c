//Falcon-180B DATASET v1.0 Category: Encryption ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16

typedef struct {
    char key[KEY_SIZE];
    char iv[BLOCK_SIZE];
} encryption_params;

void generate_key(char *key) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_SIZE - 1] = '\0';
}

void generate_iv(char *iv) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        iv[i] = rand() % 26 + 'a';
    }
    iv[BLOCK_SIZE - 1] = '\0';
}

void encrypt(char *message, encryption_params *params) {
    int message_len = strlen(message);
    char *cipher_text = malloc(message_len + 1);
    char *key = params->key;
    char *iv = params->iv;

    for (int i = 0; i < message_len; i++) {
        cipher_text[i] = message[i] ^ key[i % KEY_SIZE];
    }

    cipher_text[message_len] = '\0';

    for (int i = 0; i < message_len; i++) {
        cipher_text[i] ^= iv[i % BLOCK_SIZE];
    }

    printf("Cipher Text: %s\n", cipher_text);
}

void decrypt(char *cipher_text, encryption_params *params) {
    int message_len = strlen(cipher_text);
    char *message = malloc(message_len + 1);
    char *key = params->key;
    char *iv = params->iv;

    for (int i = 0; i < message_len; i++) {
        message[i] = cipher_text[i] ^ iv[i % BLOCK_SIZE];
    }

    message[message_len] = '\0';

    for (int i = 0; i < message_len; i++) {
        message[i] ^= key[i % KEY_SIZE];
    }

    printf("Decrypted Text: %s\n", message);
}

int main() {
    encryption_params params;
    generate_key(params.key);
    generate_iv(params.iv);

    char message[] = "Hello, World! ";
    encrypt(message, &params);
    decrypt(message, &params);

    return 0;
}