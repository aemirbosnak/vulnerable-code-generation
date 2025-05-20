//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generate a random key phrase
char* generateKeyPhrase(int length) {
    srand(time(NULL));
    char* key = malloc(length * sizeof(char));
    
    for (int i = 0; i < length; i++) {
        key[i] = 'A' + rand() % 26;
    }
    
    return key;
}

// Encrypt the message
char* encryptMessage(char* message, char* key) {
    int length = strlen(message);
    char* encryptedMessage = malloc(length * sizeof(char));
    
    for (int i = 0; i < length; i++) {
        encryptedMessage[i] = message[i] + key[i % strlen(key)];
    }
    
    return encryptedMessage;
}

// Decrypt the message
char* decryptMessage(char* encryptedMessage, char* key) {
    int length = strlen(encryptedMessage);
    char* decryptedMessage = malloc(length * sizeof(char));
    
    for (int i = 0; i < length; i++) {
        decryptedMessage[i] = encryptedMessage[i] - key[i % strlen(key)];
    }
    
    return decryptedMessage;
}

int main() {
    printf("Welcome to our cheerful cryptography implementation!\n");
    
    // Get the message to encrypt from the user
    char message[100];
    printf("Please enter the message you would like to encrypt: ");
    fgets(message, 100, stdin);
    
    // Generate a random key phrase
    char* key = generateKeyPhrase(strlen(message));
    printf("Your key phrase is: %s\n", key);
    
    // Encrypt the message
    char* encryptedMessage = encryptMessage(message, key);
    printf("Your encrypted message is: %s\n", encryptedMessage);
    
    // Decrypt the message
    char* decryptedMessage = decryptMessage(encryptedMessage, key);
    printf("Your decrypted message is: %s\n", decryptedMessage);
    
    free(key);
    free(encryptedMessage);
    free(decryptedMessage);
    
    printf("Thank you for using our cheerful cryptography implementation!\n");
    
    return 0;
}