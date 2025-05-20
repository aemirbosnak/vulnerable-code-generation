//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Function to rotate a character by a given number of positions
char rotateCharacter(char ch, int num) {
    // Calculate the new position of the character
    int newPos = (ch - 'a' + num) % 26;

    // Convert the new position back to a character
    return 'a' + newPos;
}

// Function to encrypt a string using the Caesar cipher
char* caesarEncrypt(char* plaintext, int key) {
    // Allocate memory for the ciphertext
    char* ciphertext = malloc(sizeof(char) * (strlen(plaintext) + 1));

    // Encrypt each character in the plaintext
    for (int i = 0; i < strlen(plaintext); i++) {
        // Check if the character is a letter
        if (isalpha(plaintext[i])) {
            // Rotate the character using the given key
            ciphertext[i] = rotateCharacter(plaintext[i], key);
        } else {
            // Copy the character to the ciphertext without encryption
            ciphertext[i] = plaintext[i];
        }
    }

    // Terminate the ciphertext with a null character
    ciphertext[strlen(plaintext)] = '\0';

    // Return the ciphertext
    return ciphertext;
}

// Function to decrypt a string using the Caesar cipher
char* caesarDecrypt(char* ciphertext, int key) {
    // Allocate memory for the plaintext
    char* plaintext = malloc(sizeof(char) * (strlen(ciphertext) + 1));

    // Decrypt each character in the ciphertext
    for (int i = 0; i < strlen(ciphertext); i++) {
        // Check if the character is a letter
        if (isalpha(ciphertext[i])) {
            // Rotate the character using the negative of the given key
            plaintext[i] = rotateCharacter(ciphertext[i], -key);
        } else {
            // Copy the character to the plaintext without decryption
            plaintext[i] = ciphertext[i];
        }
    }

    // Terminate the plaintext with a null character
    plaintext[strlen(ciphertext)] = '\0';

    // Return the plaintext
    return plaintext;
}

// Function to print a message in a Sherlock Holmes style
void printSherlockMessage(char* message) {
    printf("\nElementary, my dear Watson!\n\n");
    printf("\"%s\"\n\n", message);
}

int main() {
    // The secret message
    char* secretMessage = "the quick brown fox jumps over the lazy dog";

    // Encrypt the secret message using the Caesar cipher with a key of 3
    char* encryptedMessage = caesarEncrypt(secretMessage, 3);

    // Print the encrypted message in a Sherlock Holmes style
    printSherlockMessage(encryptedMessage);

    // Decrypt the encrypted message using the Caesar cipher with a key of 3
    char* decryptedMessage = caesarDecrypt(encryptedMessage, 3);

    // Print the decrypted message in a Sherlock Holmes style
    printSherlockMessage(decryptedMessage);

    // Free the allocated memory
    free(encryptedMessage);
    free(decryptedMessage);

    return 0;
}