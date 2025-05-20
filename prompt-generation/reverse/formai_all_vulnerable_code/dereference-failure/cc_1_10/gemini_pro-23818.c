//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A simple encryption algorithm to make our secrets safe and sound!
// This algorithm is not meant to be secure, it's just for fun!

// Our secret key, shhh! Don't tell anyone!
const char *key = "HAPPYHIPPO";

// Encrypt a message using our secret key
char *encrypt(char *message) {
    // Allocate memory for the encrypted message
    char *encryptedMessage = malloc(strlen(message) + 1);

    // Loop through each character in the message
    for (int i = 0; i < strlen(message); i++) {
        // Get the current character and its ASCII value
        char character = message[i];
        int asciiValue = (int)character;

        // Shift the ASCII value by the key value
        asciiValue += (int)key[i % strlen(key)];

        // Wrap around if we go past the end of the ASCII table
        if (asciiValue > 127) {
            asciiValue -= 95;
        }

        // Convert the shifted ASCII value back to a character
        character = (char)asciiValue;

        // Store the encrypted character in the encrypted message
        encryptedMessage[i] = character;
    }

    // Null-terminate the encrypted message
    encryptedMessage[strlen(message)] = '\0';

    // Return the encrypted message
    return encryptedMessage;
}

// Decrypt an encrypted message using our secret key
char *decrypt(char *encryptedMessage) {
    // Allocate memory for the decrypted message
    char *decryptedMessage = malloc(strlen(encryptedMessage) + 1);

    // Loop through each character in the encrypted message
    for (int i = 0; i < strlen(encryptedMessage); i++) {
        // Get the current character and its ASCII value
        char character = encryptedMessage[i];
        int asciiValue = (int)character;

        // Shift the ASCII value back by the key value
        asciiValue -= (int)key[i % strlen(key)];

        // Wrap around if we go past the beginning of the ASCII table
        if (asciiValue < 32) {
            asciiValue += 95;
        }

        // Convert the shifted ASCII value back to a character
        character = (char)asciiValue;

        // Store the decrypted character in the decrypted message
        decryptedMessage[i] = character;
    }

    // Null-terminate the decrypted message
    decryptedMessage[strlen(encryptedMessage)] = '\0';

    // Return the decrypted message
    return decryptedMessage;
}

int main() {
    // Get the message to encrypt from the user
    char message[100];
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    // Encrypt the message
    char *encryptedMessage = encrypt(message);

    // Print the encrypted message
    printf("Encrypted message: %s\n", encryptedMessage);

    // Decrypt the message
    char *decryptedMessage = decrypt(encryptedMessage);

    // Print the decrypted message
    printf("Decrypted message: %s\n", decryptedMessage);

    // Free the allocated memory
    free(encryptedMessage);
    free(decryptedMessage);

    return 0;
}