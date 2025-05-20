//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simple substitution cipher
char *sub_encrypt(char *plaintext, char *key) {
    int len = strlen(plaintext);
    char *ciphertext = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        int index = plaintext[i] - 'a';
        ciphertext[i] = key[index];
    }
    ciphertext[len] = '\0';
    return ciphertext;
}

char *sub_decrypt(char *ciphertext, char *key) {
    int len = strlen(ciphertext);
    char *plaintext = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        int index = strchr(key, ciphertext[i]) - key;
        plaintext[i] = index + 'a';
    }
    plaintext[len] = '\0';
    return plaintext;
}

// Vigenere cipher
char *vigenere_encrypt(char *plaintext, char *key) {
    int len = strlen(plaintext);
    char *ciphertext = malloc(len + 1);
    int keylen = strlen(key);
    for (int i = 0; i < len; i++) {
        int index = plaintext[i] - 'a';
        int shift = key[i % keylen] - 'a';
        char shifted = (index + shift) % 26 + 'a';
        ciphertext[i] = shifted;
    }
    ciphertext[len] = '\0';
    return ciphertext;
}

char *vigenere_decrypt(char *ciphertext, char *key) {
    int len = strlen(ciphertext);
    char *plaintext = malloc(len + 1);
    int keylen = strlen(key);
    for (int i = 0; i < len; i++) {
        int index = ciphertext[i] - 'a';
        int shift = key[i % keylen] - 'a';
        char shifted = (index - shift + 26) % 26 + 'a';
        plaintext[i] = shifted;
    }
    plaintext[len] = '\0';
    return plaintext;
}

int main() {
    char *plaintext = "hello world";
    char *key = "secret";

    // Substitution cipher
    printf("Substitution Cipher:\n");
    char *sub_ciphertext = sub_encrypt(plaintext, key);
    printf("Ciphertext: %s\n", sub_ciphertext);
    char *sub_plaintext = sub_decrypt(sub_ciphertext, key);
    printf("Plaintext: %s\n\n", sub_plaintext);

    // Vigenere cipher
    printf("Vigenere Cipher:\n");
    char *vigenere_ciphertext = vigenere_encrypt(plaintext, key);
    printf("Ciphertext: %s\n", vigenere_ciphertext);
    char *vigenere_plaintext = vigenere_decrypt(vigenere_ciphertext, key);
    printf("Plaintext: %s\n", vigenere_plaintext);

    return 0;
}