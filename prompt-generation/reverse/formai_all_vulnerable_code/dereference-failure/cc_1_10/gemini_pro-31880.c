//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate a random key
int* generateKey(int keySize) {
    int* key = (int*)malloc(keySize * sizeof(int));
    for (int i = 0; i < keySize; i++) {
        key[i] = rand() % 256;
    }
    return key;
}

// Function to encrypt a message
int* encryptMessage(char* message, int* key, int keySize) {
    int messageLength = strlen(message);
    int* encryptedMessage = (int*)malloc(messageLength * sizeof(int));
    for (int i = 0; i < messageLength; i++) {
        encryptedMessage[i] = message[i] ^ key[i % keySize];
    }
    return encryptedMessage;
}

// Function to decrypt a message
char* decryptMessage(int* encryptedMessage, int* key, int keySize) {
    int messageLength = strlen((char*)encryptedMessage);
    char* decryptedMessage = (char*)malloc(messageLength * sizeof(char));
    for (int i = 0; i < messageLength; i++) {
        decryptedMessage[i] = encryptedMessage[i] ^ key[i % keySize];
    }
    return decryptedMessage;
}

// Main function
int main() {
    // Generate a random key
    int keySize = 16;
    int* key = generateKey(keySize);

    // Encrypt a message
    char* message = "Hello, world!";
    int* encryptedMessage = encryptMessage(message, key, keySize);

    // Decrypt the encrypted message
    char* decryptedMessage = decryptMessage(encryptedMessage, key, keySize);

    // Print the decrypted message
    printf("Decrypted message: %s\n", decryptedMessage);

    return 0;
}