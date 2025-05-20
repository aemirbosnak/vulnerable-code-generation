//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: post-apocalyptic
// Post-apocalyptic Cryptography System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 1000
#define MAX_KEY_LENGTH 256

// Encrypts the message using the key provided and returns the encrypted message
char* encrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    char* encrypted_message = (char *) malloc(sizeof(char) * message_length);

    for (int i = 0; i < message_length; i++) {
        int key_index = i % key_length;
        int encrypted_char = ((int) message[i]) + ((int) key[key_index]);
        encrypted_message[i] = (char) encrypted_char;
    }

    return encrypted_message;
}

// Decrypts the message using the key provided and returns the decrypted message
char* decrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    char* decrypted_message = (char *) malloc(sizeof(char) * message_length);

    for (int i = 0; i < message_length; i++) {
        int key_index = i % key_length;
        int decrypted_char = ((int) message[i]) - ((int) key[key_index]);
        decrypted_message[i] = (char) decrypted_char;
    }

    return decrypted_message;
}

int main() {
    printf("Welcome to the Post-apocalyptic Cryptography System\n");

    // Ask user for message to encrypt
    printf("Please enter message to encrypt: ");
    char message[MAX_MESSAGE_LENGTH];
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    // Ask user for key to encrypt message with
    printf("Please enter key to encrypt message with: ");
    char key[MAX_KEY_LENGTH];
    fgets(key, MAX_KEY_LENGTH, stdin);

    // Encrypt message and print result
    char* encrypted_message = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt message and print result
    char* decrypted_message = decrypt(encrypted_message, key);
    printf("Decrypted message: %s\n", decrypted_message);

    // Free dynamically allocated memory
    free(encrypted_message);
    free(decrypted_message);

    return 0;
}