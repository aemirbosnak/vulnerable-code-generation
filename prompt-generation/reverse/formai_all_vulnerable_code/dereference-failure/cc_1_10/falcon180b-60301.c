//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 1024

// Function to generate a random key
void generate_key(char* key, int length) {
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[length] = '\0';
}

// Function to encrypt the message using the key
void encrypt(char* message, char* key, char* encrypted_message) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int encrypted_message_length = message_length + 1;

    encrypted_message[encrypted_message_length - 1] = '\0';

    for (int i = 0; i < message_length; i++) {
        encrypted_message[i] = message[i] + key[i % key_length];
    }
}

// Function to decrypt the message using the key
void decrypt(char* encrypted_message, char* key, char* decrypted_message) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_length = strlen(key);
    int decrypted_message_length = encrypted_message_length - 1;

    decrypted_message[decrypted_message_length] = '\0';

    for (int i = 0; i < encrypted_message_length; i++) {
        decrypted_message[i] = encrypted_message[i] - key[i % key_length];
    }
}

int main() {
    char key[MAX_KEY_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];
    char decrypted_message[MAX_MESSAGE_LENGTH];

    // Generate a random key
    generate_key(key, rand() % MAX_KEY_LENGTH + 1);

    // Get the message from the user
    printf("Enter the message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    // Encrypt the message using the key
    encrypt(message, key, encrypted_message);

    // Display the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt the message using the key
    decrypt(encrypted_message, key, decrypted_message);

    // Display the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}