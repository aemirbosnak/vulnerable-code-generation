//FormAI DATASET v1.0 Category: Modern Encryption ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1000

// function to generate a random key
char* generateKey(int length) {
    char* key = malloc(sizeof(char) * (length + 1));
    for (int i = 0; i < length; i++) {
        key[i] = (char)(rand() % 26 + 65);
    }
    key[length] = '\0';
    return key;
}

// function to encrypt a message using the key
char* encrypt(char* message, char* key) {
    int messageLength = strlen(message);
    int keyLength = strlen(key);
    char* encryptedMessage = malloc(sizeof(char) * (messageLength + 1));

    for (int i = 0; i < messageLength; i++) {
        int j = i % keyLength;
        encryptedMessage[i] = (message[i] + key[j]) % 26 + 65;
    }
    encryptedMessage[messageLength] = '\0';

    return encryptedMessage;
}

int main() {
    srand(time(NULL));
    char message[MAX_LENGTH];
    char* key = NULL;
    char* encryptedMessage = NULL;

    printf("Enter the message to be encrypted: ");
    fgets(message, MAX_LENGTH, stdin);
    message[strcspn(message, "\n")] = '\0';

    key = generateKey(strlen(message));
    printf("Generated key: %s\n", key);

    encryptedMessage = encrypt(message, key);
    printf("Encrypted message: %s\n", encryptedMessage);

    free(key);
    free(encryptedMessage);

    return 0;
}