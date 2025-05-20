//Falcon2-11B DATASET v1.0 Category: Modern Encryption ; Style: mind-bending
#include <stdio.h>
#include <string.h>

void modernEncryption(char* key, char* message) {
    // Convert message and key to uppercase for consistency
    char* messageUpper = strdup(message);
    char* keyUpper = strdup(key);
    for (int i = 0; messageUpper[i]; i++) {
        messageUpper[i] = toupper(messageUpper[i]);
    }
    for (int i = 0; keyUpper[i]; i++) {
        keyUpper[i] = toupper(keyUpper[i]);
    }

    // Initialize variables
    int messageLength = strlen(messageUpper);
    int keyLength = strlen(keyUpper);
    int shift = 0;

    // Perform encryption
    for (int i = 0; i < messageLength; i++) {
        // Calculate the index in the key string where the current character of the message will be shifted to
        int keyIndex = (keyUpper[i % keyLength] - 'A') + shift;

        // Adjust shift if the index is out of bounds
        if (keyIndex < 0 || keyIndex >= keyLength) {
            shift += keyLength - keyIndex + 1;
        }

        // Shift the character in the message
        char encryptedCharacter = messageUpper[i] + shift - 'A';
        if (encryptedCharacter < 'A' || encryptedCharacter > 'Z') {
            encryptedCharacter += 26;
        }

        // Store the encrypted character back in the message
        messageUpper[i] = encryptedCharacter;
    }

    // Convert message back to lowercase for consistency
    for (int i = 0; messageUpper[i]; i++) {
        messageUpper[i] = tolower(messageUpper[i]);
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", messageUpper);

    // Free allocated memory
    free(messageUpper);
    free(keyUpper);
}

int main() {
    char* key = "K3Y";
    char* message = "Hello, World!";
    modernEncryption(key, message);
    return 0;
}