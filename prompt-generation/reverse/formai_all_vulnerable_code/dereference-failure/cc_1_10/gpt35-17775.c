//FormAI DATASET v1.0 Category: Encryption ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING_LENGTH 1000

char* encrypt(char* message, char* key);
char* decrypt(char* message, char* key);

int main() {
    char message[MAX_STRING_LENGTH];
    char key[MAX_STRING_LENGTH];
    char* encryptedMessage;
    char* decryptedMessage;
    
    printf("Enter message to encrypt: ");
    fgets(message, MAX_STRING_LENGTH, stdin);
    message[strcspn(message, "\n")] = 0; // Remove newline character
    
    printf("Enter encryption key: ");
    fgets(key, MAX_STRING_LENGTH, stdin);
    key[strcspn(key, "\n")] = 0; // Remove newline character
    
    encryptedMessage = encrypt(message, key);
    printf("Encrypted Message: %s\n", encryptedMessage);
    
    decryptedMessage = decrypt(encryptedMessage, key);
    printf("Decrypted Message: %s\n", decryptedMessage);
    
    free(encryptedMessage);
    free(decryptedMessage);
    
    return 0;
}

char* encrypt(char* message, char* key) {
    char* encryptedMessage = malloc(MAX_STRING_LENGTH * sizeof(char));
    strcpy(encryptedMessage, message);
    int messageLength = strlen(message);
    int keyLength = strlen(key);
    int i, j;
    
    for(i = 0, j = 0; i < messageLength; ++i, ++j) {
        if(j == keyLength) {
            j = 0;
        }
        
        int newChar = (message[i] + key[j]) % 256;
        encryptedMessage[i] = newChar;
    }
    
    encryptedMessage[i] = '\0';
    return encryptedMessage;
}

char* decrypt(char* message, char* key) {
    char* decryptedMessage = malloc(MAX_STRING_LENGTH * sizeof(char));
    strcpy(decryptedMessage, message);
    int messageLength = strlen(message);
    int keyLength = strlen(key);
    int i, j;
    
    for(i = 0, j = 0; i < messageLength; ++i, ++j) {
        if(j == keyLength) {
            j = 0;
        }
        
        int newChar = (message[i] - key[j] + 256) % 256;
        decryptedMessage[i] = newChar;
    }
    
    decryptedMessage[i] = '\0';
    return decryptedMessage;
}