//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 32
#define MAX_MESSAGE_SIZE 1024

// Function to generate a random key
void generate_key(char* key, int key_size) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < key_size; i++) {
        key[i] = charset[rand() % strlen(charset)];
    }
    key[key_size] = '\0';
}

// Function to encrypt a message using a key
void encrypt(char* message, char* key, char* encrypted_message) {
    int message_length = strlen(message);
    int encrypted_message_length = message_length + 1; // +1 for null terminator
    int key_index = 0;

    for (int i = 0; i < message_length; i++) {
        char ch = toupper(message[i]);
        if (isalpha(ch)) {
            encrypted_message[i] = (ch + key[key_index]) % 26 + 'A';
            key_index = (key_index + 1) % strlen(key);
        } else {
            encrypted_message[i] = message[i];
        }
    }
    encrypted_message[encrypted_message_length - 1] = '\0';
}

// Function to decrypt an encrypted message using a key
void decrypt(char* encrypted_message, char* key, char* decrypted_message) {
    int encrypted_message_length = strlen(encrypted_message);
    int decrypted_message_length = encrypted_message_length - 1; // -1 for null terminator
    int key_index = 0;

    for (int i = 0; i < encrypted_message_length; i++) {
        char ch = encrypted_message[i];
        if (isalpha(ch)) {
            int decrypted_ch = (ch - key[key_index]) % 26 + 'A';
            decrypted_message[i] = decrypted_ch;
            key_index = (key_index + 1) % strlen(key);
        } else {
            decrypted_message[i] = ch;
        }
    }
    decrypted_message[decrypted_message_length] = '\0';
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    char key[MAX_KEY_SIZE];
    char encrypted_message[MAX_MESSAGE_SIZE];
    char decrypted_message[MAX_MESSAGE_SIZE];

    // Get message from user
    printf("Enter message to encrypt: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);
    message[strcspn(message, "\r")] = '\0';

    // Generate a random key
    generate_key(key, strlen(message));

    // Encrypt message using key
    encrypt(message, key, encrypted_message);

    // Decrypt encrypted message using key
    decrypt(encrypted_message, key, decrypted_message);

    // Print encrypted and decrypted messages
    printf("Encrypted message: %s\n", encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}