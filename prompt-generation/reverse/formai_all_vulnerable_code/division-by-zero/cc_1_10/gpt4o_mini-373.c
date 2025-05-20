//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void encrypt(char *plaintext, char *key, char *ciphertext);
void decrypt(char *ciphertext, char *key, char *decryptedtext);
void printHex(const char *str, size_t len);

int main() {
    char plaintext[256], key[256];
    char ciphertext[256], decryptedtext[256];

    // Input plaintext and key
    printf("Enter the plaintext (max 255 characters): ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0; // Remove newline character

    printf("Enter the encryption key (max 255 characters): ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0; // Remove newline character

    // Encrypt the plaintext
    encrypt(plaintext, key, ciphertext);
    
    // Output ciphertext in hexadecimal format
    printf("Ciphertext (hex): ");
    printHex(ciphertext, strlen(plaintext));
    printf("\n");

    // Decrypt the ciphertext
    decrypt(ciphertext, key, decryptedtext);
    
    // Output decrypted text
    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}

// Function to encrypt the plaintext using XOR cipher
void encrypt(char *plaintext, char *key, char *ciphertext) {
    int plaintext_len = strlen(plaintext);
    int key_len = strlen(key);

    for (int i = 0; i < plaintext_len; ++i) {
        // XOR each character with the corresponding key character
        ciphertext[i] = plaintext[i] ^ key[i % key_len];
    }
    ciphertext[plaintext_len] = '\0'; // Null-terminate the ciphertext
}

// Function to decrypt the ciphertext using XOR cipher
void decrypt(char *ciphertext, char *key, char *decryptedtext) {
    int ciphertext_len = strlen(ciphertext);
    int key_len = strlen(key);

    for (int i = 0; i < ciphertext_len; ++i) {
        // XOR each character with the corresponding key character
        decryptedtext[i] = ciphertext[i] ^ key[i % key_len];
    }
    decryptedtext[ciphertext_len] = '\0'; // Null-terminate the decrypted text
}

// Function to print the hex representation of the string
void printHex(const char *str, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        printf("%02X ", (unsigned char)str[i]);
    }
}