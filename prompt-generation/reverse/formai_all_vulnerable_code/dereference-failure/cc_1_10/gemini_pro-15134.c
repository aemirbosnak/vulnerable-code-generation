//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a string using a shift cipher
char *encrypt(char *plaintext, int shift) {
    int len = strlen(plaintext);
    char *ciphertext = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        char c = plaintext[i];
        if (c >= 'a' && c <= 'z') {
            ciphertext[i] = (c - 'a' + shift) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            ciphertext[i] = (c - 'A' + shift) % 26 + 'A';
        } else {
            ciphertext[i] = c;
        }
    }
    ciphertext[len] = '\0';
    return ciphertext;
}

// Function to decrypt a string using a shift cipher
char *decrypt(char *ciphertext, int shift) {
    int len = strlen(ciphertext);
    char *plaintext = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        char c = ciphertext[i];
        if (c >= 'a' && c <= 'z') {
            plaintext[i] = (c - 'a' - shift + 26) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            plaintext[i] = (c - 'A' - shift + 26) % 26 + 'A';
        } else {
            plaintext[i] = c;
        }
    }
    plaintext[len] = '\0';
    return plaintext;
}

int main() {
    char *plaintext = "Hello, world!";
    int shift = 3;

    char *ciphertext = encrypt(plaintext, shift);
    printf("Ciphertext: %s\n", ciphertext);

    char *decryptedText = decrypt(ciphertext, shift);
    printf("Decrypted text: %s\n", decryptedText);

    return 0;
}