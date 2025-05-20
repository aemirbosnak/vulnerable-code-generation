//Falcon-180B DATASET v1.0 Category: Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 26
#define INIT_VALUE 97
#define RANDOM_VALUE ((rand() % 26) + INIT_VALUE)

// Function to encrypt the message
void encrypt(char* message) {
    int length = strlen(message);
    char* encrypted_message = (char*)malloc(length + 1);
    memset(encrypted_message, 0, length + 1);

    // Loop through each character in the message
    for (int i = 0; i < length; i++) {
        char c = toupper(message[i]);

        // Check if the character is a letter
        if (isalpha(c)) {
            // Encrypt the letter using the Caesar cipher
            int index = c - 65;
            int key = RANDOM_VALUE;
            int encrypted_char = ((index + key) % SIZE) + 65;

            encrypted_message[i] = encrypted_char;
        } else {
            // Copy non-letter characters as is
            encrypted_message[i] = message[i];
        }
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the message
void decrypt(char* message) {
    int length = strlen(message);
    char* decrypted_message = (char*)malloc(length + 1);
    memset(decrypted_message, 0, length + 1);

    // Loop through each character in the message
    for (int i = 0; i < length; i++) {
        char c = toupper(message[i]);

        // Check if the character is a letter
        if (isalpha(c)) {
            // Decrypt the letter using the Caesar cipher
            int index = c - 65;
            int key = RANDOM_VALUE;
            int decrypted_char = ((index - key + 26) % SIZE) + 65;

            decrypted_message[i] = decrypted_char;
        } else {
            // Copy non-letter characters as is
            decrypted_message[i] = message[i];
        }
    }

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char* message = "Hello, World!";

    // Encrypt the message
    encrypt(message);

    // Decrypt the encrypted message
    char* encrypted_message = (char*)malloc(strlen(message) + 1);
    strcpy(encrypted_message, message);
    decrypt(encrypted_message);

    return 0;
}