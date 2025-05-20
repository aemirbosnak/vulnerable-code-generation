//Falcon-180B DATASET v1.0 Category: Encryption ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 16
#define MAX_MESSAGE_LENGTH 1024

void generate_key(char *key, int key_length) {
    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_length] = '\0';
}

void encrypt(char *message, char *key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    char encrypted_message[MAX_MESSAGE_LENGTH];

    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            char c = toupper(message[i]);
            int key_index = (c - 'A') % key_length;
            encrypted_message[i] = (key[key_index] + c) % 26 + 'A';
        } else {
            encrypted_message[i] = message[i];
        }
    }

    encrypted_message[message_length] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char *encrypted_message, char *key) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_length = strlen(key);
    char decrypted_message[MAX_MESSAGE_LENGTH];

    for (int i = 0; i < encrypted_message_length; i++) {
        if (isalpha(encrypted_message[i])) {
            char c = toupper(encrypted_message[i]);
            int key_index = (c - 'A') % key_length;
            decrypted_message[i] = (c - key[key_index] + 26) % 26 + 'A';
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }

    decrypted_message[encrypted_message_length] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    // Generate a random encryption key
    generate_key(key, MAX_KEY_LENGTH);

    // Prompt the user to enter a message to encrypt
    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    // Encrypt the message
    encrypt(message, key);

    // Prompt the user to enter the encrypted message to decrypt
    printf("Enter an encrypted message to decrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    // Decrypt the message
    decrypt(message, key);

    return 0;
}