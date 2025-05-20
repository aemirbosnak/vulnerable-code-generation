//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a message using a Caesar cipher
char *encryptCaesar(char *message, int key) {
    // Allocate memory for the encrypted message
    char *encryptedMessage = malloc(strlen(message) + 1);

    // Encrypt each character in the message
    for (int i = 0; i < strlen(message); i++) {
        // Get the ASCII value of the current character
        int asciiValue = (int) message[i];

        // Shift the ASCII value by the key
        asciiValue += key;

        // If the ASCII value is greater than 'z', wrap around to 'a'
        if (asciiValue > 'z') {
            asciiValue -= 26;
        }

        // If the ASCII value is less than 'a', wrap around to 'z'
        if (asciiValue < 'a') {
            asciiValue += 26;
        }

        // Set the encrypted character in the encrypted message
        encryptedMessage[i] = (char) asciiValue;
    }

    // Terminate the encrypted message with a null character
    encryptedMessage[strlen(message)] = '\0';

    // Return the encrypted message
    return encryptedMessage;
}

// Function to decrypt a message using a Caesar cipher
char *decryptCaesar(char *message, int key) {
    // Allocate memory for the decrypted message
    char *decryptedMessage = malloc(strlen(message) + 1);

    // Decrypt each character in the message
    for (int i = 0; i < strlen(message); i++) {
        // Get the ASCII value of the current character
        int asciiValue = (int) message[i];

        // Shift the ASCII value by the key
        asciiValue -= key;

        // If the ASCII value is less than 'a', wrap around to 'z'
        if (asciiValue < 'a') {
            asciiValue += 26;
        }

        // If the ASCII value is greater than 'z', wrap around to 'a'
        if (asciiValue > 'z') {
            asciiValue -= 26;
        }

        // Set the decrypted character in the decrypted message
        decryptedMessage[i] = (char) asciiValue;
    }

    // Terminate the decrypted message with a null character
    decryptedMessage[strlen(message)] = '\0';

    // Return the decrypted message
    return decryptedMessage;
}

int main() {
    // Get the message to be encrypted
    char *message = "Hello, world!";

    // Get the encryption key
    int key = 3;

    // Encrypt the message
    char *encryptedMessage = encryptCaesar(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", encryptedMessage);

    // Decrypt the message
    char *decryptedMessage = decryptCaesar(encryptedMessage, key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", decryptedMessage);

    // Free the allocated memory
    free(encryptedMessage);
    free(decryptedMessage);

    return 0;
}