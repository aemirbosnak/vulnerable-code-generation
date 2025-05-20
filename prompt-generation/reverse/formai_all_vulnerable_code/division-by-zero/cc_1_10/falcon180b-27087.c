//Falcon-180B DATASET v1.0 Category: Encryption ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 64
#define MAX_MESSAGE_LENGTH 1024

// Function to shift a character by a given amount
char shift(char c, int amount) {
    if (islower(c)) {
        return (char)((c - 'a' + amount) % 26 + 'a');
    } else if (isupper(c)) {
        return (char)((c - 'A' + amount) % 26 + 'A');
    } else {
        return c;
    }
}

// Function to encrypt a message using a key
void encrypt(char* message, char* key) {
    int i, j, keyIndex = 0;
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = shift(message[i], key[keyIndex] - 'a');
            keyIndex = (keyIndex + 1) % strlen(key);
        }
    }
}

// Function to decrypt a message using a key
void decrypt(char* message, char* key) {
    int i, j, keyIndex = 0;
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = shift(message[i], 'a' - key[keyIndex]);
            keyIndex = (keyIndex + 1) % strlen(key);
        }
    }
}

// Function to generate a random key
void generateKey(char* key) {
    int i;
    for (i = 0; i < MAX_KEY_LENGTH; i++) {
        key[i] = 'a' + rand() % 26;
    }
    key[MAX_KEY_LENGTH - 1] = '\0';
}

int main() {
    // Initialize variables
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    // Get message from user
    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    // Remove newline character from message
    message[strcspn(message, "\n")] = '\0';

    // Get key from user
    printf("Enter a key to encrypt with (leave blank for a random key): ");
    if (fgets(key, MAX_KEY_LENGTH, stdin) == NULL) {
        generateKey(key);
    }

    // Encrypt message using key
    encrypt(message, key);

    // Print encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt message using key
    decrypt(message, key);

    // Print decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}