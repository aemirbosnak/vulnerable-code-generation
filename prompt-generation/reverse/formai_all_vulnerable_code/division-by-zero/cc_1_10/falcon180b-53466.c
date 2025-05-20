//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100

// Function to generate a random key of specified length
void generate_key(char* key, int length) {
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[length] = '\0';
}

// Function to encrypt a message using the Vigenere cipher
void encrypt_message(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    char encrypted_message[message_length];

    for (int i = 0; i < message_length; i++) {
        char c = toupper(message[i]);
        if (isalpha(c)) {
            int index = toupper(key[i % key_length]) - 'A';
            encrypted_message[i] = (c - 'A' + index) % 26 + 'A';
        } else {
            encrypted_message[i] = c;
        }
    }

    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt an encrypted message using the Vigenere cipher
void decrypt_message(char* encrypted_message, char* key) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_length = strlen(key);
    char decrypted_message[encrypted_message_length];

    for (int i = 0; i < encrypted_message_length; i++) {
        char c = toupper(encrypted_message[i]);
        if (isalpha(c)) {
            int index = toupper(key[i % key_length]) - 'A';
            decrypted_message[i] = (c - 'A' - index + 26) % 26 + 'A';
        } else {
            decrypted_message[i] = c;
        }
    }

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_KEY_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_KEY_LENGTH, stdin);

    printf("Enter a key to encrypt the message with: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    encrypt_message(message, key);

    printf("Enter the encrypted message to decrypt: ");
    fgets(message, MAX_KEY_LENGTH, stdin);

    printf("Enter the key used to encrypt the message: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    decrypt_message(message, key);

    return 0;
}