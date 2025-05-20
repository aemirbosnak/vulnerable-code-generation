//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 1024

// Function to generate a random key
void generate_key(char* key, int key_length) {
    const char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < key_length; i++) {
        key[i] = chars[rand() % strlen(chars)];
    }
}

// Function to encrypt the message using the key
void encrypt(char* message, char* key, int key_length, char* encrypted_message) {
    for (int i = 0; i < strlen(message); i++) {
        encrypted_message[i] = (message[i] + key[i % key_length]) % 256;
    }
}

// Function to decrypt the message using the key
void decrypt(char* encrypted_message, char* key, int key_length, char* decrypted_message) {
    for (int i = 0; i < strlen(encrypted_message); i++) {
        decrypted_message[i] = encrypted_message[i] - key[i % key_length] + 256;
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];
    char decrypted_message[MAX_MESSAGE_LENGTH];

    // Prompt the user to enter a message
    printf("Enter a message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    // Generate a random key
    generate_key(key, strlen(message));

    // Encrypt the message using the key
    encrypt(message, key, strlen(message), encrypted_message);

    // Decrypt the message using the key
    decrypt(encrypted_message, key, strlen(message), decrypted_message);

    // Output the original message and the encrypted and decrypted messages
    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}