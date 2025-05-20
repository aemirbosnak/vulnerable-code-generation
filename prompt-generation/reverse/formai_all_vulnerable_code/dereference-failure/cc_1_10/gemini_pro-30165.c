//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Forward declarations
int encrypt(char *data, int length, char *key, int keyLength);
int decrypt(char *data, int length, char *key, int keyLength);
char *generateKey(int keyLength);

// XOR-based encryption algorithm
int encrypt(char *data, int length, char *key, int keyLength) {
    for (int i = 0; i < length; i++) {
        data[i] ^= key[i % keyLength];
    }
    return 0;
}

// Inverse XOR-based decryption algorithm
int decrypt(char *data, int length, char *key, int keyLength) {
    return encrypt(data, length, key, keyLength);
}

// Generate a random key of the specified length
char *generateKey(int keyLength) {
    char *key = (char *)malloc(keyLength);
    for (int i = 0; i < keyLength; i++) {
        key[i] = rand() % 256;
    }
    return key;
}

// Recursive function to print the encrypted data in a tree-like structure
void printEncryptedData(char *data, int length, int level) {
    if (length <= 0) {
        return;
    }
    // Print the current level of data
    for (int i = 0; i < level; i++) {
        printf(" ");
    }
    printf("%02X ", data[0]);
    // Recursively print the remaining data
    printEncryptedData(data + 1, length - 1, level + 1);
}

int main() {
    // Get the plaintext from the user
    char plaintext[1024];
    printf("Enter the plaintext to be encrypted: ");
    fgets(plaintext, 1024, stdin);

    // Generate a random key
    int keyLength = 16;
    char *key = generateKey(keyLength);

    // Encrypt the plaintext using the generated key
    int ciphertextLength = strlen(plaintext);
    encrypt(plaintext, ciphertextLength, key, keyLength);

    // Print the encrypted data in a tree-like structure
    printf("Encrypted data:\n");
    printEncryptedData(plaintext, ciphertextLength, 0);

    // Decrypt the ciphertext using the same key
    decrypt(plaintext, ciphertextLength, key, keyLength);

    // Print the decrypted plaintext
    printf("\nDecrypted plaintext: %s\n", plaintext);

    // Free the allocated memory
    free(key);

    return 0;
}