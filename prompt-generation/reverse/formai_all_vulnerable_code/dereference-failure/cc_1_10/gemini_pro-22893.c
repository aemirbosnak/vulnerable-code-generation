//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    int key_len;
} cipher_key_t;

typedef struct {
    char *cipher;
    int cipher_len;
} cipher_t;

cipher_key_t generate_key(int key_len) {
    cipher_key_t key;
    key.key = malloc(key_len + 1);
    for (int i = 0; i < key_len; i++) {
        key.key[i] = rand() % 26 + 'a';
    }
    key.key[key_len] = '\0';
    return key;
}

cipher_t encrypt(char *plaintext, cipher_key_t key) {
    cipher_t cipher;
    cipher.cipher = malloc(strlen(plaintext) + 1);
    for (int i = 0; i < strlen(plaintext); i++) {
        cipher.cipher[i] = (plaintext[i] + key.key[i % key.key_len] - 'a') % 26 + 'a';
    }
    cipher.cipher[strlen(plaintext)] = '\0';
    return cipher;
}

char *decrypt(cipher_t cipher, cipher_key_t key) {
    char *plaintext = malloc(strlen(cipher.cipher) + 1);
    for (int i = 0; i < strlen(cipher.cipher); i++) {
        plaintext[i] = (cipher.cipher[i] - key.key[i % key.key_len] + 26) % 26 + 'a';
    }
    plaintext[strlen(cipher.cipher)] = '\0';
    return plaintext;
}

int main() {
    char *plaintext = "Hello, world!";
    int key_len = 5;

    // Generate a key.
    cipher_key_t key = generate_key(key_len);

    // Encrypt the plaintext.
    cipher_t cipher = encrypt(plaintext, key);

    // Print the ciphertext.
    printf("Ciphertext: %s\n", cipher.cipher);

    // Decrypt the ciphertext.
    char *decrypted_plaintext = decrypt(cipher, key);

    // Print the decrypted plaintext.
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    return 0;
}