//FormAI DATASET v1.0 Category: Modern Encryption ; Style: interoperable
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void generateKey(char *key, int keyLength) {
    for(int i=0; i<keyLength; i++) {
        key[i] = rand() % 26 + 65; // Generate a random uppercase letter
    }
    key[keyLength] = '\0'; // Terminate the string
}

char* encrypt(char *message, char *key) {
    int messageLength = strlen(message);
    int keyLength = strlen(key);
    char *encryptedMessage = malloc(sizeof(char) * (messageLength + 1)); // Allocate memory for the encrypted message

    for(int i=0; i<messageLength; i++) {
        encryptedMessage[i] = ((message[i] - 65) + (key[i % keyLength] - 65)) % 26 + 65; // Apply the encryption algorithm
    }
    encryptedMessage[messageLength] = '\0'; // Terminate the string

    return encryptedMessage;
}

char* decrypt(char *encryptedMessage, char *key) {
    int messageLength = strlen(encryptedMessage);
    int keyLength = strlen(key);
    char *decryptedMessage = malloc(sizeof(char) * (messageLength + 1)); // Allocate memory for the decrypted message

    for(int i=0; i<messageLength; i++) {
        decryptedMessage[i] = ((encryptedMessage[i] - 65) - (key[i % keyLength] - 65) + 26) % 26 + 65; // Apply the decryption algorithm
    }
    decryptedMessage[messageLength] = '\0'; // Terminate the string

    return decryptedMessage;
}

int main() {
    char *key = malloc(sizeof(char) * 11); // Allocate memory for the key (10 characters + terminator)
    generateKey(key, 10); // Generate a random key
    printf("Key: %s\n", key);

    char *message = "HELLO WORLD";
    printf("Original message: %s\n", message);

    char *encryptedMessage = encrypt(message, key);
    printf("Encrypted message: %s\n", encryptedMessage);

    char *decryptedMessage = decrypt(encryptedMessage, key);
    printf("Decrypted message: %s\n", decryptedMessage);

    return 0;
}