//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the text using a simple Caesar cipher
void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        // Encrypt uppercase letters
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' + shift) % 26 + 'a';
        }
    }
}

// Function to decrypt the text using a simple Caesar cipher
void decrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        // Decrypt uppercase letters
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' - shift + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' - shift + 26) % 26 + 'a';
        }
    }
}

int main() {
    char *text = NULL;
    size_t bufsize = 0;
    int shift;

    printf("Welcome to the C Encryption Program!\n");
    printf("Please enter the text to be encrypted: ");
    
    // Dynamically allocate memory for the text input
    getline(&text, &bufsize, stdin);
    
    // Remove the newline character from the input if it exists
    size_t len = strlen(text);
    if (text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }

    printf("Enter the shift value (0-25): ");
    scanf("%d", &shift);
    
    // Ensuring the shift value is within the accepted range
    if (shift < 0 || shift > 25) {
        printf("Invalid shift value. Exiting program.\n");
        free(text);
        return 1;
    }

    // Print the original text
    printf("Original text: %s\n", text);

    // Encrypting the text
    encrypt(text, shift);
    printf("Encrypted text: %s\n", text);

    // Decrypting the text back to original
    decrypt(text, shift);
    printf("Decrypted text: %s\n", text);

    // Free the dynamically allocated memory
    free(text);
    return 0;
}