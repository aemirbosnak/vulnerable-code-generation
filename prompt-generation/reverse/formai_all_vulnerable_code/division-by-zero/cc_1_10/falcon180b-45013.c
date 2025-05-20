//Falcon-180B DATASET v1.0 Category: Encryption ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 16
#define MAX_MESSAGE_LENGTH 1024

// Encryption algorithm
void encrypt(char *message, char *key) {
    int i, j;
    int key_index = 0;

    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            // Shift the character by the key index
            message[i] = ((message[i] - 'a' + key[key_index]) % 26) + 'a';
        } else {
            // Leave non-alphabetic characters unchanged
            message[i] = message[i];
        }

        // Increment the key index
        key_index = (key_index + 1) % strlen(key);
    }
}

// Decryption algorithm
void decrypt(char *message, char *key) {
    int i, j;
    int key_index = 0;

    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            // Shift the character back to its original position
            message[i] = ((message[i] - 'a' - key[key_index]) % 26) + 'a';
        } else {
            // Leave non-alphabetic characters unchanged
            message[i] = message[i];
        }

        // Increment the key index
        key_index = (key_index + 1) % strlen(key);
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    // Get the message from the user
    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    // Get the key from the user
    printf("Enter a key to encrypt the message with: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    // Remove the newline character from the key
    key[strcspn(key, "\n")] = '\0';

    // Encrypt the message with the key
    encrypt(message, key);

    // Display the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message with the key
    decrypt(message, key);

    // Display the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}