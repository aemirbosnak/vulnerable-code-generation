//Falcon-180B DATASET v1.0 Category: Encryption ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"

// Function to encrypt the message
void encrypt(char* message) {
    int len = strlen(message);
    char* encrypted = malloc(len + 1);
    int i = 0;

    // Loop through each character in the message
    for (int j = 0; j < len; j++) {
        // Convert character to uppercase
        message[j] = toupper(message[j]);

        // XOR the character with the key
        char c = message[j] ^ KEY[i];

        // Increment the key index
        i++;
        if (i == strlen(KEY)) {
            i = 0;
        }

        // Append the encrypted character to the result string
        encrypted[j] = c;
    }

    // Terminate the result string
    encrypted[len] = '\0';

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted);
}

// Function to decrypt the message
void decrypt(char* encrypted_message) {
    int len = strlen(encrypted_message);
    char* decrypted = malloc(len + 1);
    int i = 0;

    // Loop through each character in the encrypted message
    for (int j = 0; j < len; j++) {
        // XOR the character with the key
        char c = encrypted_message[j] ^ KEY[i];

        // Increment the key index
        i++;
        if (i == strlen(KEY)) {
            i = 0;
        }

        // Append the decrypted character to the result string
        decrypted[j] = c;
    }

    // Terminate the result string
    decrypted[len] = '\0';

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted);
}

int main() {
    char* message = "Hello, world!";

    // Encrypt the message
    encrypt(message);

    // Decrypt the encrypted message
    char* encrypted_message = malloc(strlen(message) + 1);
    strcpy(encrypted_message, message);
    decrypt(encrypted_message);

    return 0;
}