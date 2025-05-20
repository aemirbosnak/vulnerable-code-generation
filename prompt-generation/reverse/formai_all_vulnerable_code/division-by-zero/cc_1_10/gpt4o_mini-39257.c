//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define KEY_SIZE 10

// Function to encrypt the message using a simple Caesar cipher
void encrypt(char *message, const char *key) {
    int key_length = strlen(key);
    for (int i = 0; message[i] != '\0'; i++) {
        char current_char = message[i];

        if (isalpha(current_char)) {
            // Determine the shift value based on the key
            int shift = tolower(key[i % key_length]) - 'a';
            char base = isupper(current_char) ? 'A' : 'a';
            // Encrypt the character
            message[i] = (current_char - base + shift) % 26 + base;
        }
    }
}

// Function to decrypt the message using a simple Caesar cipher
void decrypt(char *message, const char *key) {
    int key_length = strlen(key);
    for (int i = 0; message[i] != '\0'; i++) {
        char current_char = message[i];

        if (isalpha(current_char)) {
            // Determine the shift value based on the key
            int shift = tolower(key[i % key_length]) - 'a';
            char base = isupper(current_char) ? 'A' : 'a';
            // Decrypt the character
            message[i] = (current_char - base - shift + 26) % 26 + base;
        }
    }
}

// Function to get input message from the user
void getInput(char *message) {
    printf("Enter the message to encrypt: ");
    fgets(message, BUFFER_SIZE, stdin);
    
    // Remove trailing newline character, if it exists
    message[strcspn(message, "\n")] = 0;
}

// Function to get the encryption key from the user
void getEncryptionKey(char *key) {
    do {
        printf("Enter a key (alphabetic characters only): ");
        fgets(key, KEY_SIZE, stdin);
        key[strcspn(key, "\n")] = 0;
    } while (strspn(key, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != strlen(key)); // Validate key
}

// Function to display results
void displayResult(const char *message, const char *mode) {
    printf("The %s message is: %s\n", mode, message);
}

int main() {
    char message[BUFFER_SIZE];
    char key[KEY_SIZE];

    // User input
    getInput(message);
    getEncryptionKey(key);

    // Encrypt the message
    encrypt(message, key);
    displayResult(message, "encrypted");

    // Decrypt the message
    decrypt(message, key);
    displayResult(message, "decrypted");

    return 0;
}