//Falcon-180B DATASET v1.0 Category: Encryption ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 256
#define MAX_MESSAGE_LENGTH 1000

// Function to shift each character of the message by a certain amount
void shift_message(char* message, int shift) {
    int i = 0;
    while (message[i]!= '\0') {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] + shift - 65) % 26 + 65;
            } else {
                message[i] = (message[i] + shift - 97) % 26 + 97;
            }
        }
        i++;
    }
}

// Function to generate a random key of a certain length
void generate_key(char* key, int length) {
    int i = 0;
    while (i < length) {
        key[i] = rand() % 26 + 'a';
        i++;
    }
    key[length] = '\0';
}

// Function to encrypt the message using the key
void encrypt_message(char* message, char* key) {
    shift_message(message, key[0] - 'a');
    int i = 1;
    while (message[i]!= '\0') {
        message[i] = (message[i] + key[i % strlen(key)] - 'a') % 26 + 'a';
        i++;
    }
}

// Function to decrypt the message using the key
void decrypt_message(char* message, char* key) {
    shift_message(message, 26 - key[0] + 'a');
    int i = 1;
    while (message[i]!= '\0') {
        message[i] = (message[i] - key[i % strlen(key)] + 26) % 26 + 'a';
        i++;
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    // Get the message from the user
    printf("Enter the message to encrypt/decrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message[strcspn(message, "\n")] = '\0';

    // Generate a random key
    generate_key(key, strlen(message));

    // Encrypt the message
    encrypt_message(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt_message(message, key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}