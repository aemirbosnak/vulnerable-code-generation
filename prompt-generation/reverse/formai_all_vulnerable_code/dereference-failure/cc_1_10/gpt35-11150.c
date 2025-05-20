//FormAI DATASET v1.0 Category: Encryption ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"

// Function to encrypt a message using Caesar Cipher
char* caesarEncrypt(char* message, int key) {
    char* result = (char*)malloc(sizeof(char) * strlen(message));

    for (int i = 0; i < strlen(message); i++) {
        // Encrypt uppercase characters
        if (message[i] >= 'A' && message[i] <= 'Z') {
            result[i] = ((message[i] - 'A' + key) % 26) + 'A';
        }
        // Encrypt lowercase characters
        else if (message[i] >= 'a' && message[i] <= 'z') {
            result[i] = ((message[i] - 'a' + key) % 26) + 'a';
        }
        // Leave special characters as they are
        else {
            result[i] = message[i];
        }
    }

    return result;
}

// Function to decrypt a message using Caesar Cipher
char* caesarDecrypt(char* message, int key) {
    char* result = (char*)malloc(sizeof(char) * strlen(message));

    for (int i = 0; i < strlen(message); i++) {
        // Decrypt uppercase characters
        if (message[i] >= 'A' && message[i] <= 'Z') {
            result[i] = ((message[i] - 'A' - key + 26) % 26) + 'A';
        }
        // Decrypt lowercase characters
        else if (message[i] >= 'a' && message[i] <= 'z') {
            result[i] = ((message[i] - 'a' - key + 26) % 26) + 'a';
        }
        // Leave special characters as they are
        else {
            result[i] = message[i];
        }
    }

    return result;
}

// Main function with encryption and decryption examples
int main() {
    char message[100];
    int key;

    printf("Enter a message to encrypt: ");
    scanf("%[^\n]", message);
    getchar();

    printf("Enter a key: ");
    scanf("%d", &key);
    getchar();

    char* encryptedMessage = caesarEncrypt(message, key);
    printf("Encrypted message: %s\n", encryptedMessage);

    char* decryptedMessage = caesarDecrypt(encryptedMessage, key);
    printf("Decrypted message: %s\n", decryptedMessage);

    free(encryptedMessage);
    free(decryptedMessage);

    return 0;
}