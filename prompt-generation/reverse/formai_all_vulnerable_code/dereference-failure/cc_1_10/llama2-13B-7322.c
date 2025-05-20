//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 256

// Function to generate a random key for encryption
void generate_key(int *key) {
    int i;
    for (i = 0; i < 8; i++) {
        key[i] = rand() % 26 + 1;
    }
}

// Function to encrypt a string using a Caesar cipher
void encrypt(char *plaintext, int key) {
    int i;
    char ciphertext[MAX_LENGTH];

    for (i = 0; i < strlen(plaintext); i++) {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = (plaintext[i] + key - 'A') % 26 + 'A';
        } else if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[i] = (plaintext[i] + key - 'a') % 26 + 'a';
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    printf("Encrypted message: %s\n", ciphertext);
}

// Function to decrypt a string using a Caesar cipher
void decrypt(char *ciphertext, int key) {
    int i;
    char plaintext[MAX_LENGTH];

    for (i = 0; i < strlen(ciphertext); i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            plaintext[i] = (ciphertext[i] - 'A' + key) % 26 + 'A';
        } else if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            plaintext[i] = (ciphertext[i] - 'a' + key) % 26 + 'a';
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    printf("Decrypted message: %s\n", plaintext);
}

int main() {
    int key;
    char plaintext[] = "Hello, World!";
    char ciphertext[MAX_LENGTH];

    // Generate a random key
    generate_key(key);

    // Encrypt the plaintext
    encrypt(plaintext, key);

    // Decrypt the ciphertext
    decrypt(ciphertext, key);

    return 0;
}