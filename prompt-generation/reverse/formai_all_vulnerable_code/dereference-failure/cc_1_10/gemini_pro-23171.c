//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 32

typedef struct {
    char key[MAX_KEY_SIZE];
    int key_len;
} Cipher;

Cipher* cipher_new() {
    Cipher* cipher = malloc(sizeof(Cipher));
    cipher->key_len = 0;
    return cipher;
}

void cipher_delete(Cipher* cipher) {
    memset(cipher->key, 0, MAX_KEY_SIZE);
    free(cipher);
}

void cipher_set_key(Cipher* cipher, const char* key) {
    strncpy(cipher->key, key, MAX_KEY_SIZE);
    cipher->key_len = strlen(key);
}

char cipher_encrypt(Cipher* cipher, char c) {
    return (c + cipher->key[cipher->key_len % MAX_KEY_SIZE]) % 256;
}

char cipher_decrypt(Cipher* cipher, char c) {
    return (c - cipher->key[cipher->key_len % MAX_KEY_SIZE] + 256) % 256;
}

void cipher_encrypt_string(Cipher* cipher, char* str) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = cipher_encrypt(cipher, str[i]);
    }
}

void cipher_decrypt_string(Cipher* cipher, char* str) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = cipher_decrypt(cipher, str[i]);
    }
}

int main() {
    Cipher* cipher = cipher_new();
    cipher_set_key(cipher, "my secret key");

    char* plaintext = "Hello, world!";
    printf("Plaintext: %s\n", plaintext);

    char* ciphertext = malloc(strlen(plaintext) + 1);
    strcpy(ciphertext, plaintext);
    cipher_encrypt_string(cipher, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    cipher_decrypt_string(cipher, ciphertext);
    printf("Decrypted: %s\n", ciphertext);

    cipher_delete(cipher);
    free(ciphertext);
    return 0;
}