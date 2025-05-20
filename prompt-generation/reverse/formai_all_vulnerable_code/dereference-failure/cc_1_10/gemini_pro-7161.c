//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encrypt a message using a simple substitution cipher
char *encrypt(const char *message) {
    // Create a new string to store the encrypted message
    char *encryptedMessage = malloc(strlen(message) + 1);
    if (encryptedMessage == NULL) {
        printf("Error: Could not allocate memory for encrypted message\n");
        return NULL;
    }

    // Loop through each character in the message
    for (int i = 0; i < strlen(message); i++) {
        // Get the current character
        char c = message[i];

        // Encrypt the character using a simple substitution cipher
        if (c >= 'a' && c <= 'z') {
            c += 3;
            if (c > 'z') {
                c -= 26;
            }
        } else if (c >= 'A' && c <= 'Z') {
            c += 3;
            if (c > 'Z') {
                c -= 26;
            }
        }

        // Store the encrypted character in the new string
        encryptedMessage[i] = c;
    }

    // Terminate the new string with a null character
    encryptedMessage[strlen(message)] = '\0';

    // Return the encrypted message
    return encryptedMessage;
}

// Decrypt a message using a simple substitution cipher
char *decrypt(const char *encryptedMessage) {
    // Create a new string to store the decrypted message
    char *decryptedMessage = malloc(strlen(encryptedMessage) + 1);
    if (decryptedMessage == NULL) {
        printf("Error: Could not allocate memory for decrypted message\n");
        return NULL;
    }

    // Loop through each character in the encrypted message
    for (int i = 0; i < strlen(encryptedMessage); i++) {
        // Get the current character
        char c = encryptedMessage[i];

        // Decrypt the character using a simple substitution cipher
        if (c >= 'a' && c <= 'z') {
            c -= 3;
            if (c < 'a') {
                c += 26;
            }
        } else if (c >= 'A' && c <= 'Z') {
            c -= 3;
            if (c < 'A') {
                c += 26;
            }
        }

        // Store the decrypted character in the new string
        decryptedMessage[i] = c;
    }

    // Terminate the new string with a null character
    decryptedMessage[strlen(encryptedMessage)] = '\0';

    // Return the decrypted message
    return decryptedMessage;
}

int main() {
    // Get the message to encrypt
    char message[100];
    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    // Encrypt the message
    char *encryptedMessage = encrypt(message);

    // Decrypt the encrypted message
    char *decryptedMessage = decrypt(encryptedMessage);

    // Print the encrypted and decrypted messages
    printf("Encrypted message: %s\n", encryptedMessage);
    printf("Decrypted message: %s\n", decryptedMessage);

    // Free the allocated memory
    free(encryptedMessage);
    free(decryptedMessage);

    return 0;
}