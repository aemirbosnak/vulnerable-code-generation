//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Generate a random key for encryption
char *generateKey(int len) {
    char *key = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        key[i] = (rand() % 26) + 'a';
    }
    key[len] = '\0';
    return key;
}

// Encrypt a given string
char *encrypt(char *plaintext, char *key) {
    int len_plaintext = strlen(plaintext);
    int len_key = strlen(key);
    char *ciphertext = malloc(len_plaintext + 1);
    for (int i = 0; i < len_plaintext; i++) {
        ciphertext[i] = (plaintext[i] + key[i % len_key] - 'a') % 26 + 'a';
    }
    ciphertext[len_plaintext] = '\0';
    return ciphertext;
}

// Decrypt a given string
char *decrypt(char *ciphertext, char *key) {
    int len_ciphertext = strlen(ciphertext);
    int len_key = strlen(key);
    char *plaintext = malloc(len_ciphertext + 1);
    for (int i = 0; i < len_ciphertext; i++) {
        plaintext[i] = (ciphertext[i] - key[i % len_key] + 26) % 26 + 'a';
    }
    plaintext[len_ciphertext] = '\0';
    return plaintext;
}

int main() {
    // Generate a random key
    char *key = generateKey(16);

    // Encrypt a given string
    char *plaintext = "Hello, world!";
    char *ciphertext = encrypt(plaintext, key);

    // Decrypt the encrypted string
    char *decryptedText = decrypt(ciphertext, key);

    // Print the encrypted and decrypted strings
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted text: %s\n", decryptedText);

    // Free the allocated memory
    free(key);
    free(ciphertext);
    free(decryptedText);

    return 0;
}