//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simple XOR encryption/decryption
void xor_encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, int key_len) {
    for (int i = 0; i < plaintext_len; i++) {
        plaintext[i] ^= key[i % key_len];
    }
}

// Simple substitution encryption/decryption
void substitution_encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key) {
    for (int i = 0; i < plaintext_len; i++) {
        plaintext[i] = key[plaintext[i]];
    }
}

// Vigenere encryption/decryption
void vigenere_encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key) {
    int key_len = strlen(key);
    for (int i = 0; i < plaintext_len; i++) {
        plaintext[i] += key[i % key_len] - 'a';
        plaintext[i] %= 26;
        plaintext[i] += 'a';
    }
}

int main() {
    // Sample plaintext and encryption key
    char plaintext[] = "Hello, world!";
    char key[] = "secret";

    // Encrypt plaintext using XOR
    unsigned char xor_ciphertext[strlen(plaintext)];
    memcpy(xor_ciphertext, plaintext, strlen(plaintext));
    xor_encrypt(xor_ciphertext, strlen(plaintext), key, strlen(key));

    // Decrypt ciphertext using XOR
    unsigned char xor_plaintext[strlen(plaintext)];
    memcpy(xor_plaintext, xor_ciphertext, strlen(plaintext));
    xor_encrypt(xor_plaintext, strlen(plaintext), key, strlen(key));

    // Encrypt plaintext using substitution
    unsigned char substitution_ciphertext[strlen(plaintext)];
    memcpy(substitution_ciphertext, plaintext, strlen(plaintext));
    substitution_encrypt(substitution_ciphertext, strlen(plaintext), key);

    // Decrypt ciphertext using substitution
    unsigned char substitution_plaintext[strlen(plaintext)];
    memcpy(substitution_plaintext, substitution_ciphertext, strlen(plaintext));
    substitution_encrypt(substitution_plaintext, strlen(plaintext), key);

    // Encrypt plaintext using Vigenere
    unsigned char vigenere_ciphertext[strlen(plaintext)];
    memcpy(vigenere_ciphertext, plaintext, strlen(plaintext));
    vigenere_encrypt(vigenere_ciphertext, strlen(plaintext), key);

    // Decrypt ciphertext using Vigenere
    unsigned char vigenere_plaintext[strlen(plaintext)];
    memcpy(vigenere_plaintext, vigenere_ciphertext, strlen(plaintext));
    vigenere_encrypt(vigenere_plaintext, strlen(plaintext), key);

    // Print results
    printf("Plaintext: %s\n", plaintext);
    printf("XOR ciphertext: %s\n", xor_ciphertext);
    printf("XOR plaintext: %s\n", xor_plaintext);
    printf("Substitution ciphertext: %s\n", substitution_ciphertext);
    printf("Substitution plaintext: %s\n", substitution_plaintext);
    printf("Vigenere ciphertext: %s\n", vigenere_ciphertext);
    printf("Vigenere plaintext: %s\n", vigenere_plaintext);

    return 0;
}