//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Initialize the secret key
#define MAGIC_KEY "Abracadabra!"

// The encryption function
char* encrypt(char* plainText) {
    // Create an encrypted string
    char* encryptedText = malloc(strlen(plainText) + 1);

    // Iterate over each character in the plain text
    for (int i = 0; plainText[i]; i++) {
        // XOR the current character with the magic key
        encryptedText[i] = plainText[i] ^ MAGIC_KEY[i % strlen(MAGIC_KEY)];
    }

    // Add the null terminator
    encryptedText[strlen(plainText)] = 0;

    // Return the encrypted string
    return encryptedText;
}

// The decryption function
char* decrypt(char* encryptedText) {
    // Create a decrypted string
    char* decryptedText = malloc(strlen(encryptedText) + 1);

    // Iterate over each character in the encrypted text
    for (int i = 0; encryptedText[i]; i++) {
        // XOR the current character with the magic key
        decryptedText[i] = encryptedText[i] ^ MAGIC_KEY[i % strlen(MAGIC_KEY)];
    }

    // Add the null terminator
    decryptedText[strlen(encryptedText)] = 0;

    // Return the decrypted string
    return decryptedText;
}

int main() {
    // Get the plain text from the user
    char plainText[1024];
    printf("Enter the plain text: ");
    scanf("%s", plainText);

    // Encrypt the plain text
    char* encryptedText = encrypt(plainText);

    // Print the encrypted text
    printf("Encrypted text: %s\n", encryptedText);

    // Decrypt the encrypted text
    char* decryptedText = decrypt(encryptedText);

    // Print the decrypted text
    printf("Decrypted text: %s\n", decryptedText);

    // Free the allocated memory
    free(encryptedText);
    free(decryptedText);

    return 0;
}