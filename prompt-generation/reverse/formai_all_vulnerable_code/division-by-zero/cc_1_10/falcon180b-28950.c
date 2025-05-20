//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_KEY_SIZE 16
#define MAX_MESSAGE_SIZE 1000

// Function to encrypt the message
void encrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int i = 0;

    while (i < message_length) {
        char c = tolower(message[i]);
        if (isalpha(c)) {
            if (isupper(c)) {
                c += 'a' - 'A';
            }
            c = (c + key[i % key_length]) % 26 + 'a';
        }
        message[i] = c;
        i++;
    }
}

// Function to decrypt the message
void decrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int i = 0;

    while (i < message_length) {
        char c = tolower(message[i]);
        if (isalpha(c)) {
            if (isupper(c)) {
                c = 'A' + (c - 'a' - key[i % key_length] + 26) % 26;
            } else {
                c = 'a' + (c - 'a' - key[i % key_length] + 26) % 26;
            }
        }
        message[i] = c;
        i++;
    }
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    char key[MAX_KEY_SIZE];

    // Get the message from the user
    printf("Enter the message to encrypt: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);

    // Remove newline character from the message
    message[strcspn(message, "\n")] = '\0';

    // Get the key from the user
    printf("Enter the encryption key (up to %d characters): ", MAX_KEY_SIZE - 1);
    fgets(key, MAX_KEY_SIZE, stdin);

    // Remove newline character from the key
    key[strcspn(key, "\n")] = '\0';

    // Encrypt the message
    encrypt(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}