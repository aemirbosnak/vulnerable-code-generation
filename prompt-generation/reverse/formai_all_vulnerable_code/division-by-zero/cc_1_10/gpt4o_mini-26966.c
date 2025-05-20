//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024
#define KEY_LENGTH 16

// Function prototypes
void encrypt(const char *plaintext, char *ciphertext, const char *key);
void decrypt(const char *ciphertext, char *plaintext, const char *key);
void generate_key(const char *passphrase, char *key);

int main() {
    char passphrase[256], key[KEY_LENGTH + 1], 
         plaintext[MAX_LENGTH], ciphertext[MAX_LENGTH], decryptedtext[MAX_LENGTH];

    // The detective's musings
    printf("Ah! Another case for the great detective, Sherlock Holmes.\n");
    printf("In order to maintain the secrecy of our correspondences, we need to encrypt our messages.\n");
    printf("Please enter a passphrase for key generation: ");
    
    fgets(passphrase, sizeof(passphrase), stdin);
    passphrase[strcspn(passphrase, "\n")] = 0; // Remove trailing newline

    generate_key(passphrase, key);
    printf("Key generated from passphrase: %.*s\n", KEY_LENGTH, key);

    printf("Enter the plaintext message to encrypt: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0; // Remove trailing newline

    encrypt(plaintext, ciphertext, key);
    printf("Encrypted ciphertext: %s\n", ciphertext);

    decrypt(ciphertext, decryptedtext, key);
    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}

// Simple hashing function for key generation based on a passphrase
void generate_key(const char *passphrase, char *key) {
    int i;
    for (i = 0; i < KEY_LENGTH; i++) {
        key[i] = passphrase[i % strlen(passphrase)];
    }
    key[KEY_LENGTH] = '\0'; // Ensure null-termination
}

// Encryption function using a simple XOR cipher for demonstration purposes
void encrypt(const char *plaintext, char *ciphertext, const char *key) {
    int i, len = strlen(plaintext);
    for (i = 0; i < len; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % KEY_LENGTH];
    }
    ciphertext[len] = '\0'; // Ensure null-termination
}

// Decryption function which is identical to encryption due to XOR usage
void decrypt(const char *ciphertext, char *plaintext, const char *key) {
    int i, len = strlen(ciphertext);
    for (i = 0; i < len; i++) {
        plaintext[i] = ciphertext[i] ^ key[i % KEY_LENGTH];
    }
    plaintext[len] = '\0'; // Ensure null-termination
}