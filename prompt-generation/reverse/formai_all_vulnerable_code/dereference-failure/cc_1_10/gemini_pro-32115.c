//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 32

// Function to encrypt a message using a key
char *encrypt(char *message, char *key) {
    int message_length = strlen(message);
    int key_length = strlen(key);

    // Check if the key is too long
    if (key_length > MAX_KEY_LENGTH) {
        fprintf(stderr, "Error: Key is too long. Maximum length is %d characters.\n", MAX_KEY_LENGTH);
        return NULL;
    }

    // Allocate memory for the encrypted message
    char *encrypted_message = malloc(message_length + 1);
    if (encrypted_message == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for encrypted message.\n");
        return NULL;
    }

    // Encrypt the message
    for (int i = 0; i < message_length; i++) {
        encrypted_message[i] = message[i] ^ key[i % key_length];
    }

    // Add the null terminator
    encrypted_message[message_length] = '\0';

    // Return the encrypted message
    return encrypted_message;
}

// Function to decrypt a message using a key
char *decrypt(char *encrypted_message, char *key) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_length = strlen(key);

    // Check if the key is too long
    if (key_length > MAX_KEY_LENGTH) {
        fprintf(stderr, "Error: Key is too long. Maximum length is %d characters.\n", MAX_KEY_LENGTH);
        return NULL;
    }

    // Allocate memory for the decrypted message
    char *decrypted_message = malloc(encrypted_message_length + 1);
    if (decrypted_message == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for decrypted message.\n");
        return NULL;
    }

    // Decrypt the message
    for (int i = 0; i < encrypted_message_length; i++) {
        decrypted_message[i] = encrypted_message[i] ^ key[i % key_length];
    }

    // Add the null terminator
    decrypted_message[encrypted_message_length] = '\0';

    // Return the decrypted message
    return decrypted_message;
}

int main() {
    // Define the message and key
    char *message = "This is a secret message.";
    char *key = "password";

    // Encrypt the message
    char *encrypted_message = encrypt(message, key);
    if (encrypted_message == NULL) {
        return 1;
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt the message
    char *decrypted_message = decrypt(encrypted_message, key);
    if (decrypted_message == NULL) {
        return 1;
    }

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    // Free the allocated memory
    free(encrypted_message);
    free(decrypted_message);

    return 0;
}