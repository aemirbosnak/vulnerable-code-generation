//FormAI DATASET v1.0 Category: Encryption ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This program implements a configurable encryption algorithm.
 * The user can specify the encryption key and the input message.
 * The encryption is performed using a bitwise XOR operation.
 */

// Define constants
#define MAX_MESSAGE_LENGTH 1000
#define MAX_KEY_LENGTH 100

// Function declarations
char *encrypt(char *message, char *key);

// Main function - entry point of the program
int main() {
    // Declare variables
    char message[MAX_MESSAGE_LENGTH], key[MAX_KEY_LENGTH];
    char *encrypted_message;

    // Get user input
    printf("Enter the message you want to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    printf("Enter the encryption key (must be same length as message): ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    // Remove newline characters at the end of the input strings
    message[strcspn(message, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    // Encrypt the message
    encrypted_message = encrypt(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    // Free memory
    free(encrypted_message);

    return 0;
}

/*
 * This function performs the encryption of the message using the key.
 * It returns a pointer to the encrypted message.
 */
char *encrypt(char *message, char *key) {
    // Allocate memory for the encrypted message
    char *encrypted_message = (char *) malloc(strlen(message) + 1);

    // XOR each character of the message with the corresponding character of the key
    int i;
    for(i=0; i<strlen(message); i++) {
        encrypted_message[i] = message[i] ^ key[i];
    }

    // Add null terminator to the end of the encrypted message
    encrypted_message[i] = '\0';

    // Return the pointer to the encrypted message
    return encrypted_message;
}