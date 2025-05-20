//Falcon2-11B DATASET v1.0 Category: Cryptography Implementation ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to encrypt a message
void encrypt(char* message, char* key) {
    // Convert message and key to uppercase
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        message[i] = toupper(message[i]);
    }
    for (int i = 0; i < strlen(key); i++) {
        key[i] = toupper(key[i]);
    }

    // Shift each character by its position in the key
    int keyLength = strlen(key);
    for (int i = 0; i < len; i++) {
        int shift = key[i % keyLength] - 'A';
        message[i] = (char)((message[i] - 'A' + shift) % 26 + 'A');
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);
}

// Function to decrypt a message
void decrypt(char* message, char* key) {
    // Convert message and key to uppercase
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        message[i] = toupper(message[i]);
    }
    for (int i = 0; i < strlen(key); i++) {
        key[i] = toupper(key[i]);
    }

    // Shift each character by its position in the key
    int keyLength = strlen(key);
    for (int i = 0; i < len; i++) {
        int shift = key[i % keyLength] - 'A';
        message[i] = (char)((message[i] - 'A' + shift) % 26 + 'A');
    }

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);
}

int main() {
    // Get the plaintext message
    char plaintext[100];
    printf("Enter the plaintext message: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Get the encryption key
    char key[100];
    printf("Enter the encryption key: ");
    fgets(key, sizeof(key), stdin);

    // Encrypt the plaintext message
    encrypt(plaintext, key);

    // Decrypt the encrypted message
    decrypt(plaintext, key);

    return 0;
}