//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 256

// Function to encrypt a message using a key
char *encrypt(char *message, char *key) {
    int message_len = strlen(message);
    int key_len = strlen(key);

    // Check if the key is long enough
    if (key_len < message_len) {
        printf("Error: Key is too short!\n");
        return NULL;
    }

    // Create an encrypted message buffer
    char *encrypted_message = malloc(message_len + 1);
    if (encrypted_message == NULL) {
        printf("Error: Could not allocate memory for encrypted message!\n");
        return NULL;
    }

    // Encrypt the message
    for (int i = 0; i < message_len; i++) {
        encrypted_message[i] = message[i] ^ key[i % key_len];
    }

    // Null-terminate the encrypted message
    encrypted_message[message_len] = '\0';

    // Return the encrypted message
    return encrypted_message;
}

// Function to decrypt a message using a key
char *decrypt(char *encrypted_message, char *key) {
    int encrypted_message_len = strlen(encrypted_message);
    int key_len = strlen(key);

    // Check if the key is long enough
    if (key_len < encrypted_message_len) {
        printf("Error: Key is too short!\n");
        return NULL;
    }

    // Create a decrypted message buffer
    char *decrypted_message = malloc(encrypted_message_len + 1);
    if (decrypted_message == NULL) {
        printf("Error: Could not allocate memory for decrypted message!\n");
        return NULL;
    }

    // Decrypt the message
    for (int i = 0; i < encrypted_message_len; i++) {
        decrypted_message[i] = encrypted_message[i] ^ key[i % key_len];
    }

    // Null-terminate the decrypted message
    decrypted_message[encrypted_message_len] = '\0';

    // Return the decrypted message
    return decrypted_message;
}

// Main function
int main() {
    // Get the message to encrypt
    char message[MAX_KEY_LEN];
    printf("Enter your message to encrypt: ");
    fgets(message, MAX_KEY_LEN, stdin);

    // Get the key
    char key[MAX_KEY_LEN];
    printf("Enter your encryption key: ");
    fgets(key, MAX_KEY_LEN, stdin);

    // Encrypt the message
    char *encrypted_message = encrypt(message, key);
    if (encrypted_message == NULL) {
        return EXIT_FAILURE;
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt the message
    char *decrypted_message = decrypt(encrypted_message, key);
    if (decrypted_message == NULL) {
        return EXIT_FAILURE;
    }

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    // Free the allocated memory
    free(encrypted_message);
    free(decrypted_message);

    return EXIT_SUCCESS;
}