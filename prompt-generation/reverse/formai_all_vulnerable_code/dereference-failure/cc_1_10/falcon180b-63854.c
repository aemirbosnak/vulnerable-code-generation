//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 1000
#define MAX_ENCRYPTED_LENGTH (MAX_MESSAGE_LENGTH + 1)

// Function to generate a random key
void generate_key(char *key, int length) {
    for (int i = 0; i < length; i++) {
        char c = rand() % 26 + 'a';
        key[i] = c;
    }
    key[length] = '\0';
}

// Function to encrypt the message using the key
void encrypt(char *message, char *key, char *encrypted_message) {
    int message_length = strlen(message);
    int key_length = strlen(key);

    for (int i = 0; i < message_length; i++) {
        encrypted_message[i] = (char) ((int) message[i] + (int) key[i % key_length]);
    }

    encrypted_message[message_length] = '\0';
}

// Function to decrypt the message using the key
void decrypt(char *encrypted_message, char *key, char *decrypted_message) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_length = strlen(key);

    for (int i = 0; i < encrypted_message_length; i++) {
        decrypted_message[i] = (char) ((int) encrypted_message[i] - (int) key[i % key_length]);
    }

    decrypted_message[encrypted_message_length] = '\0';
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    char encrypted_message[MAX_ENCRYPTED_LENGTH];
    char decrypted_message[MAX_MESSAGE_LENGTH];

    // Get the message from the user
    printf("Enter message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    // Generate a random key
    generate_key(key, MAX_KEY_LENGTH);

    // Encrypt the message using the key
    encrypt(message, key, encrypted_message);

    // Get the encrypted message from the user
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt the message using the key
    decrypt(encrypted_message, key, decrypted_message);

    // Display the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}