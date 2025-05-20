//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message using a basic substitution cipher
char* encrypt(const char* message, int shift) {
    int len = strlen(message);
    char* encrypted = malloc(len + 1);
    if (!encrypted) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < len; i++) {
        char c = message[i];
        if (c >= 'a' && c <= 'z') {
            // Shift lowercase letters
            encrypted[i] = (c - 'a' + shift) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            // Shift uppercase letters
            encrypted[i] = (c - 'A' + shift) % 26 + 'A';
        } else {
            // Non-alphabetical characters remain unchanged
            encrypted[i] = c;
        }
    }
    encrypted[len] = '\0'; // Null-terminate the string
    return encrypted;
}

// Function to decrypt the message
char* decrypt(const char* encryptedMsg, int shift) {
    int len = strlen(encryptedMsg);
    char* decrypted = malloc(len + 1);
    if (!decrypted) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < len; i++) {
        char c = encryptedMsg[i];
        if (c >= 'a' && c <= 'z') {
            // Reverse shift for lowercase letters
            decrypted[i] = (c - 'a' - shift + 26) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            // Reverse shift for uppercase letters
            decrypted[i] = (c - 'A' - shift + 26) % 26 + 'A';
        } else {
            // Non-alphabetical characters remain unchanged
            decrypted[i] = c;
        }
    }
    decrypted[len] = '\0'; // Null-terminate the string
    return decrypted;
}

int main() {
    const int SHIFT = 3; // Example shift value for encryption
    char message[256];

    printf("🎉 Welcome to the Surprise Encryption Program! 🎉\n");
    printf("Please enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    // Remove newline character that fgets might add
    message[strcspn(message, "\n")] = '\0';

    char* encryptedMessage = encrypt(message, SHIFT);
    printf("✨ Encrypted Message: %s\n", encryptedMessage);

    char* decryptedMessage = decrypt(encryptedMessage, SHIFT);
    printf("✨ Decrypted Message: %s\n", decryptedMessage);

    // Clean up dynamically allocated memory
    free(encryptedMessage);
    free(decryptedMessage);

    printf("Thank you for using the Surprise Encryption Program! 💫\n");
    return 0;
}