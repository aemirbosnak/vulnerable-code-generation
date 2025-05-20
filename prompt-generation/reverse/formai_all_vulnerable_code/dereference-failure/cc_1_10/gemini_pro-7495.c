//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a message using the Caesar cipher
char* caesar_encrypt(char* message, int key) {
    // Allocate memory for the encrypted message
    char* encrypted_message = malloc(strlen(message) + 1);

    // Loop through each character in the message
    for (int i = 0; i < strlen(message); i++) {
        // Get the ASCII value of the character
        int ascii_value = (int)message[i];

        // Encrypt the character using the Caesar cipher
        if (ascii_value >= 'a' && ascii_value <= 'z') {
            ascii_value += key;
            if (ascii_value > 'z') {
                ascii_value -= 26;
            }
        } else if (ascii_value >= 'A' && ascii_value <= 'Z') {
            ascii_value += key;
            if (ascii_value > 'Z') {
                ascii_value -= 26;
            }
        }

        // Store the encrypted character in the encrypted message
        encrypted_message[i] = (char)ascii_value;
    }

    // Terminate the encrypted message with a null character
    encrypted_message[strlen(message)] = '\0';

    // Return the encrypted message
    return encrypted_message;
}

// Function to decrypt a message using the Caesar cipher
char* caesar_decrypt(char* message, int key) {
    // Allocate memory for the decrypted message
    char* decrypted_message = malloc(strlen(message) + 1);

    // Loop through each character in the message
    for (int i = 0; i < strlen(message); i++) {
        // Get the ASCII value of the character
        int ascii_value = (int)message[i];

        // Decrypt the character using the Caesar cipher
        if (ascii_value >= 'a' && ascii_value <= 'z') {
            ascii_value -= key;
            if (ascii_value < 'a') {
                ascii_value += 26;
            }
        } else if (ascii_value >= 'A' && ascii_value <= 'Z') {
            ascii_value -= key;
            if (ascii_value < 'A') {
                ascii_value += 26;
            }
        }

        // Store the decrypted character in the decrypted message
        decrypted_message[i] = (char)ascii_value;
    }

    // Terminate the decrypted message with a null character
    decrypted_message[strlen(message)] = '\0';

    // Return the decrypted message
    return decrypted_message;
}

int main() {
    // Get the message to be encrypted from the user
    char message[100];
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    // Get the encryption key from the user
    int key;
    printf("Enter the encryption key: ");
    scanf("%d", &key);

    // Encrypt the message using the Caesar cipher
    char* encrypted_message = caesar_encrypt(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt the encrypted message using the Caesar cipher
    char* decrypted_message = caesar_decrypt(encrypted_message, key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    // Free the allocated memory
    free(encrypted_message);
    free(decrypted_message);

    return 0;
}