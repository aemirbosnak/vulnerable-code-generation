//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

// Function to generate a random key
void generate_key(char* key) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'A';
    }
}

// Function to encrypt a message using the key
void encrypt(char* message, char* key, char* encrypted_message) {
    int message_length = strlen(message);
    int encrypted_message_length = message_length + KEY_SIZE;
    encrypted_message[encrypted_message_length - 1] = '\0';

    // Copy the message into the encrypted_message string
    strncpy(encrypted_message, message, message_length);

    // Generate a random key
    generate_key(key);

    // XOR the message with the key
    for (int i = 0; i < message_length; i++) {
        encrypted_message[i] = encrypted_message[i] ^ key[i % KEY_SIZE];
    }
}

// Function to decrypt a message using the key
void decrypt(char* encrypted_message, char* key, char* decrypted_message) {
    int encrypted_message_length = strlen(encrypted_message);
    int message_length = encrypted_message_length - KEY_SIZE;
    decrypted_message[message_length] = '\0';

    // Generate a random key
    generate_key(key);

    // XOR the encrypted message with the key
    for (int i = 0; i < encrypted_message_length; i++) {
        decrypted_message[i] = encrypted_message[i] ^ key[i % KEY_SIZE];
    }
}

int main() {
    char message[256];
    char key[KEY_SIZE];
    char encrypted_message[256];
    char decrypted_message[256];

    printf("Enter a message to encrypt: ");
    fgets(message, 256, stdin);

    generate_key(key);

    encrypt(message, key, encrypted_message);

    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(encrypted_message, key, decrypted_message);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}