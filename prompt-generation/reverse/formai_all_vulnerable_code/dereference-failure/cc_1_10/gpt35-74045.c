//FormAI DATASET v1.0 Category: Modern Encryption ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
#define MAX_KEY_LENGTH 10

char* encrypt(char* message, char* key) {
    int messageLength = strlen(message);
    int keyLength = strlen(key);
    char* encryptedMessage = (char*) malloc(sizeof(char) * messageLength);

    for (int i = 0; i < messageLength; i++) {
        encryptedMessage[i] = ((message[i] + key[i % keyLength]) % 26) + 'A';
    }

    return encryptedMessage;
}

char* decrypt(char* encryptedMessage, char* key) {
    int messageLength = strlen(encryptedMessage);
    int keyLength = strlen(key);
    char* decryptedMessage = (char*) malloc(sizeof(char) * messageLength);

    for (int i = 0; i < messageLength; i++) {
        decryptedMessage[i] = (((encryptedMessage[i] - key[i % keyLength]) + 26) % 26) + 'A';
    }

    return decryptedMessage;
}

int main() {
    char message[MAX_STRING_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter message: ");
    fgets(message, MAX_STRING_LENGTH, stdin);
    message[strcspn(message, "\n")] = 0;

    printf("Enter key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);
    key[strcspn(key, "\n")] = 0;

    printf("\nOriginal Message: %s\n", message);

    char* encryptedMessage = encrypt(message, key);
    printf("Encrypted Message: %s\n", encryptedMessage);

    char* decryptedMessage = decrypt(encryptedMessage, key);
    printf("Decrypted Message: %s\n", decryptedMessage);

    free(encryptedMessage);
    free(decryptedMessage);

    return 0;
}