//Falcon-180B DATASET v1.0 Category: Text processing ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the given message
void encrypt(char* message) {
    int length = strlen(message);
    int key = 3; // Key for encryption

    // Encrypt each character of the message
    for(int i=0; i<length; i++) {
        char currentChar = message[i];
        char encryptedChar;

        // Encrypt uppercase characters
        if(currentChar >= 'A' && currentChar <= 'Z') {
            encryptedChar = ((currentChar - 'A' + key) % 26) + 'A';
        }
        // Encrypt lowercase characters
        else if(currentChar >= 'a' && currentChar <= 'z') {
            encryptedChar = ((currentChar - 'a' + key) % 26) + 'a';
        }
        // Encrypt special characters
        else {
            encryptedChar = currentChar;
        }

        // Replace the original character with the encrypted character
        message[i] = encryptedChar;
    }
}

// Function to decrypt the encrypted message
void decrypt(char* message) {
    int length = strlen(message);
    int key = 3; // Key for decryption

    // Decrypt each character of the message
    for(int i=0; i<length; i++) {
        char currentChar = message[i];
        char decryptedChar;

        // Decrypt uppercase characters
        if(currentChar >= 'A' && currentChar <= 'Z') {
            decryptedChar = ((currentChar - 'A' - key + 26) % 26) + 'A';
        }
        // Decrypt lowercase characters
        else if(currentChar >= 'a' && currentChar <= 'z') {
            decryptedChar = ((currentChar - 'a' - key + 26) % 26) + 'a';
        }
        // Decrypt special characters
        else {
            decryptedChar = currentChar;
        }

        // Replace the encrypted character with the decrypted character
        message[i] = decryptedChar;
    }
}

int main() {
    // Message to be encrypted/decrypted
    char* message = "Hello, World! ";

    // Encrypt the message
    encrypt(message);
    printf("Encrypted message: %s\n", message);

    // Decrypt the encrypted message
    decrypt(message);
    printf("Decrypted message: %s\n", message);

    return 0;
}