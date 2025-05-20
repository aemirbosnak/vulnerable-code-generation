//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: immersive
#include <stdio.h>
#include <string.h>

// Declare the encryption table
char encryptionTable[26][26];

// Initialize the encryption table
void initEncryptionTable() {
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            encryptionTable[i][j] = 'A' + ((i + j) % 26);
        }
    }
}

// Encrypt a message using the encryption table
char* encryptMessage(char* message) {
    int messageLength = strlen(message);
    char* encryptedMessage = malloc(messageLength + 1);

    for (int i = 0; i < messageLength; i++) {
        char letter = message[i];
        int row = letter - 'A';
        int column = i % 26;
        encryptedMessage[i] = encryptionTable[row][column];
    }

    encryptedMessage[messageLength] = '\0';
    return encryptedMessage;
}

// Decrypt a message using the encryption table
char* decryptMessage(char* encryptedMessage) {
    int messageLength = strlen(encryptedMessage);
    char* decryptedMessage = malloc(messageLength + 1);

    for (int i = 0; i < messageLength; i++) {
        char letter = encryptedMessage[i];
        int row = letter - 'A';
        int column = i % 26;
        decryptedMessage[i] = encryptionTable[row][column];
    }

    decryptedMessage[messageLength] = '\0';
    return decryptedMessage;
}

// Main function to test the encryption and decryption
int main() {
    // Initialize the encryption table
    initEncryptionTable();

    // Define the message to be encrypted
    char* message = "Hello world!";

    // Encrypt the message
    char* encryptedMessage = encryptMessage(message);

    // Print the encrypted message
    printf("Encrypted message: %s\n", encryptedMessage);

    // Decrypt the message
    char* decryptedMessage = decryptMessage(encryptedMessage);

    // Print the decrypted message
    printf("Decrypted message: %s\n", decryptedMessage);

    return 0;
}